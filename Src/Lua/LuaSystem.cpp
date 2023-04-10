#include "LuaSystem.h"

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

#include "ECS/GameObject.h"
#include "ECS/Manager.h"
#include <ECS/Components.h>
#include <LuaBridge\LuaBridge.h>
// AUDIO
#include "Audio/AudioSystem.h"
// UI
#include "UI/UISystem.h"
// RENDER
#include "Render/Animator.h"
#include "Render/ParticleSystem.h"
#include "Render/RenderSystem.h"
// PHYSICS
#include "Physics/PhysicsSystem.h"
#include "Physics/RigidBody.h"
// BASE
#include "BehaviourScript.h"
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
    createFlamingoFunctions();
    readScript("camara");
    readScript("luces");
}

void Flamingo::LuaSystem::update(float t_delta_time)
{
    // TO DO : CHANGE TO SCRIPT GROUP
    for (auto game_object : m_mngr->getEntities(ecs::GROUP_EXAMPLE))
    {
        auto bs = m_mngr->getComponent<BehaviourScript>(game_object);
        if (bs)
        {
            bs->update();
        }
    }
}

void Flamingo::LuaSystem::recieve(const Message& t_m)
{
    switch (t_m.id)
    {
        case MSG_COLLISION_STAY:
        {
            // Si alguno de los GameObjects implicados en la colisión tiene BehaviourScript,
            // se llama a su OnCollisionStay() para ejecutar la acción determinada por el usuario.
            if (auto bsCmp = m_mngr->getComponent<BehaviourScript>(t_m.collision.obj1))
            {
                bsCmp->onCollisionStay(t_m.collision.obj2);
            }

            if (auto bsCmp = m_mngr->getComponent<BehaviourScript>(t_m.collision.obj2))
            {
                bsCmp->onCollisionStay(t_m.collision.obj1);
            }

            break;
        }
        case MSG_COLLISION_ENTER:
        {
            if (auto bsCmp = m_mngr->getComponent<BehaviourScript>(t_m.collision.obj1))
            {
                bsCmp->onCollisionEnter(t_m.collision.obj2);
            }

            if (auto bsCmp = m_mngr->getComponent<BehaviourScript>(t_m.collision.obj2))
            {
                bsCmp->onCollisionEnter(t_m.collision.obj1);
            }

            break;
        }
        case MSG_COLLIISION_EXIT:
        {
            if (auto bsCmp = m_mngr->getComponent<BehaviourScript>(t_m.collision.obj1))
            {
                bsCmp->onCollisionExit(t_m.collision.obj2);
            }

            if (auto bsCmp = m_mngr->getComponent<BehaviourScript>(t_m.collision.obj2))
            {
                bsCmp->onCollisionExit(t_m.collision.obj1);
            }

            break;
        }
        default:
            break;
    }
}

lua_State* Flamingo::LuaSystem::getLuaState()
{
    return lua_state;
}

void Flamingo::LuaSystem::readScript(const std::string& t_name)
{
    std::string path = PATH_PREFIX + t_name + FILE_EXTENSION;
    // Cargar el script de lua
    int fd = luaL_dofile(lua_state, path.c_str());
    // Comprobar si ha fallado
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
    luabridge::LuaRef fun = getFromLua(t_name);
    fun();
}

void Flamingo::LuaSystem::addIntToLua(int var, std::string name)
{
    lua_pushinteger(lua_state, var);
    lua_setglobal(lua_state, name.c_str());
}

void Flamingo::LuaSystem::addNumToLua(float var, std::string name)
{
    lua_pushnumber(lua_state, var);
    lua_setglobal(lua_state, name.c_str());
}

void Flamingo::LuaSystem::addBooleanToLua(bool var, std::string t_name)
{
    lua_pushboolean(lua_state, (int)var);
    lua_setglobal(lua_state, t_name.c_str());
}

void Flamingo::LuaSystem::addColorToLua(SColor t_color_param, std::string t_var_name)
{
    luabridge::push(lua_state, t_color_param);
    lua_setglobal(lua_state, t_var_name.c_str());
}

void Flamingo::LuaSystem::addVector3ToLua(SVector3 t_vec_param, std::string t_var_name)
{
    luabridge::push(lua_state, t_vec_param);
    lua_setglobal(lua_state, t_var_name.c_str());
}

void Flamingo::LuaSystem::addTransSpaceToLua(Camera::transformSpace t_trs, std::string t_var_name)
{
    luabridge::push(lua_state, t_trs);
    lua_setglobal(lua_state, t_var_name.c_str());
}

void Flamingo::LuaSystem::addPolygonModeToLua(Camera::polygonMode t_pm, std::string t_var_name)
{
    luabridge::push(lua_state, t_pm);
    lua_setglobal(lua_state, t_var_name.c_str());
}

void Flamingo::LuaSystem::addLightTypeToLua(Light::lightType t_type, std::string t_var_name)
{
    luabridge::push(lua_state, t_type);
    lua_setglobal(lua_state, t_var_name.c_str());
}

void Flamingo::LuaSystem::addCameraToLua(Camera* t_cam, std::string t_var_name)
{
    luabridge::push(lua_state, t_cam);
    lua_setglobal(lua_state, t_var_name.c_str());
}

void Flamingo::LuaSystem::addLightToLua(Light* t_light, std::string t_var_name)
{
    luabridge::push(lua_state, t_light);
    lua_setglobal(lua_state, t_var_name.c_str());
}

void Flamingo::LuaSystem::addMeshRendererToLua(MeshRenderer* t_mr, std::string t_var_name)
{
    luabridge::push(lua_state, t_mr);
    lua_setglobal(lua_state, t_var_name.c_str());
}

void Flamingo::LuaSystem::createSystemFuntions()
{
    // SceneManager
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<Flamingo::SceneManager>("SceneManager")
        /*.addStaticFunction("getSceneManager", &SceneManager::getInstance)*/
        .addFunction("createScene", (&Flamingo::SceneManager::createScene))
        .addFunction("deleteScene", (&Flamingo::SceneManager::delScene))
        .addFunction("getCurrentScene", (&Flamingo::SceneManager::getSceneActive))
        .addFunction("setCurrentScene", (&Flamingo::SceneManager::setSceneActive))
        .endClass();

    // AudioSystem
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<AudioSystem>("AudioSystem")
        .addFunction("play", (&AudioSystem::playAudio))
        .addFunction("setMusicVolume", (&AudioSystem::setMusicVolume))
        .addFunction("setFxVolume", (&AudioSystem::setSoundEffectsVolume))
        .endClass();
    // RenderSystem
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<RenderSystem>("RenderSystem")
        .endClass();
    // ParticleSystem
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<Flamingo::ParticleSystem>("ParticleSystem")
        .endClass();
    // PhysicsSystem
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<PhysicsSystem>("PhysicsSystem")
        .addFunction("addRigidBody", (&PhysicsSystem::addRigidBody))
        .addFunction("removeRigidBody", (&PhysicsSystem::removeRigidBody))
        .endClass();
    // UISystem
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<Flamingo::UISystem>("UISystem")
        .addFunction("changeScreenSize", (&UISystem::chageScreenSize))
        .endClass();
    // Manager
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<ecs::Manager>("Manager")
        .addStaticFunction("getSceneManager", &ecs::Manager::instance)
        .addFunction("addGameObject", (&ecs::Manager::addGameObject))
        .addFunction("addComponent", (&ecs::Manager::addComponent<Camera>))
        .addFunction("addComponent", (&ecs::Manager::addComponent<Light>))
        .addFunction("addComponent", (&ecs::Manager::addComponent<MeshRenderer>))
        .addFunction("addComponent", (&ecs::Manager::addComponent<Transform>))
        .addFunction("addComponent", (&ecs::Manager::addComponent<RigidBody>))
        .addFunction("addComponent", (&ecs::Manager::addComponent<PlayerController>))
        .addFunction("addSystem", (&ecs::Manager::addSystem<RenderSystem>))
        .addFunction("addSystem", (&ecs::Manager::addSystem<PhysicsSystem>))
        //.addFunction("addSystem", (&ecs::Manager::addSystem<Flamingo::ParticleSystem>))
        .addFunction("addSystem", (&ecs::Manager::addSystem<AudioSystem>))
        .addFunction("addSystem", (&ecs::Manager::addSystem<UISystem>))
        .addFunction("getComponent", (&ecs::Manager::getComponent<Camera>))
        .addFunction("getComponent", (&ecs::Manager::getComponent<Light>))
        .addFunction("getComponent", (&ecs::Manager::getComponent<MeshRenderer>))
        .addFunction("getComponent", (&ecs::Manager::getComponent<Transform>))
        .addFunction("getComponent", (&ecs::Manager::getComponent<RigidBody>))
        .addFunction("getComponent", (&ecs::Manager::getComponent<PlayerController>))
        .addFunction("getEntities", (&ecs::Manager::getEntities))
        .addFunction("getHandler", (&ecs::Manager::getHandler))
        .addFunction("getSystem", (&ecs::Manager::getSystem<AudioSystem>))
        .addFunction("getSystem", (&ecs::Manager::getSystem<RenderSystem>))
        //.addFunction("getSystem", (&ecs::Manager::getSystem<Flamingo::ParticleSystem>))
        .addFunction("getSystem", (&ecs::Manager::getSystem<PhysicsSystem>))
        .addFunction("getSystem", (&ecs::Manager::getSystem<UISystem>))
        .addFunction("hasComponent", (&ecs::Manager::hasComponent<Camera>))
        .addFunction("hasComponent", (&ecs::Manager::hasComponent<MeshRenderer>))
        .addFunction("hasComponent", (&ecs::Manager::hasComponent<Light>))
        .addFunction("hasComponent", (&ecs::Manager::hasComponent<Transform>))
        .addFunction("hasComponent", (&ecs::Manager::hasComponent<RigidBody>))
        .addFunction("hasComponent", (&ecs::Manager::hasComponent<PlayerController>))
        .addFunction("isAlive", (&ecs::Manager::isAlive))
        .addFunction("setAlive", (&ecs::Manager::setAlive))
        .addFunction("removeComponent", (&ecs::Manager::removeComponent<Camera>))
        .addFunction("removeComponent", (&ecs::Manager::removeComponent<Light>))
        .addFunction("removeComponent", (&ecs::Manager::removeComponent<MeshRenderer>))
        .addFunction("removeComponent", (&ecs::Manager::removeComponent<Transform>))
        .addFunction("removeComponent", (&ecs::Manager::removeComponent<RigidBody>))
        .addFunction("removeComponent", (&ecs::Manager::removeComponent<PlayerController>))
        .addFunction("removeSystem", (&ecs::Manager::removeSystem<AudioSystem>))
        .addFunction("removeSystem", (&ecs::Manager::removeSystem<UISystem>))
        .addFunction("removeSystem", (&ecs::Manager::removeSystem<RenderSystem>))
        //.addFunction("removeSystem", (&ecs::Manager::removeSystem<Flamingo::ParticleSystem>))
        .addFunction("removeSystem", (&ecs::Manager::removeSystem<PhysicsSystem>))
        .addFunction("setAlive", (&ecs::Manager::setAlive))
        .addFunction("setHandler", (&ecs::Manager::setHandler))
        .endClass();
}

void Flamingo::LuaSystem::createComponetsFuntions()
{
    // RENDER
    //
    // Camara
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<Camera>("Camera")                                                       // Aunque sea un struct en lua se pone como clase (beginClass), esta en el manual de luabridge
        .addFunction("lookAt", (&Camera::lookAt))                                           // Funciona
        .addFunction("setFarClipDistance", (&Camera::setFarClipDistance))                   // Funciona
        .addFunction("setViewPortBackgroundColour", (&Camera::setViewPortBackgroundColour)) // Funciona
        .addFunction("setNearClipDistance", (&Camera::setNearClipDistance))                 // Funciona
        .addFunction("pith", (&Camera::pitch))                                              // Funciona
        .addFunction("roll", (&Camera::roll))                                               // Funciona
        .addFunction("yaw", (&Camera::yaw))                                                 // Funciona
        .addFunction("setPolygonMode", (&Camera::setPolygonMode))                           // Funciona
        .addFunction("setAutoAspectRatio", (&Camera::setAutoAspectRatio))                   // Funciona
        .endClass();
    // Light
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<Light>("Light")
        .addFunction("setType", (&Light::setType)) // Funciona
        .addFunction("setAttenuation", (&Light::setAttenuation))
        .addFunction("setCastShadows", (&Light::setCastShadows))                       // Funciona
        .addFunction("setDiffuseColour", (&Light::setDiffuseColour))                   // Funciona
        .addFunction("setSpecularColour", (&Light::setSpecularColour))                 // Funciona
        .addFunction("setDirection", (&Light::setDirection))                           // Funciona
        .addFunction("setShadowFarClipDistance", (&Light::setShadowFarClipDistance))   // Funciona
        .addFunction("setShadowFarDistance", (&Light::setShadowFarDistance))           // Funciona
        .addFunction("setShadowNearClipDistance", (&Light::setShadowNearClipDistance)) // Funciona
        // SpotLight
        .addFunction("setSpotlightFalloff", (&Light::setSpotlightFalloff))                   // Funciona
        .addFunction("setSpotlightInnerAngle", (&Light::setSpotlightInnerAngle))             // Funciona
        .addFunction("setSpotlightOuterAngle", (&Light::setSpotlightOuterAngle))             // Funciona
        .addFunction("setSpotlightNearClipDistance", (&Light::setSpotlightNearClipDistance)) // Funciona
        .addFunction("setSpotlightRange", (&Light::setSpotlightRange))
        .endClass();
    // MeshRenderer
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<MeshRenderer>("MeshRenderer")
        .addFunction("setMaterial", (&MeshRenderer::changeMaterial))
        .addFunction("onEnable", (&MeshRenderer::onEnable))
        .addFunction("onDisable", (&MeshRenderer::onDisable))
        .addFunction("attachObjectToBone", (&MeshRenderer::attachObjectToBone))
        //.addFunction("detachObjectFromBone", (&MeshRenderer::detachObjectFromBone))
        .endClass();
    // Animator
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<Animator>("Animator")
        .addFunction("createAnimation", (&Animator::createAnimation))
        .addFunction("setAnimation", (&Animator::setAnimation))
        .addFunction("createFrame", (&Animator::setFrameAnimation))
        .endClass();

    // PHYSICS
    //
    // RigidBody
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

    // BASE
    //
    // Transform
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

void Flamingo::LuaSystem::createFlamingoFunctions()
{
    // SColor
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<SColor>("SColor")
        .addFunction("setColor", (&SColor::setColor))
        .endClass();
    // SVector3
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<SVector3>("SVector3")
        .addFunction("setVector3", (&SVector3::setVector3))
        .addFunction("getMagnitude", (&SVector3::magnitude))
        .endClass();
    // Camera Transfom Space
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<Camera::transformSpace>("transformSpace")
        .endClass();
    // Camera Polygon Mode
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<Camera::polygonMode>("polygonMode")
        .endClass();
    // Light Type
    luabridge::getGlobalNamespace(lua_state)
        .beginClass<Light::lightType>("lightType")
        .endClass();

    luabridge::getGlobalNamespace(lua_state)
        .beginClass<GameObject>("GameObject")
        .endClass();
}

luabridge::LuaRef Flamingo::LuaSystem::getFromLua(std::string t_name)
{
    return luabridge::getGlobal(lua_state, t_name.c_str());
}
