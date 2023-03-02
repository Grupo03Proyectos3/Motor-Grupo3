#include "Entity.h"

ecs::Entity::Entity()
    : m_current_comps()
    , m_alive()
    , m_gId(_grp_GENERAL)
    , m_comps()
{
    m_current_comps.reserve(ecs::maxComponentId);
}

ecs::Entity::Entity(ecs::groupId_type t_gId)
    : m_current_comps()
    , m_alive()
    , m_gId(t_gId)
    , m_comps()
{
    m_current_comps.reserve(ecs::maxComponentId);
}

ecs::Entity::~Entity()
{
    for (auto c : m_comps)
        if (c != nullptr)
            delete c;
}
