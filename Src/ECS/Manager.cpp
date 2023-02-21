#include "Manager.h"

ecs::Manager::Manager()
{
}

ecs::Manager::~Manager()
{
}

ecs::Entity* ecs::Manager::addEntity(groupId t_gId)
{
    // create and initialise the entity
    auto e = new Entity(t_gId);
    e->m_alive = true;
   
    m_ents_by_group_[t_gId].push_back(e);

    return e;
}

void ecs::Manager::setAlive(Entity* t_e, bool t_alive)
{
    t_e->m_alive = t_alive;
}

bool ecs::Manager::isAlive(Entity* t_e)
{
    return t_e->m_alive;
}

void ecs::Manager::setHandler(handlerId_type t_hId, Entity* t_e)
{
    assert(t_hId < maxHandlerId);
    m_handlers[t_hId] = t_e;
}

void ecs::Manager::send(const Message& t_m, bool t_delay)
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

void ecs::Manager::flushMessages()
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

void ecs::Manager::flushMessagesWithSwap()
{
    // std::swap(msgs_, msgs_aux_);
    // for (auto& m : msgs_aux_)
    //{
    //     for (System* s : sys_)
    //     {
    //         if (s != nullptr)
    //             s->recieve(m);
    //     }
    // }
    //
    // msgs_aux_.clear();
}

void ecs::Manager::refresh()
{
}

// inline const auto& ecs::Manager::getEntities(/*grpId_type t_gId*/)
//{
//     //return entsByGroup_[t_gId];
//     //;
// }

template <typename T, typename... Ts>
T* ecs::Manager::addComponent(ecs::Entity* t_e, Ts&&... t_args)
{
    //    constexpr cmpId_type cId = T::id;
    //    assert(cId < maxComponentId);
    //
    //    // delete the current component, if any
    //    //
    //    removeComponent<T>(t_e);
    //
    //    // create, initialise and install the new component
    //    //
    //    Component* c = new T(std::forward<Ts>(t_args)...);
    //    c->setContext(t_e, this);
    //    c->initComponent();
    //    t_e->cmps_[cId] = c;
    //    t_e->currCmps_.push_back(c);
    //
    //    // return it to the user so i can be initialised if needed
    //    return static_cast<T*>(c);
}

template <typename T>
void ecs::Manager::removeComponent(Entity* t_e)
{
    // constexpr cmpId_type cId = T::id;
    // assert(cId < maxComponentId);

    // if (t_e->cmps_[cId] != nullptr)
    //{
    //     // find the element that is equal to e->cmps_[cId] (returns an iterator)
    //     //
    //     auto iter = std::find(t_e->currCmps_.begin(), t_e->currCmps_.end(),
    //                           t_e->cmps_[cId]);

    //    // must have such a component
    //    assert(iter != t_e->currCmps_.end());

    //    // and then remove it
    //    t_e->currCmps_.erase(iter);
    //    // destroy it
    //    //
    //    delete t_e->cmps_[cId];

    //    // remove the pointer
    //    //
    //    t_e->cmps_[cId] = nullptr;
    //}
}

template <typename T>
T* ecs::Manager::getComponent(Entity* t_e)
{
    /* constexpr cmpId_type cId = T::id;
     assert(cId < maxComponentId);

     return static_cast<T*>(t_e->cmps_[cId]);*/
}

template <typename T>
bool ecs::Manager::hasComponent(Entity* t_e)
{
    /*constexpr cmpId_type cId = T::id;
    assert(cId < maxComponentId);

    return t_e->cmps_[cId] != nullptr;*/
}

template <typename T, typename... Ts>
T* ecs::Manager::addSystem(Ts&&... t_args)
{
    // constexpr sysId_type sId = T::id;
    // assert(sId < maxSystemId);

    // removeSystem<T>();

    //// create, initialise and install the new component
    ////
    // System* s = new T(std::forward<Ts>(t_args)...);
    // s->setContext(this);
    // s->initSystem();
    // sys_[sId] = s;

    //// return it to the user so it can be initialised if needed
    // return static_cast<T*>(s);
}

template <typename T>
void ecs::Manager::removeSystem()
{
    // constexpr sysId_type sId = T::id;
    // assert(sId < maxSystemId);

    // if (sys_[sId] != nullptr)
    //{
    //     // destroy it
    //     //
    //     delete sys_[sId];

    //    // remove the pointer
    //    //
    //    sys_[sId] = nullptr;
    //}
}

template <typename T>
T* ecs::Manager::getSystem()
{
    /*constexpr sysId_type sId = T::id;
    assert(sId < maxSystemId);

    return static_cast<T*>(sys_[sId]);*/
}
