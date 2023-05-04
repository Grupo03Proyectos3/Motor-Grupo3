#include "AnimatorFactory.h"
#include "Render/Animator.h"
#include "ECS/Manager.h"
#include "Render/RenderSystem.h"
namespace Flamingo
{

    AnimatorFactory::AnimatorFactory(Flamingo::RenderSystem* t_renderSystem)
    {
    }

    Flamingo::Component* AnimatorFactory::createComponent(Flamingo::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
    {
        try
        {
            std::string name = (args.at("t_name"));

            Flamingo::Animator* c = Manager::instance()->addComponent<Flamingo::Animator>(gO);
            c->initValues(name);

            Flamingo::Manager::instance()->addGameObjectToGroups(gO, {Flamingo::GROUP_RENDER});

            return c;
        }
        catch (...)
        {
            throw std::exception("[ERROR Animator Factory]: Key not found or valid");
        }
    }
} // namespace Flamingo