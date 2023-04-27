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
        root = Flamingo::SceneMngr().getSceneActive()->getSceneRoot();
    }

    Component* LightFactory::createComponent(GameObject* gO, const std::unordered_map<std::string, std::string>& args)
    {
        try
        {
            std::string name = (args.at("t_name"));

            Light* c = addComponent<Light>(gO);
            c->initValues(Flamingo::SceneMngr().getSceneActive()->getSceneManger(), root->createChildSceneNode(), name);
            c->initComponent();

            Manager::instance()->addGameObjectToGroups(gO, {GROUP_RENDER});
            return c;
        }
        catch (...)
        {
            std::cerr << "[ERROR Light Factory]: Key not found" << '\n';
            exit(1);
        }
    }
} // namespace Flamingo