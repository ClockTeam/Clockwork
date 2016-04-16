-- Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
-- See License.txt in the project root for license information.

function PugiXml_Project()
    group "Libs"
    project "PugiXml"
        targetname "PugiXml"
        kind "StaticLib"
        language "C++"
        prepareProject("PugiXml", "../lib")

        files { "../Source/ThirdParty/PugiXml/src/*.*" }

        vpaths { ["*"] = "../Source/ThirdParty/PugiXml/src/" }
end
