#pragma once
#ifndef __PHYSICS_SYSTEM_H__
#define __PHYSICS_SYSTEM_H__

#include "../ECS/System.h"
#include <vector>

class btRigidBody;
class btDiscreteDynamicsWorld;
class btDispatcher;
class btConstraintSolver;
class btCollisionConfiguration;
class btBroadphaseInterface;
class btCollisionShape;
class btTransform;
class btCollisionShape;
class btGhostObject;

template <typename T>
class btAlignedObjectArray;

class PhysicsSystem : public ecs::System
{
  public:
    __SYSTEM_ID_DECL__(ecs::_sys_PHYSICS)

    PhysicsSystem();
    virtual ~PhysicsSystem();

    void recieve(const Message&) override;
    void initSystem() override;
    void update(float t_delta_time) override;

    /**
     * @brief Adds t_rb to bullet's physics world
     *
     * The parameter is added to the physics world for it to be updated every frame
     * within the game.
     *
     * @param[in] t_rb btRigidBody* to be added to the game
     * @return
     */
    void addRigidBody(btRigidBody* t_rb);

    /**
     * @brief Create a Bullet RigidBody
     *
     * With the given parameters, it creates a Bullet RigidBody object
     *
     * @param[in] t_transform Position, location and rotation of the body
     * @param[in] t_shape Collision shape of the body
     * @param[in] t_mass Mass value of the body
     * @return btRigidBody* object 
     */
    btRigidBody* createRigidBody(btTransform* t_transform, btCollisionShape* t_shape, const float& t_mass);
    
  private:
    btDiscreteDynamicsWorld* m_world = nullptr;
    btDispatcher* m_dispatcher = nullptr;
    btConstraintSolver* m_solver = nullptr;
    btCollisionConfiguration* m_collision_config = nullptr;
    // BroadphaseInterface sirve para identificar pares de objetos que podrían colisionar entre sí
    btBroadphaseInterface* m_broadphase = nullptr;
    // Guardamos las formas para eliminarlas después
    btAlignedObjectArray<btCollisionShape*>* m_collision_shapes;
};

#endif
