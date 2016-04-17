-- Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
-- See License.txt in the project root for license information.

function AngelScript_Project()
    group "Libs"
    project "AngelScript"
        targetname "AngelScript"
        kind "StaticLib"
        language "C++"
        prepareProject("AngelScript", "../lib")

        files { "../Source/ThirdParty/AngelScript/source/*.cpp", "../Source/ThirdParty/AngelScript/source/*.h" }

        if isIOS() then
            files { "../Source/ThirdParty/AngelScript/source/as_callfunc_arm_xcode.S" }
        elseif isAndroid() then
            files { "../Source/ThirdParty/AngelScript/source/as_callfunc_arm_gcc.S" }
        end

        baseObjPath = path.join(solution().location, "obj", "AngelScript")

       -- print(configuration({"Release"}).objdir)


        --[[if isWindows() then
          --  files { "../Source/ThirdParty/AngelScript/source/as_callfunc_x64_msvc_asm.asm" }

         -- print(configuration({}).objdir)

           -- configuration { "Release" }
                custombuildtask {
                    { 
                        "../Source/ThirdParty/AngelScript/source/as_callfunc_x64_msvc_asm.asm",
                        "$(OBJDIR)" .. "/x64/Release/as_callfunc_x64_msvc_asm.obj",
                           
                        { "ml64" },
                        { "Compiling as_callfunc_x64_msvc_asm.asm...", "$(1) /nologo /c /Fo $(@) $(<)" }
                    }
                }



        end--]]

        vpaths { ["*"] = "../Source/ThirdParty/AngelScript/source/" }

        configuration {}
        strip()
end
