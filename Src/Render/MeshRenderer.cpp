#include "MeshRenderer.h"

#include "ECS/Components.h"
#include "FlamingoBase/Transform.h"

#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include "RenderSystem.h"
#include "FlamingoUtils/SVector3.h"
namespace Flamingo
{
    void MeshRenderer::initValues(SVector3 scaleNode, std::string t_model_name, std::string t_entity_name)
    {
        auto sys = m_mngr->getSystem<RenderSystem>();
        m_scene_mngr = SceneMngr().getSceneActive()->getSceneManger();
        m_entity_name = t_entity_name;
        m_model_name = t_model_name;
        m_material_name = "";
        try
        {
            m_ent_ogre = m_scene_mngr->createEntity(m_entity_name, m_model_name);
        }
        catch (...)
        {
            std::cerr << "[ERROR Mesh Renderer]: Mesh name is different from .mesh name" << '\n';
            exit(1);
        }

        m_scene_node = SceneMngr().getSceneActive()->getSceneRoot()->createChildSceneNode();
        m_scale_diff = scaleNode;

        auto t = ecs::getComponent<Transform>(m_ent);
        try
        {
            if (t == nullptr)
            {
                throw std::exception("Transform is missing");
            }
        }
        catch (std::exception& excepcion)
        {
            std::cerr << "[ERROR Mesh Renderer]: " << excepcion.what() << '\n';
            exit(1);
        }
        // hay que tener en cuenta m_sclae_diff, hacerlo
        m_scene_node->setScale(t->getScale());
        m_scene_node->setPosition(t->getPosition());
        m_scene_node->setOrientation(t->getRotation());
        m_scene_node->attachObject(m_ent_ogre);
    }

    void MeshRenderer::initComponent()
    {
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

    MeshRenderer::~MeshRenderer()
    {
        // delete m_ent_ogre;
        m_scene_node->detachAllObjects();
        m_ent_ogre = nullptr;
    }
} // namespace Flamingo
