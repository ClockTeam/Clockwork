-- Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
-- See License.txt in the project root for license information.

function Civetweb_Project()
    group "Libs"
    project "Civetweb"
        targetname "Civetweb"
        kind "StaticLib"
        language "C++"
        prepareProject("Civetweb", "../lib")

        files { 
            "../Source/ThirdParty/Civetweb/src/*.*",
            "../Source/ThirdParty/Civetweb/include/*.*"
        }

        includedirs { "../Source/ThirdParty/Civetweb/include" }

        vpaths { ["*"] = { "../Source/ThirdParty/Civetweb/src", "../Source/ThirdParty/Civetweb/include" } }

        configuration {}
        strip()        
end
