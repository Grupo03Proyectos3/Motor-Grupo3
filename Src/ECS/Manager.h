#pragma once
#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <array>
#include <cassert>
#include <iostream>
#include <vector>

#include <algorithm>
#include <unordered_map>

#include "Component.h"
#include "GameObject.h"
#include "SingletonECS.h"
#include "System.h"
#include "ecs.h"
#include "messages_defs.h"

namespace Flamingo
{

    /*
     * Clase para manejar las listas de GameObjects, grupos, etc.
     */
    class FLAMINGOEXPORT_API Manager
    {
      public:
        Manager();
        virtual ~Manager();

        void init();

        Manager(Manager&) = delete;
        Manager(Manager&&) = delete;
        Manager& operator=(Manager&) = delete;
        Manager& operator=(Manager&&) = delete;

        /**
         * @brief Inicializa los componentes existentes
         *
         * @return void
         */
        void initComponents();

        /**
         * @brief Añade una entidad al grupo correspondiente
         *
         * @param[in] t_vect_gId grupo al que se va a añadir
         *
         * @return GameObject*
         */
        GameObject* addGameObject(std::vector<groupId_type> t_vect_gId = {});

        void addGameObjectToGroups(GameObject* t_e, std::vector<groupId_type> t_vect_gId = {});

        /**
         * @brief Establece si el gameobject esta vivo o muerto
         *
         * @param[in] t_e gameobject al que se quiere cambiar el atributo
         * @param[in] t_alive estado al que se va a cambiar
         *
         * @return void
         */
        void setAlive(GameObject* t_e, bool t_alive);

        /**
         * @brief Devuelve si un gameobject esta vido o muerto
         *
         * @param[in] t_e gameobject al que se quiere conocer el atributo alive
         *
         * @return bool
         */
        bool isAlive(GameObject* t_e);

        void freeAllGameObjects();

        /**
         * @brief Añade un componente a la entidad
         *
         * @param[in] t_e gameobject al que se quiere añadir
         *
         * @return static_cast<T*>(component)
         */
        template <typename T>
        inline T* addComponent(GameObject* t_e)
        {
            // delete the current component, if any
            removeComponent<T>(t_e);

            // create, initialise and install the new component
            Component* c = new T();
            c->setContext(t_e, this);
            // seran las factorias las encargadas de inicializar dicha inicializacion, tanto esta como la de parámetros
            // c->initComponent();

            t_e->m_current_comps.insert({(typeid(T).name()), c});

            return static_cast<T*>(c);
        }

        /**
         * @brief Elimina un componente a la entidad
         *
         * @param[in] t_e gameobject al que se quiere quitar
         *
         * @return void
         */
        template <typename T>
        inline void removeComponent(GameObject* t_e)
        {
            auto comp = t_e->m_current_comps.find(typeid(T).name());

            if (comp != t_e->m_current_comps.end())
            {
                delete comp->second;
                comp->second = nullptr;
                t_e->m_current_comps.erase(comp);
            }
        }

        /**
         * @brief Añade un script a un gameObject, la instancia de la clase del script
         * debe estar ya creada y no comprueba si es necesario borrar
         * un duplicado
         *
         * @param[in] t_e gameobject al que se quiere añadir
         *
         * @return T*
         */
        template <typename T>
        inline T* addScript(GameObject* t_e, T* t_s, std::string t_n)
        {
            t_s->setContext(t_e, this);

            t_e->m_current_comps.insert({t_n, t_s});

            addGameObjectToGroups(t_e, {GROUP_SCRIPTING});

            return t_s;
        }

        /**
         * @brief Remueve un componente dado un iterador del mapa de componentes,
         * es usado por el ScriptFactory para eliminar los componentes en caso de estar repetidos.
         *
         * @param[in] t_e gameobject al que se quiere quitar
         *
         * @return void
         */

        void removeScript(GameObject* t_e, std::unordered_map<std::string, Component*>::iterator t_scriptIndex);

        /**
         * @brief devuelve el commponente de un gameobject
         *
         * @param[in] t_e gameobject
         *
         * @return static_cast<T*>(component)
         */
        template <typename T>
        inline T* getComponent(GameObject* t_e)
        {
            try
            {
                if (t_e->m_current_comps.size() == 0)
                    return nullptr;

                auto c = t_e->m_current_comps.at(typeid(T).name());
                return static_cast<T*>(c);
            }
            catch (...)
            {
                return nullptr;
            }
        }

        /**
         * @brief Devuelve si un componente tiene o no un componente
         *
         * @param[in] t_e gameobject
         *
         * @return bool
         */
        template <typename T>
        inline bool hasComponent(GameObject* t_e)
        {
            return t_e->m_current_comps.find(typeid(T).name()) != t_e->m_current_comps.end();
        }

        /**
         * @brief Devuelve el tipo de grupo de una entidad
         *
         * @param[in] t_e entidad
         *
         * @return vector<groupId_type>
         */
        std::vector<groupId_type> groupId(GameObject* t_e);

        /**
         * @brief Devuelve todas las entidades de un grupo
         *
         * @param[in] t_gId Id del grupo a devolver
         *
         * @return vector<GameObject*>&
         */
        const std::vector<GameObject*>& getEntities(groupId_type t_gId = GROUP_EXAMPLE);

        /**
         * @brief Asocia el GameObject al handler
         *
         * @param[in] t_hId handlerId_type handler
         * @param[in] t_e GameObject* GameObject
         *
         * @return void
         */
        void setHandler(handlerId_type t_hId, GameObject* t_e);

        /**
         * @brief Devuelve la entidad asociada al handler
         *
         * @param[in] t_hId handlerId_type handler
         * @return GameObject*
         */
        GameObject* getHandler(handlerId_type t_hId);

        /**
         * @brief Añade un sistema al manager
         *
         * @param[in] t_args lista de argumentos que se necesitan
         * para pasar al sistema
         *
         * return static_cast<T*>(system)
         */
        template <typename T, typename... Ts>
        inline T* addSystem(Ts&&... t_args)
        {
            constexpr systemId_type sId = T::id;
            assert(sId < maxSystemId);

            removeSystem<T>();

            // create, initialise and install the new component
            System* s = new T(std::forward<Ts>(t_args)...);
            s->setContext(this);
            s->initSystem();
            m_systems[sId] = s;

            // return it to the user so it can be initialised if needed
            return static_cast<T*>(s);
        }

        /**
         * @brief Quita un sistema del manager
         *
         * return void
         */
        template <typename T>
        inline void removeSystem()
        {
            constexpr systemId_type sId = T::id;
            assert(sId < maxSystemId);

            if (m_systems[sId] != nullptr)
            {
                // destroy it
                delete m_systems[sId];

                // remove the pointer
                m_systems[sId] = nullptr;
            }
        }
        /**
         * @brief Devuelve un sistema en especifico
         *
         * return T*
         */
        template <typename T>
        inline T* getSystem()
        {
            constexpr systemId_type sId = T::id;
            assert(sId < maxSystemId);

            return static_cast<T*>(m_systems[sId]);
        }

        std::array<System*, maxSystemId> getSystems();

        void reajustGroups();

        void send(const Message& t_m, bool t_delay = false);

        void flushMessages();

        void refresh();

        bool gameObjectMarked(const std::vector<GameObject*>& v, GameObject* gO);

        static Manager* instance();

        static void close();

      private:
        void reajustSizeGroups();

        std::array<GameObject*, maxHandlerId>
            m_handlers;
        std::array<std::vector<GameObject*>, maxGroupId> m_ents_by_group;
        std::array<System*, maxSystemId> m_systems;

        std::vector<Message> m_msgs;
        std::vector<Message> m_msgs_aux;

        bool reajustG = false;

        static Manager* m_instance;
    };

} // namespace Flamingo
#endif