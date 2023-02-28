#pragma once
#ifndef __RENDER_SYSTEM_H__
#define __RENDER_SYSTEM_H__

#include "../ECS/System.h"

#include <OgreEntity.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreSceneNode.h>

#include "Window.h"

class RenderSystem : public ecs::System
{
  public:
    __SYSTEM_ID_DECL__(ecs::_sys_RENDER)

    RenderSystem(){};
    ~RenderSystem() override;

    void recieve(const Message&) override;
    void initSystem() override;
    void update(float t_delta_time) override;

    Ogre::SceneManager* getSceneMngr();
    inline OgreWindow::Window* getWindow() { return m_window; }

  private:
    OgreWindow::Window* m_window = nullptr;
    Ogre::SceneManager* m_scene_mgr = nullptr;
    Ogre::SceneNode* m_scene_node = nullptr;
};

#endif