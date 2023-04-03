#include "LuaSystem.h"

extern "C"
{
	#include "lua.h"
	#include "lauxlib.h"
	#include "lualib.h"
}

#include <LuaBridge\LuaBridge.h>
//AUDIO
#include "Audio/AudioSystem.h"
//UI
#include "UI/UISystem.h"
//RENDER
#include "Render/RenderSystem.h"
#include "Render/ParticleSystem.h"
#include "Render/Camera.h"
#include "Render/Light.h"
#include "Render/MeshRenderer.h"
//PHYSICS
#include "Physics/PhysicsSystem.h"
//BASE
#include "FlamingoBase/SceneManager.h"

void Flamingo::LuaSystem::initSystem()
{
    // crear un Lua state
    lua_state = luaL_newstate();
    // cargar las standard libs
    luaL_openlibs(lua_state);
    // guardarme en Lua las funciones internas de Flamingo
    createSystemFuntions();
    createComponetsFuntions();
    // LuaSystem::getInstance()->readLuaScript("engineFunctions");
}

lua_State* Flamingo::LuaSystem::getLuaState()
{
    return lua_state;
}

void Flamingo::LuaSystem::createSystemFuntions()
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
    //ParticleSystem
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<Flamingo::ParticleSystem>("ParticleSystem")
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
}

void Flamingo::LuaSystem::createComponetsFuntions()
{
    //RENDER
    // 
    //Camara
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<Camera>("Camera") //Aunque sea un struct en lua se pone como clase (beginClass), esta en el manual de luabridge
        .addFunction("lookAt", (&Camera::lookAt))
        .addFunction("setFarClipDistance", (&Camera::setFarClipDistance))
        .addFunction("setVPBackgroundColour", (&Camera::setViewPortBackgroundColour))
        .addFunction("setNearClipDistance", (&Camera::setNearClipDistance))
        .addFunction("pith", (&Camera::pitch))
        .addFunction("roll", (&Camera::roll))
        .addFunction("yaw", (&Camera::yaw))
        .addFunction("setPolygonMode", (&Camera::setPolygonMode))
        .addFunction("setAutoAspectRatio", (&Camera::setAutoAspectRatio))
        .endClass();

    //Light
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<Light>("Light")
        .addFunction("setType", (&Light::setType))
        .addFunction("setAttenuation", (&Light::setAttenuation))
        .addFunction("setCastShadows", (&Light::setCastShadows))
        .addFunction("setDiffuseColour", (&Light::setDiffuseColour))
        .addFunction("setSpecularColour", (&Light::setSpecularColour))
        .addFunction("setDirection", (&Light::setDirection))
        .addFunction("setShadowFarClipDistance", (&Light::setShadowFarClipDistance))
        .addFunction("setShadowFarDistance", (&Light::setShadowFarDistance))
        .addFunction("setShadowNearClipDistance", (&Light::setShadowNearClipDistance))
        //SpotLight
        .addFunction("setSpotlightFalloff", (&Light::setSpotlightFalloff))
        .addFunction("setSpotlightInnerAngle", (&Light::setSpotlightInnerAngle))
        .addFunction("setSpotlightOuterAngle", (&Light::setSpotlightOuterAngle))
        .addFunction("setSpotlightNearClipDistance", (&Light::setSpotlightNearClipDistance))
        .addFunction("setSpotlightRange", (&Light::setSpotlightRange))
        .endClass();

    //MeshRenderer
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<MeshRenderer>("Camera")
        .addFunction("setMaterial", (&MeshRenderer::changeMaterial))
        .addFunction("onEnable", (&MeshRenderer::onEnable))
        .addFunction("onDisable", (&MeshRenderer::onDisable))
        .addFunction("attachObjectToBone", (&MeshRenderer::attachObjectToBone))
        //.addFunction("detachObjectFromBone", (&MeshRenderer::detachObjectFromBone))
        .endClass();
}