#include "AnimatorFactory.h"
#include "Render/Animator.h"
#include "ECS/Manager.h"

AnimatorFactory::AnimatorFactory(Flamingo::RenderSystem* t_renderSystem)
{
    m_renderSystem = t_renderSystem;
    root = m_renderSystem->getSceneManager()->getSceneActive()->getSceneRoot();
}

ecs::Component* AnimatorFactory::createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
{
    try
    {
        std::string name = (args.at("t_name"));
        
        Flamingo::Animator* c = ecs::AddComponent<Flamingo::Animator>(gO);
        c->initValues(m_renderSystem->getSceneManager()->getSceneActive()->getSceneManger());
        c->initComponent();

        ecs::Manager::instance()->addGameObjectToGroups(gO, {ecs::GROUP_RENDER});

        return c;
    }
    catch (...)
    {
        std::cerr << "[ERROR Animator Factory]: Key not found" << '\n';
        exit(1);
    }



}
