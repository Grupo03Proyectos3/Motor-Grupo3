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
    }

    Flamingo::Component* CameraFactory::createComponent(Flamingo::GameObject* gO, const std::unordered_map<std::string, std::string>& args)
    {
        try
        {
            std::string name = (args.at("t_name"));
            std::string entityName = (args.at("t_entity_name"));
            float color_x = std::stof(args.at("t_color_x"));
            float color_y = std::stof(args.at("t_color_y"));
            float color_z = std::stof(args.at("t_color_z"));
            
              if (color_x < 0 || color_x > 1 || 
                  color_y < 0 || color_y > 1 || 
                  color_z < 0 || color_z > 1 )
                throw std::exception();

            Camera* c = Manager::instance()->addComponent<Camera>(gO);
            c->initValues(name, color_x, color_y, color_z);

            Flamingo::Manager::instance()->addGameObjectToGroups(gO, {Flamingo::GROUP_RENDER});
            return c;
        }
        catch (...)
        {
            throw std::exception("[ERROR Camera Factory]: Key not found or valid");
        }
    }
} // namespace Flamingo