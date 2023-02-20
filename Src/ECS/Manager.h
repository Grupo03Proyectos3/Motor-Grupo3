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

namespace ecs
{

    /*
     * A class fir managing the list of entities, groups, etc.
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
        T* addComponent(Entity* t_e, Ts&&... t_args);
        // Removes the component of Entity 't_e' at position T::id.
        //
        template <typename T>
        void removeComponent(Entity* t_e);

        // Returns the component that corresponds to position T::id, casting it
        // to T*. The casting is done just for ease of use, to avoid casting
        // outside.
        //
        template <typename T>
        T* getComponent(Entity* t_e);

        // returns true if there is a component with identifier T::id
        // in the entity 't_e'
        //
        template <typename T>
        bool hasComponent(Entity* t_e);

        // returns the group 't_gId' of entity 't_e'
        //
        /*inline grpId_type groupId(Entity* t_e)
        {
            return e->gId_;
        }*/

        // returns the vector of all entities of a given group
        //
        // inline const auto& getEntities(/*grpId_type t_gId = _grp_GENERAL*/);

        // associates the entity 't_e' to the handler 't_hId'
        //
        void setHandler(handlerId_type t_hId, Entity* t_e);

        // returns the entity associated to the handler 't_hId'
        //
        /*inline Entity* getHandler(hdlrId_type t_hId)
        {
            assert(t_hId < maxHandlerId);
            return hdlrs_[t_hId];
        }*/

        // Adds a System to the manager. It receives the type
        // T of the system (to be created), and the list of
        // arguments (if any) to be passed to the system. The
        // system's identifier 'cId' is taken from T::id.
        //
        template <typename T, typename... Ts>
        T* addSystem(Ts&&... t_args);

        // Removes the system at position T::id.
        //
        template <typename T>
        void removeSystem();
        // Returns the system that corresponds to position T::id, casting it
        // to T*. The casting is done just for ease of use, to avoid casting
        // outside.
        //
        template <typename T>
        T* getSystem();

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
        // std::array<Entity*, maxHandlerId> hdlrs_;
        // std::array<std::vector<Entity*>, maxGroupId> entsByGroup_;
        // std::array<System*, maxSystemId> sys_;

        // std::vector<Message> msgs_;
        // std::vector<Message> msgs_aux_;
    };

} // namespace ecs

#endif