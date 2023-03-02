#include "MeshRenderer.h"
#include <ECS/Manager.h>
#include "FlamingoBase/Transform.h"

MeshRenderer::MeshRenderer(Ogre::SceneNode* t_root, Ogre::Entity* t_entity, Ogre::String t_materialName)
{
    m_node = t_root;
    m_ent_ogre = t_entity;
    m_materialName = t_materialName;
    if (m_materialName != "")
        m_ent_ogre->setMaterialName(m_materialName);
    if (t_entity != nullptr)
        m_node->attachObject(m_ent_ogre);
}
void MeshRenderer::initComponent()
{
    setPosition(m_mngr->getComponent<Transform>(m_ent)->getPosition());
    setRotation(m_mngr->getComponent<Transform>(m_ent)->getRotation());
    setScale(m_mngr->getComponent<Transform>(m_ent)->getScale());
}

void MeshRenderer::setPosition(SVector3 t_pos)
{
    m_node->setPosition(t_pos);    
}

void MeshRenderer::setRotation(SQuaternion t_pos)
{
    m_node->setOrientation(t_pos);
}

void MeshRenderer::setScale(SVector3 t_pos)
{
    m_node->setScale(t_pos);
}

void MeshRenderer::changeMaterial(std::string t_materialName)
{
    m_materialName = t_materialName;
    m_ent_ogre->setMaterialName(m_materialName);
}
