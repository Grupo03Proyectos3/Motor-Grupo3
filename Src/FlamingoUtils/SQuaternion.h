#pragma once

#ifndef __SQUATERNION_H__
#define __SQUATERNION_H__

#include <OgreQuaternion.h>
/**
 * Clase base que usaremos como interprete entre todos los demás quaterniones presentes en el motor (ogreQuaternion, bulletQuaternion...)
 * Almacena los valores de un Quaternion y cuenta con setters, getters, conversores a las otras clases Quaternion y métodos que se irán añadiendo
 * relacionados con transformaciones en éste.
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

    friend std::ostream& operator<<(std::ostream& out, const SQuaternion& q);
    friend std::istream& operator>>(std::istream& in, SQuaternion& q);

    operator Ogre::Quaternion() const;
    static SQuaternion ogreToSQuaternion(const Ogre::Quaternion& ogreQuaternion);

  private:
    double m_x;
    double m_y;
    double m_z;
    double m_w;
};
#endif