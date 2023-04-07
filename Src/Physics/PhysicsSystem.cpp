#include "PhysicsSystem.h"

#include <Ogre.h>

#include <LinearMath/btIDebugDraw.h>
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>

#include "DebugDrawer.h"
#include "ECS/GameObject.h"
#include "ECS/Manager.h"
#include "FlamingoBase/Transform.h"
#include "Render/RenderSystem.h"
#include "RigidBody.h"

PhysicsSystem::PhysicsSystem()
{
    m_group = ecs::GROUP_PHYSICS;
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
        default:
            break;
    }
}

void PhysicsSystem::initSystem()
{
    m_collision_shapes = new btAlignedObjectArray<btCollisionShape*>();
    m_collision_config = new btDefaultCollisionConfiguration();
    m_dispatcher = new btCollisionDispatcher(m_collision_config);
    m_dispatcher->setNearCallback(onCollisionStay);
    m_broadphase = new btDbvtBroadphase();
    // Tipo por defecto de solver
    btSequentialImpulseConstraintSolver* sol = new btSequentialImpulseConstraintSolver;
    m_solver = sol;

    m_world = new btDiscreteDynamicsWorld(m_dispatcher, m_broadphase, m_solver, m_collision_config);

    // Optional : set gravity to a certain value, plus other characteristics we need
    // m_world->setGravity();

    auto render_sys = m_mngr->getSystem<RenderSystem>();

    m_debug_drawer = new OgreDebugDrawer(render_sys->getSceneManager()->getSceneManager(), render_sys->getOgreRoot());
    m_debug_drawer->setDebugMode(btIDebugDraw::DBG_DrawWireframe | btIDebugDraw::DBG_DrawAabb);
    m_world->setDebugDrawer(m_debug_drawer);
}

void PhysicsSystem::update(float t_delta_time)
{
    // For each GameObject that has at least one Physics type component,
    // check for the components and update them

    for (auto game_object : m_mngr->getEntities(ecs::GROUP_EXAMPLE))
    {
        if (auto rb = m_mngr->getComponent<RigidBody>(game_object))
        {
            // TODO actualise position with Transform values --> Check if its really necessary
            /* if (rb->isKinematic())
                 rb->setPosition(m_mngr->getComponent<Transform>(game_object)->getPosition());*/

            // std::cout << "RB rotation: " << rb->getRotation().getX() << " " << rb->getRotation().getX() << " " << rb->getRotation().getX() << std::endl;
            //  rbPruebas = rb;
        }
    }

    // TO DO add forces with input/scripts

    if (m_world)
    {
        m_world->stepSimulation(t_delta_time);
        m_world->getDebugDrawer()->clearLines();
        m_world->debugDrawWorld();
    }

    // std::cout << "RB position after: " << rbPruebas->getPosition().getX() << " " << rbPruebas->getPosition().getX() << " " << rbPruebas->getPosition().getX() << std::endl;

    // std::cout << "  ---- \n";
}

void PhysicsSystem::addRigidBody(btRigidBody* t_rb)
{
    m_world->addRigidBody(t_rb);
}

void PhysicsSystem::removeRigidBody(btRigidBody* t_rb)
{
    m_world->removeRigidBody(t_rb);
}

btRigidBody* PhysicsSystem::createRigidBody(btTransform* t_transform, btCollisionShape* t_shape, const float& t_mass)
{
    m_collision_shapes->push_back(t_shape);

    // Crea el Rigidbody a partir de:
    //- Un MotionState (interno de Bullet)
    //- Un ConstructionInfo (interno de Bullet)

    btDefaultMotionState* state = new btDefaultMotionState(*t_transform);

    btVector3 localInertia(0, 0, 0);

    // TODO Poner masa 0 a los cinemáticos
    if (t_mass != 0.0f)
        t_shape->calculateLocalInertia(t_mass, localInertia);

    btRigidBody::btRigidBodyConstructionInfo cInfo(t_mass, state, t_shape, localInertia);

    btRigidBody* body = new btRigidBody(cInfo);

    body->setUserIndex(1);
    return body;
}

void PhysicsSystem::onCollisionStay(btBroadphasePair& t_collisionPair, btCollisionDispatcher& t_dispatcher, const btDispatcherInfo& t_dispatchInfo)
{
    // Obtener los dos objetos implicados en la colisión
    btCollisionObject* obj1 = static_cast<btCollisionObject*>(t_collisionPair.m_pProxy0->m_clientObject);
    btCollisionObject* obj2 = static_cast<btCollisionObject*>(t_collisionPair.m_pProxy1->m_clientObject);
    // Comprobar si los dos objetos son rigid bodies
    RigidBody* rigidBody1 = static_cast<RigidBody*>(obj1->getUserPointer());
    RigidBody* rigidBody2 = static_cast<RigidBody*>(obj2->getUserPointer());

    if (rigidBody1 && rigidBody2)
    {
     //   std::cout << "Colision entre " << rigidBody1 << " y " << rigidBody2 << "\n ";

        Message m;
        m.id = MSG_COLLISION_STAY;
        // TO DO : cambiar a Grupo físico
        /*for (auto game_object : ecs::Manager::instance()->getEntities(ecs::GROUP_EXAMPLE))
        {
            if (auto rb = ecs::Manager::instance()->getComponent<RigidBody>(game_object))
            {
                if (rb->getBtRigidBody() == rigidBody1)
                {
                    m.collision.obj1 = game_object;
                }
                else if (rb->getBtRigidBody() == rigidBody2)
                {
                    m.collision.obj2 = game_object;
                }
            }
        }*/
        m.collision.obj1 = rigidBody1->gameObject();
        m.collision.obj2 = rigidBody1->gameObject();
        ecs::Manager::instance()->send(m);
    }

    // Llamar a la función de devolución de llamada predeterminada de Bullet para manejar la colisión
    t_dispatcher.defaultNearCallback(t_collisionPair, t_dispatcher, t_dispatchInfo);
}
