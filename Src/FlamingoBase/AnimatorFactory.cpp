#include "AnimatorFactory.h"
#include "Render/Animator.h"

AnimatorFactory::AnimatorFactory(RenderSystem* t_renderSystem)
{
    m_renderSystem = t_renderSystem;
}

ecs::Component* AnimatorFactory::createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
{
    try
    {
        std::string name = (args.at("t_name"));
        
        Flamingo::Animator* c = ecs::AddComponent<Flamingo::Animator>(gO);
        c->initValues(m_renderSystem->getSceneManager()->getSceneActive()->getSceneManger());
        c->initComponent();

        compsCreated.push_back(c);
        return c;
    }
    catch (const std::exception&)
    {
        throw new std::exception("Invalids or incompletes params");
    }



}
