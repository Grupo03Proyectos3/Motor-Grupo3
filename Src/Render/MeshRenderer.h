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
    __declspec(dllexport) struct MeshRenderer : public Component
    {
      public:
        __SYSTEM_ID_DECL__(_cmp_MESH_RENDERER)

        MeshRenderer(){};
        virtual ~MeshRenderer();
        virtual void initValues(SVector3 scaleNode, std::string t_model_name, std::string t_entity_name);
        virtual void initComponent();

        void changeMaterial(std::string t_materialName);
        void onDisable();
        void onEnable();
        void setRenderingDistance(float t_d);
        void setDebugVisibility(bool t_b);
        void setCastShadows(bool t_b);
        void attachObjectToBone(std::string t_bone_name, Ogre::Entity* t_ent); // NO EXPORTAR
        void detachObjectFromBone(Ogre::Entity* t_ent);                        // NO EXPORTAR
        void detachObjectFromBone(std::string t_bone);

        Ogre::AxisAlignedBox getBoundingBox(); // NO EXPORTAR
        Ogre::Entity* getEntity();    // NO EXPORTAR
        Ogre::SceneNode* getNode(); // NO EXPORTAR

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