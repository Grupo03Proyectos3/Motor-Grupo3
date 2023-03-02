#pragma once
#ifndef __RIGID_BODY_H__
#define __RIGID_BODY_H__

#include "ECS/Entity.h"
#include "ECS/Manager.h"


class btVector3;
class btQuaternion;
class btTransform;
class btRigidBody;
class btGhostObject;
class btCollisionShape;
class btCollisionObject;

struct RigidBody : public ecs::Component
{
  public:
    __SYSTEM_ID_DECL__(ecs::_cmp_RIGID_BODY)

    RigidBody();
    RigidBody(float t_mass, bool t_trigger, bool t_static);
    virtual ~RigidBody();

    virtual void initComponent();

    void setMass(const float& t_mass);
    void setTrigger(bool t_trigger);
    void setStatic(bool t_static);
    // NOTE : We may need to add these methods with btVector3
    //void setLinearVelocity(const SVector3& t_velocity);
    //void setAngularVelocity(const SVector3& t_velocity);

    inline float getMass() const { return m_mass; };
    inline bool isTrigger() const { return m_trigger; };
    inline bool isStatic() const { return m_static; };
    //SVector3 getLinearVelocity() const;
    //SVector3 getAngularVelocity() const;

  private:
    btRigidBody* m_rigid_body = nullptr;       // rigidbody de Bullet
    btTransform* m_bullet_transform = nullptr; // transform de bullet

    float m_mass = 1.0f;
    bool m_trigger = false;
    bool m_static = false;

    // la velocidad va en el btRigidBody
};

#endif
