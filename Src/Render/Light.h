#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "ECS/Component.h"
#include "FlamingoUtils/SVector3.h"
#include <string>

namespace Ogre
{
    class SceneNode;
    class SceneManager;
    class Light;
}

namespace Flamingo
{
    __declspec(dllexport) struct Light : Component
    {
      public:
        __SYSTEM_ID_DECL__(_cmp_LIGHT)

        enum lightType
        {
            DIRECTIONAL,
            POINT,
            SPOTLIGHT
        };

        Light(){};
        virtual ~Light(){};

        virtual void initValues(Ogre::SceneManager* t_sceneMgr, Ogre::SceneNode* t_scene_node, std::string t_name);
        virtual void initComponent();

        void setDirection(SVector3 t_direction);
        // Tipo de luz
        void setType(lightType t_l);
        // Colores
        void setDiffuseColour(float t_r = 1.0f, float t_g = 1.0f, float t_b = 1.0f);
        void setSpecularColour(float t_r = 0.5f, float t_g = 0.5f, float t_b = 0.5f);
        void setAttenuation(float t_range, float t_constat, float t_linear, float t_quadratic);
        // Spotlight
        void setSpotlightInnerAngle(float t_angle = 5.0f);
        void setSpotlightOuterAngle(float t_angle = 45.0f);
        void setSpotlightFalloff(float t_angle = 0.0f);
        void setSpotlightNearClipDistance(float t_nearClip);
        void setSpotlightRange(float t_in_angle, float t_out_angle, float falloff = 1.0f);
        // Apagar/Encender la luz
        void setVisible(bool t_visible);
        // Activar/desactivar sombras
        void setCastShadows(bool t_shadows);
        void setShadowFarClipDistance(float t_farClip);
        // Maxima distancia a la que se van a ver las sombras
        void setShadowFarDistance(float t_distance);
        void setShadowNearClipDistance(float t_nearClip);

        Ogre::SceneNode* getLightNode();

      private:
        Ogre::Light* m_light = nullptr;
        Ogre::SceneManager* m_sceneMgr = nullptr;
        // Ogre::SceneNode* m_scene_node = nullptr;
        Ogre::SceneNode* m_light_node = nullptr;

        std::string m_name;
    };
} // namespace Flamingo
#endif