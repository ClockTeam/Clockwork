-- Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
-- See License.txt in the project root for license information.

function RecastNavigation_Project()
    group "Libs"
    project "RecastNavigation"
        targetname "RecastNavigation"
        kind "StaticLib"
        language "C++"
        prepareProject("RecastNavigation", "../lib")

        files {
            "../Source/ThirdParty/Detour/source/*.*", "../Source/ThirdParty/Detour/include/*.*",
            "../Source/ThirdParty/DetourCrowd/source/*.*", "../Source/ThirdParty/DetourCrowd/include/*.*",
            "../Source/ThirdParty/DetourTileCache/source/*.*", "../Source/ThirdParty/DetourTileCache/include/*.*",
            "../Source/ThirdParty/Recast/source/*.*", "../Source/ThirdParty/Recast/include/*.*"
        }

        includedirs {
            "../Source/ThirdParty/Detour/include/",
            "../Source/ThirdParty/DetourCrowd/include/",
            "../Source/ThirdParty/DetourTileCache/include/",
            "../Source/ThirdParty/Recast/include/"
        }

        vpaths {
            ["Detour"] = { "../Source/ThirdParty/Detour/source/**.cpp", "../Source/ThirdParty/Detour/include/**.h" },
            ["DetourCrowd"] = { "../Source/ThirdParty/DetourCrowd/source/**.cpp", "../Source/ThirdParty/DetourCrowd/include/**.h" },
            ["DetourTileCache"] = { "../Source/ThirdParty/DetourTileCache/source/**.cpp", "../Source/ThirdParty/DetourTileCache/include/**.h" },
            ["Recast"] = { "../Source/ThirdParty/Recast/source/**.cpp", "../Source/ThirdParty/Recast/include/**.h" }
        }

        configuration {}
        strip()        
end
