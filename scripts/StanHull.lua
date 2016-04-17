-- Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
-- See License.txt in the project root for license information.

function StanHull_Project()
    group "Libs"
    project "StanHull"
        targetname "StanHull"
        kind "StaticLib"
        language "C++"
        prepareProject("StanHull", "../lib")

        files { "../Source/ThirdParty/StanHull/Hull.cpp", "../Source/ThirdParty/StanHull/Hull.h" }

        vpaths { ["*"] = "../Source/ThirdParty/StanHull/" }

        configuration {}
        strip()        
end
