//
// Copyright (c) 2008-2016 the Clockwork project.
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

namespace Clockwork
{

/// AnimatedModel bone hierarchy created.
CLOCKWORK_EVENT(E_BONEHIERARCHYCREATED, BoneHierarchyCreated)
{
    CLOCKWORK_PARAM(P_NODE, Node);                    // Node pointer
}

/// AnimatedModel animation trigger.
CLOCKWORK_EVENT(E_ANIMATIONTRIGGER, AnimationTrigger)
{
    CLOCKWORK_PARAM(P_NODE, Node);                    // Node pointer
    CLOCKWORK_PARAM(P_ANIMATION, Animation);          // Animation pointer
    CLOCKWORK_PARAM(P_NAME, Name);                    // String
    CLOCKWORK_PARAM(P_TIME, Time);                    // Float
    CLOCKWORK_PARAM(P_DATA, Data);                    // User-defined data type
}

/// AnimatedModel animation finished or looped.
CLOCKWORK_EVENT(E_ANIMATIONFINISHED, AnimationFinished)
{
    CLOCKWORK_PARAM(P_NODE, Node);                    // Node pointer
    CLOCKWORK_PARAM(P_ANIMATION, Animation);          // Animation pointer
    CLOCKWORK_PARAM(P_NAME, Name);                    // String
    CLOCKWORK_PARAM(P_LOOPED, Looped);                // Bool
}

/// Particle effect finished.
CLOCKWORK_EVENT(E_PARTICLEEFFECTFINISHED, ParticleEffectFinished)
{
    CLOCKWORK_PARAM(P_NODE, Node);                    // Node pointer
    CLOCKWORK_PARAM(P_EFFECT, Effect);                // ParticleEffect pointer
}

/// Terrain geometry created.
CLOCKWORK_EVENT(E_TERRAINCREATED, TerrainCreated)
{
    CLOCKWORK_PARAM(P_NODE, Node);                    // Node pointer
}

}
