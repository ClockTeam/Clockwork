-- Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
-- See License.txt in the project root for license information.

SDL_SRC_PATH = "../Source/ThirdParty/SDL/src/"
SDL_INC_PATH = "../Source/ThirdParty/SDL/include/"

function SDL_Project()
    group "Libs"
    project "SDL"
        targetname "SDL"
        kind "StaticLib"
        language "C++"
        prepareProject("SDL", "../lib")

        defines {"SDL_RENDER_DISABLED"}

        files {
            SDL_SRC_PATH .. "*.c", SDL_SRC_PATH .. "*.h",
            SDL_SRC_PATH .. "atomic/*.c",
            SDL_SRC_PATH .. "audio/*.c", SDL_SRC_PATH .. "audio/*.h",
            SDL_SRC_PATH .. "audio/disk/*.c", SDL_SRC_PATH .. "audio/disk/*.h",
            SDL_SRC_PATH .. "audio/dummy/*.c", SDL_SRC_PATH .. "audio/disk/dummy/*.h",
            SDL_SRC_PATH .. "cpuinfo/*.c",
            SDL_SRC_PATH .. "events/*.c", SDL_SRC_PATH .. "events/*.h",
            SDL_SRC_PATH .. "file/*.c",
            SDL_SRC_PATH .. "haptic/*.c", SDL_SRC_PATH .. "haptic/*.h",
            SDL_SRC_PATH .. "joystick/*.c", SDL_SRC_PATH .. "joystick/*.h",
            SDL_SRC_PATH .. "libm/*.c", SDL_SRC_PATH .. "libm/*.h",
            SDL_SRC_PATH .. "power/*.c",
            SDL_SRC_PATH .. "stdlib/*.c",
            SDL_SRC_PATH .. "thread/*.c", SDL_SRC_PATH .. "thread/*.h",
            SDL_SRC_PATH .. "timer/*.c", SDL_SRC_PATH .. "timer/*.h",
            SDL_SRC_PATH .. "video/*.c", SDL_SRC_PATH .. "video/*.h",
            SDL_SRC_PATH .. "video/dummy/*.c", SDL_SRC_PATH .. "video/dummy/*.h"
        }

        -- todo: other platforms
        if isWindows() then
            if isWindowsDesktop() then
                files {
                    SDL_SRC_PATH .. "audio/directsound/*.c", SDL_SRC_PATH .. "audio/directsound/*.h",
                    SDL_SRC_PATH .. "audio/winmm/*.c", SDL_SRC_PATH .. "audio/winmm/*.h",
                    SDL_SRC_PATH .. "core/windows/*.c", SDL_SRC_PATH .. "core/windows/*.h",
                    SDL_SRC_PATH .. "filesystem/windows/*.c",
                    SDL_SRC_PATH .. "power/windows/*.c",
                    SDL_SRC_PATH .. "video/windows/*.c", SDL_SRC_PATH .. "video/windows/*.h"
                }
            else
                files {
                    SDL_SRC_PATH .. "core/winrt/*.cpp", SDL_SRC_PATH .. "core/winrt/*.h", 
                    SDL_SRC_PATH .. "filesystem/winrt/*.cpp",
                    SDL_SRC_PATH .. "power/winrt/*.cpp",
                    SDL_SRC_PATH .. "video/winrt/*.cpp", SDL_SRC_PATH .. "video/winrt/*.h"
                }
            end

            files {
                SDL_SRC_PATH .. "audio/xaudio2/*.c", SDL_SRC_PATH .. "audio/xaudio2/*.h",
    
                SDL_SRC_PATH .. "haptic/windows/*.c", SDL_SRC_PATH .. "haptic/windows/*.h",
                SDL_SRC_PATH .. "joystick/windows/*.c", SDL_SRC_PATH .. "joystick/windows/*.h",

                SDL_SRC_PATH .. "loadso/windows/*.c",
                
                SDL_SRC_PATH .. "thread/windows/*.c", SDL_SRC_PATH .. "thread/windows/*.h", SDL_SRC_PATH .. "thread/generic/SDL_syscond.c",
                SDL_SRC_PATH .. "timer/windows/*.c",       
            }         
        end

        includedirs { SDL_INC_PATH }

        vpaths { ["*"] = SDL_SRC_PATH }
end
