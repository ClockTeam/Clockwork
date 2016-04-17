-- Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
-- See License.txt in the project root for license information.

function nanodbc_Project()
    group "Libs"
    project "nanodbc"
        targetname "nanodbc"
        kind "StaticLib"
        language "C++"
        prepareProject("nanodbc", "../lib")

        files { "../Source/ThirdParty/nanodbc/src/*.*" }

        vpaths { ["*"] = "../Source/ThirdParty/nanodbc/src/" }
end
