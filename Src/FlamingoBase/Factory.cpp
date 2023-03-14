#include "Factory.h"

Factory::~Factory()
{
    deleteComponents();
}

void Factory::deleteComponents()
{
    for (ecs::Component* comp : compsCreated)
    {
        if (comp != nullptr)
        {
            delete comp;
            comp = nullptr;
        }
    }
}
