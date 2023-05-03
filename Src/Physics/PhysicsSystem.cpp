#include "PhysicsSystem.h"

#include <Ogre.h>

#include <LinearMath/btIDebugDraw.h>
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>

#include "ECS/GameObject.h"
#include "ECS/Manager.h"
#include "FlamingoBase/Transform.h"
#include "Render/DebugDrawer.h"
#include "Render/RenderSystem.h"
#include "RigidBody.h"

namespace Flamingo
{
    PhysicsSystem::PhysicsSystem()
    {
        m_group = GROUP_PHYSICS;
    }

    PhysicsSystem::~PhysicsSystem()
    {
        if (m_world != nullptr)
        {
            // cleanup in the reverse order of creation/initialization

            // Borrar constraints (si hubiera)
            int numConstraints = m_world->getNumConstraints();
            for (int i = 0; i < numConstraints; i++)
            {
                btTypedConstraint* constraint = m_world->getConstraint(i);
                m_world->removeConstraint(constraint);
                delete constraint;
            }

            // Borrar cada RigidBody
            int i;
            for (i = m_world->getNumCollisionObjects() - 1; i >= 0; i--)
            {
                btCollisionObject* obj = m_world->getCollisionObjectArray()[i];
                btRigidBody* body = btRigidBody::upcast(obj);
                if (body && body->getMotionState())
                    delete body->getMotionState();
                m_world->removeCollisionObject(obj);
                delete obj;
            }

            /*      for (auto rb : m_rigid_bodies)
                  {
                      delete rb;
                  }*/

            // delete collision shapes
            for (unsigned int j = 0; j < m_collision_shapes->size(); j++)
            {
                btCollisionShape* shape = (*m_collision_shapes)[j];
                delete shape;
            }
            m_collision_shapes->clear();
            delete m_collision_shapes;
            m_collision_shapes = nullptr;

            delete m_world;
            m_world = nullptr;
        }
        if (m_solver != nullptr)
        {
            delete m_solver;
            m_solver = nullptr;
        }
        if (m_broadphase)
        {
            delete m_broadphase;
            m_broadphase = nullptr;
        }
        if (m_dispatcher != nullptr)
        {
            delete m_dispatcher;
            m_dispatcher = nullptr;
        }
        if (m_collision_config != nullptr)
        {
            delete m_collision_config;
            m_collision_config = nullptr;
        }

        if (m_debug_drawer != nullptr)
        {
            delete m_debug_drawer;
            m_debug_drawer = nullptr;
        }
    }

    void PhysicsSystem::recieve(const Message& t_m)
    {
        switch (t_m.id)
        {
            case MSG_TRANSFORM_MOVE:
            {
                if (t_m.entity_affected == nullptr)
                    return;

                auto rb = m_mngr->getComponent<RigidBody>(t_m.entity_affected);

                if (rb == NULL)
                    return;

                rb->setPosition(SVector3(t_m.vector.x, t_m.vector.y, t_m.vector.z));
                break;
            }
            case MSG_TRANSFORM_TRANSLATE:
            {
                if (t_m.entity_affected == nullptr)
                    return;

                auto rb = m_mngr->getComponent<RigidBody>(t_m.entity_affected);

                if (rb == NULL)
                    return;

                rb->setPosition(rb->getPosition() + SVector3(t_m.vector.x, t_m.vector.y, t_m.vector.z));
                break;
            }
            case MSG_TRANSFORM_ROTATE:
            {
                if (t_m.entity_affected == nullptr)
                    return;

                auto rb = m_mngr->getComponent<RigidBody>(t_m.entity_affected);

                if (rb == NULL)
                    return;

                rb->setRotation(SQuaternion(t_m.quaternion.x, t_m.quaternion.y, t_m.quaternion.z, t_m.quaternion.w));
                break;
            }
            case MSG_GAME_OBJECT_ACTIVE_CHANGED:
            {
                auto game_object = t_m.gameObejctChangeActive.object_changed;
                auto rb = m_mngr->getComponent<RigidBody>(game_object);
                if (rb)
                {
                    if (t_m.gameObejctChangeActive.mode)
                    {
                        addRigidBody(rb->getBtRigidBody());
                    }
                    else
                    {
                        removeRigidBody(rb->getBtRigidBody());
                    }
                }
                break;
            }
            case MSG_TRANSFORM_SCALING:
            {
                if (t_m.entity_affected == nullptr)
                    return;

                auto rb = m_mngr->getComponent<RigidBody>(t_m.entity_affected);

                if (rb == NULL)
                    return;

                // rb->setScale({t_m.vector.x, t_m.vector.y, t_m.vector.z});
                break;
            }
            default:
                break;
        }
    }

    void PhysicsSystem::initSystem()
    {
        m_collision_shapes = new btAlignedObjectArray<btCollisionShape*>();
        m_collision_config = new btDefaultCollisionConfiguration();
        m_dispatcher = new btCollisionDispatcher(m_collision_config);

        // Callbacks de las colisiones
        // m_dispatcher->setNearCallback(onCollisionStay);
        gContactStartedCallback = onCollisionEnter;
        gContactEndedCallback = onCollisionExit;
        gContactProcessedCallback = onCollisionStay;

        m_broadphase = new btDbvtBroadphase();

        // Tipo por defecto de solver
        btSequentialImpulseConstraintSolver* sol = new btSequentialImpulseConstraintSolver;
        m_solver = sol;

        m_world = new btDiscreteDynamicsWorld(m_dispatcher, m_broadphase, m_solver, m_collision_config);

        // Optional : set gravity to a certain value, plus other characteristics we need
        // m_world->setGravity();

        auto render_sys = m_mngr->getSystem<RenderSystem>();

        m_debug_drawer = new OgreDebugDrawer(FlamingoSceneManager().getSceneActive()->getSceneManger(), render_sys->getOgreRoot());
        m_debug_drawer->setDebugMode(btIDebugDraw::DBG_DrawWireframe | btIDebugDraw::DBG_DrawAabb);
        m_world->setDebugDrawer(m_debug_drawer);

        SetDebugMode(true);
    }

    void PhysicsSystem::update(float t_delta_time)
    {
        for (auto game_object : m_mngr->getEntities(GROUP_PHYSICS))
        {
            if (game_object != nullptr && game_object->getActive())
            {
                auto rb = m_mngr->getComponent<RigidBody>(game_object);
                if (rb)
                {
                    rb->getBtRigidBody()->setDeactivationTime(0);
                }
            }
        }

        if (m_world)
        {
            m_world->stepSimulation(t_delta_time);

            if (m_debug_enabled)
            {
                m_world->getDebugDrawer()->clearLines();
                m_world->debugDrawWorld();
            }
        }
    }

    void PhysicsSystem::addRigidBody(btRigidBody* t_rb)
    {
        m_world->addRigidBody(t_rb);
    }

    void PhysicsSystem::removeRigidBody(btRigidBody* t_rb)
    {
        if (t_rb != nullptr)
        {
            removeShape(t_rb->getCollisionShape());

            m_world->removeRigidBody(t_rb);
        }
    }

    btRigidBody* PhysicsSystem::createRigidBody(btTransform* t_transform, btCollisionShape* t_shape, const float& t_mass)
    {
        m_collision_shapes->push_back(t_shape);

        // Crea el Rigidbody a partir de:
        //- Un MotionState (interno de Bullet)
        //- Un ConstructionInfo (interno de Bullet)

        btDefaultMotionState* state = new btDefaultMotionState(*t_transform);

        btVector3 localInertia(0, 0, 0);

        // TO DO Poner masa 0 a los cinemáticos
        if (t_mass != 0.0f)
            t_shape->calculateLocalInertia(t_mass, localInertia);

        btRigidBody::btRigidBodyConstructionInfo cInfo(t_mass, state, t_shape, localInertia);

        btRigidBody* body = new btRigidBody(cInfo);

        body->setUserIndex(1);
        return body;
    }

    void PhysicsSystem::onCollisionEnter(btPersistentManifold* const& manifold)
    {
        RigidBody* rb1 = static_cast<RigidBody*>(manifold->getBody0()->getUserPointer());
        RigidBody* rb2 = static_cast<RigidBody*>(manifold->getBody1()->getUserPointer());
        if (rb1 && rb2)
        {
            Message m;
            m.id = MSG_COLLISION_ENTER;

            m.collision.obj1 = rb1->gameObject();
            m.collision.obj2 = rb2->gameObject();
            Manager::instance()->send(m);
        }
    }

    void PhysicsSystem::onCollisionExit(btPersistentManifold* const& manifold)
    {
        RigidBody* rb1 = static_cast<RigidBody*>(manifold->getBody0()->getUserPointer());
        RigidBody* rb2 = static_cast<RigidBody*>(manifold->getBody1()->getUserPointer());
        if (rb1 && rb2)
        {
            Message m;
            m.id = MSG_COLLIISION_EXIT;

            m.collision.obj1 = rb1->gameObject();
            m.collision.obj2 = rb2->gameObject();
            Manager::instance()->send(m);
        }
    }

    void PhysicsSystem::SetDebugMode(bool t_mode)
    {
        m_debug_enabled = t_mode;
    }

    bool PhysicsSystem::GetDebugMode()
    {
        return m_debug_enabled;
    }

    void PhysicsSystem::removeShape(btCollisionShape* t_shape)
    {
        int index = m_collision_shapes->findLinearSearch(t_shape);
        if (index >= 0)
        {
            m_collision_shapes->removeAtIndex(index);
            //delete t_shape;
        }
    }

    bool PhysicsSystem::onCollisionStay(btManifoldPoint& cp, void* body0, void* body1)
    {
        // Obtener los dos objetos implicados en la colisión
        btCollisionObject* obj1 = static_cast<btCollisionObject*>(body0);
        btCollisionObject* obj2 = static_cast<btCollisionObject*>(body1);
        // Comprobar si los dos objetos son rigid bodies
        RigidBody* rigidBody1 = static_cast<RigidBody*>(obj1->getUserPointer());
        RigidBody* rigidBody2 = static_cast<RigidBody*>(obj2->getUserPointer());

        if (rigidBody1 && rigidBody2)
        {
            //   std::cout << "Colision entre " << rigidBody1 << " y " << rigidBody2 << "\n ";

            Message m;
            m.id = MSG_COLLISION_STAY;
            // TO DO : cambiar a Grupo físico

            m.collision.obj1 = rigidBody1->gameObject();
            m.collision.obj2 = rigidBody1->gameObject();
            Manager::instance()->send(m);
        }

        return true;
    }
} // namespace Flamingo
