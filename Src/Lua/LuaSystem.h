#pragma once
#ifndef __LUA_SYSTEM_H__
#define __LUA_SYSTEM_H__

#include "ECS/System.h"
#include "Render/Camera.h"

#include <string>
#include <OgreColourValue.h>

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
        void update(float t_delta_time) override{};

        lua_State* getLuaState();

        void readScript(const std::string& t_name);
        void callLuaFunction(std::string t_name);
        //template <class... Args>
        //void callLuaFunction(std::string name, Args&&...args);
        void pushBool(bool var, std::string t_name);
        void pushColorToLua(Ogre::ColourValue t_color, std::string t_var_name);
        void addCameraToLua(Camera* t_cam, std::string t_var_name);

      private:
        lua_State* lua_state;

        void createSystemFuntions();
        void createComponetsFuntions();

        luabridge::LuaRef getFromLua(std::string t_name);
    };
    
} // namespace Flamingo

class t_color
{
  public:
    float r, g, b;
    // constructor
    t_color(float r_, float g_, float b_)
        : r(r_)
        , g(g_)
        , b(b_)
    {
    }
};
#endif