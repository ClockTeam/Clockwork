// Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
// See License.txt in the project root for license information.

#include "../Thread.h"

#include <Windows.h>

#include "../../DebugNew.h"

namespace Urho3D
{

Mutex::Mutex() :
    handle_(new CRITICAL_SECTION)
{
    InitializeCriticalSectionEx((CRITICAL_SECTION*)handle_, 2000, 0);
}

Mutex::~Mutex()
{
    CRITICAL_SECTION* cs = (CRITICAL_SECTION*)handle_;
    DeleteCriticalSection(cs);
    delete cs;
    handle_ = NULL;
}

void Mutex::Acquire()
{
    EnterCriticalSection((CRITICAL_SECTION*)handle_);
}

bool Mutex::TryAcquire()
{
    return TryEnterCriticalSection((CRITICAL_SECTION*)handle_) != FALSE;
}

void Mutex::Release()
{
    LeaveCriticalSection((CRITICAL_SECTION*)handle_);
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
