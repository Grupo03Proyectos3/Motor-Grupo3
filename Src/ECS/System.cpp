#include "System.h"

ecs::System::System(): mngr_(nullptr)
{
}

ecs::System::~System()
{
}

void ecs::System::setContext(Manager* t_mngr)
{
    mngr_ = t_mngr;
}

void ecs::System::initSystem()
{
}

void ecs::System::update()
{
}

void ecs::System::recieve(/*const Message&*/)
{
}
