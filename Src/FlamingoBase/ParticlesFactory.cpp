#include "ParticlesFactory.h"
#include "Render/ParticleSystem.h"
namespace Flamingo
{
    Component* ParticlesFactory::createComponent(GameObject* gO, const std::unordered_map<std::string, std::string>& args)
    {
        try
        {
            auto it_name = args.at("t_name");
            auto it_template = args.at("t_template");

            ParticleSystem* c = Manager::instance()->addComponent<ParticleSystem>(gO);
            c->initValues(it_name, it_template);

            Manager::instance()->addGameObjectToGroups(gO, {GROUP_PARTICLES});

            return c;
        }
        catch (...)
        {
            throw std::exception("[ERROR Particles Factory]:Key not found or valid");
        }
    }
} // namespace Flamingo