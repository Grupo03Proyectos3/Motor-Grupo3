//#pragma once
//
//#ifndef __MI_FLAMINGO_H__
//#define __MI_FLAMINGO_H__
//
//#include "MiMotorDLL.h"
////#include <Windows.h>
////#include <chrono>
//
//
//#include <crtdbg.h>
//
//// ENTITY COMPONENT SYSTEM
//#include "ECS/Components.h"
//#include "ECS/GameObject.h"
//#include "ECS/InputHandler.h"
//#include "ECS/Manager.h"
//
//// PHYSICS
//#include "Physics/PhysicsSystem.h"
//#include "Physics/PlayerController.h"
//#include "Physics/RigidBody.h"
//
//// RENDER
//#include "Render/Animator.h"
//#include "Render/Light.h"
//#include "Render/MeshRenderer.h"
//#include "Render/ParticleSystem.h"
//#include "Render/RenderSystem.h"
//
//// LUA
//#include "Lua/LuaSystem.h"
//
//// BASE
//#include "FlamingoBase/SceneManager.h"
//#include "FlamingoBase/Transform.h"
//
//// UTILS
//#include "FlamingoUtils/Timer.h"
//
//// EXTERNAL
//#include <OgreParticleSystem.h>
//#include <OgreRoot.h> // MEMORY LEAK
//#include <fmod.h>
//
//// C++
//#include <filesystem>
//#include <fstream>
//#include <iostream>
//#include <string>
//#include <vector>
//
//// Carga de mapas
//#include "FlamingoBase/MapReader.h"
//
//union SDL_Event;
//class directory_iterator;
//
//namespace Flamingo
//{
//    class __MY_FLAMINGO__ MiFlamingo
//    {
//      public:
//        MiFlamingo();
//
//        ~MiFlamingo();
//
//        void loadScene(RenderSystem* t_render_sys);
//        void prueba();
//        bool setup();
//        void loop();
//        void exit();
//
//      private:
//        ecs::Manager* m_mngr;
//        RenderSystem* render_sys;
//        PhysicsSystem* physics_sys;
//        LuaSystem* lua_system;
//
//        Timer* playerTimer;
//        unsigned long long time;
//        unsigned long long dt;
//    };
//} // namespace Flamingo
//
//#endif