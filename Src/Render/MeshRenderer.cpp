#include "MeshRenderer.h"

MeshRenderer::MeshRenderer(Ogre::SceneNode* t_node, Ogre::Entity* t_entity, Ogre::String t_materialName)
    : m_ent_ogre(t_entity)
    , m_material_name(t_materialName)
{
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

MeshRenderer::~MeshRenderer() {
    delete m_ent_ogre;
    m_ent_ogre = nullptr;
}
