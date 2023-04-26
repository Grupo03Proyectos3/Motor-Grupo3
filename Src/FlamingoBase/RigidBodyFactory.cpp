#include "RigidBodyFactory.h"
#include "Physics/RigidBody.h"

ecs::Component* RigidBodyFactory::createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
{
    try
    {
        float mass = std::stof(args.at("t_mass"));
        bool trigger = std::stof(args.at("t_trigger"));
        bool is_static = std::stof(args.at("t_static"));

        RigidBody* c = ecs::AddComponent<RigidBody>(gO);
        c->initValues(mass, trigger, is_static);
        c->initComponent();

         ecs::Manager::instance()->addGameObjectToGroups(gO, {ecs::GROUP_PHYSICS});
        //compsCreated.push_back(c);
        return c;
       
    }
    catch (...)
    {
        std::cerr << "[ERROR RigidBody Factory]: Key not found" << '\n';
        exit(1);
    }
}
