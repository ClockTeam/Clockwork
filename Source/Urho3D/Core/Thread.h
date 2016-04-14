// Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
// See License.txt in the project root for license information.

#pragma once

#include "../Config.h"

#if defined(CW_PLATFORM_WIN32) || defined(CW_PLATFORM_WINRT)
typedef unsigned ThreadID;
#elif defined(CW_PLATFORM_ANDROID) || defined(CW_PLATFORM_IOS) || defined(CW_PLATFORM_MACOSX) || defined(CW_PLATFORM_LINUX)
#include <pthread.h>
typedef pthread_t ThreadID;
#endif

namespace Urho3D
{

/// Condition on which a thread can wait.
class URHO3D_API Condition
{
public:
    /// Construct.
    Condition();
    /// Destruct.
    ~Condition();

    /// Set the condition. Will be automatically reset once a waiting thread wakes up.
    void Set();
    /// Wait on the condition.
    void Wait();

private:
#if defined(CW_PLATFORM_ANDROID) || defined(CW_PLATFORM_IOS) || defined(CW_PLATFORM_MACOSX) || defined(CW_PLATFORM_LINUX)
    /// Mutex for the event, necessary for pthreads-based implementation.
    void* mutex_;
#endif
    /// Operating system specific event.
    void* event_;
};

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

/// Operating system thread.
class URHO3D_API Thread
{
public:
    /// Construct. Does not start the thread yet.
    Thread();
    /// Destruct. If running, stop and wait for thread to finish.
    virtual ~Thread();

    /// The function to run in the thread.
    virtual void ThreadFunction() = 0;

    /// Start running the thread. Return true if successful, or false if already running or if can not create the thread.
    bool Run();
    /// Set the running flag to false and wait for the thread to finish.
    void Stop();
    /// Set thread priority. The thread must have been started first.
    void SetPriority(int priority);

    /// Return whether thread exists.
    bool IsStarted() const { return handle_ != NULL; }

    /// Set the current thread as the main thread.
    static void SetMainThread();
    /// Return the current thread's ID.
    static ThreadID GetCurrentThreadID();
    /// Return whether is executing in the main thread.
    static bool IsMainThread();

protected:
    /// Thread handle.
    void* handle_;
    /// Running flag.
    volatile bool shouldRun_;

    /// Main thread's thread ID.
    static ThreadID mainThreadID;
};

}
