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

/// New screen mode set.
CLOCKWORK_EVENT(E_SCREENMODE, ScreenMode)
{
    CLOCKWORK_PARAM(P_WIDTH, Width);                  // int
    CLOCKWORK_PARAM(P_HEIGHT, Height);                // int
    CLOCKWORK_PARAM(P_FULLSCREEN, Fullscreen);        // bool
    CLOCKWORK_PARAM(P_BORDERLESS, Borderless);        // bool
    CLOCKWORK_PARAM(P_RESIZABLE, Resizable);          // bool
    CLOCKWORK_PARAM(P_HIGHDPI, HighDPI);              // bool
}

/// Window position changed.
CLOCKWORK_EVENT(E_WINDOWPOS, WindowPos)
{
    CLOCKWORK_PARAM(P_X, X);                          // int
    CLOCKWORK_PARAM(P_Y, Y);                          // int
}

/// Request for queuing rendersurfaces either in manual or always-update mode.
CLOCKWORK_EVENT(E_RENDERSURFACEUPDATE, RenderSurfaceUpdate)
{
}

/// Frame rendering started.
CLOCKWORK_EVENT(E_BEGINRENDERING, BeginRendering)
{
}

/// Frame rendering ended.
CLOCKWORK_EVENT(E_ENDRENDERING, EndRendering)
{
}

/// Update of a view started.
CLOCKWORK_EVENT(E_BEGINVIEWUPDATE, BeginViewUpdate)
{
    CLOCKWORK_PARAM(P_VIEW, View);                    // View pointer
    CLOCKWORK_PARAM(P_TEXTURE, Texture);              // Texture pointer
    CLOCKWORK_PARAM(P_SURFACE, Surface);              // RenderSurface pointer
    CLOCKWORK_PARAM(P_SCENE, Scene);                  // Scene pointer
    CLOCKWORK_PARAM(P_CAMERA, Camera);                // Camera pointer
}

/// Update of a view ended.
CLOCKWORK_EVENT(E_ENDVIEWUPDATE, EndViewUpdate)
{
    CLOCKWORK_PARAM(P_VIEW, View);                    // View pointer
    CLOCKWORK_PARAM(P_TEXTURE, Texture);              // Texture pointer
    CLOCKWORK_PARAM(P_SURFACE, Surface);              // RenderSurface pointer
    CLOCKWORK_PARAM(P_SCENE, Scene);                  // Scene pointer
    CLOCKWORK_PARAM(P_CAMERA, Camera);                // Camera pointer
}

/// Render of a view started.
CLOCKWORK_EVENT(E_BEGINVIEWRENDER, BeginViewRender)
{
    CLOCKWORK_PARAM(P_VIEW, View);                    // View pointer
    CLOCKWORK_PARAM(P_TEXTURE, Texture);              // Texture pointer
    CLOCKWORK_PARAM(P_SURFACE, Surface);              // RenderSurface pointer
    CLOCKWORK_PARAM(P_SCENE, Scene);                  // Scene pointer
    CLOCKWORK_PARAM(P_CAMERA, Camera);                // Camera pointer
}

/// Render of a view ended.
CLOCKWORK_EVENT(E_ENDVIEWRENDER, EndViewRender)
{
    CLOCKWORK_PARAM(P_VIEW, View);                    // View pointer
    CLOCKWORK_PARAM(P_TEXTURE, Texture);              // Texture pointer
    CLOCKWORK_PARAM(P_SURFACE, Surface);              // RenderSurface pointer
    CLOCKWORK_PARAM(P_SCENE, Scene);                  // Scene pointer
    CLOCKWORK_PARAM(P_CAMERA, Camera);                // Camera pointer
}

/// Graphics context has been lost. Some or all (depending on the API) GPU objects have lost their contents.
CLOCKWORK_EVENT(E_DEVICELOST, DeviceLost)
{
}

/// Graphics context has been recreated after being lost. GPU objects in the "data lost" state can be restored now.
CLOCKWORK_EVENT(E_DEVICERESET, DeviceReset)
{
}

}
