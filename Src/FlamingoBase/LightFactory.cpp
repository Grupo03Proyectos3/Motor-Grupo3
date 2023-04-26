#include "LightFactory.h"
#include "Render/Light.h"

LightFactory::LightFactory(Flamingo::RenderSystem* t_renderSystem)
{
    m_renderSystem = t_renderSystem;
    root = m_renderSystem->getSceneManager()->getSceneActive()->getSceneRoot();
}

ecs::Component* LightFactory::createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
{
    try
    {
        std::string name = (args.at("t_name"));

        Light* c = ecs::AddComponent<Light>(gO);
        c->initValues(m_renderSystem->getSceneManager()->getSceneActive()->getSceneManger(), root->createChildSceneNode(), name);
        c->initComponent();

        ecs::Manager::instance()->addGameObjectToGroups(gO, {ecs::GROUP_RENDER});
        return c;
       
    }
    catch (...)
    {
        std::cerr << "[ERROR Light Factory]: Key not found" << '\n';
        exit(1);
    }
}
