// Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
// See License.txt in the project root for license information.

#include "../../Precompiled.h"
#include "POSIXMutex.h"

#include <pthread.h>

#include "../../DebugNew.h"

namespace Urho3D
{

Mutex::Mutex() :
    handle_(new pthread_mutex_t)
{
    pthread_mutex_t* mutex = (pthread_mutex_t*)handle_;
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(mutex, &attr);
}

Mutex::~Mutex()
{
    pthread_mutex_t* mutex = (pthread_mutex_t*)handle_;
    pthread_mutex_destroy(mutex);
    delete mutex;
    handle_ = NULL;
}

void Mutex::Acquire()
{
    pthread_mutex_lock((pthread_mutex_t*)handle_);
}

bool Mutex::TryAcquire()
{
    return pthread_mutex_trylock((pthread_mutex_t*)handle_) == 0;
}

void Mutex::Release()
{
    pthread_mutex_unlock((pthread_mutex_t*)handle_);
}

MutexLock::MutexLock(Mutex& mutex) :
    mutex_(mutex)
{
    mutex_.Acquire();
}

MutexLock::~MutexLock()
{
    mutex_.Release();
}

}
