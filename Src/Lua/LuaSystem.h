#pragma once
#ifndef __LUA_SYSTEM_H__
#define __LUA_SYSTEM_H__

#include "ECS/System.h"
//RENDER
#include "Render/Camera.h"
#include "Render/Light.h"
#include "Render/MeshRenderer.h"
//FLAMINGO UTILS
#include "FlamingoUtils/SColor.h" 
#include "FlamingoUtils/SVector3.h"

#include <string>

#define PATH_PREFIX "Assets/Scripts/"
#define FILE_EXTENSION ".lua"

class lua_State;

namespace luabridge
{
    class LuaRef;
    class LuaResult;
}

namespace Flamingo
{
    class LuaSystem : public ecs::System
    {
      public:
        __SYSTEM_ID_DECL__(ecs::_sys_LUA)

        LuaSystem(){};
        virtual ~LuaSystem();

        void initSystem() override;
        void update(float t_delta_time) override;

        lua_State* getLuaState();

        void readScript(const std::string& t_name);
        void callLuaFunction(std::string t_name);
        //template <class... Args>
        //void callLuaFunction(std::string name, Args&&...args);
        void addNumToLua(float var, std::string name);
        void addIntToLua(int var, std::string name);
        void addTransSpaceToLua(Camera::transformSpace t_trs, std::string t_var_name);
        void addPolygonModeToLua(Camera::polygonMode t_pm, std::string t_var_name);
        void addLightTypeToLua(Light::lightType t_type, std::string t_var_name);
        void addBooleanToLua(bool var, std::string t_name);
        void addColorToLua(SColor t_color, std::string t_var_name);
        void addVector3ToLua(SVector3 t_vec, std::string t_var_name);
        void addCameraToLua(Camera* t_cam, std::string t_var_name);
        void addLightToLua(Light* t_light, std::string t_var_name);
        void addMeshRendererToLua(MeshRenderer* t_mr, std::string t_var_name);

      private:
        lua_State* lua_state;

        void createSystemFuntions();
        void createComponetsFuntions();
        void createFlamingoFunctions();

        luabridge::LuaRef getFromLua(std::string t_name);
    };
    
} // namespace Flamingo
#endif