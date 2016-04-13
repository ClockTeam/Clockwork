// Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
// See License.txt in the project root for license information.

#pragma once

namespace Urho3D
{

/// Operating system mutual exclusion primitive.
class URHO3D_API Mutex
{
public:
    /// Construct.
    Mutex();
    /// Destruct.
    ~Mutex();

    /// Acquire the mutex. Block if already acquired.
    void Acquire();
    /// Try to acquire the mutex without locking. Return true if successful.
    bool TryAcquire();
    /// Release the mutex.
    void Release();

private:
    /// Mutex handle.
    void* handle_;
};

/// Lock that automatically acquires and releases a mutex.
class URHO3D_API MutexLock
{
public:
    /// Construct and acquire the mutex.
    MutexLock(Mutex& mutex);
    /// Destruct. Release the mutex.
    ~MutexLock();

private:
    /// Prevent copy construction.
    MutexLock(const MutexLock& rhs);
    /// Prevent assignment.
    MutexLock& operator =(const MutexLock& rhs);

    /// Mutex reference.
    Mutex& mutex_;
};

}
