
#pragma once
#ifndef __LUA_VARIABLES_CPP__
#define __LUA_VARIABLES_CPP__

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

#include <LuaBridge\LuaBridge.h>
#include <string>

    template <typename T>
    void addVarToLua(T t_var, std::string t_name, lua_State* t_lua_state)
    {
        luabridge::push(t_lua_state, t_var);
        lua_setglobal(t_lua_state, t_name.c_str());
    }

#endif