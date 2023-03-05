#include "GameObject.h"
#include "Manager.h"

ecs::GameObject::GameObject(Ogre::SceneNode* t_scene_node)
    : m_current_comps()
    , m_alive()
    , m_active(true)
    , m_gId(_grp_GENERAL)
    , m_comps()
    , m_node(nullptr)
{
    m_current_comps.reserve(ecs::maxComponentId);
    if (m_node==nullptr)
        m_node = t_scene_node->createChildSceneNode();
}

ecs::GameObject::GameObject(Ogre::SceneNode* t_scene_node, ecs::groupId_type t_gId)
    : m_current_comps()
    , m_alive()
    , m_active(true)
    , m_gId(t_gId)
    , m_comps()
    , m_node(nullptr)
{
    m_current_comps.reserve(ecs::maxComponentId);
    if (m_node == nullptr)
        m_node = t_scene_node->createChildSceneNode();
}

ecs::GameObject::~GameObject()
{
    for (auto c : m_comps)
        if (c != nullptr)
            delete c;
}

void ecs::GameObject::setAlive(bool to)
{
    m_alive = to;
}

void ecs::GameObject::setActive(bool to)
{
    m_active = to;
}

std::string ecs::GameObject::getName()
{
    return m_name;
}

Ogre::SceneNode* ecs::GameObject::getNode() {
    return m_node;
}