#include "ComponentsFactory.h"

ComponentsFactory::ComponentsFactory()
{
    componentFactories = std::map<std::string, Factory*>();
}

ComponentsFactory::~ComponentsFactory()
{
    for (auto f : componentFactories)
    {
        if (f.second != nullptr)
        {
            delete f.second;
            f.second = nullptr;
        }
    }
}

ecs::Component* ComponentsFactory::addComponent(ecs::GameObject* gO, const std::string& type, std::unordered_map<std::string, std::string> args)
{
    try
    {
        ecs::Component* c = componentFactories[type]->createComponent(gO, args);
        return c;
    }
    catch (const std::exception&)
    {
        return nullptr;
    }
}

void ComponentsFactory::addFactory(std::string type, Factory* f)
{
    componentFactories.emplace(type, f);
	
}
