-- Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
-- See License.txt in the project root for license information.

function ClockworkPlayer_Project()
    project "ClockworkPlayer"
        targetname "ClockworkPlayer"
        kind "WindowedApp"
        language "C++"
        prepareProject("ClockworkPlayer", "../bin")

        defines {
            "URHO3D_ANGELSCRIPT",            
            "URHO3D_NAVIGATION",
            "URHO3D_NETWORK",
            "URHO3D_PHYSICS",
            "URHO3D_URHO2D",
            "URHO3D_FILEWATCHER",
            "URHO3D_PROFILING",
            "URHO3D_LOGGING",
            "URHO3D_THREADING",
            "URHO3D_D3D11"
        }

        files { "../Source/Tools/ClockworkPlayer/*.*" }

        includedirs { "../Source/" }

        links { "Clockwork" }

        if isWindowsDesktop() then
            links { "Winmm", "D3D11", "DXGI", "dxguid", "D3dcompiler", "Version", "Imm32", "Ws2_32" }            
        end        

        vpaths { ["*"] = "../Source/Tools/ClockworkPlayer" }

        configuration {}
        strip()        
end
