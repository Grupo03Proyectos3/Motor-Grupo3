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
#include "Render/Light.h"
#include "Render/MeshRenderer.h"
#include "Render/Animator.h"
//PHYSICS
#include "Physics/PhysicsSystem.h"
#include "Physics/RigidBody.h"
//BASE
#include "FlamingoBase/SceneManager.h"
#include "FlamingoBase/Transform.h"

Flamingo::LuaSystem::~LuaSystem()
{
    lua_close(lua_state);
}

void Flamingo::LuaSystem::initSystem()
{
    // crear un Lua state
    lua_state = luaL_newstate();
    // cargar las standard libs
    luaL_openlibs(lua_state);
    // guardarme en Lua las funciones internas de Flamingo
    createSystemFuntions();
    createComponetsFuntions();
    readScript("prueba");
}

lua_State* Flamingo::LuaSystem::getLuaState()
{
    return lua_state;
}

void Flamingo::LuaSystem::readScript(const std::string& t_name)
{
    std::string path = PATH_PREFIX + t_name + FILE_EXTENSION;
    //Cargar el script de lua
    int fd = luaL_dofile(lua_state, path.c_str());
    //Comprobar si ha fallado
    if (fd == 0)
    {
        return;
    }
    std::cerr << "[LUA ERROR] " << lua_tostring(lua_state, -1) << std::endl;
    // remove error message from Lua state
    lua_pop(lua_state, 1);
}

void Flamingo::LuaSystem::callLuaFunction(std::string t_name)
{
    luabridge::LuaRef fun = /*getFromLua(t_name)*/ luabridge::getGlobal(lua_state, t_name.c_str());
    fun();
}

void Flamingo::LuaSystem::pushBool(bool var, std::string t_name)
{
    lua_pushboolean(lua_state, (int)var);
    lua_setglobal(lua_state, t_name.c_str());
}

void Flamingo::LuaSystem::pushColorToLua(Ogre::ColourValue t_color_param, std::string t_var_name)
{
    // Uso de la funci�n push() de LuaBridge para empujar una instancia de la clase a Lua
    t_color my_color(t_color_param.r, t_color_param.g, t_color_param.b);
    luabridge::push(lua_state, my_color);
    lua_setglobal(lua_state, t_var_name.c_str());
}

void Flamingo::LuaSystem::addCameraToLua(Camera* t_cam, std::string t_var_name)
{
    luabridge::push(lua_state, t_cam);
    lua_setglobal(lua_state, t_var_name.c_str());
}

//template <class... Args>
//void Flamingo::LuaSystem::callLuaFunction(std::string name, Args&&... args)
//{
//    luabridge::LuaRef s = getFromLua(name);
//    s(args...);
//}

void Flamingo::LuaSystem::createSystemFuntions()
{
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<t_color>("t_color")
        .addConstructor<void (*)(float, float, float)>()
        .addData("r", &t_color::r)
        .addData("g", &t_color::g)
        .addData("b", &t_color::b)
        .endClass();

   

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
        .addFunction("setViewPortBackgroundColour", (&Camera::setViewPortBackgroundColour))
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
        .beginClass<MeshRenderer>("MeshRenderer")
        .addFunction("setMaterial", (&MeshRenderer::changeMaterial))
        .addFunction("onEnable", (&MeshRenderer::onEnable))
        .addFunction("onDisable", (&MeshRenderer::onDisable))
        .addFunction("attachObjectToBone", (&MeshRenderer::attachObjectToBone))
        //.addFunction("detachObjectFromBone", (&MeshRenderer::detachObjectFromBone))
        .endClass();
    //Animator
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<Animator>("Animator")
        .addFunction("createAnimation", (&Animator::createAnimation))
        .addFunction("setAnimation", (&Animator::setAnimation))
        .addFunction("createFrame", (&Animator::setFrameAnimation))
        .endClass();

    //PHYSICS
    //
    //RigidBody
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<RigidBody>("RigidBody")
        .addFunction("getAngularVelocity", (&RigidBody::getAngularVelocity))
        .addFunction("setAnimation", (&RigidBody::getLinearVelocity))
        .addFunction("getLinearVelocity", (&RigidBody::getMass))
        .addFunction("isKinematic", (&RigidBody::isKinematic))
        .addFunction("isStatic", (&RigidBody::isStatic))
        .addFunction("isTrigger", (&RigidBody::isTrigger))
        .addFunction("setAngularVelocity", (&RigidBody::setAngularVelocity))
        .addFunction("setKinematic", (&RigidBody::setKinematic))
        .addFunction("setStatic", (&RigidBody::setStatic))
        .addFunction("setTrigger", (&RigidBody::setTrigger))
        .addFunction("setLinearVelocity", (&RigidBody::setLinearVelocity))
        .addFunction("setMass", (&RigidBody::setMass))
        .endClass();

    //BASE
    //
    //Transform
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<Transform>("Transform")
        .addFunction("getPosition", (&Transform::getPosition))
        .addFunction("getRotation", (&Transform::getRotation))
        .addFunction("getScale", (&Transform::getScale))
        .addFunction("setPosition", (&Transform::setPosition))
        .addFunction("setPositionPerPhysics", (&Transform::setPositionPerPhysics))
        .addFunction("setRotation", (&Transform::setRotation))
        .addFunction("setRotationPerPhysics", (&Transform::setRotationPerPhysics))
        .addFunction("setScale", (&Transform::setScale))
        .endClass();
}

luabridge::LuaRef Flamingo::LuaSystem::getFromLua(std::string t_name)
{
    return luabridge::getGlobal(lua_state, t_name.c_str());
}
