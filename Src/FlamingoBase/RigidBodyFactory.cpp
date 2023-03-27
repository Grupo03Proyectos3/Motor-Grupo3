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

        //compsCreated.push_back(c);
        return c;
       
    }
    catch (const std::exception&)
    {
        throw new std::exception("Invalids or incompletes params");
    }
}