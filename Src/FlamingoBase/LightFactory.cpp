#include "LightFactory.h"
#include "Render/Light.h"

LightFactory::LightFactory(RenderSystem* t_renderSystem)
{
    m_renderSystem = t_renderSystem;
}

ecs::Component* LightFactory::createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
{
    try
    {
        std::string name = (args.at("t_name"));

        Light* c = ecs::AddComponent<Light>(gO);
        c->initValues(m_renderSystem->getSceneManager()->getSceneActive()->getSceneManger(), m_renderSystem->getSceneManager()->getSceneActive()->getSceneRoot()->createChildSceneNode(), name);
        c->initComponent();

        compsCreated.push_back(c);
        return c;
       
    }
    catch (const std::exception&)
    {
        throw new std::exception("Invalids or incompletes params");
    }
}
