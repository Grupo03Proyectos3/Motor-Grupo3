#include "CameraFactory.h"
#include "SceneManager.h"
#include "ECS/Manager.h"
#include "Render/Camera.h"
#include "Render/RenderSystem.h"
#include <iostream>

namespace Flamingo
{
    CameraFactory::CameraFactory(Flamingo::RenderSystem* t_renderSystem)
    {
        m_renderSystem = t_renderSystem;
        root = Flamingo::SceneMngr().getSceneActive()->getSceneRoot();
    }

    Flamingo::Component* CameraFactory::createComponent(Flamingo::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
    {
        try
        {
            std::string name = (args.at("t_name"));
            std::string entityName = (args.at("t_entity_name"));

            Camera* c = Flamingo::AddComponent<Camera>(gO);
            c->initValues(Flamingo::SceneMngr().getSceneActive()->getSceneManger(),
                          root->createChildSceneNode(), m_renderSystem->getWindow(), name);
            c->initComponent();

            Flamingo::Manager::instance()->addGameObjectToGroups(gO, {Flamingo::GROUP_RENDER});
            return c;
        }
        catch (...)
        {
            std::cerr << "[ERROR Camera Factory]: Key not found" << '\n';
            exit(1);
        }
    }
} // namespace Flamingo