#include "LuaSystem.h"

extern "C"
{
	#include "lua.h"
	#include "lauxlib.h"
	#include "lualib.h"
}

#include <LuaBridge\LuaBridge.h>

#include "Audio/AudioSystem.h"
#include "UI/UISystem.h"
#include "Render/RenderSystem.h"
#include "Physics/PhysicsSystem.h"
#include "FlamingoBase/SceneManager.h"

void LuaSystem::initSystem()
{
    // crear un Lua state
    lua_state = luaL_newstate();
    // cargar las standard libs
    luaL_openlibs(lua_state);
    // guardarme en Lua las funciones internas de Flamingo
    createFuntions();
}

lua_State* LuaSystem::getLuaState()
{
    return lua_state;
}

void LuaSystem::createFuntions()
{
    //SceneManager
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<Flamingo::SceneManager>("SceneManager")
        /*.addStaticFunction("getSceneManager", &SceneManager::getInstance)*/
        .addFunction("createScene", (&Flamingo::SceneManager::createScene))
        .addFunction("deleteScene", (&Flamingo::SceneManager::delScene))
        .addFunction("getCurrentScene", (&Flamingo::SceneManager::getSceneActive))
        .addFunction("setCurrentScene", (&Flamingo::SceneManager::setSceneActive))
        .endClass();
    //AudioSystem
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<AudioSystem>("AudioSystem")
        .addFunction("play", (&AudioSystem::playAudio))
        .addFunction("setMusicVolume", (&AudioSystem::setMusicVolume))
        .addFunction("setFxVolume", (&AudioSystem::setSoundEffectsVolume))
        .endClass();
    //RenderSystem
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<RenderSystem>("RenderSystem")
        .endClass();
    //PhysicsSystem
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<PhysicsSystem>("PhysicsSystem")
        .addFunction("addRigidBody", (&PhysicsSystem::addRigidBody))
        .addFunction("removeRigidBody", (&PhysicsSystem::removeRigidBody))
        .endClass();
   //UISystem
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<Flamingo::UISystem>("UISystem")
        .endClass();

    //LuaSystem::getInstance()->readLuaScript("engineFunctions");
}