#include "Light.h"

#include <OgreSceneManager.h>
#include <OgreSceneNode.h>

Light::Light(Ogre::SceneManager* t_sceneMgr, Ogre::SceneNode* t_scene_node, std::string t_name):
     m_sceneMgr(t_sceneMgr)
    , m_scene_node(t_scene_node)
    , m_name(t_name)
{
}

void Light::initComponent()
{
    m_light = m_sceneMgr->createLight(m_name);
    m_light_node = m_scene_node->createChildSceneNode();
    //m_light_node->setPosition(Ogre::Vector3(0, 50, 0));
    //m_sceneMgr->setAmbientLight(Ogre::ColourValue::White);
    m_light_node->attachObject(m_light);
}

void Light::setDirection(SVector3 t_direction)
{
    m_light_node->setDirection(t_direction);
}

void Light::setType(lightType t_l)
{
    switch (t_l)
    {
        case Light::DIRECTIONAL:
            m_light->setType(Ogre::Light::LT_DIRECTIONAL);
            break;
        case Light::POINT:
            m_light->setType(Ogre::Light::LT_POINT);
            break;
        case Light::SPOTLIGHT:
            m_light->setType(Ogre::Light::LT_SPOTLIGHT);
            break;
        default:
            break;
    }
}

void Light::setDiffuseColour(float t_r, float t_g, float t_b)
{
    m_light->setDiffuseColour(t_r, t_g, t_b);
}

void Light::setSpecularColour(float t_r, float t_g, float t_b)
{
    m_light->setSpecularColour(t_r, t_g, t_b);
}

void Light::setAttenuation(float t_range, float t_constat, float t_linear, float t_quadratic)
{
    m_light->setAttenuation(t_range, t_constat, t_linear, t_quadratic);
}

void Light::setSpotlightInnerAngle(float t_angle)
{
    m_light->setSpotlightInnerAngle(Ogre::Degree(t_angle));
}

void Light::setSpotlightOuterAngle(float t_angle)
{
    m_light->setSpotlightOuterAngle(Ogre::Degree(t_angle));
}

void Light::setSpotlightFalloff(float t_angle)
{
    m_light->setSpotlightFalloff(0.0f);
}

void Light::setSpotlightNearClipDistance(float t_nearClip)
{
    m_light->setSpotlightNearClipDistance(t_nearClip);
}

void Light::setVisible(bool t_visible) {
    m_light->setVisible(t_visible);
}

void Light::setSpotlightRange(float t_in_angle, float t_out_angle, float t_falloff)
{
    m_light->setSpotlightRange(Ogre::Degree(t_in_angle), Ogre::Degree(t_out_angle), t_falloff);
}

void Light::setCastShadows(bool t_shadows)
{
    m_light->setCastShadows(t_shadows);
}

void Light::setShadowFarClipDistance(float t_farClip)
{
    m_light->setShadowFarClipDistance(t_farClip);
}

void Light::setShadowFarDistance(float t_distance)
{
    m_light->setShadowFarDistance(t_distance);
}

void Light::setShadowNearClipDistance(float t_nearClip)
{
    m_light->setShadowNearClipDistance(t_nearClip);
}

Ogre::SceneNode* Light::getLightNode() {
    return m_light_node;
}