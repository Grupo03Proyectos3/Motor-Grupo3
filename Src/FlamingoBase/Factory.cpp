#include "Factory.h"

namespace Flamingo
{
    Factory::~Factory()
    {
        deleteComponents();
    }

    Flamingo::Component* Factory::createComponent(Flamingo::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
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
} // namespace Flamingo