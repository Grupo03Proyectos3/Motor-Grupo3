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
    //    inline Entity* addEntity(grpId gId = _grp_GENERAL)
    //    {
    //        // create and initialise the entity
    //        auto e = new Entity(gId);
    //        e->alive_ = true;

    //        // add the entity 'e' to list of entities if the given group
    //        //
    //        // IMPORTANT NOTE:
    //        //
    //        // Currently we immediately add the entity to the list of entities,
    //        // so we will actually see them in this 'frame' if we traverse the list of
    //        // entities afterwards!
    //        //
    //        // A better solution would be to add them to an auxiliary list, and
    //        // define a method 'flush()' that moves them from the auxiliary list
    //        // to the corresponding list of entities.
    //        //
    //        // We will have to call 'flush()' in each iteration of the
    //        // main loop. This way we guarantee that entities that are added in one
    //        // 'frame' they will appear only in the next 'frame' -- I leave it as an
    //        // exercise for you ...
    //        //
    //        entsByGroup_[gId].push_back(e);

    //        // return it to the caller
    //        //
    //        return e;
    //    }

    //    // Setting the state of entity 'e' (alive or dead)
    //    //
    //    inline void setAlive(Entity* e, bool alive)
    //    {
    //        e->alive_ = alive;
    //    }

    //    // Returns the state of the entity 'e' (alive o dead)
    //    //
    //    inline bool isAlive(Entity* e)
    //    {
    //        return e->alive_;
    //    }

    //    // Adds a component to the entity 'e'. It receives the type
    //    // T (to be created), and the list of arguments (if any) to
    //    // be passed to the constructor. The component identifier
    //    // 'cId' is taken from T::id.
    //    //
    //    template <typename T, typename... Ts>
    //    inline T* addComponent(Entity* e, Ts&&... args)
    //    {
    //        constexpr cmpId_type cId = T::id;
    //        assert(cId < maxComponentId);

    //        // delete the current component, if any
    //        //
    //        removeComponent<T>(e);

    //        // create, initialise and install the new component
    //        //
    //        Component* c = new T(std::forward<Ts>(args)...);
    //        c->setContext(e, this);
    //        c->initComponent();
    //        e->cmps_[cId] = c;
    //        e->currCmps_.push_back(c);

    //        // return it to the user so i can be initialised if needed
    //        return static_cast<T*>(c);
    //    }

    //    // Removes the component of Entity 'e' at position T::id.
    //    //
    //    template <typename T>
    //    inline void removeComponent(Entity* e)
    //    {
    //        constexpr cmpId_type cId = T::id;
    //        assert(cId < maxComponentId);

    //        if (e->cmps_[cId] != nullptr)
    //        {
    //            // find the element that is equal to e->cmps_[cId] (returns an iterator)
    //            //
    //            auto iter = std::find(e->currCmps_.begin(), e->currCmps_.end(),
    //                                  e->cmps_[cId]);

    //            // must have such a component
    //            assert(iter != e->currCmps_.end());

    //            // and then remove it
    //            e->currCmps_.erase(iter);
    //            // destroy it
    //            //
    //            delete e->cmps_[cId];

    //            // remove the pointer
    //            //
    //            e->cmps_[cId] = nullptr;
    //        }
    //    }

    //    // Returns the component that corresponds to position T::id, casting it
    //    // to T*. The casting is done just for ease of use, to avoid casting
    //    // outside.
    //    //
    //    template <typename T>
    //    inline T* getComponent(Entity* e)
    //    {
    //        constexpr cmpId_type cId = T::id;
    //        assert(cId < maxComponentId);

    //        return static_cast<T*>(e->cmps_[cId]);
    //    }

    //    // returns true if there is a component with identifier T::id
    //    // in the entity 'e'
    //    //
    //    template <typename T>
    //    inline bool hasComponent(Entity* e)
    //    {
    //        constexpr cmpId_type cId = T::id;
    //        assert(cId < maxComponentId);

    //        return e->cmps_[cId] != nullptr;
    //    }

    //    // returns the group 'gId' of entity 'e'
    //    //
    //    inline grpId_type groupId(Entity* e)
    //    {
    //        return e->gId_;
    //    }

    //    // returns the vector of all entities of a given group
    //    //
    //    inline const auto& getEntities(grpId_type gId = _grp_GENERAL)
    //    {
    //        return entsByGroup_[gId];
    //        ;
    //    }

    //    // associates the entity 'e' to the handler 'hId'
    //    //
    //    inline void setHandler(hdlrId_type hId, Entity* e)
    //    {
    //        assert(hId < maxHandlerId);
    //        hdlrs_[hId] = e;
    //    }

    //    // returns the entity associated to the handler 'hId'
    //    //
    //    inline Entity* getHandler(hdlrId_type hId)
    //    {
    //        assert(hId < maxHandlerId);
    //        return hdlrs_[hId];
    //    }

    //    // Adds a System to the manager. It receives the type
    //    // T of the system (to be created), and the list of
    //    // arguments (if any) to be passed to the system. The
    //    // system's identifier 'cId' is taken from T::id.
    //    //
    //    template <typename T, typename... Ts>
    //    inline T* addSystem(Ts&&... args)
    //    {
    //        constexpr sysId_type sId = T::id;
    //        assert(sId < maxSystemId);

    //        removeSystem<T>();

    //        // create, initialise and install the new component
    //        //
    //        System* s = new T(std::forward<Ts>(args)...);
    //        s->setContext(this);
    //        s->initSystem();
    //        sys_[sId] = s;

    //        // return it to the user so it can be initialised if needed
    //        return static_cast<T*>(s);
    //    }

    //    // Removes the system at position T::id.
    //    //
    //    template <typename T>
    //    inline void removeSystem()
    //    {
    //        constexpr sysId_type sId = T::id;
    //        assert(sId < maxSystemId);

    //        if (sys_[sId] != nullptr)
    //        {
    //            // destroy it
    //            //
    //            delete sys_[sId];

    //            // remove the pointer
    //            //
    //            sys_[sId] = nullptr;
    //        }
    //    }

    //    // Returns the system that corresponds to position T::id, casting it
    //    // to T*. The casting is done just for ease of use, to avoid casting
    //    // outside.
    //    //
    //    template <typename T>
    //    inline T* getSystem()
    //    {
    //        constexpr sysId_type sId = T::id;
    //        assert(sId < maxSystemId);

    //        return static_cast<T*>(sys_[sId]);
    //    }

    //    inline void send(const Message& m, bool delay = false)
    //    {
    //        if (!delay)
    //        {
    //            for (System* s : sys_)
    //            {
    //                if (s != nullptr)
    //                    s->recieve(m);
    //            }
    //        }
    //        else
    //        {
    //            // will make a copy of m, we could use std::move to move it
    //            // but then we will have to remove const from above
    //            msgs_.emplace_back(m);
    //        }
    //    }

    //    // this method should be called in the main loop to send queued
    //    // messages, i.e., those were sent using send(m,true)
    //    //
    //    inline void flushMessages()
    //    {
    //        // we traverse until msgs_.size(), so if new message
    //        // we added we don't send them now. If you wish to send
    //        // them as will you should write this loop in a different way
    //        // and maybe using std::list would be better.
    //        //
    //        auto size = msgs_.size();
    //        for (auto i = 0u; i < size; i++)
    //        {
    //            auto& m = msgs_[i];
    //            for (System* s : sys_)
    //            {
    //                if (s != nullptr)
    //                    s->recieve(m);
    //            }
    //        }

    //        // delete all message that we have sent. This might be expensive
    //        // since it has to shift all remaining elements to the left. A better
    //        // solution would be to keep two vectors 'v1' and 'v2', when sending a
    //        // message we always add it to 'v1' and in flush we swap them and send
    //        // all messages in v2. After flush we simply clear v2
    //        //
    //        msgs_.erase(msgs_.begin(), msgs_.begin() + size);
    //    }

    //    // THIS IS THE VERSION THAT SWAP QUEUES, IF YOU WANT TO USE IT
    //    //
    //    // this method should be called in the main loop to send queued
    //    // messages, i.e., those were sent using send(m,true)
    //    //
    //    inline void flushMessagesWithSwap()
    //    {
    //        std::swap(msgs_, msgs_aux_);
    //        for (auto& m : msgs_aux_)
    //        {
    //            for (System* s : sys_)
    //            {
    //                if (s != nullptr)
    //                    s->recieve(m);
    //            }
    //        }

    //        msgs_aux_.clear();
    //    }

    //    void refresh();

    //  private:
    //    std::array<Entity*, maxHandlerId> hdlrs_;
    //    std::array<std::vector<Entity*>, maxGroupId> entsByGroup_;
    //    std::array<System*, maxSystemId> sys_;

    //    std::vector<Message> msgs_;
    //    std::vector<Message> msgs_aux_;
    //};

} // namespace ecs

#endif