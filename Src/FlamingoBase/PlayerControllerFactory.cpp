#include "PlayerControllerFactory.h"
#include "Physics/PlayerController.h"

ecs::Component* PlayerControllerFactory::createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
{
    try
    {
        float speed = std::stof(args.at("t_speed"));
        PlayerController* c = ecs::AddComponent<PlayerController>(gO);
        c->initValues(speed);
        c->initComponent();

        ecs::Manager::instance()->addGameObjectToGroups(gO, {ecs::GROUP_PHYSICS});
        return c;
       
    }
    catch (...)
    {
        std::cerr << "[ERROR PlayerController Factory]: Key does not found" << '\n';
        exit(1);
    }
}
