-- Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
-- See License.txt in the project root for license information.

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

    dofile "FreeType.lua"
    FreeType_Project()

    dofile "Bullet.lua"
    Bullet_Project()

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
