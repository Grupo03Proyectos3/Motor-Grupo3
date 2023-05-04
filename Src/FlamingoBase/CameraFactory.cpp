#include "CameraFactory.h"
#include "SceneManager.h"
#include "ECS/Manager.h"
#include "Render/Camera.h"
#include "Render/RenderSystem.h"
#include <OgreSceneNode.h>
#include <iostream>

namespace Flamingo
{
    CameraFactory::CameraFactory(Flamingo::RenderSystem* t_renderSystem)
    {
        m_renderSystem = t_renderSystem;
        root = Flamingo::FlamingoSceneManager().getSceneActive()->getSceneRoot();
    }

    Flamingo::Component* CameraFactory::createComponent(Flamingo::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
    {
        try
        {
            std::string name = (args.at("t_name"));
            std::string entityName = (args.at("t_entity_name"));

            Camera* c = Manager::instance()->addComponent<Camera>(gO);
            c->initValues(name);

            Flamingo::Manager::instance()->addGameObjectToGroups(gO, {Flamingo::GROUP_RENDER});
            return c;
        }
        catch (...)
        {
            throw std::exception("[ERROR Camera Factory]: Key not found or valid");
        }
    }
} // namespace Flamingo