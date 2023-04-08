#pragma once
#ifndef __BEHAVIOUR_SCRIPT_H__
#define __BEHAVIOUR_SCRIPT_H__

#include "ECS/Component.h"
#include "ECS/GameObject.h"
//
//namespace luabridge
//{
//    class LuaRef;
//    class LuaResult;
//} // namespace luabridge
//class lua_State;

struct BehaviourScript : public ecs::Component
{
  public:
    __SYSTEM_ID_DECL__(ecs::_cmp_BEHAVIOUR_SCRIPT)

    BehaviourScript();
    virtual ~BehaviourScript();

    // Clases que podrán ser overrideadas por el desarrollador, para definir a su gusto
    virtual void initValues();
    virtual void initComponent(); // == start() ?

    virtual void update();

    /**
     * @brief Se llama una vez al comienzo de collisionar con otro cuerpo 
     *
     * 
     *
     * @param[in] t_other GameObject* GameObject del cuerpo contra el que ha colisionado
     * @return
     */
    virtual void onCollisionEnter(ecs::GameObject* t_other);

    /**
     * @brief Se llama continuamente al collisionar con otro cuerpo
     *
     *
     * @param[in] t_other GameObject* GameObject del cuerpo contra el que colisiona
     * @return
     */
    virtual void onCollisionStay(ecs::GameObject* t_other);

    /**
     * @brief Se llama al salir de la colision con otro cuerpo
     *
     *
     * @param[in] t_other GameObject* GameObject del cuerpo contra el que colisiona
     * @return
     */
    virtual void onCollisionExit(ecs::GameObject* t_other);

    private:

};

#endif // !define __BEHAVIOUR_SCRIPT_H__
