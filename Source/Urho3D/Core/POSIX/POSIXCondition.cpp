// Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
// See License.txt in the project root for license information.

#include "../../Precompiled.h"
#include "POSIXCondition.h"

#include <pthread.h>

#include "../../DebugNew.h"

namespace Urho3D
{

Condition::Condition() :
    mutex_(new pthread_mutex_t),
    event_(new pthread_cond_t)
{
    pthread_mutex_init((pthread_mutex_t*)mutex_, NULL);
    pthread_cond_init((pthread_cond_t*)event_, NULL);
}

Condition::~Condition()
{
    pthread_cond_t* cond = (pthread_cond_t*)event_;
    pthread_mutex_t* mutex = (pthread_mutex_t*)mutex_;

    pthread_cond_destroy(cond);
    pthread_mutex_destroy(mutex);
    delete cond;
    delete mutex;
    event_ = NULL;
    mutex_ = NULL;
}

void Condition::Set()
{
    pthread_cond_signal((pthread_cond_t*)event_);
}

void Condition::Wait()
{
    pthread_cond_t* cond = (pthread_cond_t*)event_;
    pthread_mutex_t* mutex = (pthread_mutex_t*)mutex_;

    pthread_mutex_lock(mutex);
    pthread_cond_wait(cond, mutex);
    pthread_mutex_unlock(mutex);
}

}
