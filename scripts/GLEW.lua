-- Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
-- See License.txt in the project root for license information.

function GLEW_Project()
    group "Libs"
    project "GLEW"
        targetname "GLEW"
        kind "StaticLib"
        language "C++"
        prepareProject("GLEW", "../lib")

        defines { "GLEW_STATIC" }

        files { "../Source/ThirdParty/GLEW/*.c", "../Source/ThirdParty/GLEW/*.h" }

        includedirs { "../Source/ThirdParty/GLEW/" }

        vpaths { ["*"] = "../Source/ThirdParty/GLEW/" }
        
        configuration {}
        strip()        
end
