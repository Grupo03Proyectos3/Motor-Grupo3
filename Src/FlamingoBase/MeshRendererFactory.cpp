#include "MeshRendererFactory.h"
#include "Render/MeshRenderer.h"


MeshRendererFactory::MeshRendererFactory(RenderSystem* t_renderSystem)
{
    m_renderSystem = t_renderSystem;
    root = m_renderSystem->getSceneManager()->getSceneActive()->getSceneRoot();
}

ecs::Component* MeshRendererFactory::createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
{
    try
    {
        std::string modelName = (args.at("t_model_name"));
        std::string entityName= (args.at("t_entity_name"));
        std::string matName= (args.at("t_mat_name"));
        float s_x = std::stof(args.at("t_node_x"));
        float s_y = std::stof(args.at("t_node_y"));
        float s_z = std::stof(args.at("t_node_z"));

        MeshRenderer* c = ecs::AddComponent<MeshRenderer>(gO);
        c->initValues(root->createChildSceneNode(), m_renderSystem->getSceneManager()->getSceneActive()->getSceneManger(), Ogre::Vector3(s_x, s_y, s_z), modelName, entityName);
        c->changeMaterial(matName);
        c->initComponent();



        //compsCreated.push_back(c);
        return c;
       
    }
    catch (const std::exception&)
    {
        throw new std::exception("Invalids or incompletes params");
    }
}
