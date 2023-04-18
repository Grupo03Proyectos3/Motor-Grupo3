#include "CameraFactory.h"
#include "Render/Camera.h"

CameraFactory::CameraFactory(RenderSystem* t_renderSystem)
{
    m_renderSystem = t_renderSystem;
    root = m_renderSystem->getSceneManager()->getSceneActive()->getSceneRoot();
}

ecs::Component* CameraFactory::createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
{
    try
    {
        std::string name = (args.at("t_name"));
        std::string entityName = (args.at("t_entity_name"));

        Camera* c = ecs::AddComponent<Camera>(gO);
        c->initValues(m_renderSystem->getSceneManager()->getSceneActive()->getSceneManger(), root->createChildSceneNode()
            , m_renderSystem->getWindow(), name);
        c->initComponent();

         ecs::Manager::instance()->addGameObjectToGroups(gO, {ecs::GROUP_RENDER});
        //compsCreated.push_back(c);
        return c;
    }
    catch (const std::exception&)
    {
        throw new std::exception("Invalids or incompletes params");
    }
}
