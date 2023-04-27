#include "RigidBodyFactory.h"
#include "Physics/RigidBody.h"
namespace Flamingo{
    Component* RigidBodyFactory::createComponent(GameObject* gO, const std::unordered_map<std::string, std::string>& args)
    {
        try
        {
            float mass = std::stof(args.at("t_mass"));
            bool trigger = std::stof(args.at("t_trigger"));
            bool is_static = std::stof(args.at("t_static"));

            RigidBody* c = addComponent<RigidBody>(gO);
            c->initValues(mass, trigger, is_static);
            c->initComponent();

            Manager::instance()->addGameObjectToGroups(gO, {GROUP_PHYSICS});
            // compsCreated.push_back(c);
            return c;
        }
        catch (...)
        {
            std::cerr << "[ERROR RigidBody Factory]: Key not found" << '\n';
            exit(1);
        }
    }
} // namespace Flamingo