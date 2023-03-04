#include "MeshRenderer.h"
#include <ECS/Manager.h>

MeshRenderer::MeshRenderer(Ogre::Entity* t_entity, Ogre::String t_materialName)
{
    m_ent_ogre = t_entity;
    m_materialName = t_materialName;
    if (m_materialName != "")
        m_ent_ogre->setMaterialName(m_materialName);
}
void MeshRenderer::initComponent()
{
    
}
void MeshRenderer::changeMaterial(std::string t_materialName)
{
    m_materialName = t_materialName;
    m_ent_ogre->setMaterialName(m_materialName);
}
