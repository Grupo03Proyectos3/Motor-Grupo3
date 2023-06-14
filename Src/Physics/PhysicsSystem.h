#pragma once
#ifndef __PHYSICS_SYSTEM_H__
#define __PHYSICS_SYSTEM_H__

#include "ECS/System.h"
#include "FlamingoExport/FlamingoAPI.h"
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

namespace Flamingo
{
    class PhysicsSystem : public System
    {
      public:
        __SYSTEM_ID_DECL__(_sys_PHYSICS)

        PhysicsSystem();
        virtual ~PhysicsSystem();

        void recieve(const Message&) override;
        void initSystem() override;
        void update(float t_delta_time) override;

        /**
         * @brief Añade un t_rb al mundo de fisica
         *
         * El parametro se añade al mundo físico y será actualizado en cada update
         * del juego
         *
         * @param[in] t_rb btRigidBody* que se añadira al juego
         * @return
         */
        void addRigidBody(btRigidBody* t_rb);

        /**
         * @brief Quitar un t_rb del mundo de fisica
         *
         * El parametro se quita del mundo físico y será actualizado en cada update
         * del juego
         *
         * @param[in] t_rb btRigidBody* que se quitara dell juego
         * @return
         */
        void removeRigidBody(btRigidBody* t_rb);

        /**
         * @brief Crea un Bullet RigidBody
         *
         * A partir de los parametros crea un Bullet RigidBody
         *
         * @param[in] t_transform Posicion, escala y rotacion del cuerpo
         * @param[in] t_shape Forma de colision del cuerpo
         * @param[in] t_mass Masa
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
         * @return bool
         */
        static bool onCollisionStay(btManifoldPoint& cp, void* body0, void* body1);
        static void onCollisionEnter(btPersistentManifold* const& manifold);
        static void onCollisionExit(btPersistentManifold* const& manifold);

        /**
         * @brief Inicializa el modo debug visual, que se podrá activar o desactivar
         *
         * Se debe llamar tras leer las escenas e inicializar el resto de sistemas, y se encarga de la creación
         * del debug drawer asociado al mundo físico de bullet
         */
        void initDebugMode();

        FLAMINGOEXPORT_API void SetDebugMode(bool t_mode);
        FLAMINGOEXPORT_API bool GetDebugMode();

        void removeShape(btCollisionShape* t_shape);

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
        bool m_debug_enabled = false;
    };
} // namespace Flamingo

#endif
