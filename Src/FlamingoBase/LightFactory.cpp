#include "LightFactory.h"
#include "Render/Light.h"

LightFactory::LightFactory(RenderSystem* t_renderSystem)
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

        //compsCreated.push_back(c);
        ecs::Manager::instance()->addGameObjectToGroups(gO, {ecs::GROUP_RENDER});
        return c;
       
    }
    catch (const std::exception&)
    {
        throw new std::exception("Invalids or incompletes params");
    }
}
