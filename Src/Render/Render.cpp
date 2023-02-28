#include "Render.h"

Render::Render(){
    m_scene_node = nullptr;
    m_ent = nullptr;
    m_materialName = "";
}
void Render::initComponent(Ogre::SceneNode* t_root, Ogre::Entity* t_entity, std::string t_materialName) {
    m_scene_node = t_root;
    m_ent = t_entity;
    m_materialName = t_materialName;
    if (m_materialName != "") m_ent->setMaterialName(m_materialName);

    //configurar con posicion
}