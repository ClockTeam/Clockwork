//
// Copyright (c) 2008-2016 the Clockwork project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#include "../Precompiled.h"

#include "../AngelScript/Addons.h"
#include "../AngelScript/Script.h"
#include "../AngelScript/ScriptAPI.h"
#include "../AngelScript/ScriptFile.h"
#include "../AngelScript/ScriptInstance.h"
#include "../Core/Profiler.h"
#include "../Engine/EngineEvents.h"
#include "../IO/FileSystem.h"
#include "../IO/Log.h"
#include "../Resource/ResourceCache.h"
#include "../Scene/Scene.h"

#include "../DebugNew.h"

namespace Clockwork
{

class ScriptResourceRouter : public ResourceRouter
{
    CLOCKWORK_OBJECT(ScriptResourceRouter, ResourceRouter);

    /// Construct.
    ScriptResourceRouter(Context* context) :
        ResourceRouter(context)
    {
    }

    /// Check if request is for an AngelScript file and reroute to compiled version if necessary (.as file not available)
    virtual void Route(String& name, ResourceRequest requestType)
    {
        String extension = GetExtension(name);
        if (extension == ".as")
        {
            String replaced = ReplaceExtension(name, ".asc");
            // Note: ResourceCache prevents recursive calls to the resource routers so this is OK, the nested Exists()
            // check does not go through the router again
            ResourceCache* cache = GetSubsystem<ResourceCache>();
            if (!cache->Exists(name) && cache->Exists(replaced))
                name = replaced;
        }
    }
};


Script::Script(Context* context) :
    Object(context),
    scriptEngine_(0),
    immediateContext_(0),
    scriptNestingLevel_(0),
    executeConsoleCommands_(false)
{
    scriptEngine_ = asCreateScriptEngine(ANGELSCRIPT_VERSION);
    if (!scriptEngine_)
    {
        CLOCKWORK_LOGERROR("Could not create AngelScript engine");
        return;
    }

    scriptEngine_->SetUserData(this);
    scriptEngine_->SetEngineProperty(asEP_USE_CHARACTER_LITERALS, (asPWORD)true);
    scriptEngine_->SetEngineProperty(asEP_ALLOW_UNSAFE_REFERENCES, (asPWORD)true);
    scriptEngine_->SetEngineProperty(asEP_ALLOW_IMPLICIT_HANDLE_TYPES, (asPWORD)true);
    scriptEngine_->SetEngineProperty(asEP_BUILD_WITHOUT_LINE_CUES, (asPWORD)true);
    scriptEngine_->SetMessageCallback(asMETHOD(Script, MessageCallback), this, asCALL_THISCALL);

    // Create the context for immediate execution
    immediateContext_ = scriptEngine_->CreateContext();
    immediateContext_->SetExceptionCallback(asMETHOD(Script, ExceptionCallback), this, asCALL_THISCALL);

    // Register Script library object factories
    RegisterScriptLibrary(context_);

    // Register the Array, String & Dictionary API
    RegisterArray(scriptEngine_);
    RegisterString(scriptEngine_);
    RegisterDictionary(scriptEngine_);
    RegisterScriptInterfaceAPI(scriptEngine_);

    // Register the rest of the script API
    RegisterMathAPI(scriptEngine_);
    RegisterCoreAPI(scriptEngine_);
    RegisterIOAPI(scriptEngine_);
    RegisterResourceAPI(scriptEngine_);
    RegisterSceneAPI(scriptEngine_);
    RegisterGraphicsAPI(scriptEngine_);
    RegisterInputAPI(scriptEngine_);
    RegisterAudioAPI(scriptEngine_);
    RegisterUIAPI(scriptEngine_);
#ifdef CLOCKWORK_NETWORK
    RegisterNetworkAPI(scriptEngine_);
#endif
#ifdef CLOCKWORK_DATABASE
    RegisterDatabaseAPI(scriptEngine_);
#endif
#ifdef CLOCKWORK_PHYSICS
    RegisterPhysicsAPI(scriptEngine_);
#endif
#ifdef CLOCKWORK_NAVIGATION
    RegisterNavigationAPI(scriptEngine_);
#endif
#ifdef CLOCKWORK_URHO2D
    RegisterUrho2DAPI(scriptEngine_);
#endif
    RegisterScriptAPI(scriptEngine_);
    RegisterEngineAPI(scriptEngine_);

    // Subscribe to console commands
    SetExecuteConsoleCommands(true);

    // Create and register resource router for checking for compiled AngelScript files
    ResourceCache* cache = GetSubsystem<ResourceCache>();
    if (cache)
    {
        router_ = new ScriptResourceRouter(context_);
        cache->AddResourceRouter(router_);
    }
}

Script::~Script()
{
    if (immediateContext_)
    {
        immediateContext_->Release();
        immediateContext_ = 0;
    }

    for (unsigned i = 0; i < scriptFileContexts_.Size(); ++i)
        scriptFileContexts_[i]->Release();

    if (scriptEngine_)
    {
        scriptEngine_->Release();
        scriptEngine_ = 0;
    }

    ResourceCache* cache = GetSubsystem<ResourceCache>();
    if (cache)
        cache->RemoveResourceRouter(router_);
}

bool Script::Execute(const String& line)
{
    // Note: compiling code each time is slow. Not to be used for performance-critical or repeating activity
    CLOCKWORK_PROFILE(ExecuteImmediate);

    ClearObjectTypeCache();

    String wrappedLine = "void f(){\n" + line + ";\n}";

    // If no immediate mode script file set, create a dummy module for compiling the line
    asIScriptModule* module = 0;
    if (defaultScriptFile_)
        module = defaultScriptFile_->GetScriptModule();
    if (!module)
        module = scriptEngine_->GetModule("ExecuteImmediate", asGM_CREATE_IF_NOT_EXISTS);
    if (!module)
        return false;

    asIScriptFunction* function = 0;
    if (module->CompileFunction("", wrappedLine.CString(), -1, 0, &function) < 0)
        return false;

    if (immediateContext_->Prepare(function) < 0)
    {
        function->Release();
        return false;
    }

    bool success = immediateContext_->Execute() >= 0;
    immediateContext_->Unprepare();
    function->Release();

    return success;
}

void Script::SetDefaultScriptFile(ScriptFile* file)
{
    defaultScriptFile_ = file;
}

void Script::SetDefaultScene(Scene* scene)
{
    defaultScene_ = scene;
}

void Script::SetExecuteConsoleCommands(bool enable)
{
    if (enable == executeConsoleCommands_)
        return;

    executeConsoleCommands_ = enable;
    if (enable)
        SubscribeToEvent(E_CONSOLECOMMAND, CLOCKWORK_HANDLER(Script, HandleConsoleCommand));
    else
        UnsubscribeFromEvent(E_CONSOLECOMMAND);
}

void Script::MessageCallback(const asSMessageInfo* msg)
{
    String message;
    message.AppendWithFormat("%s:%d,%d %s", msg->section, msg->row, msg->col, msg->message);

    switch (msg->type)
    {
    case asMSGTYPE_ERROR:
        CLOCKWORK_LOGERROR(message);
        break;

    case asMSGTYPE_WARNING:
        CLOCKWORK_LOGWARNING(message);
        break;

    default:
        CLOCKWORK_LOGINFO(message);
        break;
    }
}

void Script::ExceptionCallback(asIScriptContext* context)
{
    String message;
    message.AppendWithFormat("- Exception '%s' in '%s'\n%s", context->GetExceptionString(),
        context->GetExceptionFunction()->GetDeclaration(), GetCallStack(context).CString());

    asSMessageInfo msg;
    msg.row = context->GetExceptionLineNumber(&msg.col, &msg.section);
    msg.type = asMSGTYPE_ERROR;
    msg.message = message.CString();

    MessageCallback(&msg);
}

String Script::GetCallStack(asIScriptContext* context)
{
    String str("AngelScript callstack:\n");

    // Append the call stack
    for (asUINT i = 0; i < context->GetCallstackSize(); i++)
    {
        asIScriptFunction* func;
        const char* scriptSection;
        int line, column;
        func = context->GetFunction(i);
        line = context->GetLineNumber(i, &column, &scriptSection);
        str.AppendWithFormat("\t%s:%s:%d,%d\n", scriptSection, func->GetDeclaration(), line, column);
    }

    return str;
}

ScriptFile* Script::GetDefaultScriptFile() const
{
    return defaultScriptFile_;
}

Scene* Script::GetDefaultScene() const
{
    return defaultScene_;
}

void Script::ClearObjectTypeCache()
{
    objectTypes_.Clear();
}

asIObjectType* Script::GetObjectType(const char* declaration)
{
    HashMap<const char*, asIObjectType*>::ConstIterator i = objectTypes_.Find(declaration);
    if (i != objectTypes_.End())
        return i->second_;

    asIObjectType* type = scriptEngine_->GetObjectTypeById(scriptEngine_->GetTypeIdByDecl(declaration));
    objectTypes_[declaration] = type;
    return type;
}

asIScriptContext* Script::GetScriptFileContext()
{
    while (scriptNestingLevel_ >= scriptFileContexts_.Size())
    {
        asIScriptContext* newContext = scriptEngine_->CreateContext();
        newContext->SetExceptionCallback(asMETHOD(Script, ExceptionCallback), this, asCALL_THISCALL);
        scriptFileContexts_.Push(newContext);
    }

    return scriptFileContexts_[scriptNestingLevel_];
}

void Script::HandleConsoleCommand(StringHash eventType, VariantMap& eventData)
{
    using namespace ConsoleCommand;
    if (eventData[P_ID].GetString() == GetTypeName())
        Execute(eventData[P_COMMAND].GetString());
}

void RegisterScriptLibrary(Context* context)
{
    ScriptFile::RegisterObject(context);
    ScriptInstance::RegisterObject(context);
}

}
