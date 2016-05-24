//
// Copyright (c) 2008-2016 the Urho3D project.
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

#pragma once

#include "../Core/Object.h"

namespace Urho3D
{

/// Variable timestep scene update.
CLOCKWORK_EVENT(E_SCENEUPDATE, SceneUpdate)
{
    CLOCKWORK_PARAM(P_SCENE, Scene);                  // Scene pointer
    CLOCKWORK_PARAM(P_TIMESTEP, TimeStep);            // float
}

/// Scene subsystem update.
CLOCKWORK_EVENT(E_SCENESUBSYSTEMUPDATE, SceneSubsystemUpdate)
{
    CLOCKWORK_PARAM(P_SCENE, Scene);                  // Scene pointer
    CLOCKWORK_PARAM(P_TIMESTEP, TimeStep);            // float
}

/// Scene transform smoothing update.
CLOCKWORK_EVENT(E_UPDATESMOOTHING, UpdateSmoothing)
{
    CLOCKWORK_PARAM(P_CONSTANT, Constant);            // float
    CLOCKWORK_PARAM(P_SQUAREDSNAPTHRESHOLD, SquaredSnapThreshold);  // float
}

/// Scene drawable update finished. Custom animation (eg. IK) can be done at this point.
CLOCKWORK_EVENT(E_SCENEDRAWABLEUPDATEFINISHED, SceneDrawableUpdateFinished)
{
    CLOCKWORK_PARAM(P_SCENE, Scene);                  // Scene pointer
    CLOCKWORK_PARAM(P_TIMESTEP, TimeStep);            // float
}

/// SmoothedTransform target position changed.
CLOCKWORK_EVENT(E_TARGETPOSITION, TargetPositionChanged)
{
}

/// SmoothedTransform target position changed.
CLOCKWORK_EVENT(E_TARGETROTATION, TargetRotationChanged)
{
}

/// Scene attribute animation update.
CLOCKWORK_EVENT(E_ATTRIBUTEANIMATIONUPDATE, AttributeAnimationUpdate)
{
    CLOCKWORK_PARAM(P_SCENE, Scene);                  // Scene pointer
    CLOCKWORK_PARAM(P_TIMESTEP, TimeStep);            // float
}

/// Attribute animation added to object animation.
CLOCKWORK_EVENT(E_ATTRIBUTEANIMATIONADDED, AttributeAnimationAdded)
{
    CLOCKWORK_PARAM(P_OBJECTANIMATION, ObjectAnimation);               // Object animation pointer
    CLOCKWORK_PARAM(P_ATTRIBUTEANIMATIONNAME, AttributeAnimationName); // String
}

/// Attribute animation removed from object animation.
CLOCKWORK_EVENT(E_ATTRIBUTEANIMATIONREMOVED, AttributeAnimationRemoved)
{
    CLOCKWORK_PARAM(P_OBJECTANIMATION, ObjectAnimation);               // Object animation pointer
    CLOCKWORK_PARAM(P_ATTRIBUTEANIMATIONNAME, AttributeAnimationName); // String
}

/// Variable timestep scene post-update.
CLOCKWORK_EVENT(E_SCENEPOSTUPDATE, ScenePostUpdate)
{
    CLOCKWORK_PARAM(P_SCENE, Scene);                  // Scene pointer
    CLOCKWORK_PARAM(P_TIMESTEP, TimeStep);            // float
}

/// Asynchronous scene loading progress.
CLOCKWORK_EVENT(E_ASYNCLOADPROGRESS, AsyncLoadProgress)
{
    CLOCKWORK_PARAM(P_SCENE, Scene);                  // Scene pointer
    CLOCKWORK_PARAM(P_PROGRESS, Progress);            // float
    CLOCKWORK_PARAM(P_LOADEDNODES, LoadedNodes);      // int
    CLOCKWORK_PARAM(P_TOTALNODES, TotalNodes);        // int
    CLOCKWORK_PARAM(P_LOADEDRESOURCES, LoadedResources); // int
    CLOCKWORK_PARAM(P_TOTALRESOURCES, TotalResources);   // int
};

/// Asynchronous scene loading finished.
CLOCKWORK_EVENT(E_ASYNCLOADFINISHED, AsyncLoadFinished)
{
    CLOCKWORK_PARAM(P_SCENE, Scene);                  // Scene pointer
};

/// A child node has been added to a parent node.
CLOCKWORK_EVENT(E_NODEADDED, NodeAdded)
{
    CLOCKWORK_PARAM(P_SCENE, Scene);                  // Scene pointer
    CLOCKWORK_PARAM(P_PARENT, Parent);                // Node pointer
    CLOCKWORK_PARAM(P_NODE, Node);                    // Node pointer
}

/// A child node is about to be removed from a parent node.
CLOCKWORK_EVENT(E_NODEREMOVED, NodeRemoved)
{
    CLOCKWORK_PARAM(P_SCENE, Scene);                  // Scene pointer
    CLOCKWORK_PARAM(P_PARENT, Parent);                // Node pointer
    CLOCKWORK_PARAM(P_NODE, Node);                    // Node pointer
}

/// A component has been created to a node.
CLOCKWORK_EVENT(E_COMPONENTADDED, ComponentAdded)
{
    CLOCKWORK_PARAM(P_SCENE, Scene);                  // Scene pointer
    CLOCKWORK_PARAM(P_NODE, Node);                    // Node pointer
    CLOCKWORK_PARAM(P_COMPONENT, Component);          // Component pointer
}

/// A component is about to be removed from a node.
CLOCKWORK_EVENT(E_COMPONENTREMOVED, ComponentRemoved)
{
    CLOCKWORK_PARAM(P_SCENE, Scene);                  // Scene pointer
    CLOCKWORK_PARAM(P_NODE, Node);                    // Node pointer
    CLOCKWORK_PARAM(P_COMPONENT, Component);          // Component pointer
}

/// A node's name has changed.
CLOCKWORK_EVENT(E_NODENAMECHANGED, NodeNameChanged)
{
    CLOCKWORK_PARAM(P_SCENE, Scene);                  // Scene pointer
    CLOCKWORK_PARAM(P_NODE, Node);                    // Node pointer
}

/// A node's enabled state has changed.
CLOCKWORK_EVENT(E_NODEENABLEDCHANGED, NodeEnabledChanged)
{
    CLOCKWORK_PARAM(P_SCENE, Scene);                  // Scene pointer
    CLOCKWORK_PARAM(P_NODE, Node);                    // Node pointer
}

/// A node's tag has been added.
CLOCKWORK_EVENT(E_NODETAGADDED, NodeTagAdded)
{
    CLOCKWORK_PARAM(P_SCENE, Scene);                  // Scene pointer
    CLOCKWORK_PARAM(P_NODE, Node);                    // Node pointer
    CLOCKWORK_PARAM(P_TAG, Tag);                      // String tag
}

/// A node's tag has been removed.
CLOCKWORK_EVENT(E_NODETAGREMOVED, NodeTagRemoved)
{
    CLOCKWORK_PARAM(P_SCENE, Scene);                  // Scene pointer
    CLOCKWORK_PARAM(P_NODE, Node);                    // Node pointer
    CLOCKWORK_PARAM(P_TAG, Tag);                      // String tag
}

/// A component's enabled state has changed.
CLOCKWORK_EVENT(E_COMPONENTENABLEDCHANGED, ComponentEnabledChanged)
{
    CLOCKWORK_PARAM(P_SCENE, Scene);                  // Scene pointer
    CLOCKWORK_PARAM(P_NODE, Node);                    // Node pointer
    CLOCKWORK_PARAM(P_COMPONENT, Component);          // Component pointer
}

/// A serializable's temporary state has changed.
CLOCKWORK_EVENT(E_TEMPORARYCHANGED, TemporaryChanged)
{
    CLOCKWORK_PARAM(P_SERIALIZABLE, Serializable);    // Serializable pointer
}

/// A network attribute update from the server has been intercepted.
CLOCKWORK_EVENT(E_INTERCEPTNETWORKUPDATE, InterceptNetworkUpdate)
{
    CLOCKWORK_PARAM(P_SERIALIZABLE, Serializable);    // Serializable pointer
    CLOCKWORK_PARAM(P_TIMESTAMP, TimeStamp);          // unsigned (0-255)
    CLOCKWORK_PARAM(P_INDEX, Index);                  // unsigned
    CLOCKWORK_PARAM(P_NAME, Name);                    // String
    CLOCKWORK_PARAM(P_VALUE, Value);                  // Variant
}

}
