#pragma once
#ifndef __MESH_RENDERER_H__
#define __MESH_RENDERER_H__
#include "ECS/Component.h"

#include <OgreAxisAlignedBox.h>
#include <OgreEntity.h>
#include <OgreSceneNode.h>

struct MeshRenderer : public ecs::Component
{
  public:
    __SYSTEM_ID_DECL__(ecs::_cmp_MESH_RENDERER)

    MeshRenderer(){};
    virtual ~MeshRenderer();
    virtual void initValues(Ogre::SceneNode* t_node, Ogre::SceneManager* t_sceneMgr, Ogre::Vector3 scaleNode, Ogre::String t_model_name, Ogre::String t_entity_name);
    virtual void initComponent();

    void changeMaterial(std::string t_materialName);
    void onDisable();
    void onEnable();
    void setRenderingDistance(float t_d);
    void setDebugVisibility(bool t_b);
    void setCastShadows(bool t_b);
    void attachObjectToBone(std::string t_bone_name, Ogre::Entity* t_ent);
    void detachObjectFromBone(Ogre::Entity* t_ent);
    void detachObjectFromBone(std::string t_bone);

    Ogre::AxisAlignedBox getBoundingBox();
    inline Ogre::Entity* getEntity() { return m_ent_ogre; };
    inline Ogre::SceneNode* getNode() { return m_scene_node; };

  protected:
    Ogre::Entity* m_ent_ogre;
    Ogre::SceneManager* m_scene_mngr;
    Ogre::SceneNode* m_scene_node;
    Ogre::Vector3 m_scale_diff;

    std::string m_material_name;
    std::string m_entity_name;
    std::string m_model_name;
};
#endif