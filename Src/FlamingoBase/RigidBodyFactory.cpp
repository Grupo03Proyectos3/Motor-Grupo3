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

            RigidBody* c = Manager::instance()->addComponent<RigidBody>(gO);
            c->initValues(mass, trigger, is_static);

            Manager::instance()->addGameObjectToGroups(gO, {GROUP_PHYSICS});

            return c;
        }
        catch (...)
        {
            throw std::exception("[ERROR RigidBody Factory]:Key not found or valid");
        }
    }
} // namespace Flamingo