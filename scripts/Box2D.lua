-- Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
-- See License.txt in the project root for license information.

function Box2D_Project()
    group "Libs"
    project "Box2D"
        targetname "Box2D"
        kind "StaticLib"
        language "C++"
        prepareProject("Box2D", "../lib")

        files {
            "../Source/ThirdParty/Box2D/Box2D/*.*",
            "../Source/ThirdParty/Box2D/Box2D/Collision/*.*",
            "../Source/ThirdParty/Box2D/Box2D/Collision/Shapes/*.*",
            "../Source/ThirdParty/Box2D/Box2D/Common/*.*",
            "../Source/ThirdParty/Box2D/Box2D/Dynamics/*.*",
            "../Source/ThirdParty/Box2D/Box2D/Dynamics/Contacts/*.*",
            "../Source/ThirdParty/Box2D/Box2D/Dynamics/Joints/*.*",
            "../Source/ThirdParty/Box2D/Box2D/Rope/*.*"
        }
        
        includedirs { "../Source/ThirdParty/Box2D/" }

        vpaths { ["*"] = "../Source/ThirdParty/Box2D/Box2D/" }

        configuration {}
        strip()
end
