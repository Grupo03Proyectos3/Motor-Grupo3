#include "Component.h"

ecs::Component::Component() //: ent_(), mngr_()
{
}

ecs::Component::~Component()
{
}

inline void ecs::Component::setContext(/*Entity* ent, Manager* mngr*/)
{
    /* ent_ = ent;
     mngr_ = mngr;*/
}

void ecs::Component::initComponent()
{
}

void ecs::Component::update()
{
}

void ecs::Component::render()
{
}
