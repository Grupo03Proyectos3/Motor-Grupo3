#include "Light.h"

#include <OgreLight.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreVector3.h>

#include "ECS/Manager.h"
#include "ECS/Components.h"
#include "FlamingoBase/Transform.h"
#include "RenderSystem.h"
namespace Flamingo
{
    void Light::initValues( std::string t_name)
    {
        auto sys = m_mngr->getSystem<RenderSystem>();
        m_sceneMgr = FlamingoSceneManager().getSceneActive()->getSceneManger();
        m_light_node = FlamingoSceneManager().getSceneActive()->getSceneRoot()->createChildSceneNode();
        m_name = t_name;
    }

    Light::~Light()
    {
        if (m_light != nullptr)
        {
            m_sceneMgr->destroyLight(m_light);
            //delete m_light;
            m_light = nullptr;
        }
        m_sceneMgr = nullptr;
    }

    void Light::initComponent()
    {
        auto t = getComponent<Transform>(m_ent);
        if (t == nullptr)
            throw std::exception("Transform is missing");
        
        m_light = m_sceneMgr->createLight(m_name);
        // m_sceneMgr->setAmbientLight(Ogre::ColourValue::White);
        m_light_node->setScale(t->getScale());
        m_light_node->setPosition(t->getPosition());
        m_light_node->setOrientation(t->getRotation());
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

    void Light::setVisible(bool t_visible)
    {
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

    Ogre::SceneNode* Light::getNode()
    {
        return m_light_node;
    }
} // namespace Flamingo