#include "ComponentsFactory.h"

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

void ComponentsFactory::addFactory(const std::string& type, const Factory* f)
{
    componentFactories.emplace(type, f);
	
}
