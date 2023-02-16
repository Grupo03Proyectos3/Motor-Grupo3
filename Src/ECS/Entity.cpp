#include "Entity.h"

ecs::Entity::Entity()
    : m_current_cmps()
    , m_alive()
{
}

ecs::Entity::~Entity()
{
    /* comentado de momento
    for (auto c : cmps_)
         if (c != nullptr)
             delete c;*/
}
