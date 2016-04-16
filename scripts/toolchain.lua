--
-- Copyright 2010-2016 Branimir Karadzic. All rights reserved.
-- License: https://github.com/bkaradzic/bx#license-bsd-2-clause
--

-- Edited by cosmy1 for Clockwork Engine

local bxDir = path.getabsolute("..")
local androidPlatform = "android-14"
local iosPlatform = ""
local tvosPlatform = ""

function toolchain()

    newoption {
        trigger = "gcc",
        value = "GCC",
        description = "Choose GCC flavor",
        allowed = {
            { "android-arm",     "Android - ARM"              },
            { "android-mips",    "Android - MIPS"             },
            { "android-x86",     "Android - x86"              },
            { "ios-arm",         "iOS - ARM"                  },
            { "ios-simulator",   "iOS - Simulator"            },
            { "linux-gcc",       "Linux (GCC compiler)"       },
            { "linux-gcc-5",     "Linux (GCC-5 compiler)"     },
            { "linux-clang",     "Linux (Clang compiler)"     },
            { "linux-mips-gcc",  "Linux (MIPS, GCC compiler)" },
            { "linux-arm-gcc",   "Linux (ARM, GCC compiler)"  },
            { "tvos-arm64",      "tvOS - ARM64"               },
            { "tvos-simulator",  "tvOS - Simulator"           },
            { "osx",             "OSX"                        },
            { "ps4",             "PS4"                        },
        },
    }

    newoption {
        trigger = "vs",
        value = "toolset",
        description = "Choose VS toolset",
        allowed = {
            { "win32desktop",  "Windows Desktop"                 },
            { "winphone8",     "Windows Phone 8.0"               },
            { "winphone81",    "Windows Phone 8.1"               },
            { "winstore81",    "Windows Store 8.1"               },
            { "winstore82",    "Universal Windows App"           },
            { "durango",       "Durango"                         },
        },
    }

    newoption {
        trigger = "xcode",
        value = "xcode_target",
        description = "Choose XCode target",
        allowed = {
            { "osx", "OSX" },
            { "ios", "iOS" },
            { "tvos", "tvOS" },
        }
    }

    newoption {
        trigger = "with-android",
        value   = "#",
        description = "Set Android platform version (default: android-14).",
    }

    newoption {
        trigger = "with-ios",
        value   = "#",
        description = "Set iOS target version (default: 8.0).",
    }

    newoption {
        trigger = "with-tvos",
        value   = "#",
        description = "Set tvOS target version (default: 9.0).",
    }

    newoption {
        trigger = "with-static-runtime",
        description = "Statically link with the runtime rather than dynamically",
    }

    -- Avoid error when invoking genie --help.
    if (_ACTION == nil) then return false end

    location (path.join(bxDir, "projects", _ACTION))

    if _OPTIONS["with-android"] then
        androidPlatform = "android-" .. _OPTIONS["with-android"]
    end

    if _OPTIONS["with-ios"] then
        iosPlatform = _OPTIONS["with-ios"]
    end
  
    if _OPTIONS["with-tvos"] then
        tvosPlatform = _OPTIONS["with-tvos"]
    end

    if _ACTION == "gmake" then

        if nil == _OPTIONS["gcc"] then
            print("GCC flavor must be specified!")
            os.exit(1)
        end

        flags {
            "ExtraWarnings",
        }

        if "android-arm" == _OPTIONS["gcc"] then

            if not os.getenv("ANDROID_NDK_ARM") or not os.getenv("ANDROID_NDK_ROOT") then
                print("Set ANDROID_NDK_ARM and ANDROID_NDK_ROOT envrionment variables.")
            end

            premake.gcc.cc  = "$(ANDROID_NDK_ARM)/bin/arm-linux-androideabi-gcc"
            premake.gcc.cxx = "$(ANDROID_NDK_ARM)/bin/arm-linux-androideabi-g++"
            premake.gcc.ar  = "$(ANDROID_NDK_ARM)/bin/arm-linux-androideabi-ar"
            location (path.join(bxDir, "projects", _ACTION .. "-android-arm"))

        elseif "android-mips" == _OPTIONS["gcc"] then

            if not os.getenv("ANDROID_NDK_MIPS") or not os.getenv("ANDROID_NDK_ROOT") then
                print("Set ANDROID_NDK_MIPS and ANDROID_NDK_ROOT envrionment variables.")
            end

            premake.gcc.cc  = "$(ANDROID_NDK_MIPS)/bin/mipsel-linux-android-gcc"
            premake.gcc.cxx = "$(ANDROID_NDK_MIPS)/bin/mipsel-linux-android-g++"
            premake.gcc.ar  = "$(ANDROID_NDK_MIPS)/bin/mipsel-linux-android-ar"
            location (path.join(bxDir, "projects", _ACTION .. "-android-mips"))

        elseif "android-x86" == _OPTIONS["gcc"] then

            if not os.getenv("ANDROID_NDK_X86") or not os.getenv("ANDROID_NDK_ROOT") then
                print("Set ANDROID_NDK_X86 and ANDROID_NDK_ROOT envrionment variables.")
            end

            premake.gcc.cc  = "$(ANDROID_NDK_X86)/bin/i686-linux-android-gcc"
            premake.gcc.cxx = "$(ANDROID_NDK_X86)/bin/i686-linux-android-g++"
            premake.gcc.ar  = "$(ANDROID_NDK_X86)/bin/i686-linux-android-ar"
            location (path.join(bxDir, "projects", _ACTION .. "-android-x86"))

        elseif "ios-arm" == _OPTIONS["gcc"] then
            premake.gcc.cc  = "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang"
            premake.gcc.cxx = "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++"
            premake.gcc.ar  = "ar"
            location (path.join(bxDir, "projects", _ACTION .. "-ios-arm"))

        elseif "ios-simulator" == _OPTIONS["gcc"] then
            premake.gcc.cc  = "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang"
            premake.gcc.cxx = "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++"
            premake.gcc.ar  = "ar"
            location (path.join(bxDir, "projects", _ACTION .. "-ios-simulator"))

        elseif "tvos-arm64" == _OPTIONS["gcc"] then
            premake.gcc.cc  = "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang"
            premake.gcc.cxx = "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++"
            premake.gcc.ar  = "ar"
            location (path.join(bxDir, "projects", _ACTION .. "-tvos-arm64"))

        elseif "tvos-simulator" == _OPTIONS["gcc"] then
            premake.gcc.cc  = "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang"
            premake.gcc.cxx = "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++"
            premake.gcc.ar  = "ar"
            location (path.join(bxDir, "projects", _ACTION .. "-tvos-simulator"))

        elseif "linux-gcc" == _OPTIONS["gcc"] then
            location (path.join(bxDir, "projects", _ACTION .. "-linux"))

        elseif "linux-gcc-5" == _OPTIONS["gcc"] then
            premake.gcc.cc  = "gcc-5"
            premake.gcc.cxx = "g++-5"
            premake.gcc.ar  = "ar"
            location (path.join(bxDir, "projects", _ACTION .. "-linux"))

        elseif "linux-clang" == _OPTIONS["gcc"] then
            premake.gcc.cc  = "clang"
            premake.gcc.cxx = "clang++"
            premake.gcc.ar  = "ar"
            location (path.join(bxDir, "projects", _ACTION .. "-linux-clang"))

        elseif "linux-mips-gcc" == _OPTIONS["gcc"] then
            location (path.join(bxDir, "projects", _ACTION .. "-linux-mips-gcc"))

        elseif "linux-arm-gcc" == _OPTIONS["gcc"] then
            location (path.join(bxDir, "projects", _ACTION .. "-linux-arm-gcc"))

        elseif "osx" == _OPTIONS["gcc"] then

            if os.is("linux") then
                local osxToolchain = "x86_64-apple-darwin13-"
                premake.gcc.cc  = osxToolchain .. "clang"
                premake.gcc.cxx = osxToolchain .. "clang++"
                premake.gcc.ar  = osxToolchain .. "ar"
            end
            location (path.join(bxDir, "projects", _ACTION .. "-osx"))

        elseif "ps4" == _OPTIONS["gcc"] then

            if not os.getenv("PS4_SDK_ROOT") then
                print("Set PS4_SDK_ROOT enviroment variable.")
            end

            ps4Toolchain = "$(PS4_SDK_ROOT)/host_tools/bin/orbis-"

            premake.gcc.cc  = ps4Toolchain .. "clang"
            premake.gcc.cxx = ps4Toolchain .. "clang++"
            premake.gcc.ar  = ps4Toolchain .. "ar"
            location (path.join(bxDir, "projects", _ACTION .. "-ps4"))

        end
    elseif _ACTION == "vs2012" or _ACTION == "vs2013" or _ACTION == "vs2015" then

        if "winphone8" == _OPTIONS["vs"] then
            premake.vstudio.toolset = "v110_wp80"
            location (path.join(_buildDir, "projects", _ACTION .. "-winphone8"))

        elseif "winphone81" == _OPTIONS["vs"] then
            premake.vstudio.toolset = "v120_wp81"
            premake.vstudio.storeapp = "8.1"
            platforms { "ARM" }
            location (path.join(bxDir, "projects", _ACTION .. "-winphone81"))

        elseif "winstore81" == _OPTIONS["vs"] then
            premake.vstudio.toolset = "v120"
            premake.vstudio.storeapp = "8.1"
            platforms { "ARM" }
            location (path.join(bxDir, "projects", _ACTION .. "-winstore81"))

        elseif "winstore82" == _OPTIONS["vs"] then
            premake.vstudio.toolset = "v140"
            premake.vstudio.storeapp = "8.2"
            platforms { "ARM" }
            location (path.join(bxDir, "projects", _ACTION .. "-winstore82"))

        elseif "durango" == _OPTIONS["vs"] then
            if not os.getenv("DurangoXDK") then
                print("DurangoXDK not found.")
            end

            premake.vstudio.toolset = "v140"
            premake.vstudio.storeapp = "durango"
            platforms { "Durango" }
            location (path.join(bxDir, "projects", _ACTION .. "-durango"))

        elseif "win32desktop" == _OPTIONS["vs"] then
            location (path.join(bxDir, "projects", _ACTION .. "-win32desktop"))    

        end
    elseif _ACTION == "xcode4" then

        if "osx" == _OPTIONS["xcode"] then
            premake.xcode.toolset = "macosx"
            location (path.join(bxDir, "projects", _ACTION .. "-osx"))

        elseif "ios" == _OPTIONS["xcode"] then
            premake.xcode.toolset = "iphoneos"
            location (path.join(bxDir, "projects", _ACTION .. "-ios"))

        elseif "tvos" == _OPTIONS["xcode"] then
            premake.xcode.toolset = "appletvos"
            location (path.join(bxDir, "projects", _ACTION .. "-tvos"))
        end
    end

    if  _OPTIONS["with-static-runtime"] then
        flags { "StaticRuntime" }
    end

    return true
end

function strip()

    configuration { "android-arm", "Release" }
        postbuildcommands {
            "$(SILENT) echo Stripping symbols.",
            "$(SILENT) $(ANDROID_NDK_ARM)/bin/arm-linux-androideabi-strip -s \"$(TARGET)\""
        }

    configuration { "android-mips", "Release" }
        postbuildcommands {
            "$(SILENT) echo Stripping symbols.",
            "$(SILENT) $(ANDROID_NDK_MIPS)/bin/mipsel-linux-android-strip -s \"$(TARGET)\""
        }

    configuration { "android-x86", "Release" }
        postbuildcommands {
            "$(SILENT) echo Stripping symbols.",
            "$(SILENT) $(ANDROID_NDK_X86)/bin/i686-linux-android-strip -s \"$(TARGET)\""
        }

    configuration { "linux-*", "Release" }
        postbuildcommands {
            "$(SILENT) echo Stripping symbols.",
            "$(SILENT) strip -s \"$(TARGET)\""
        }

    configuration {} -- reset configuration
end


function prepareProject(_projectName, _buildDir)

    flags {
        "NoPCH",
        "NativeWChar",
        "NoRTTI",
        "NoExceptions",
        "NoEditAndContinue",
        "Symbols",
        "WinMain"
    }

    defines {
        "__STDC_LIMIT_MACROS",
        "__STDC_FORMAT_MACROS",
        "__STDC_CONSTANT_MACROS",
    }

    configuration { "Debug" }
        defines { "_DEBUG" }
        targetsuffix "_d"

    configuration { "Release" }
        defines { "NDEBUG" }
        flags {
            "OptimizeSpeed",
        }
        targetsuffix ""

    configuration { "vs*", "x32" }
        flags {
            "EnableSSE2",
        }

    configuration { "vs*" }
        includedirs { path.join(bxDir, "Source/ThirdParty/compat/msvc") }
        defines {
            "WIN32",
            "_WIN32",
            "_HAS_EXCEPTIONS=0",
            "_HAS_ITERATOR_DEBUGGING=0",
            "_SCL_SECURE=0",
            "_SECURE_SCL=0",
            "_SCL_SECURE_NO_WARNINGS",
            "_CRT_SECURE_NO_WARNINGS",
            "_CRT_SECURE_NO_DEPRECATE",
        }
        buildoptions {
            "/Oy-", -- Suppresses creation of frame pointers on the call stack.
            "/Ob2", -- The Inline Function Expansion
        }
        linkoptions {
            "/ignore:4221", -- LNK4221: This object file does not define any previously undefined public symbols, so it will not be used by any link operation that consumes this library
        }

    objdir (path.join(solution().location, "obj", _projectName))

    configuration { "x32", "vs*" }
        targetdir (path.join(_buildDir, "win32_" .. _ACTION))
        libdirs { path.join(bxDir, "lib/win32_" .. _ACTION) }

    configuration { "x64", "vs*" }
        defines { "_WIN64" }
        targetdir (path.join(_buildDir, "win64_" .. _ACTION))
        libdirs { path.join(bxDir, "lib/win64_" .. _ACTION) }

    configuration { "ARM", "vs*" }
        targetdir (path.join(_buildDir, "arm_" .. _ACTION))
        libdirs { path.join(bxDir, "lib/arm_" .. _ACTION) }

    configuration { "winphone8* or winstore8*" }
        removeflags {
            "StaticRuntime",
            "NoExceptions",
        }

    configuration { "*-gcc* or osx" }
        buildoptions {
            "-Wshadow",
        }

    configuration { "linux-clang" }

    configuration { "linux-gcc-5" }
        buildoptions {
--          "-fno-omit-frame-pointer",
--          "-fsanitize=address",
--          "-fsanitize=undefined",
--          "-fsanitize=float-divide-by-zero",
--          "-fsanitize=float-cast-overflow",
        }
        links {
--          "asan",
--          "ubsan",
        }

    configuration { "linux-gcc" }
        buildoptions {
            "-mfpmath=sse",
        }

    configuration { "linux-gcc or linux-clang" }
        buildoptions {
            "-msse2",
            "-Wunused-value",
            "-Wundef",
        }
        buildoptions_cpp {
            "-std=c++0x",
        }
        links {
            "rt",
            "dl",
        }
        linkoptions {
            "-Wl,--gc-sections",
        }

    configuration { "linux-gcc*", "x32" }
        targetdir (path.join(_buildDir, "linux32_gcc"))
        libdirs { path.join(bxDir, "lib/linux32_gcc") }
        buildoptions {
            "-m32",
        }

    configuration { "linux-gcc*", "x64" }
        targetdir (path.join(_buildDir, "linux64_gcc"))
        libdirs { path.join(bxDir, "lib/linux64_gcc") }
        buildoptions {
            "-m64",
        }

    configuration { "linux-clang", "x32" }
        targetdir (path.join(_buildDir, "linux32_clang"))
        libdirs { path.join(bxDir, "lib/linux32_clang") }
        buildoptions {
            "-m32",
        }

    configuration { "linux-clang", "x64" }
        targetdir (path.join(_buildDir, "linux64_clang"))
        libdirs { path.join(bxDir, "lib/linux64_clang") }
        buildoptions {
            "-m64",
        }

    configuration { "linux-mips-gcc" }
        targetdir (path.join(_buildDir, "linux32_mips_gcc"))
        libdirs { path.join(bxDir, "lib/linux32_mips_gcc") }
        buildoptions {
            "-Wunused-value",
            "-Wundef",
        }
        buildoptions_cpp {
            "-std=c++0x",
        }
        links {
            "rt",
            "dl",
        }
        linkoptions {
            "-Wl,--gc-sections",
        }

    configuration { "linux-arm-gcc" }
        targetdir (path.join(_buildDir, "linux32_arm_gcc"))
        libdirs { path.join(bxDir, "lib/linux32_arm_gcc") }
        buildoptions {
            "-Wunused-value",
            "-Wundef",
        }
        buildoptions_cpp {
            "-std=c++0x",
        }
        links {
            "rt",
            "dl",
        }
        linkoptions {
            "-Wl,--gc-sections",
        }

    configuration { "android-*" }
        targetprefix ("lib")
        flags {
            "NoImportLib",
        }
        includedirs {
            "$(ANDROID_NDK_ROOT)/sources/cxx-stl/gnu-libstdc++/4.8/include",
            "$(ANDROID_NDK_ROOT)/sources/android/native_app_glue",
        }
        linkoptions {
            "-nostdlib",
            "-static-libgcc",
        }
        links {
            "c",
            "dl",
            "m",
            "android",
            "log",
            "gnustl_static",
            "gcc",
        }
        buildoptions {
            "-fPIC",
            "-no-canonical-prefixes",
            "-Wa,--noexecstack",
            "-fstack-protector",
            "-ffunction-sections",
            "-Wno-psabi", -- note: the mangling of 'va_list' has changed in GCC 4.4.0
            "-Wunused-value",
            "-Wundef",
        }
        buildoptions_cpp {
            "-std=c++0x",
        }
        linkoptions {
            "-no-canonical-prefixes",
            "-Wl,--no-undefined",
            "-Wl,-z,noexecstack",
            "-Wl,-z,relro",
            "-Wl,-z,now",
        }

    configuration { "android-arm" }
        targetdir (path.join(_buildDir, "android-arm"))
        libdirs {
            path.join(bxDir, "lib/android-arm"),
            "$(ANDROID_NDK_ROOT)/sources/cxx-stl/gnu-libstdc++/4.9/libs/armeabi-v7a",
        }
        includedirs {
            "$(ANDROID_NDK_ROOT)/sources/cxx-stl/gnu-libstdc++/4.9/libs/armeabi-v7a/include",
            "$(ANDROID_NDK_ROOT)/sources/cxx-stl/gnu-libstdc++/4.9/include",
        }
        buildoptions {
            "--sysroot=" .. path.join("$(ANDROID_NDK_ROOT)/platforms", androidPlatform, "arch-arm"),
            "-mthumb",
            "-march=armv7-a",
            "-mfloat-abi=softfp",
            "-mfpu=neon",
            "-Wunused-value",
            "-Wundef",
        }
        linkoptions {
            "--sysroot=" .. path.join("$(ANDROID_NDK_ROOT)/platforms", androidPlatform, "arch-arm"),
            path.join("$(ANDROID_NDK_ROOT)/platforms", androidPlatform, "arch-arm/usr/lib/crtbegin_so.o"),
            path.join("$(ANDROID_NDK_ROOT)/platforms", androidPlatform, "arch-arm/usr/lib/crtend_so.o"),
            "-march=armv7-a",
            "-Wl,--fix-cortex-a8",
        }

    configuration { "android-mips" }
        targetdir (path.join(_buildDir, "android-mips"))
        libdirs {
            path.join(bxDir, "lib/android-mips"),
            "$(ANDROID_NDK_ROOT)/sources/cxx-stl/gnu-libstdc++/4.8/libs/mips",
        }
        includedirs {
            "$(ANDROID_NDK_ROOT)/sources/cxx-stl/gnu-libstdc++/4.8/libs/mips/include",
        }
        buildoptions {
            "--sysroot=" .. path.join("$(ANDROID_NDK_ROOT)/platforms", androidPlatform, "arch-mips"),
            "-Wunused-value",
            "-Wundef",
        }
        linkoptions {
            "--sysroot=" .. path.join("$(ANDROID_NDK_ROOT)/platforms", androidPlatform, "arch-mips"),
            path.join("$(ANDROID_NDK_ROOT)/platforms", androidPlatform, "arch-mips/usr/lib/crtbegin_so.o"),
            path.join("$(ANDROID_NDK_ROOT)/platforms", androidPlatform, "arch-mips/usr/lib/crtend_so.o"),
        }

    configuration { "android-x86" }
        targetdir (path.join(_buildDir, "android-x86"))
        libdirs {
            path.join(bxDir, "lib/android-x86"),
            "$(ANDROID_NDK_ROOT)/sources/cxx-stl/gnu-libstdc++/4.8/libs/x86",
        }
        includedirs {
            "$(ANDROID_NDK_ROOT)/sources/cxx-stl/gnu-libstdc++/4.8/libs/x86/include",
        }
        buildoptions {
            "--sysroot=" .. path.join("$(ANDROID_NDK_ROOT)/platforms", androidPlatform, "arch-x86"),
            "-march=i686",
            "-mtune=atom",
            "-mstackrealign",
            "-msse3",
            "-mfpmath=sse",
            "-Wunused-value",
            "-Wundef",
        }
        linkoptions {
            "--sysroot=" .. path.join("$(ANDROID_NDK_ROOT)/platforms", androidPlatform, "arch-x86"),
            path.join("$(ANDROID_NDK_ROOT)/platforms", androidPlatform, "arch-x86/usr/lib/crtbegin_so.o"),
            path.join("$(ANDROID_NDK_ROOT)/platforms", androidPlatform, "arch-x86/usr/lib/crtend_so.o"),
        }

    configuration { "durango" }
        targetdir (path.join(_buildDir, "durango"))
        includedirs { path.join(bxDir, "Source/ThirdParty/compat/msvc") }
        libdirs { path.join(bxDir, "lib/durango") }
        removeflags { "StaticRuntime" }
        defines {
            "NOMINMAX",
        }

    configuration { "osx", "x32" }
        targetdir (path.join(_buildDir, "osx32_clang"))
        --libdirs { path.join(bxDir, "lib/osx32_clang") }
        buildoptions {
            "-m32",
        }

    configuration { "osx", "x64" }
        targetdir (path.join(_buildDir, "osx64_clang"))
        --libdirs { path.join(bxDir, "lib/osx64_clang") }
        buildoptions {
            "-m64",
        }

    configuration { "osx", "Universal" }
        targetdir (path.join(_buildDir, "osx_universal"))

    configuration { "osx" }
        buildoptions {
            "-Wfatal-errors",
            "-msse2",
            "-Wunused-value",
            "-Wundef",
        }
        includedirs { path.join(bxDir, "Source/ThirdParty/compat/osx") }

    configuration { "ios*" }
        linkoptions {
            "-lc++",
        }
        buildoptions {
            "-Wfatal-errors",
            "-Wunused-value",
            "-Wundef",
        }
        includedirs { path.join(bxDir, "Source/ThirdParty/compat/ios") }

    configuration { "xcode4", "ios*" }
        targetdir (path.join(_buildDir, "ios-arm"))

    configuration { "ios-arm" }
        targetdir (path.join(_buildDir, "ios-arm"))
        libdirs { path.join(bxDir, "lib/ios-arm") }
        linkoptions {
            "-miphoneos-version-min=7.0",
            "-arch armv7",
            "--sysroot=/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS" ..iosPlatform .. ".sdk",
            "-L/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS" ..iosPlatform .. ".sdk/usr/lib/system",
            "-F/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS" ..iosPlatform .. ".sdk/System/Library/Frameworks",
            "-F/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS" ..iosPlatform .. ".sdk/System/Library/PrivateFrameworks",
        }
        buildoptions {
            "-miphoneos-version-min=7.0",
            "-arch armv7",
            "--sysroot=/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS" ..iosPlatform .. ".sdk",
        }

    configuration { "ios-simulator" }
        targetdir (path.join(_buildDir, "ios-simulator"))
        libdirs { path.join(bxDir, "lib/ios-simulator") }
        linkoptions {
            "-mios-simulator-version-min=7.0",
            "-arch i386",
            "--sysroot=/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator" ..iosPlatform .. ".sdk",
            "-L/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator" ..iosPlatform .. ".sdk/usr/lib/system",
            "-F/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator" ..iosPlatform .. ".sdk/System/Library/Frameworks",
            "-F/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator" ..iosPlatform .. ".sdk/System/Library/PrivateFrameworks",
        }
        buildoptions {
            "-mios-simulator-version-min=7.0",
            "-arch i386",
            "--sysroot=/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator" ..iosPlatform .. ".sdk",
        }

    configuration { "tvos*" }
        linkoptions {
            "-lc++",
        }
        buildoptions {
            "-Wfatal-errors",
            "-Wunused-value",
            "-Wundef",
        }
        includedirs { path.join(bxDir, "Source/ThirdParty/compat/ios") }

    configuration { "xcode4", "tvos*" }
        targetdir (path.join(_buildDir, "tvos-arm64"))

    configuration { "tvos-arm64" }
        targetdir (path.join(_buildDir, "tvos-arm64"))
        libdirs { path.join(bxDir, "lib/tvos-arm64") }
        linkoptions {
            "-mtvos-version-min=9.0",
            "-arch arm64",
            "--sysroot=/Applications/Xcode.app/Contents/Developer/Platforms/AppleTVOS.platform/Developer/SDKs/AppleTVOS" ..tvosPlatform .. ".sdk",
            "-L/Applications/Xcode.app/Contents/Developer/Platforms/AppleTVOS.platform/Developer/SDKs/AppleTVOS" ..tvosPlatform .. ".sdk/usr/lib/system",
            "-F/Applications/Xcode.app/Contents/Developer/Platforms/AppleTVOS.platform/Developer/SDKs/AppleTVOS" ..tvosPlatform .. ".sdk/System/Library/Frameworks",
            "-F/Applications/Xcode.app/Contents/Developer/Platforms/AppleTVOS.platform/Developer/SDKs/AppleTVOS" ..tvosPlatform .. ".sdk/System/Library/PrivateFrameworks",
        }
        buildoptions {
            "-mtvos-version-min=9.0",
            "-arch arm64",
            "--sysroot=/Applications/Xcode.app/Contents/Developer/Platforms/AppleTVOS.platform/Developer/SDKs/AppleTVOS" ..tvosPlatform .. ".sdk",
        }

    configuration { "tvos-simulator" }
        targetdir (path.join(_buildDir, "tvos-simulator"))
        libdirs { path.join(bxDir, "lib/tvos-simulator") }
        linkoptions {
            "-mtvos-simulator-version-min=9.0",
            "-arch i386",
            "--sysroot=/Applications/Xcode.app/Contents/Developer/Platforms/AppleTVSimulator.platform/Developer/SDKs/AppleTVSimulator" ..tvosPlatform .. ".sdk",
            "-L/Applications/Xcode.app/Contents/Developer/Platforms/AppleTVSimulator.platform/Developer/SDKs/AppleTVSimulator" ..tvosPlatform .. ".sdk/usr/lib/system",
            "-F/Applications/Xcode.app/Contents/Developer/Platforms/AppleTVSimulator.platform/Developer/SDKs/AppleTVSimulator" ..tvosPlatform .. ".sdk/System/Library/Frameworks",
            "-F/Applications/Xcode.app/Contents/Developer/Platforms/AppleTVSimulator.platform/Developer/SDKs/AppleTVSimulator" ..tvosPlatform .. ".sdk/System/Library/PrivateFrameworks",
        }
        buildoptions {
            "-mtvos-simulator-version-min=9.0",
            "-arch i386",
            "--sysroot=/Applications/Xcode.app/Contents/Developer/Platforms/AppleTVSimulator.platform/Developer/SDKs/AppleTVSimulator" ..tvosPlatform .. ".sdk",
        }

    configuration { "ps4" }
        targetdir (path.join(_buildDir, "ps4"))
        libdirs { path.join(bxDir, "lib/ps4") }
        includedirs {
            path.join(bxDir, "Source/ThirdParty/compat/freebsd"),
            "$(PS4_SDK_ROOT)/target/include",
            "$(PS4_SDK_ROOT)/target/include_common",
        }
        buildoptions {
        }
        buildoptions_cpp {
            "-std=c++0x",
        }
        linkoptions {
        }

    configuration {} -- reset configuration
end
