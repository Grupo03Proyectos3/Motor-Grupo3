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

    enum lightType
    {
        DIRECTIONAL,
        POINT,
        SPOTLIGHT
    };

    Light(Ogre::SceneManager* t_sceneMgr, Ogre::SceneNode*t_scene_node);
    virtual ~Light(){};

    virtual void initComponent(std::string t_name);
    //Tipo de luz
    void setType(lightType t_l);
    //Colores
    void setDiffuseColour(float t_r = 1.0f, float t_g = 1.0f, float t_b = 1.0f);
    void setSpecularColour(float t_r = 0.5f, float t_g = 0.5f, float t_b = 0.5f);
    void setAttenuation(float t_range, float t_constat, float t_linear, float t_quadratic);
    //Spotlight
    void setSpotlightInnerAngle(float t_angle = 5.0f);
    void setSpotlightOuterAngle(float t_angle = 45.0f);
    void setSpotlightFalloff(float t_angle = 0.0f);
    void setSpotlightNearClipDistance(float t_nearClip);
    void setSpotlightRange(float t_in_angle, float t_out_angle, float falloff = 1.0f);
    //Apagar/Encender la luz
    void setVisible(bool t_visible);
    //Activar/desactivar sombras
    void setCastShadows(bool t_shadows);
    void setShadowFarClipDistance(float t_farClip);
    //Maxima distancia a la que se van a ver las sombras
    void setShadowFarDistance(float t_distance);
    void setShadowNearClipDistance(float t_nearClip);	

  private:
    Ogre::Light* m_light = nullptr;
    Ogre::SceneManager* m_sceneMgr = nullptr;
    Ogre::SceneNode* m_scene_node = nullptr;
};

#endif