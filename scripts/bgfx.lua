-- Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
-- See License.txt in the project root for license information.

function bgfx_Project()
    group "Libs"
    project "bgfx"
        targetname "bgfx"
        kind "StaticLib"
        language "C++"
        prepareProject("bgfx", "../lib")

        files { 
            "../Source/ThirdParty/bgfx/include/bgfx/*.*",
            "../Source/ThirdParty/bgfx/include/bgfx/c99/*.*",
            "../Source/ThirdParty/bgfx/src/*.cpp",
            "../Source/ThirdParty/bgfx/src/*.h",
        }

        removefiles {
            "../Source/ThirdParty/bgfx/src/*.bin.h",
            "../Source/ThirdParty/bgfx/src/amalgamated.*",
        }

        includedirs {
            "../Source/ThirdParty/bgfx-deps/",
            "../Source/ThirdParty/bgfx-deps/dxsdk/include/",
            "../Source/ThirdParty/bgfx-deps/khronos/",
            "../Source/ThirdParty/bx/",
            "../Source/ThirdParty/bgfx/include/",
        }

        configuration { "Debug" }
            defines {
                "BGFX_CONFIG_DEBUG=1",
            }
            
        configuration { "android*" }
            links {
                "EGL",
                "GLESv2",
            }

        configuration { "osx" }
            linkoptions {
                "-framework Cocoa",
                "-framework QuartzCore",
                "-framework OpenGL",
                "-weak_framework Metal",
            }  
            
        configuration { "xcode* or osx or ios*" }
            files {
                "../Source/ThirdParty/bgfx/src/glcontext_eagl.mm",
                "../Source/ThirdParty/bgfx/src/glcontext_nsgl.mm",
                "../Source/ThirdParty/bgfx/src/renderer_mtl.mm",
            }                  

        vpaths { ["*"] = { "../Source/ThirdParty/bgfx/src", "../Source/ThirdParty/bgfx/include" } }
end
