#pragma once
#ifndef __LUA_SYSTEM_H__
#define __LUA_SYSTEM_H__

#include "ECS/System.h"
#include "ECS/Manager.h"
#include "FlamingoBase/ComponentsFactory.h"
#include "FlamingoBase/PlayerControllerFactory.h"
#include "FlamingoBase/MeshRendererFactory.h"
#include "FlamingoBase/RigidbodyFactory.h"
#include "FlamingoBase/TransformFactory.h"
#include "FlamingoBase/LightFactory.h"
#include "FlamingoBase/CameraFactory.h"
#include "FlamingoBase/AnimatorFactory.h"
#include "FlamingoBase/ScriptFactory.h"
#include "FlamingoBase/SceneManager.h"
#include "Render/RenderSystem.h"

//LUA
extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

#include <LuaBridge\LuaBridge.h>
#include <unordered_map>
#include <string>

#define PATH_PREFIX "Assets/Scripts/"
#define FILE_EXTENSION ".lua"

using Data = std::unordered_map<std::string, std::string>;

class lua_State;

namespace luabridge
{
    class LuaRef;
    class LuaResult;
} // namespace luabridge

// LUA

namespace Flamingo
{
    class ScriptingSystem : public ecs::System
    {
      public:
        __SYSTEM_ID_DECL__(ecs::_sys_LUA)

        ScriptingSystem(SceneManager* t_scene_mngr);
        virtual ~ScriptingSystem();

        void initSystem() override;
        void update(float t_delta_time) override;
        void recieve(const Message& t_m) override;

        lua_State* getLuaState();

        void readScript(const std::string& t_name);
        void callLuaFunction(std::string t_name);
        //// template <class... Args>
        //// void callLuaFunction(std::string name, Args&&...args);
        //void addNumToLua(float var, std::string name);
        //void addIntToLua(int var, std::string name);
        //void addBooleanToLua(bool var, std::string t_name);
        bool loadScene(std::string t_scene, bool t_first = true);
        
        template <typename T>
        void addVarToLua(T t_var, std::string t_name)
        {
            luabridge::push(lua_state, t_var);
            lua_setglobal(lua_state, t_name.c_str());
        }

      private:
        lua_State* lua_state;
        ComponentsFactory* m_componentFactory;
        SceneManager* m_scene_mngr;
        Data m_data;
        ecs::Manager* m_mngr;

        void createSystemFuntions();
        luabridge::LuaRef getFromLua(std::string t_name);
    };
    
   //extern template void LuaSystem::addVar(Light::lightType t_var, std::string t_name);

} // namespace Flamingo


#endif