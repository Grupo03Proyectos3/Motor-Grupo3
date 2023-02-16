#include "Manager.h"

inline void ecs::Manager::setAlive(/*Entity* e, bool alive*/)
{
    // e->alive_ = alive;
}

inline bool ecs::Manager::isAlive(/*Entity* e*/)
{
    // return e->alive_;
}

inline void ecs::Manager::setHandler(/*hdlrId_type hId, Entity* e*/)
{
    /*assert(hId < maxHandlerId);
    hdlrs_[hId] = e;*/
}

inline void ecs::Manager::send(/*const Message& m, bool delay*/)
{
    //if (!delay)
    //{
    //    for (System* s : sys_)
    //    {
    //        if (s != nullptr)
    //            s->recieve(m);
    //    }
    //}
    //else
    //{
    //    // will make a copy of m, we could use std::move to move it
    //    // but then we will have to remove const from above
    //    msgs_.emplace_back(m);
    //}
}

inline void ecs::Manager::flushMessages()
{
    //// we traverse until msgs_.size(), so if new message
    //// we added we don't send them now. If you wish to send
    //// them as will you should write this loop in a different way
    //// and maybe using std::list would be better.
    ////
    // auto size = msgs_.size();
    // for (auto i = 0u; i < size; i++)
    //{
    //     auto& m = msgs_[i];
    //     for (System* s : sys_)
    //     {
    //         if (s != nullptr)
    //             s->recieve(m);
    //     }
    // }

    //// delete all message that we have sent. This might be expensive
    //// since it has to shift all remaining elements to the left. A better
    //// solution would be to keep two vectors 'v1' and 'v2', when sending a
    //// message we always add it to 'v1' and in flush we swap them and send
    //// all messages in v2. After flush we simply clear v2
    ////
    // msgs_.erase(msgs_.begin(), msgs_.begin() + size);
}

inline void ecs::Manager::flushMessagesWithSwap()
{
    //std::swap(msgs_, msgs_aux_);
    //for (auto& m : msgs_aux_)
    //{
    //    for (System* s : sys_)
    //    {
    //        if (s != nullptr)
    //            s->recieve(m);
    //    }
    //}
    //
    //msgs_aux_.clear();
}

void ecs::Manager::refresh()
{
}

// inline const auto& ecs::Manager::getEntities(/*grpId_type gId*/)
//{
//     //return entsByGroup_[gId];
//     //;
// }

template <typename T, typename... Ts>
inline T* ecs::Manager::addComponent(/*Entity* e, Ts&&... args*/)
{
    constexpr cmpId_type cId = T::id;
    assert(cId < maxComponentId);

    // delete the current component, if any
    //
    removeComponent<T>(e);

    // create, initialise and install the new component
    //
    Component* c = new T(std::forward<Ts>(args)...);
    c->setContext(e, this);
    c->initComponent();
    e->cmps_[cId] = c;
    e->currCmps_.push_back(c);

    // return it to the user so i can be initialised if needed
    return static_cast<T*>(c);
}

template <typename T>
inline void ecs::Manager::removeComponent(/*Entity* e*/)
{
    constexpr cmpId_type cId = T::id;
    assert(cId < maxComponentId);

    if (e->cmps_[cId] != nullptr)
    {
        // find the element that is equal to e->cmps_[cId] (returns an iterator)
        //
        auto iter = std::find(e->currCmps_.begin(), e->currCmps_.end(),
                              e->cmps_[cId]);

        // must have such a component
        assert(iter != e->currCmps_.end());

        // and then remove it
        e->currCmps_.erase(iter);
        // destroy it
        //
        delete e->cmps_[cId];

        // remove the pointer
        //
        e->cmps_[cId] = nullptr;
    }
}

template <typename T>
inline T* ecs::Manager::getComponent(/*Entity* e*/)
{
    constexpr cmpId_type cId = T::id;
    assert(cId < maxComponentId);

    return static_cast<T*>(e->cmps_[cId]);
}

template <typename T>
inline bool ecs::Manager::hasComponent(/*Entity* e*/)
{
    constexpr cmpId_type cId = T::id;
    assert(cId < maxComponentId);

    return e->cmps_[cId] != nullptr;
}

template <typename T, typename... Ts>
inline T* ecs::Manager::addSystem(Ts&&... args)
{
    constexpr sysId_type sId = T::id;
    assert(sId < maxSystemId);

    removeSystem<T>();

    // create, initialise and install the new component
    //
    System* s = new T(std::forward<Ts>(args)...);
    s->setContext(this);
    s->initSystem();
    sys_[sId] = s;

    // return it to the user so it can be initialised if needed
    return static_cast<T*>(s);
}

template <typename T>
inline void ecs::Manager::removeSystem()
{
    constexpr sysId_type sId = T::id;
    assert(sId < maxSystemId);

    if (sys_[sId] != nullptr)
    {
        // destroy it
        //
        delete sys_[sId];

        // remove the pointer
        //
        sys_[sId] = nullptr;
    }
}

template <typename T>
inline T* ecs::Manager::getSystem()
{
    constexpr sysId_type sId = T::id;
    assert(sId < maxSystemId);

    return static_cast<T*>(sys_[sId]);
}
