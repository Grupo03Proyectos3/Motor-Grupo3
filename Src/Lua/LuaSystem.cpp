#include "LuaSystem.h"

extern "C"
{
	#include "lua.h"
	#include "lauxlib.h"
	#include "lualib.h"
}

#include <LuaBridge\LuaBridge.h>

void LuaSystem::initSystem()
{
    // create a Lua state
    lua_state = luaL_newstate();
    // load standard libs
    luaL_openlibs(lua_state);
}

lua_State* LuaSystem::getLuaState()
{
    return lua_state;
}
