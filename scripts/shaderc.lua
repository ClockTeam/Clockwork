--
-- Copyright 2010-2016 Branimir Karadzic. All rights reserved.
-- License: https://github.com/bkaradzic/bgfx#license-bsd-2-clause
--

-- Edited by cosmy1 for Clockwork Engine

group "Tools"
project "shaderc"
    targetname "shaderc"
    kind "StaticLib"
    language "C++"
    prepareProject("shaderc", "../bin")

    local GLSL_OPTIMIZER = "../Source/ThirdParty/bgfx-deps/glsl-optimizer/"
    local FCPP_DIR = "../Source/ThirdParty/bgfx-deps/fcpp/"
    local BGFX_DIR = "../Source/ThirdParty/bgfx/"
    local BGFX_DEPS = "../Source/ThirdParty/bgfx-deps/"
    local BX_DIR = "../Source/ThirdParty/bx/"

    includedirs {
        path.join(GLSL_OPTIMIZER, "src"),
    }

    removeflags {
        -- GCC 4.9 -O2 + -fno-strict-aliasing don't work together...
        "OptimizeSpeed",
    }

    configuration { "vs*" }
        includedirs {
            path.join(GLSL_OPTIMIZER, "src/glsl/msvc"),
        }

        defines { -- glsl-optimizer
            "__STDC__",
            "__STDC_VERSION__=199901L",
            "strdup=_strdup",
            "alloca=_alloca",
            "isascii=__isascii",
        }

        buildoptions {
            "/wd4996" -- warning C4996: 'strdup': The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: _strdup.
        }

    configuration { "mingw* or linux or osx" }
        buildoptions {
            "-fno-strict-aliasing", -- glsl-optimizer has bugs if strict aliasing is used.
            "-Wno-unused-parameter",
        }
        removebuildoptions {
            "-Wshadow", -- glsl-optimizer is full of -Wshadow warnings ignore it.
        }

    configuration { "osx" }
        links {
            "Cocoa.framework",
        }

    configuration { "vs*" }
        includedirs {
            path.join(GLSL_OPTIMIZER, "include/c99"),
        }

    configuration {}

    defines { -- fcpp
        "NINCLUDE=64",
        "NWORK=65536",
        "NBUFF=65536",
        "OLD_PREPROCESSOR=0",
    }

    includedirs {
        BX_DIR,
        path.join(BGFX_DIR, "include"),

        path.join(BGFX_DEPS, "dxsdk/include"),
        FCPP_DIR,

        path.join(GLSL_OPTIMIZER, "include"),
        path.join(GLSL_OPTIMIZER, "src/mesa"),
        path.join(GLSL_OPTIMIZER, "src/mapi"),
        path.join(GLSL_OPTIMIZER, "src/glsl"),
    }

    files {
        path.join(BGFX_DIR, "tools/shaderc/**.cpp"),
        path.join(BGFX_DIR, "tools/shaderc/**.h"),
        path.join(BGFX_DIR, "src/vertexdecl.**"),

        path.join(FCPP_DIR, "**.h"),
        path.join(FCPP_DIR, "cpp1.c"),
        path.join(FCPP_DIR, "cpp2.c"),
        path.join(FCPP_DIR, "cpp3.c"),
        path.join(FCPP_DIR, "cpp4.c"),
        path.join(FCPP_DIR, "cpp5.c"),
        path.join(FCPP_DIR, "cpp6.c"),
        path.join(FCPP_DIR, "cpp6.c"),

        path.join(GLSL_OPTIMIZER, "src/mesa/**.c"),
        path.join(GLSL_OPTIMIZER, "src/glsl/**.cpp"),
        path.join(GLSL_OPTIMIZER, "src/mesa/**.h"),
        path.join(GLSL_OPTIMIZER, "src/glsl/**.c"),
        path.join(GLSL_OPTIMIZER, "src/glsl/**.cpp"),
        path.join(GLSL_OPTIMIZER, "src/glsl/**.h"),
        path.join(GLSL_OPTIMIZER, "src/util/**.c"),
        path.join(GLSL_OPTIMIZER, "src/util/**.h"),
    }

    removefiles {
        path.join(GLSL_OPTIMIZER, "src/glsl/glcpp/glcpp.c"),
        path.join(GLSL_OPTIMIZER, "src/glsl/glcpp/tests/**"),
        path.join(GLSL_OPTIMIZER, "src/glsl/glcpp/**.l"),
        path.join(GLSL_OPTIMIZER, "src/glsl/glcpp/**.y"),
        path.join(GLSL_OPTIMIZER, "src/glsl/ir_set_program_inouts.cpp"),
        path.join(GLSL_OPTIMIZER, "src/glsl/main.cpp"),
        path.join(GLSL_OPTIMIZER, "src/glsl/builtin_stubs.cpp"),
    }

    vpaths { ["*"] = { 
            "../Source/ThirdParty/bgfx/",
            "../Source/ThirdParty/bgfx/tools/",
            "../Source/ThirdParty/bgfx-deps/"
        }
    }
    
    configuration {}
    strip()
