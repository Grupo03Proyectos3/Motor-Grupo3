#include "MeshRendererFactory.h"
#include "Render/MeshRenderer.h"


MeshRendererFactory::MeshRendererFactory(RenderSystem* t_renderSystem)
{
    m_renderSystem = t_renderSystem;
}

ecs::Component* MeshRendererFactory::createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
{
    try
    {
        std::string modelName = (args.at("t_model_name"));
        std::string entityName= (args.at("t_entity_name"));

        MeshRenderer* c = ecs::AddComponent<MeshRenderer>(gO);
        c->initValues(m_renderSystem->getSceneManager()->getSceneActive()->getSceneRoot()->createChildSceneNode(), m_renderSystem->getSceneManager()->getSceneActive()->getSceneManger(), modelName, entityName);
        c->initComponent();

        compsCreated.push_back(c);
        return c;
       
    }
    catch (const std::exception&)
    {
        throw new std::exception("Invalids or incompletes params");
    }
}
