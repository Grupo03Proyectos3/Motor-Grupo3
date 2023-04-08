#pragma once
#ifndef __PHYSICS_SYSTEM_H__
#define __PHYSICS_SYSTEM_H__

#include "../ECS/System.h"
#include <vector>

class btBroadphaseInterface;
class btBroadphasePair;
class btCollisionConfiguration;
class btCollisionDispatcher;
class btCollisionShape;
class btConstraintSolver;
class btDiscreteDynamicsWorld;
class btDispatcherInfo;
class btGhostObject;
class btRigidBody;
class btTransform;
class btPersistentManifold;
class btManifoldPoint;

class OgreDebugDrawer;

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
     * @brief Removes t_rb from bullet's physics world
     *
     * The parameter is removed from the physics world
     *
     * @param[in] t_rb btRigidBody* to be removed from the game
     * @return
     */
    void removeRigidBody(btRigidBody* t_rb);

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
    
    /**
     * @brief Controla la colisión de objetos del mundo físico de bullet
     *
     * Llamada cuando dos objetos del mundo físico de bullet estén en contacto. 
     * Avisa al sistema de scripting para llamar a las funciones definidas por el desarrollador.
     * Tras ello delega en bullet para que maneje la colisión.
     *
     * @param[in] t_collisionPair 
     * @param[in] t_dispatcher
     * @param[in] t_dispatchInfo
     */
    //static void onCollisionStay(btBroadphasePair& t_collisionPair, btCollisionDispatcher& t_dispatcher, const btDispatcherInfo& t_dispatchInfo);
    static bool onCollisionStay(btManifoldPoint& cp, void* body0, void* body1);
    static void onCollisionEnter(btPersistentManifold* const& manifold);
    static void onCollisionExit(btPersistentManifold* const& manifold);

  private:
    btDiscreteDynamicsWorld* m_world = nullptr;
    btCollisionDispatcher* m_dispatcher = nullptr;
    btConstraintSolver* m_solver = nullptr;
    btCollisionConfiguration* m_collision_config = nullptr;
    // BroadphaseInterface sirve para identificar pares de objetos que podrían colisionar entre sí
    btBroadphaseInterface* m_broadphase = nullptr;
    // Guardamos las formas para eliminarlas después
    btAlignedObjectArray<btCollisionShape*>* m_collision_shapes;

    OgreDebugDrawer* m_debug_drawer = nullptr;
};

#endif
