-- Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
-- See License.txt in the project root for license information.

function LZ4_Project()
    group "Libs"
    project "LZ4"
        targetname "LZ4"
        kind "StaticLib"
        language "C++"
        prepareProject("LZ4", "../lib")

        files { "../Source/ThirdParty/LZ4/*.c", "../Source/ThirdParty/LZ4/*.h" }

        vpaths { ["*"] = "../Source/ThirdParty/LZ4/" }

        configuration {}
        strip()        
end
