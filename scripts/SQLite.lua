-- Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
-- See License.txt in the project root for license information.

function SQLite_Project()
    group "Libs"
    project "SQLite"
        targetname "SQLite"
        kind "StaticLib"
        language "C++"
        prepareProject("SQLite", "../lib")

        defines {
            "SQLITE_USE_URI=1",
            "SQLITE_ENABLE_COLUMN_METADATA",
            "SQLITE_SOUNDEX",
        }

        files { "../Source/ThirdParty/SQLite/src/sqlite3.c", "../Source/ThirdParty/SQLite/src/*.h" }

        vpaths { ["*"] = "../Source/ThirdParty/SQLite/src/" }

    group "Tools"
    project "isql"
        targetname "isql"
        kind "ConsoleApp"
        language "C++"
        prepareProject("isql", "../bin")

        defines {
            "SQLITE_USE_URI=1",
            "SQLITE_ENABLE_COLUMN_METADATA",
            "SQLITE_SOUNDEX",
        }

        files { "../Source/ThirdParty/SQLite/src/*.*" }

        vpaths { ["*"] = "../Source/ThirdParty/SQLite/src/" }   
end
