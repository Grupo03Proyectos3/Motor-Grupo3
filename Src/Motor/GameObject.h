#pragma once

#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include "ECS/Entity.h"
#include "ECS/Manager.h"
#include <OgreQuaternion.h>
#include <OgreVector3.h>
#include <string>

#include "Render/Camera.h"

/**
 * Clase de ejemplo SVector3 a falta de definir que Vector3 usaremos como base para el proyecto.
 * De momento solo almacena los datos básicos propios de un Quaternion similar al de Unity y actualiza el Ogre::Vector3 que contiene si se cambia su valor.
 */

class SVector3
{
  public:
    SVector3();
    SVector3(double t_x, double t_y, double t_z);
    ~SVector3() = default;
    void setVector3(double t_x, double t_y, double t_z);
    double getX();
    double getY();
    double getZ();

  private:
    double m_x;
    double m_y;
    double m_z;
    Ogre::Vector3 m_vector3;
};

/**
 * Clase de ejemplo SQuaternion a falta de definir que Quaternion usaremos como base para el proyecto.
 * De momento solo almacena los datos básicos propios de un Quaternion similar al de Unity y actualiza el Ogre::Vector3 que contiene si se cambia su valor.
 */
class SQuaternion
{
  public:
    SQuaternion();
    SQuaternion(double t_x, double t_y, double t_z, double t_w);
    ~SQuaternion() = default;
    void setQuaternion(double t_x, double t_y, double t_z, double t_w);
    double getX();
    double getY();
    double getZ();
    double getW();

  private:
    double m_x;
    double m_y;
    double m_z;
    double m_w;
    Ogre::Quaternion m_quaternion;
};

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
