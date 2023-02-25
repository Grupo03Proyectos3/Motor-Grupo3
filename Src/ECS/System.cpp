#include "System.h"

ecs::System::System()
    : m_mngr(nullptr)
{
}

ecs::System::~System()
{
}

void ecs::System::setContext(Manager* t_mngr)
{
    m_mngr = t_mngr;
}

void ecs::System::initSystem()
{
}

void ecs::System::update(float t_delta_time)
{
}

void ecs::System::recieve(const Message&)
{
}
