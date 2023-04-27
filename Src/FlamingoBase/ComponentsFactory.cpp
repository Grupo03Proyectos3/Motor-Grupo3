#include "ComponentsFactory.h"
#include <iostream>

namespace Flamingo
{
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

    Flamingo::Component* ComponentsFactory::addComponent(Flamingo::GameObject* gO, const std::string& type, std::unordered_map<std::string, std::string> args)
    {
        auto comp = componentFactories[type];
       
        if (comp == nullptr)
        {
            throw std::exception("Component name no valid");
        }       
       
        Flamingo::Component* c = componentFactories[type]->createComponent(gO, args);
        return c;
    }

    void ComponentsFactory::addFactory(std::string type, Factory* f)
    {
        componentFactories.emplace(type, f);
    }
} // namespace Flamingo