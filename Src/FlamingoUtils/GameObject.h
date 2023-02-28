#pragma once

#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include "ECS/Entity.h"
#include "ECS/Manager.h"
#include "SVector3.h"
#include "SQuaternion.h"

/**
 *  Clase base para todas las instancias que se encuentren en el juego.
 * Servirá de identificdor a la vez que almacena los valores del objeto en el mundo (posición, roatación y escala).
 * Estrechamente relacionado con las entidades del ECS las usa como base para consstruir su estructura.
 */
class GameObject
{
  public:
    GameObject();
    GameObject(ecs::Manager* t_mgr);
    GameObject(ecs::Manager* t_mgr, SVector3 t_position);
    GameObject(ecs::Manager* t_mgr, SVector3 t_position, SQuaternion t_rotation);
    GameObject(ecs::Manager* t_mgr, SVector3 t_position, SQuaternion t_rotation, SVector3 t_scale);
    GameObject(ecs::Manager* t_mgr, std::string t_name, SVector3 t_position, SQuaternion t_rotation, SVector3 t_scale);
    GameObject(ecs::Manager* t_mgr, ecs::groupId t_group, std::string t_name, SVector3 t_position, SQuaternion t_rotation, SVector3 t_scale);
    ~GameObject();

    bool isAlive();
    bool isActive();
    void setAlive(bool to);
    void setActive(bool to);

     operator Ogre::String() const;
   
    template <typename T, typename... Ts>
    inline T* addComponent(Ts&&... args)
    {
        return m_manager->addComponent<T>(m_entity, args...);
    }

    template <typename T>
    inline void removeComponent()
    {
        m_manager->removeComponent<T>(m_entity);
    }

    template <typename T>
    inline T* getComponent()
    {
        return m_manager->getComponent<T>(m_entity);
    }

    template <typename T>
    inline bool hasComponent()
    {
        return m_manager->hasComponent<T>(m_entity);
    }

    inline std::string getName() { return name; };

    inline SVector3 getPosition() { return position; };

    static void setManager(ecs::Manager* t_manager);

    SVector3 position;
    SQuaternion rotation;
    SVector3 scale;
    std::string name;

  private:
    ecs::Entity* m_entity = nullptr;
    bool m_active;

    static ecs::Manager* m_manager;
};
#endif
