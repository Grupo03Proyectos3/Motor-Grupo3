#include "Manager.h"

ecs::Manager::Manager()
    : m_handlers()
    , m_ents_by_group()
    , m_systems()
    , m_msgs()
    , m_msgs_aux()
{
    for (auto &group : m_ents_by_group)
    {
        group.reserve(100);

    }
    m_msgs.reserve(100);
    m_msgs_aux.reserve(100);
}

ecs::Manager::~Manager()
{
    for (auto& ents : m_ents_by_group)
    {
        for (auto e : ents)
            delete e;
    }

    for (auto i = 0u; i < maxSystemId; i++)
        if (m_systems[i] != nullptr)
            delete m_systems[i];
}

ecs::Entity* ecs::Manager::addEntity(ecs::groupId t_gId)
{
    // create and initialise the entity
    auto e = new Entity(t_gId);
    e->m_alive = true;

    m_ents_by_group[t_gId].push_back(e);

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

ecs::groupId_type ecs::Manager::groupId(Entity* t_e)
{
    return t_e->m_gId;
}

void ecs::Manager::setHandler(handlerId_type t_hId, Entity* t_e)
{
    assert(t_hId < maxHandlerId);
    m_handlers[t_hId] = t_e;
}

ecs::Entity* ecs::Manager::getHandler(handlerId_type t_hId)
{
    assert(t_hId < maxHandlerId);
    return m_handlers[t_hId];
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

void ecs::Manager::flushMessagesWithSwap()
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

void ecs::Manager::refresh()
{
}

const auto& ecs::Manager::getEntities(ecs::groupId_type t_gId)
{
    return m_ents_by_group[t_gId];
    ;
}

template <typename T, typename... Ts>
T* ecs::Manager::addComponent(ecs::Entity* t_e, Ts&&... t_args)
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

template <typename T>
void ecs::Manager::removeComponent(Entity* t_e)
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

template <typename T>
T* ecs::Manager::getComponent(Entity* t_e)
{
    constexpr compId_type cId = T::id;
    assert(cId < maxComponentId);

    return static_cast<T*>(t_e->m_comps[cId]);
}

template <typename T>
bool ecs::Manager::hasComponent(Entity* t_e)
{
    constexpr compId_type cId = T::id;
    assert(cId < maxComponentId);

    return t_e->m_comps[cId] != nullptr;
}

template <typename T, typename... Ts>
T* ecs::Manager::addSystem(Ts&&... t_args)
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

template <typename T>
void ecs::Manager::removeSystem()
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

template <typename T>
T* ecs::Manager::getSystem()
{
    constexpr systemId_type sId = T::id;
    assert(sId < maxSystemId);

    return static_cast<T*>(m_systems[sId]);
}
