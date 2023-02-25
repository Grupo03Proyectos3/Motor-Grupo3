#pragma once
#ifndef __RIGID_BODY_H__
#define __RIGID_BODY_H__

#include "../ECS/Component.h"
#include "../ECS/Entity.h"
#include "../ECS/Manager.h"

struct RigidBody : public ecs::Component
{
  public:
    __SYSTEM_ID_DECL__(ecs::_cmp_RIGID_BODY)

    RigidBody();
    virtual ~RigidBody();

    virtual void initComponent();

  private:
    // btRigidBody* rigidbody de Bullet
    // btCollisionShape* forma del collider
    float m_mass = 1.0f;
    bool is_trigger = false;
    bool is_static = false;
};

#endif