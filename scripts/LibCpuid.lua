-- Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
-- See License.txt in the project root for license information.

function LibCpuid_Project()
    group "Libs"
    project "LibCpuid"
        targetname "LibCpuid"
        kind "StaticLib"
        language "C++"
        prepareProject("LibCpuid", "../lib")

        files { "../Source/ThirdParty/LibCpuid/src/*.c", "../Source/ThirdParty/LibCpuid/src/*.h" }

        vpaths { ["*"] = "../Source/ThirdParty/LibCpuid/src/" }

        configuration {}
        strip()        
end
