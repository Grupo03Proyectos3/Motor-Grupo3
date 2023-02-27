#pragma once
#ifndef __PHYSICS_SYSTEM_H__
#define __PHYSICS_SYSTEM_H__

#include "../ECS/System.h"

class btRigidBody;
class btDiscreteDynamicsWorld;
class btDispatcher;
class btConstraintSolver;
class btCollisionConfiguration;
class btBroadphaseInterface;

class btTransform;
class btCollisionShape;
class btGhostObject;

class PhysicsSystem : public ecs::System
{
  public:
    __SYSTEM_ID_DECL__(ecs::_sys_PHYSICS)

    PhysicsSystem();
    virtual ~PhysicsSystem();

    void recieve(const Message&) override;
    void initSystem() override;
    void update(float t_delta_time) override;

    void addRigidBody(btRigidBody* t_rb);
    btRigidBody* createRigidBody(btTransform* t_transform, btCollisionShape* t_shape, const float& t_mass);
    
  private:
    btDiscreteDynamicsWorld* m_world = nullptr;
    btDispatcher* m_dispatcher = nullptr;
    btConstraintSolver* m_solver = nullptr;
    btCollisionConfiguration* m_collision_config = nullptr;
    // BroadphaseInterface sirve para identificar pares de objetos que podrían colisionar entre sí
    btBroadphaseInterface* m_broadphase = nullptr;
};

#endif
