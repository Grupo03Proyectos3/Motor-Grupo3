#include "PlayerControllerFactory.h"
#include "Physics/PlayerController.h"
namespace Flamingo
{
    Component* PlayerControllerFactory::createComponent(GameObject* gO, const std::unordered_map<std::string, std::string>& args)
    {
        try
        {
            float speed = std::stof(args.at("t_speed"));
            PlayerController* c = AddComponent<PlayerController>(gO);
            c->initValues(speed);
            c->initComponent();

            Manager::instance()->addGameObjectToGroups(gO, {GROUP_PHYSICS});
            return c;
        }
        catch (...)
        {
            std::cerr << "[ERROR PlayerController Factory]: Key does not found" << '\n';
            exit(1);
        }
    }
} // namespace Flamingo