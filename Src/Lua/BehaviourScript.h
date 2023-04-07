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
    virtual void onCollisionEnter(ecs::GameObject* t_other);

    private:

};

#endif // !define __BEHAVIOUR_SCRIPT_H__
