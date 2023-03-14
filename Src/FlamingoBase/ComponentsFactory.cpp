#include "ComponentsFactory.h"

ComponentsFactory::ComponentsFactory()
{
    componentFactories = std::map<std::string, Factory*>();
}

ecs::Component* ComponentsFactory::getComponent(const std::string& type, std::map<std::string, std::string> args)
{
    try
    {
        return componentFactories[type]->createComponent(args);
    }
    catch (const std::exception&)
    {
        return nullptr;
    }
}

void ComponentsFactory::addFactory(std::string& type, Factory* f)
{
    componentFactories.emplace(type, f);
	
}
