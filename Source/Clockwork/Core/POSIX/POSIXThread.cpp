// Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
// See License.txt in the project root for license information.

#include "../Thread.h"

#include <pthread.h>

#include "../../DebugNew.h"

namespace Urho3D
{

void* ThreadFunctionStatic(void* data)
{
    Thread* thread = static_cast<Thread*>(data);
    thread->ThreadFunction();
    pthread_exit((void*)NULL);
    return NULL;
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

    handle_ = new pthread_t;
    pthread_attr_t type;
    pthread_attr_init(&type);
    pthread_attr_setdetachstate(&type, PTHREAD_CREATE_JOINABLE);
    pthread_create((pthread_t*)handle_, &type, ThreadFunctionStatic, this);

    return handle_ != NULL;
}

void Thread::Stop()
{
    if (!handle_)
        return;

    shouldRun_ = false;

    pthread_t* thread = (pthread_t*)handle_;
    if (thread)
        pthread_join(*thread, NULL);
    delete thread;

    handle_ = NULL;
}

void Thread::SetPriority(int priority)
{
#if defined(CW_PLATFORM_LINUX)
    pthread_t* thread = (pthread_t*)handle_;
    if (thread)
        pthread_setschedprio(*thread, priority);
#endif
}

void Thread::SetMainThread()
{
    mainThreadID = GetCurrentThreadID();
}

ThreadID Thread::GetCurrentThreadID()
{
    return pthread_self();
}

bool Thread::IsMainThread()
{
    return GetCurrentThreadID() == mainThreadID;
}

}
