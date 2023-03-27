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

        //compsCreated.push_back(c);
        return c;
       
    }
    catch (const std::exception&)
    {
        throw new std::exception("Invalids or incompletes params");
    }
}
