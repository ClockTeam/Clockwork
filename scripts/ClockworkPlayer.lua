-- Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
-- See License.txt in the project root for license information.

function ClockworkPlayer_Project()
    project "ClockworkPlayer"
        targetname "ClockworkPlayer"
        kind "WindowedApp"
        language "C++"
        prepareProject("ClockworkPlayer", "../bin")

        files { "../Source/Tools/ClockworkPlayer/*.*" }

        includedirs { "../Source/" }

        links { "Clockwork" }

        if isWindowsDesktop() then
            links {"Winmm", "D3D11", "DXGI", "dxguid", "D3dcompiler", "Version", "Imm32"}            
        end        

        vpaths { ["*"] = "../Source/Tools/ClockworkPlayer" }
end
