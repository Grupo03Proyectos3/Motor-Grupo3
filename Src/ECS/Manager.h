#pragma once
#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <array>
#include <cassert>
#include <iostream>
#include <vector>
// #include <OgreSceneNode.h>
#include <algorithm>
#include <unordered_map>

#include "Component.h"
#include "GameObject.h"
#include "SingletonECS.h"
#include "System.h"
#include "ecs.h"
#include "messages_defs.h"

namespace ecs
{

    /*
     * A class for managing the list of entities, groups, etc.
     *
     * In this version the manager is responsible on several things
     * that used to be done by the class Entity (like addComponent), just
     * to make it easier to develop the memory management later.
     *
     * Note that no outside the classes of ECS can access an Entity directly,
     * they just have a reference to it.
     *
     *  */
    class Manager : public SingletonECS<Manager>
    {
        // Acceso a los construtores privados
        friend SingletonECS<Manager>;

      public:
        Manager()
        {
        }

        virtual ~Manager()
        {
            for (auto& ents : m_ents_by_group)
            {
                for (auto e : ents)
                {
                    // TODO comprobar que esto elimina bien
                    if (e != nullptr && e->m_alive == true)
                    {
                        delete e;
                        e = nullptr;
                    }
                }
            }

            for (auto i = 0u; i < maxSystemId; i++)
            {
                if (m_systems[i] != nullptr)
                {
                    delete m_systems[i];
                    m_systems[i] = nullptr;
                }
            }
        }

        void init()
        {
            m_handlers = std::array<GameObject*, maxHandlerId>();
            m_ents_by_group = std::array<std::vector<GameObject*>, maxGroupId>();
            m_systems = std::array<System*, maxSystemId>();

            m_msgs = std::vector<Message>();
            m_msgs_aux = std::vector<Message>();
        }

        Manager(Manager&) = delete;
        Manager(Manager&&) = delete;
        Manager& operator=(Manager&) = delete;
        Manager& operator=(Manager&&) = delete;

        // Adding an entity simply creates an instance of Entity, adds
        // it to the list of the given group and returns it to the caller.
        // se puede eliminar los grupos de aqui ya que van a ser añadidos segun que componente contengan
        inline GameObject* addGameObject(std::vector<groupId_type> t_vect_gId = {})
        {
            auto e = new GameObject(t_vect_gId);
            e->m_alive = true;

            for (auto grp : t_vect_gId)
            {
                // create and initialise the entity
                m_ents_by_group[grp].push_back(e);
            }

            return e;
        }

        // add a specific gameobject to a grouop after be created
        inline void addGameObjectToGroups(GameObject* t_e, std::vector<groupId_type> t_vect_gId = {})
        {
            for (auto grp : t_vect_gId)
            {
                if (std::find(m_ents_by_group[grp].begin(), m_ents_by_group[grp].end(), t_e) == m_ents_by_group[grp].end())
                {
                    m_ents_by_group[grp].push_back(t_e);
                }
            }
        }

        // Setting the state of entity 't_e' (alive or dead)
        //
        inline void setAlive(GameObject* t_e, bool t_alive)
        {
            t_e->m_alive = t_alive;
        }

        // Returns the state of the entity 't_e' (alive o dead)
        //
        inline bool isAlive(GameObject* t_e)
        {
            return t_e->m_alive;
        }

        // Adds a component to the entity 't_e'. It receives the type
        // T (to be created), and the list of arguments (if any) to
        // be passed to the constructor. The component identifier
        // 'cId' is taken from T::id.
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
            ///*  constexpr compId_type cId = T::id;
            //  assert(cId < maxComponentId);*/

            //  auto comp = t_e->m_current_comps[typeid(T).name()];
            //  if (comp != nullptr)
            //  {
            //       find the element that is equal to e->cmps_[cId] (returns an iterator)
            //
            //      auto iter = std::find(t_e->m_current_comps.begin(), t_e->m_current_comps.end(),
            //                            t_e->m_comps[cId]);

            //       must have such a component
            //      assert(iter != t_e->m_current_comps.end());

            //       and then remove it
            //      t_e->m_current_comps.erase(iter);
            //       destroy it
            //
            //      delete t_e->m_comps[cId];

            //       remove the pointer
            //
            //      t_e->m_comps[cId] = nullptr;
            //  }

            auto comp = t_e->m_current_comps.find(typeid(T).name());

            if (comp != t_e->m_current_comps.end())
            {
                delete comp->second;
                comp->second = nullptr;
                t_e->m_current_comps.erase(comp);
            }
        }

        // Returns the component that corresponds to position T::id, casting it
        // to T*. The casting is done just for ease of use, to avoid casting
        // outside.
        //
        template <typename T>
        inline T* getComponent(GameObject* t_e)
        {
            try
            {
                auto c = t_e->m_current_comps.at(typeid(T).name());
                return static_cast<T*>(c);
            }
            catch (const std::exception&)
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
        inline std::vector<groupId_type> groupId(GameObject* t_e)
        {
            return t_e->m_gIds;
        }

        // returns the vector of all entities of a given group
        //
        inline const auto& getEntities(groupId_type t_gId = GROUP_EXAMPLE)
        {
            return m_ents_by_group[t_gId];
        }

        // associates the entity 't_e' to the handler 't_hId'
        //
        void setHandler(handlerId_type t_hId, GameObject* t_e)
        {
            assert(t_hId < maxHandlerId);
            m_handlers[t_hId] = t_e;
        }

        // returns the entity associated to the handler 't_hId'
        //
        GameObject* getHandler(handlerId_type t_hId)
        {
            assert(t_hId < maxHandlerId);
            return m_handlers[t_hId];
        }

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

        inline std::array<System*, maxSystemId> getSystems()
        {
            return m_systems;
        }

        inline void reajustGroups()
        {
            reajustG = true;
        }

        void send(const Message& t_m, bool t_delay = false)
        {
            if (!t_delay)
            {
                for (System* s : m_systems)
                {
                    if (s != nullptr)
                        s->recieve(t_m);
                }
            }
            else
            {
                m_msgs.emplace_back(t_m);
            }
        }
        // this method should be called in the main loop to send queued
        // messages, i.e., those were sent using send(m,true)
        //
        inline void flushMessages()
        {
            // we traverse until msgs_.size(), so if new message
            // we added we don't send them now. If you wish to send
            // them as will you should write this loop in a different way
            // and maybe using std::list would be better.
            //
            auto size = m_msgs.size();
            for (auto i = 0u; i < size; i++)
            {
                auto& m = m_msgs[i];
                for (System* s : m_systems)
                {
                    if (s != nullptr)
                        s->recieve(m);
                }
            }

            // delete all message that we have sent. This might be expensive
            // since it has to shift all remaining elements to the left. A better
            // solution would be to keep two vectors 'v1' and 'v2', when sending a
            // message we always add it to 'v1' and in flush we swap them and send
            // all messages in v2. After flush we simply clear v2
            //
            m_msgs.erase(m_msgs.begin(), m_msgs.begin() + size);
        }

        // THIS IS THE VERSION THAT SWAP QUEUES, IF YOU WANT TO USE IT
        //
        // this method should be called in the main loop to send queued
        // messages, i.e., those were sent using send(m,true)
        //
        inline void flushMessagesWithSwap()
        {
            std::swap(m_msgs, m_msgs_aux);
            for (auto& m : m_msgs_aux)
            {
                for (System* s : m_systems)
                {
                    if (s != nullptr)
                        s->recieve(m);
                }
            }

            m_msgs_aux.clear();
        }
        // uso el metodo para eliminar gameObejcts ya que estaba vacio
        inline void refresh()
        {
            // falta probar
            for (auto& ents : m_ents_by_group)
            {
                for (auto i = 0; i < ents.size(); i++)
                {
                    if (ents[i] != nullptr && ents[i]->m_alive == false)
                    {
                        delete ents[i];
                        ents[i] = nullptr;
                    }
                }
            }

            if (reajustG)
            {
                reajustG = false;
                reajustSizeGroups();
            }
        }

      private:
        inline void reajustSizeGroups()
        {
            for (auto j = 0; j < m_ents_by_group.size(); j++)
            {
                auto i = m_ents_by_group[j].begin();
                while (i != m_ents_by_group[j].end())
                {
                    if (*i == nullptr)
                        i = m_ents_by_group[j].erase(i);
                    else
                        ++i;
                }
            }
        }

        std::array<GameObject*, maxHandlerId>
            m_handlers;
        std::array<std::vector<GameObject*>, maxGroupId> m_ents_by_group;
        std::array<System*, maxSystemId> m_systems;

        std::vector<Message> m_msgs;
        std::vector<Message> m_msgs_aux;

        bool reajustG = false;
    };

} // namespace ecs
#endif