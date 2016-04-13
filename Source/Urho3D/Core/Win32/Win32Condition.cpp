// Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
// See License.txt in the project root for license information.

#include "../../Precompiled.h"
#include "Win32Condition.h"

#include <Windows.h>

namespace Urho3D
{

Condition::Condition() :
    event_(NULL)
{
    event_ = CreateEvent(NULL, FALSE, FALSE, NULL);
}

Condition::~Condition()
{
    CloseHandle((HANDLE)event_);
    event_ = NULL;
}

void Condition::Set()
{
    SetEvent((HANDLE)event_);
}

void Condition::Wait()
{
    WaitForSingleObject((HANDLE)event_, INFINITE);
}

}
