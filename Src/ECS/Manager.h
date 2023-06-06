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
     *  */
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

        /*Inicializa todos los componentes existentes*/
        void initComponents();

        // Adding an entity simply creates an instance of Entity, adds
        // it to the list of the given group and returns it to the caller.
        // se puede eliminar los grupos de aqui ya que van a ser añadidos segun que componente contengan
        GameObject* addGameObject(std::vector<groupId_type> t_vect_gId = {});
       
        // add a specific gameobject to a grouop after be created
        void addGameObjectToGroups(GameObject* t_e, std::vector<groupId_type> t_vect_gId = {});
        

        // Setting the state of entity 't_e' (alive or dead)
        //
        void setAlive(GameObject* t_e, bool t_alive);
       

        // Returns the state of the entity 't_e' (alive o dead)
        //
        bool isAlive(GameObject* t_e);      

        // Adds a component to the entity 't_e'. It receives the type
        // T (to be created), and the list of arguments (if any) to
        // be passed to the constructor. The component identifier
        // 'cId' is taken from T::id. Component is erased if existed.
        //
        template <typename T>
        inline T* addComponent(GameObject* t_e)
        {
            /* constexpr compId_type cId = T::id;
             assert(cId < maxComponentId);*/

            // delete the current component, if any
            //
            removeComponent<T>(t_e);

            // create, initialise and install the new component
            //
            Component* c = new T();
            c->setContext(t_e, this);
            // seran las factorias las encargadas de inicializar dicha inicializacion, tanto esta como la de parámetros
            // c->initComponent();

            t_e->m_current_comps.insert({(typeid(T).name()), c});

            // return it to the user so i can be initialised if needed
            return static_cast<T*>(c);
        }

        // Removes the component of Entity 't_e' at position T::id.
        //
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

        /*Añade un script a un gameObject, la isntancia de la clase del script debe estar ya creada y no comprueba si es necesario borrar
        un duplicado*/
        template <typename T>
        inline T* addScript(GameObject* t_e, T* t_s, std::string t_n)
        {
            // removeScript<T>(t_e, t_scriptIndex);

            t_s->setContext(t_e, this);

            t_e->m_current_comps.insert({t_n, t_s});

            addGameObjectToGroups(t_e, {GROUP_SCRIPTING});

            return t_s;
        }

        /*Remueve un componente dado un iterador del mapa de componentes,
         * es usado por el ScriptFactory para eliminar los componentes en caso de estar repetidos.
         */
        void removeScript(GameObject* t_e, std::unordered_map<std::string, Component*>::iterator t_scriptIndex);     

        // Returns the component that corresponds to position T::id, casting it
        // to T*. The casting is done just for ease of use, to avoid casting
        // outside.
        //
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

        // returns true if there is a component with identifier T::id
        // in the entity 't_e'
        //
        template <typename T>
        inline bool hasComponent(GameObject* t_e)
        {
            return t_e->m_current_comps.find(typeid(T).name()) != t_e->m_current_comps.end();
        }

        // returns the group 't_gId' of entity 't_e'
        //
        std::vector<groupId_type> groupId(GameObject* t_e);        

        // returns the vector of all entities of a given group
        //
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
        

        // Adds a System to the manager. It receives the type
        // T of the system (to be created), and the list of
        // arguments (if any) to be passed to the system. The
        // system's identifier 'cId' is taken from T::id.
        //
        template <typename T, typename... Ts>
        inline T* addSystem(Ts&&... t_args)
        {
            constexpr systemId_type sId = T::id;
            assert(sId < maxSystemId);

            removeSystem<T>();

            // create, initialise and install the new component
            //
            System* s = new T(std::forward<Ts>(t_args)...);
            s->setContext(this);
            s->initSystem();
            m_systems[sId] = s;

            // return it to the user so it can be initialised if needed
            return static_cast<T*>(s);
        }

        // Removes the system at position T::id.
        //
        template <typename T>
        inline void removeSystem()
        {
            constexpr systemId_type sId = T::id;
            assert(sId < maxSystemId);

            if (m_systems[sId] != nullptr)
            {
                // destroy it
                //
                delete m_systems[sId];

                // remove the pointer
                //
                m_systems[sId] = nullptr;
            }
        }

        // Returns the system that corresponds to position T::id, casting it
        // to T*. The casting is done just for ease of use, to avoid casting
        // outside.
        //
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
       
        // this method should be called in the main loop to send queued
        // messages, i.e., those were sent using send(m,true)
        //
        void flushMessages();
        
        // uso el metodo para eliminar gameObjects
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