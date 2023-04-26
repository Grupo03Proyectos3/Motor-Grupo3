#include "MeshRendererFactory.h"
#include "Render/MeshRenderer.h"

MeshRendererFactory::MeshRendererFactory(Flamingo::RenderSystem* t_renderSystem)
{
    m_renderSystem = t_renderSystem;
    root = Flamingo::SceneMngr().getSceneActive()->getSceneRoot();
}

ecs::Component* MeshRendererFactory::createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
{
    try
    {
        std::string modelName = (args.at("t_model_name"));
        std::string entityName = (args.at("t_entity_name"));
        std::string matName = (args.at("t_mat_name"));
        float s_x = std::stof(args.at("t_node_x"));
        float s_y = std::stof(args.at("t_node_y"));
        float s_z = std::stof(args.at("t_node_z"));
        Flamingo::MeshRenderer* c = ecs::AddComponent<Flamingo::MeshRenderer>(gO);
        c->initValues(SVector3(s_x, s_y, s_z), modelName, entityName);
        c->changeMaterial(matName);
        c->initComponent();

        ecs::Manager::instance()->addGameObjectToGroups(gO, {ecs::GROUP_RENDER});
        // compsCreated.push_back(c);
        return c;
    }
    catch (...)
    {
        std::cerr << "[ERROR MeshRenderer Factory]: Key not found" << '\n';
        exit(1);
    } 
}
