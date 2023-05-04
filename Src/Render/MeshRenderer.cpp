#include "MeshRenderer.h"

#include "ECS/Manager.h"
#include "ECS/ManagerFunctions.h"
#include "FlamingoBase/Transform.h"
#include "FlamingoUtils/SVector3.h"
#include "RenderSystem.h"

#include <OgreAxisAlignedBox.h>
#include <OgreEntity.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>

namespace Flamingo
{
    void MeshRenderer::initValues(SVector3 scaleNode, std::string t_model_name, std::string t_entity_name)
    {
        m_scene_mngr = FlamingoSceneManager().getSceneActive()->getSceneManger();
        m_entity_name = t_entity_name;
        m_model_name = t_model_name;
        m_material_name = "";

        try
        {
            m_ent_ogre = m_scene_mngr->createEntity(m_entity_name, m_model_name);
        }
        catch (...)
        {
            m_scene_node = nullptr;
            throw std::runtime_error("[ERROR Mesh Renderer]: Mesh name is different from .mesh name");
        }

        m_scene_node = FlamingoSceneManager().getSceneActive()->getSceneRoot()->createChildSceneNode();
        m_scale_diff = scaleNode;
    }

    void MeshRenderer::initComponent()
    {
        // auto sys = m_mngr->getSystem<RenderSystem>();

        auto t = getComponent<Transform>(m_ent);

        if (t == nullptr)
        {
            throw std::exception("Transform is missing");
        }

        // hay que tener en cuenta m_sclae_diff, hacerlo
        m_scene_node->setScale(t->getScale());
        m_scene_node->setPosition(t->getPosition());
        m_scene_node->setOrientation(t->getRotation());
        m_scene_node->attachObject(m_ent_ogre);

        if (m_material_name != "")
            m_ent_ogre->setMaterialName(m_material_name);
    }
    void MeshRenderer::changeMaterial(std::string t_materialName)
    {
        m_material_name = t_materialName;
        if (m_material_name != "")
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

    Ogre::AxisAlignedBox MeshRenderer::getBoundingBox()
    {
        return m_ent_ogre->getBoundingBox();
    }

    Ogre::Entity* MeshRenderer::getEntity()
    {
        return m_ent_ogre;
    }

    Ogre::SceneNode* MeshRenderer::getNode()
    {
        return m_scene_node;
    }

    MeshRenderer::~MeshRenderer()
    {
        // delete m_ent_ore;
        if (m_scene_node != nullptr)
            m_scene_node->detachAllObjects();
        m_ent_ogre = nullptr;
    }
} // namespace Flamingo
