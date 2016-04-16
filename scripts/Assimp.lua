-- Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
-- See License.txt in the project root for license information.

function Assimp_Project()
    group "Libs"
    project "Assimp"
        targetname "Assimp"
        kind "StaticLib"
        language "C++"
        prepareProject("Assimp", "../lib")

        defines {
            "ASSIMP_BUILD_BOOST_WORKAROUND",
            "OPENDDLPARSER_BUILD",
            "ASSIMP_BUILD_NO_C4D_IMPORTER"
        }

        files {
            "../Source/ThirdParty/Assimp/code/BoostWorkaround/boost/*.hpp",
            "../Source/ThirdParty/Assimp/code/BoostWorkaround/boost/math/*.hpp",
            "../Source/ThirdParty/Assimp/code/BoostWorkaround/boost/tuple/*.hpp",
            "../Source/ThirdParty/Assimp/code/*.*",

            "../Source/ThirdParty/Assimp/contrib/clipper/*.cpp", "../Source/ThirdParty/Assimp/contrib/clipper/*.hpp",
            "../Source/ThirdParty/Assimp/contrib/ConvertUTF/*.c", "../Source/ThirdParty/Assimp/contrib/ConvertUTF/*.h",
            "../Source/ThirdParty/Assimp/contrib/irrXML/*.cpp", "../Source/ThirdParty/Assimp/contrib/irrXML/*.h",
            "../Source/ThirdParty/Assimp/contrib/openddlparser/code/*.cpp", "../Source/ThirdParty/Assimp/openddlparser/include/openddlparser/*.h",
            "../Source/ThirdParty/Assimp/contrib/poly2tri/poly2tri/*.*", "../Source/ThirdParty/Assimp/contrib/poly2tri/poly2tri/common/*.*", "../Source/ThirdParty/Assimp/contrib/poly2tri/poly2tri/sweep/*.*",
            "../Source/ThirdParty/Assimp/contrib/unzip/*.*",
            "../Source/ThirdParty/Assimp/contrib/zlib/*.*"
        }

        includedirs {
            "../Source/ThirdParty/Assimp/include/",
            "../Source/ThirdParty/Assimp/code/BoostWorkaround/",
            "../Source/ThirdParty/Assimp/contrib/openddlparser/include/"
        }

        vpaths { ["*"] = "../Source/ThirdParty/Assimp/" }       
end
