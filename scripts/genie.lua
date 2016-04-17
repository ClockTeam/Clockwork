-- Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
-- See License.txt in the project root for license information.

-- Useful functions
function isWindows()
    if "winphone8" == _OPTIONS["vs"] or
        "winphone81" == _OPTIONS["vs"] or 
        "winstore81" == _OPTIONS["vs"] or
        "winstore82" == _OPTIONS["vs"] or
        "win32desktop" == _OPTIONS["vs"] then
        return true
    end
    return false
end

function isWindowsDesktop()
    if "win32desktop" == _OPTIONS["vs"] then
        return true
    end
    return false
end

function isOSX()
    if "osx" == _OPTIONS["xcode"] then
        return true
    end
    return false
end

function isIOS()
    if "ios" == _OPTIONS["xcode"] or
        "tvos" == _OPTIONS["xcode"] then
        return true
    end
    return false    
end

function isAndroid()
    if "android-arm" == _OPTIONS["gcc"] or
        "android-mips" == _OPTIONS["gcc"] or
        "android-x86" == _OPTIONS["gcc"] then
        return true
    end
    return false    
end

function isDurango()
    if "durango" == _OPTIONS["vs"] then
        return true
    end
    return false
end

function isOrbis()
    if "ps4" == _OPTIONS["gcc"] then
        return true
    end
    return false
end

function isUNIX() -- Technically PS4 is UNIX.
    if not isWindows() and not isDurango() and not isOrbis() then
        return true
    end
    return false
end

solution "Clockwork"
 
    configurations {
        "Release",
        "Debug"
    }

    platforms { 
        "x32",
        "x64",
        "Native"
    }

    dofile "toolchain.lua"
    toolchain()

    startproject "Urho3DPlayer"

    dofile "Clockwork.lua"
    Clockwork_Project()

    dofile "ClockworkPlayer.lua"
    ClockworkPlayer_Project()   

    dofile "FreeType.lua"
    FreeType_Project()

    dofile "Bullet.lua"
    Bullet_Project()

    dofile "Box2D.lua"
    Box2D_Project()    

    dofile "PugiXml.lua"
    PugiXml_Project()

    dofile "RecastNavigation.lua"
    RecastNavigation_Project()

    dofile "StanHull.lua"
    StanHull_Project()

    dofile "LZ4.lua"
    LZ4_Project()

    dofile "JO.lua"
    JO_Project()

    dofile "Assimp.lua"
    Assimp_Project()

    dofile "Civetweb.lua"
    Civetweb_Project()

    dofile "kNet.lua"
    kNet_Project()

    dofile "SDL.lua"
    SDL_Project()

    dofile "AngelScript.lua"
    AngelScript_Project()

    dofile "LibCpuid.lua"
    LibCpuid_Project()
