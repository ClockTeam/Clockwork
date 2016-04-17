-- Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
-- See License.txt in the project root for license information.

function FreeType_Project()
    group "Libs"
    project "FreeType"
        targetname "FreeType"
        kind "StaticLib"
        language "C++"
        prepareProject("FreeType", "../lib")

        defines {"FT2_BUILD_LIBRARY"}

        files {
            "../Source/ThirdParty/FreeType/src/autofit/autofit.c",
            "../Source/ThirdParty/FreeType/src/base/ftbase.c",
            "../Source/ThirdParty/FreeType/src/base/ftbbox.c",
            "../Source/ThirdParty/FreeType/src/base/ftbitmap.c",
            "../Source/ThirdParty/FreeType/src/base/ftfstype.c",
            "../Source/ThirdParty/FreeType/src/base/ftgasp.c",
            "../Source/ThirdParty/FreeType/src/base/ftglyph.c",
            "../Source/ThirdParty/FreeType/src/base/ftgxval.c",
            "../Source/ThirdParty/FreeType/src/base/ftinit.c",
            "../Source/ThirdParty/FreeType/src/base/ftlcdfil.c",
            "../Source/ThirdParty/FreeType/src/base/ftmm.c",
            "../Source/ThirdParty/FreeType/src/base/ftotval.c",
            "../Source/ThirdParty/FreeType/src/base/ftpatent.c",
            "../Source/ThirdParty/FreeType/src/base/ftpfr.c",
            "../Source/ThirdParty/FreeType/src/base/ftstroke.c",
            "../Source/ThirdParty/FreeType/src/base/ftsynth.c",
            "../Source/ThirdParty/FreeType/src/base/ftsystem.c",
            "../Source/ThirdParty/FreeType/src/base/fttype1.c",
            "../Source/ThirdParty/FreeType/src/base/ftwinfnt.c",
            "../Source/ThirdParty/FreeType/src/bdf/bdf.c",
            "../Source/ThirdParty/FreeType/src/bzip2/ftbzip2.c",
            "../Source/ThirdParty/FreeType/src/cache/ftcache.c",
            "../Source/ThirdParty/FreeType/src/cff/cff.c",          
            "../Source/ThirdParty/FreeType/src/cid/type1cid.c",
            "../Source/ThirdParty/FreeType/src/gxvalid/gxvalid.c",
            "../Source/ThirdParty/FreeType/src/gzip/ftgzip.c",
            "../Source/ThirdParty/FreeType/src/lzw/ftlzw.c",
            "../Source/ThirdParty/FreeType/src/otvalid/otvalid.c",
            "../Source/ThirdParty/FreeType/src/pcf/pcf.c",
            "../Source/ThirdParty/FreeType/src/pfr/pfr.c",
            "../Source/ThirdParty/FreeType/src/psaux/psaux.c",
            "../Source/ThirdParty/FreeType/src/pshinter/pshinter.c",
            "../Source/ThirdParty/FreeType/src/psnames/psmodule.c",
            "../Source/ThirdParty/FreeType/src/raster/raster.c",
            "../Source/ThirdParty/FreeType/src/sfnt/sfnt.c",
            "../Source/ThirdParty/FreeType/src/smooth/smooth.c",
            "../Source/ThirdParty/FreeType/src/truetype/truetype.c",
            "../Source/ThirdParty/FreeType/src/type1/type1.c",
            "../Source/ThirdParty/FreeType/src/type42/type42.c",
            "../Source/ThirdParty/FreeType/src/winfonts/winfnt.c"
        }

        includedirs { "../Source/ThirdParty/FreeType/include/" }

        vpaths { ["*"] = "../Source/ThirdParty/FreeType/src/" }

        configuration {}
        strip()        
end
