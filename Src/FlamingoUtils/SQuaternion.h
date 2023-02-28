#pragma once

#ifndef __SQUATERNION_H__
#define __SQUATERNION_H__

#include <OgreQuaternion.h>
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
#endif
