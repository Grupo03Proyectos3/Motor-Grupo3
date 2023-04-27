#include "UIElementFactory.h"
#include "UI/UIElement.h"
#include <iostream>
namespace Flamingo
{
    Component* UIElementFactory::createComponent(GameObject* gO, const std::unordered_map<std::string, std::string>& args)
    {
        try
        {
            std::string name = (args.at("t_name"));
            std::string type = (args.at("t_type"));
            std::string text = (args.at("t_text"));
            std::string image = (args.at("t_image"));

            Flamingo::UIElement* c = addComponent<Flamingo::UIElement>(gO);
            c->initValues(type, name, text, image);
            c->initComponent();

            Manager::instance()->addGameObjectToGroups(gO, {GROUP_UI});
            return c;
        }
        catch (...)
        {
            std::cerr << "[ERROR UIElement Factory]: Key does not found" << '\n';
            exit(1);
        }
    }
} // namespace Flamingo