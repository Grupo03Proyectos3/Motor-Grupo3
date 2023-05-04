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
    struct Light : Component
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
        virtual ~Light();

        FLAMINGOEXPORT_API virtual void initValues(std::string t_name);
        FLAMINGOEXPORT_API virtual void initComponent();

        FLAMINGOEXPORT_API void setDirection(SVector3 t_direction);
        // Tipo de luz
        FLAMINGOEXPORT_API void setType(lightType t_l);
        // Colores
        FLAMINGOEXPORT_API void setDiffuseColour(float t_r = 1.0f, float t_g = 1.0f, float t_b = 1.0f);
        FLAMINGOEXPORT_API void setSpecularColour(float t_r = 0.5f, float t_g = 0.5f, float t_b = 0.5f);
        FLAMINGOEXPORT_API void setAttenuation(float t_range, float t_constat, float t_linear, float t_quadratic);
        // Spotlight
        FLAMINGOEXPORT_API void setSpotlightInnerAngle(float t_angle = 5.0f);
        FLAMINGOEXPORT_API void setSpotlightOuterAngle(float t_angle = 45.0f);
        FLAMINGOEXPORT_API void setSpotlightFalloff(float t_angle = 0.0f);
        FLAMINGOEXPORT_API void setSpotlightNearClipDistance(float t_nearClip);
        FLAMINGOEXPORT_API void setSpotlightRange(float t_in_angle, float t_out_angle, float falloff = 1.0f);
        // Apagar/Encender la luz
        FLAMINGOEXPORT_API void setVisible(bool t_visible);
        // Activar/desactivar sombras
        FLAMINGOEXPORT_API void setCastShadows(bool t_shadows);
        FLAMINGOEXPORT_API void setShadowFarClipDistance(float t_farClip);
        // Maxima distancia a la que se van a ver las sombras
        FLAMINGOEXPORT_API void setShadowFarDistance(float t_distance);
        FLAMINGOEXPORT_API void setShadowNearClipDistance(float t_nearClip);

        Ogre::SceneNode* getNode(); // NO EXPORTAR

      private:
        Ogre::Light* m_light = nullptr;
        Ogre::SceneManager* m_sceneMgr = nullptr;
        Ogre::SceneNode* m_light_node = nullptr;

        std::string m_name;
    };
} // namespace Flamingo
#endif