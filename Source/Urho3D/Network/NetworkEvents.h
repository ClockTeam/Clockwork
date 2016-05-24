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

/// Server connection established.
CLOCKWORK_EVENT(E_SERVERCONNECTED, ServerConnected)
{
}

/// Server connection disconnected.
CLOCKWORK_EVENT(E_SERVERDISCONNECTED, ServerDisconnected)
{
}

/// Server connection failed.
CLOCKWORK_EVENT(E_CONNECTFAILED, ConnectFailed)
{
}

/// New client connection established.
CLOCKWORK_EVENT(E_CLIENTCONNECTED, ClientConnected)
{
    CLOCKWORK_PARAM(P_CONNECTION, Connection);        // Connection pointer
}

/// Client connection disconnected.
CLOCKWORK_EVENT(E_CLIENTDISCONNECTED, ClientDisconnected)
{
    CLOCKWORK_PARAM(P_CONNECTION, Connection);        // Connection pointer
}

/// Client has sent identity: identity map is in the event data.
CLOCKWORK_EVENT(E_CLIENTIDENTITY, ClientIdentity)
{
    CLOCKWORK_PARAM(P_CONNECTION, Connection);        // Connection pointer
    CLOCKWORK_PARAM(P_ALLOW, Allow);                  // bool
}

/// Client has informed to have loaded the scene.
CLOCKWORK_EVENT(E_CLIENTSCENELOADED, ClientSceneLoaded)
{
    CLOCKWORK_PARAM(P_CONNECTION, Connection);        // Connection pointer
}

/// Unhandled network message received.
CLOCKWORK_EVENT(E_NETWORKMESSAGE, NetworkMessage)
{
    CLOCKWORK_PARAM(P_CONNECTION, Connection);        // Connection pointer
    CLOCKWORK_PARAM(P_MESSAGEID, MessageID);          // int
    CLOCKWORK_PARAM(P_DATA, Data);                    // Buffer
}

/// About to send network update on the client or server.
CLOCKWORK_EVENT(E_NETWORKUPDATE, NetworkUpdate)
{
}

/// Network update has been sent on the client or server.
CLOCKWORK_EVENT(E_NETWORKUPDATESENT, NetworkUpdateSent)
{
}

/// Scene load failed, either due to file not found or checksum error.
CLOCKWORK_EVENT(E_NETWORKSCENELOADFAILED, NetworkSceneLoadFailed)
{
    CLOCKWORK_PARAM(P_CONNECTION, Connection);      // Connection pointer
}

/// Remote event: adds Connection parameter to the event data
CLOCKWORK_EVENT(E_REMOTEEVENTDATA, RemoteEventData)
{
    CLOCKWORK_PARAM(P_CONNECTION, Connection);      // Connection pointer
}

}
