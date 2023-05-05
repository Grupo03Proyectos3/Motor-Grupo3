#ifndef __MESH_RENDERER_H__
#define __MESH_RENDERER_H__

#include "ECS/Component.h"
#include "FlamingoUtils/SVector3.h"

namespace Ogre
{
    class AxisAlignedBox;
    class OgreEntity;
    class Entity;
    class SceneNode;
    class Entity;
    class SceneManager;
} // namespace Ogre


namespace Flamingo
{
    struct  MeshRenderer : public Component
    {
      public:
        __SYSTEM_ID_DECL__(_cmp_MESH_RENDERER)

        MeshRenderer(){};
        virtual ~MeshRenderer();
        FLAMINGOEXPORT_API virtual void initValues(SVector3 scaleNode, std::string t_model_name, std::string t_entity_name);
        FLAMINGOEXPORT_API virtual void initComponent();
        FLAMINGOEXPORT_API void changeMaterial(std::string t_materialName);
        FLAMINGOEXPORT_API void onDisable();
        FLAMINGOEXPORT_API void onEnable();
        /**
        @brief Establece la distancia a la que ya no se renderiza el objeto.
        **/       
        FLAMINGOEXPORT_API void setRenderingDistance(float t_d);
        /**
       @brief Establece si la visualización de depuración de este objeto está habilitada o no.
       **/  
        FLAMINGOEXPORT_API void setDebugVisibility(bool t_b);
        /**
        @brief Establece si este objeto proyectará o no sombras.
        **/  
        FLAMINGOEXPORT_API void setCastShadows(bool t_b);

        Ogre::AxisAlignedBox getBoundingBox(); // NO EXPORTAR
        Ogre::Entity* getEntity();   
        Ogre::SceneNode* getNode();

      protected:
        Ogre::Entity* m_ent_ogre;
        Ogre::SceneManager* m_scene_mngr;
        Ogre::SceneNode* m_scene_node;
        Flamingo::SVector3 m_scale_diff;

        std::string m_material_name;
        std::string m_entity_name;
        std::string m_model_name;
    };
} // namespace Flamingo
#endif