-- Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
-- See License.txt in the project root for license information.

function Bullet_Project()
    group "Libs"
    project "Bullet"
        targetname "Bullet"
        kind "StaticLib"
        language "C++"
        prepareProject("Bullet", "../lib")

        files {
            "../Source/ThirdParty/Bullet/src/*.*",
            "../Source/ThirdParty/Bullet/src/BulletCollision/BroadphaseCollision/*.*",
            "../Source/ThirdParty/Bullet/src/BulletCollision/CollisionDispatch/*.*",
            "../Source/ThirdParty/Bullet/src/BulletCollision/CollisionShapes/*.*",
            "../Source/ThirdParty/Bullet/src/BulletCollision/Gimpact/*.*",
            "../Source/ThirdParty/Bullet/src/BulletCollision/NarrowPhaseCollision/*.*",
            "../Source/ThirdParty/Bullet/src/BulletDynamics/Character/*.*",
            "../Source/ThirdParty/Bullet/src/BulletDynamics/ConstraintSolver/*.*",
            "../Source/ThirdParty/Bullet/src/BulletDynamics/Dynamics/*.*",
            "../Source/ThirdParty/Bullet/src/BulletDynamics/Featherstone/*.*",
            "../Source/ThirdParty/Bullet/src/BulletDynamics/MLCPSolvers/*.*",
            "../Source/ThirdParty/Bullet/src/BulletDynamics/Vehicle/*.*",
            "../Source/ThirdParty/Bullet/src/BulletSoftBody/*.*",
            "../Source/ThirdParty/Bullet/src/LinearMath/*.*"
        }
        
        includedirs { "../Source/ThirdParty/Bullet/src/" }

        vpaths { ["*"] = "../Source/ThirdParty/Bullet/src/" }
end
