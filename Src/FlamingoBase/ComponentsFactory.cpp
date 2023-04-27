#include "ComponentsFactory.h"
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
        try
        {
            if (comp == nullptr)
            {
                throw std::exception("Component name no valid");
            }
        }
        catch (std::exception& excepcion)
        {
            std::cerr << "[ERROR Component]: " << excepcion.what() << '\n';
            exit(1);
        }
        Flamingo::Component* c = componentFactories[type]->createComponent(gO, args);
        return c;
    }

    void ComponentsFactory::addFactory(std::string type, Factory* f)
    {
        componentFactories.emplace(type, f);
    }
} // namespace Flamingo