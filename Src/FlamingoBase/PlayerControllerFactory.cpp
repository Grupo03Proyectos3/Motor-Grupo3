#include "PlayerControllerFactory.h"
#include "Physics/PlayerController.h"
namespace Flamingo
{
    Component* PlayerControllerFactory::createComponent(GameObject* gO, const std::unordered_map<std::string, std::string>& args)
    {
        try
        {
            float speed = std::stof(args.at("t_speed"));
            PlayerController* c = addComponent<PlayerController>(gO);

            c->initValues(speed);

            Manager::instance()->addGameObjectToGroups(gO, {GROUP_PHYSICS});
            return c;
        }
        catch (...)
        {
            throw std::exception("[ERROR PlayerController Factory]: Key not found");
        }
    }
} // namespace Flamingo