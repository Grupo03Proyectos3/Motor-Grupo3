#pragma once
#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "../ECS/Component.h"
#include "../ECS/Entity.h"
#include "../ECS/Manager.h"

#include <OgreLight.h>
#include <string>

struct Light : public ecs::Component
{
  public:
    __SYSTEM_ID_DECL__(ecs::_cmp_LIGHT)

    Light(Ogre::SceneManager* t_sceneMgr, Ogre::SceneNode*t_scene_node);
    virtual ~Light(){};

    virtual void initComponent(std::string t_name);

  private:
    Ogre::Light* m_light = nullptr;
    Ogre::SceneManager* m_sceneMgr = nullptr;
    Ogre::SceneNode* m_scene_node = nullptr;
};

#endif