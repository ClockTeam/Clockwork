-- Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
-- See License.txt in the project root for license information.

function kNet_Project()
    group "Libs"
    project "kNet"
        targetname "kNet"
        kind "StaticLib"
        language "C++"
        prepareProject("kNet", "../lib")

        files {
            "../Source/ThirdParty/kNet/src/*.*",
            "../Source/ThirdParty/kNet/include/*.*",
            "../Source/ThirdParty/kNet/include/kNet/*.*",
        }

        if isWindows() or isDurango() then
            files {
                "../Source/ThirdParty/kNet/src/win32/*.*",
                "../Source/ThirdParty/kNet/include/kNet/win32/*.*",
            }

            defines {
                "_WINSOCKAPI_",
                "KNET_MEMORY_LEAK_CHECK"
            }
        else
            files { "../Source/ThirdParty/kNet/src/unix/*.*" }
        end

        includedirs { "../Source/ThirdParty/kNet/include/" }

        vpaths { ["*"] = "../Source/ThirdParty/kNet" }

        configuration {}
        strip()        
end
