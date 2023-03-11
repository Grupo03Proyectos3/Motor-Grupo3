#include "Factory.h"

void Factory::deleteComponents()
{
    for (ecs::Component* comp : compsCreated)
    {
        delete comp;
        comp = nullptr;
    }
}
