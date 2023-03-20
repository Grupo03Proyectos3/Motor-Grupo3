#pragma once
#ifndef __LUA_SYSTEM_H__
#define __LUA_SYSTEM_H__

extern "C"
{
	#include "lua.h"
	#include "lauxlib.h"
	#include "lualib.h"
}

#include <LuaBridge\LuaBridge.h>
#include "ECS/System.h"

class RenderSystem : public ecs::System
{

};

#endif