#include "MeshRenderer.h"

#include <OgreSceneManager.h>

MeshRenderer::MeshRenderer(Ogre::SceneNode* t_node, Ogre::SceneManager* t_sceneMgr, Ogre::String t_model_name, Ogre::String t_entity_name)
    : m_ent_ogre(nullptr)
    , m_entity_name(t_entity_name)
    , m_scene_mngr(t_sceneMgr)
    , m_model_name(t_model_name)
    , m_material_name(/*"Prueba/default"*/ "")
{
    m_ent_ogre = m_scene_mngr->createEntity(m_entity_name, m_model_name);
    t_node->attachObject(m_ent_ogre);
}
void MeshRenderer::initComponent()
{
    if (m_material_name != "")
        m_ent_ogre->setMaterialName(m_material_name);
}
void MeshRenderer::changeMaterial(std::string t_materialName)
{
    m_material_name = t_materialName;
    m_ent_ogre->setMaterialName(m_material_name);
}

void MeshRenderer::onEnable()
{
    m_ent_ogre->setVisible(true);
}

void MeshRenderer::onDisable()
{
    m_ent_ogre->setVisible(false);
}

void MeshRenderer::setRenderingDistance(float t_d)
{
    m_ent_ogre->setRenderingDistance(t_d);
}

void MeshRenderer::setDebugVisibility(bool t_d)
{
    m_ent_ogre->setDebugDisplayEnabled(t_d);
}

void MeshRenderer::setCastShadows(bool t_shadow)
{
    m_ent_ogre->setCastShadows(t_shadow);
}

void MeshRenderer::attachObjectToBone(std::string t_bone_name, Ogre::Entity* t_ent)
{
    m_ent_ogre->attachObjectToBone(t_bone_name, t_ent);
}

void MeshRenderer::detachObjectFromBone(Ogre::Entity* t_ent)
{
    m_ent_ogre->detachObjectFromBone(t_ent);
}

void MeshRenderer::detachObjectFromBone(std::string t_bone)
{
    m_ent_ogre->detachObjectFromBone(t_bone);
}

Ogre::AxisAlignedBox MeshRenderer::getBoundingBox(bool t_d)
{
    return m_ent_ogre->getBoundingBox();
}

MeshRenderer::~MeshRenderer() {
    //delete m_ent_ogre;
    m_ent_ogre = nullptr;
}