#include "UIElementFactory.h"
#include "UI/UIElement.h"

ecs::Component* UIElementFactory::createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
{
    try
    {
        Flamingo::UIElement* c = ecs::AddComponent<Flamingo::UIElement>(gO);
        c->initComponent();

        return c;
       
    }
    catch (const std::exception&)
    {
        throw new std::exception("Invalids or incompletes params");
    }
}
