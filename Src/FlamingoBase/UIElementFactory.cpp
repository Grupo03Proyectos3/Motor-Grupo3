#include "UIElementFactory.h"
#include "UI/UIElement.h"

ecs::Component* UIElementFactory::createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
{
    try
    {
        Flamingo::UIElement* c = ecs::AddComponent<Flamingo::UIElement>(gO);
        c->initComponent();

        ecs::Manager::instance()->addGameObjectToGroups(gO, {ecs::GROUP_UI});
        return c;
       
    }
    catch (...)
    {
        std::cerr << "[ERROR UIElement Factory]: Key does not found" << '\n';
        exit(1);
    }
}
