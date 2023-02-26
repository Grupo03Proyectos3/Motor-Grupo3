#pragma once
#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <array>
#include <cassert>
#include <iostream>
#include <vector>

#include "Component.h"
#include "Entity.h"
#include "System.h"
#include "ecs.h"
#include "messages_defs.h"

class PhysicsSystem;

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
    class Manager
    {
      public:
        Manager();
        virtual ~Manager();

        // Adding an entity simply creates an instance of Entity, adds
        // it to the list of the given group and returns it to the caller.
        //
        Entity* addEntity(groupId gId = _grp_GENERAL);

        // Setting the state of entity 't_e' (alive or dead)
        //
        void setAlive(Entity* t_e, bool t_alive);

        // Returns the state of the entity 't_e' (alive o dead)
        //
        bool isAlive(Entity* t_e);

        // Adds a component to the entity 't_e'. It receives the type
        // T (to be created), and the list of arguments (if any) to
        // be passed to the constructor. The component identifier
        // 'cId' is taken from T::id.
        //
        template <typename T, typename... Ts>
        inline T* addComponent(Entity* t_e, Ts&&... t_args)
        {
            constexpr compId_type cId = T::id;
            assert(cId < maxComponentId);

            // delete the current component, if any
            //
            removeComponent<T>(t_e);

            // create, initialise and install the new component
            //
            Component* c = new T(std::forward<Ts>(t_args)...);
            c->setContext(t_e, this);
            c->initComponent();
            t_e->m_comps[cId] = c;
            t_e->m_current_comps.push_back(c);

            // return it to the user so i can be initialised if needed
            return static_cast<T*>(c);
        }

        // Removes the component of Entity 't_e' at position T::id.
        //
        template <typename T>
        inline void removeComponent(Entity* t_e)
        {
            constexpr compId_type cId = T::id;
            assert(cId < maxComponentId);

            if (t_e->m_comps[cId] != nullptr)
            {
                // find the element that is equal to e->cmps_[cId] (returns an iterator)
                //
                auto iter = std::find(t_e->m_current_comps.begin(), t_e->m_current_comps.end(),
                                      t_e->m_comps[cId]);

                // must have such a component
                assert(iter != t_e->m_current_comps.end());

                // and then remove it
                t_e->m_current_comps.erase(iter);
                // destroy it
                //
                delete t_e->m_comps[cId];

                // remove the pointer
                //
                t_e->m_comps[cId] = nullptr;
            }
        }

        // Returns the component that corresponds to position T::id, casting it
        // to T*. The casting is done just for ease of use, to avoid casting
        // outside.
        //
        template <typename T>
        inline T* getComponent(Entity* t_e)
        {
            constexpr compId_type cId = T::id;
            assert(cId < maxComponentId);

            return static_cast<T*>(t_e->m_comps[cId]);
        }

        // returns true if there is a component with identifier T::id
        // in the entity 't_e'
        //
        template <typename T>
        inline bool hasComponent(Entity* t_e)
        {
            constexpr compId_type cId = T::id;
            assert(cId < maxComponentId);

            return t_e->m_comps[cId] != nullptr;
        }

        // returns the group 't_gId' of entity 't_e'
        //
        groupId_type groupId(Entity* t_e);

        // returns the vector of all entities of a given group
        //
        const auto& getEntities(groupId_type t_gId = _grp_GENERAL);

        // associates the entity 't_e' to the handler 't_hId'
        //
        void setHandler(handlerId_type t_hId, Entity* t_e);

        // returns the entity associated to the handler 't_hId'
        //
        Entity* getHandler(handlerId_type t_hId);

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

        PhysicsSystem* addSystem();

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

        void send(const Message& t_m, bool t_delay = false);
        // this method should be called in the main loop to send queued
        // messages, i.e., those were sent using send(m,true)
        //
        void flushMessages();

        // THIS IS THE VERSION THAT SWAP QUEUES, IF YOU WANT TO USE IT
        //
        // this method should be called in the main loop to send queued
        // messages, i.e., those were sent using send(m,true)
        //
        void flushMessagesWithSwap();
        void refresh();


      private:
        std::array<Entity*, maxHandlerId> m_handlers;
        std::array<std::vector<Entity*>, maxGroupId> m_ents_by_group;
        std::array<System*, maxSystemId> m_systems;

        std::vector<Message> m_msgs;
        std::vector<Message> m_msgs_aux;
    };


} // namespace ecs
#endif