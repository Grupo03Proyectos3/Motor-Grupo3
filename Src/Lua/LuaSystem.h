#pragma once
#ifndef __LUA_SYSTEM_H__
#define __LUA_SYSTEM_H__

#include "ECS/System.h"

class lua_State;

namespace Flamingo
{
    class LuaSystem : public ecs::System
    {
      public:
        __SYSTEM_ID_DECL__(ecs::_sys_LUA)

        LuaSystem(){};
        virtual ~LuaSystem(){};

        void initSystem() override;
        void update(float t_delta_time) override{};

        lua_State* getLuaState();

      private:
        lua_State* lua_state;

        void createSystemFuntions();
        void createComponetsFuntions();
    };
}
#endif