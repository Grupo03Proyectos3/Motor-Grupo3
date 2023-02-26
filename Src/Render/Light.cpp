#include "Light.h"

#include <OgreSceneManager.h>
#include <OgreSceneNode.h>

Light::Light(Ogre::SceneManager* t_sceneMgr, Ogre::SceneNode* t_scene_node)
    : m_sceneMgr(t_sceneMgr)
    , m_scene_node(t_scene_node)
{
}

void Light::initComponent()
{
    m_light = m_sceneMgr->createLight("myLight");
    Ogre::SceneNode* light_node = m_scene_node->createChildSceneNode();
    m_light->setType(Ogre::Light::LT_DIRECTIONAL);
    light_node->setDirection(Ogre::Vector3(0, -1, 0));
    m_light->setDiffuseColour(Ogre::ColourValue(1.0f, 1.0f, 1.0f));
    m_light->setSpecularColour(Ogre::ColourValue(0.5f, 0.5f, 0.5f));
    light_node->attachObject(m_light);
}
