-- Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
-- See License.txt in the project root for license information.

function JO_Project()
    group "Libs"
    project "JO"
        targetname "JO"
        kind "StaticLib"
        language "C++"
        prepareProject("JO", "../lib")

        files { "../Source/ThirdParty/JO/*.*" }

        vpaths { ["*"] = "../Source/ThirdParty/JO/" }

        configuration {}
        strip()    
end
