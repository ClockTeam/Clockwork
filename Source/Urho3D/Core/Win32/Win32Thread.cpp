// Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
// See License.txt in the project root for license information.

#include "../../Precompiled.h"
#include "Win32Thread.h"

#include <Windows.h>

namespace Urho3D
{

DWORD WINAPI ThreadFunctionStatic(void* data)
{
    Thread* thread = static_cast<Thread*>(data);
    thread->ThreadFunction();
    return 0;
}

ThreadID Thread::mainThreadID;

Thread::Thread() :
    handle_(NULL),
    shouldRun_(false)
{
}

Thread::~Thread()
{
    Stop();
}

bool Thread::Run()
{
    if (handle_)
        return false;

    shouldRun_ = true;
    handle_ = CreateThread(NULL, 0, ThreadFunctionStatic, this, 0, NULL);

    return handle_ != NULL;
}

void Thread::Stop()
{
    if (!handle_)
        return;

    shouldRun_ = false;

    WaitForSingleObject((HANDLE)handle_, INFINITE);
    CloseHandle((HANDLE)handle_);

    handle_ = NULL;
}

void Thread::SetPriority(int priority)
{
    if (handle_)
        SetThreadPriority((HANDLE)handle_, priority);
}

void Thread::SetMainThread()
{
    mainThreadID = GetCurrentThreadID();
}

ThreadID Thread::GetCurrentThreadID()
{
    return GetCurrentThreadId();
}

bool Thread::IsMainThread()
{
    return GetCurrentThreadID() == mainThreadID;
}

}
