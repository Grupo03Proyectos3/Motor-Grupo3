#include "LightFactory.h"
#include "Render/Light.h"
#include "SceneManager.h"
#include "ECS/Manager.h"
#include <iostream>

//Ogre
#include <OgreSceneNode.h>

namespace Flamingo
{
    LightFactory::LightFactory(Flamingo::RenderSystem* t_renderSystem)
    {
        m_renderSystem = t_renderSystem;
    }

    Component* LightFactory::createComponent(GameObject* gO, const std::unordered_map<std::string, std::string>& args)
    {
        try
        {
            std::string name = (args.at("t_name"));

            Light* c = Manager::instance()->addComponent<Light>(gO);
            c->initValues(name);

            Manager::instance()->addGameObjectToGroups(gO, {GROUP_RENDER});
            return c;
        }
        catch (...)
        {
             throw std::exception("[ERROR Light Factory]: Key not found or valid");
        }
    }
} // namespace Flamingo