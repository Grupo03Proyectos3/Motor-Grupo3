#include "Factory.h"

Factory::~Factory()
{
    deleteComponents();
}

ecs::Component* Factory::createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
{
    return nullptr;
}

void Factory::deleteComponents()
{
    /*for (ecs::Component* comp : compsCreated)
    {
        if (comp != nullptr)
        {
            delete comp;
            comp = nullptr;
        }
    }*/
}
