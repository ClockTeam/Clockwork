// Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
// See License.txt in the project root for license information.

#pragma once

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
    /// Mutex for the event, necessary for pthreads-based implementation.
    void* mutex_;
    /// Operating system specific event.
    void* event_;
};

}
