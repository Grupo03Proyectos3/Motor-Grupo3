#pragma once

#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include "ECS/Entity.h"
#include "ECS/Manager.h"
#include "FlamingoUtils/SVector3.h"
#include "FlamingoUtils/SQuaternion.h"
#include "Transform.h"
/**
 *  Clase base para todas las instancias que se encuentren en el juego.
 * Servirá de identificdor a la vez que almacena los valores del objeto en el mundo (posición, roatación y escala).
 * Estrechamente relacionado con las entidades del ECS las usa como base para consstruir su estructura.
 */
class GameObject : ecs::Entity
{
  public:
    GameObject(ecs::Manager* t_mgr = nullptr, SVector3 t_position = SVector3(), SQuaternion t_rotation = SQuaternion(), SVector3 t_scale=SVector3(1.0,1.0,1.0));
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
        return m_manager->addComponent<T>(this, args...);
    }

    template <typename T>
    inline void removeComponent()
    {
        m_manager->removeComponent<T>(this);
    }

    template <typename T>
    inline T* getComponent()
    {
        return m_manager->getComponent<T>(this);
    }

    template <typename T>
    inline bool hasComponent()
    {
        return m_manager->hasComponent<T>(this);
    }

    inline std::string getName() { return name; };

    SVector3 getPosition();
    SQuaternion getRotation();
    SVector3 getScale();

    void setPosition(SVector3 t_pos);
    void setRotation(SQuaternion t_rotation);
    void setScale(SVector3 t_scale);

    static void setManager(ecs::Manager* t_manager);

    std::string name;

  private:
    bool m_active;
    Transform* m_transform;
    static ecs::Manager* m_manager;
};
#endif
