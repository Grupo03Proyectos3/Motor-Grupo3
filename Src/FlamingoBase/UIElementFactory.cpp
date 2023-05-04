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

            Flamingo::UIElement* c = Manager::instance()->addComponent<Flamingo::UIElement>(gO);
            c->initValues(type, name, text, image);

            Manager::instance()->addGameObjectToGroups(gO, {GROUP_UI});
            return c;
        }
        catch (...)
        {
            throw std::exception("[ERROR UI Factory]: Key not found or valid");
        }
    }
} // namespace Flamingo