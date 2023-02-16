#pragma once
#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <array>
#include <cassert>
#include <iostream>
#include <vector>

#include "Component.h"
//#include "Entity.h"
//#include "System.h"
//#include "ecs.h"
//#include "messages.h"

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
        // inline Entity* addEntity(grpId gId = _grp_GENERAL)
        //{
        //    // create and initialise the entity
        //    auto e = new Entity(gId);
        //    e->alive_ = true;

        //    // add the entity 'e' to list of entities if the given group
        //    //
        //    // IMPORTANT NOTE:
        //    //
        //    // Currently we immediately add the entity to the list of entities,
        //    // so we will actually see them in this 'frame' if we traverse the list of
        //    // entities afterwards!
        //    //
        //    // A better solution would be to add them to an auxiliary list, and
        //    // define a method 'flush()' that moves them from the auxiliary list
        //    // to the corresponding list of entities.
        //    //
        //    // We will have to call 'flush()' in each iteration of the
        //    // main loop. This way we guarantee that entities that are added in one
        //    // 'frame' they will appear only in the next 'frame' -- I leave it as an
        //    // exercise for you ...
        //    //
        //    entsByGroup_[gId].push_back(e);

        //    // return it to the caller
        //    //
        //    return e;
        //}

        // Setting the state of entity 'e' (alive or dead)
        //
        inline void setAlive(/*Entity* e, bool alive*/);

        // Returns the state of the entity 'e' (alive o dead)
        //
        inline bool isAlive(/*Entity* e*/);

        // Adds a component to the entity 'e'. It receives the type
        // T (to be created), and the list of arguments (if any) to
        // be passed to the constructor. The component identifier
        // 'cId' is taken from T::id.
        //
        template <typename T, typename... Ts>
        inline T* addComponent(/*Entity* e, Ts&&... args*/);
        // Removes the component of Entity 'e' at position T::id.
        //
        template <typename T>
        inline void removeComponent(/*Entity* e*/);

        // Returns the component that corresponds to position T::id, casting it
        // to T*. The casting is done just for ease of use, to avoid casting
        // outside.
        //
        template <typename T>
        inline T* getComponent(/*Entity* e*/);

        // returns true if there is a component with identifier T::id
        // in the entity 'e'
        //
        template <typename T>
        inline bool hasComponent(/*Entity* e*/);

        // returns the group 'gId' of entity 'e'
        //
        /*inline grpId_type groupId(Entity* e)
        {
            return e->gId_;
        }*/

        // returns the vector of all entities of a given group
        //
        //inline const auto& getEntities(/*grpId_type gId = _grp_GENERAL*/);

        // associates the entity 'e' to the handler 'hId'
        //
        inline void setHandler(/*hdlrId_type hId, Entity* e*/);

        // returns the entity associated to the handler 'hId'
        //
        /*inline Entity* getHandler(hdlrId_type hId)
        {
            assert(hId < maxHandlerId);
            return hdlrs_[hId];
        }*/

        // Adds a System to the manager. It receives the type
        // T of the system (to be created), and the list of
        // arguments (if any) to be passed to the system. The
        // system's identifier 'cId' is taken from T::id.
        //
        template <typename T, typename... Ts>
        inline T* addSystem(Ts&&... args);

        // Removes the system at position T::id.
        //
        template <typename T>
        inline void removeSystem();
        // Returns the system that corresponds to position T::id, casting it
        // to T*. The casting is done just for ease of use, to avoid casting
        // outside.
        //
        template <typename T>
        inline T* getSystem();

        inline void send(/*const Message& m, bool delay = false*/);
        // this method should be called in the main loop to send queued
        // messages, i.e., those were sent using send(m,true)
        //
        inline void flushMessages();

        // THIS IS THE VERSION THAT SWAP QUEUES, IF YOU WANT TO USE IT
        //
        // this method should be called in the main loop to send queued
        // messages, i.e., those were sent using send(m,true)
        //
        inline void flushMessagesWithSwap();
        void refresh();

      private:
        //std::array<Entity*, maxHandlerId> hdlrs_;
        //std::array<std::vector<Entity*>, maxGroupId> entsByGroup_;
        //std::array<System*, maxSystemId> sys_;

        //std::vector<Message> msgs_;
        //std::vector<Message> msgs_aux_;
    };

} // namespace ecs

#endif