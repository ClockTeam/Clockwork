-- Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
-- See License.txt in the project root for license information.

function Clockwork_Project()
    project "Clockwork"
        targetname "Clockwork"
        kind "StaticLib"
        language "C++"
        prepareProject("Clockwork", "../lib")

        files {
            "../Source/Clockwork/*.*",
            --"../Source/Clockwork/AngelScript/*.*",
            "../Source/Clockwork/Audio/*.*",
            "../Source/Clockwork/Container/*.*",
            "../Source/Clockwork/Core/*.*",
            --"../Source/Clockwork/Database/*.*",
            --"../Source/Clockwork/Database/ODBC/*.*",
            --"../Source/Clockwork/Database/SQLite/*.*",
            "../Source/Clockwork/Engine/*.*",
            "../Source/Clockwork/Graphics/*.*",
            --"../Source/Clockwork/Graphics/OpenGL/*.*",
            "../Source/Clockwork/Input/*.*",
            "../Source/Clockwork/IO/*.*",            
            "../Source/Clockwork/Math/*.*",
            "../Source/Clockwork/Navigation/*.*",
            "../Source/Clockwork/Network/*.*",
            "../Source/Clockwork/Physics/*.*",
            "../Source/Clockwork/Resource/*.*",
            "../Source/Clockwork/Scene/*.*",
            "../Source/Clockwork/UI/*.*",
            "../Source/Clockwork/Urho2D/*.*"
        }

        if isWindows() then
            files {
                "../Source/Clockwork/Graphics/Direct3D11/*.*",
                "../Source/Clockwork/Core/Win32/*.*",         
            }            
        end

        includedirs {
            "../Source/Clockwork/",
            "../Source/ThirdParty/AngelScript/include/",
            "../Source/ThirdParty/Box2D/",
            "../Source/ThirdParty/Bullet/src/",
            "../Source/ThirdParty/Detour/include/",
            "../Source/ThirdParty/Civetweb/include/",
            "../Source/ThirdParty/DetourCrowd/include/",
            "../Source/ThirdParty/DetourTileCache/include/",
            "../Source/ThirdParty/FreeType/include/",
            "../Source/ThirdParty/GLEW/",
            "../Source/ThirdParty/JO/",
            "../Source/ThirdParty/kNet/include/",
            "../Source/ThirdParty/LibCpuid/src/",
            "../Source/ThirdParty/LZ4/",
            "../Source/ThirdParty/nanodbc/src/",
            "../Source/ThirdParty/PugiXml/src/",
            "../Source/ThirdParty/rapidjson/include/",
            "../Source/ThirdParty/Recast/include/",
            "../Source/ThirdParty/SDL/include/",
            "../Source/ThirdParty/StanHull/",
            "../Source/ThirdParty/STB/"
        }

        links { "Bullet", "FreeType", "JO", "LZ4", "PugiXml", "RecastNavigation", "StanHull", "SDL" }

        vpaths { ["*"] = "../Source/Clockwork/" }       
end
