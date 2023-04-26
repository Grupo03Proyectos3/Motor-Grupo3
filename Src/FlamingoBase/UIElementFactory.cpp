#include "UIElementFactory.h"
#include "UI/UIElement.h"

ecs::Component* UIElementFactory::createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
{
    try
    {
        std::string name = (args.at("t_name"));
        std::string type = (args.at("t_type"));
        std::string text = (args.at("t_text"));
        std::string image = (args.at("t_image"));

        Flamingo::UIElement* c = ecs::AddComponent<Flamingo::UIElement>(gO);
        c->initValues(type, name, text, image);
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
