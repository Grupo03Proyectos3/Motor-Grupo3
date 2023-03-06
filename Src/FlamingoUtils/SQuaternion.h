#pragma once

#ifndef __SQUATERNION_H__
#define __SQUATERNION_H__

#include <OgreQuaternion.h>
#include "SVector3.h"

class btQuaternion;
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
    SQuaternion(double angle, const SVector3& axis);
    SQuaternion(Ogre::Degree angle, const SVector3& axis);
    ~SQuaternion() = default;
    void setQuaternion(double t_x, double t_y, double t_z, double t_w);
    void setQuaternion(double angle, SVector3& axis);

     double getX();
    double getY();
    double getZ();
    double getW();

    void operator*=(const SQuaternion& other);

    friend std::ostream& operator<<(std::ostream& out, const SQuaternion& q);
    friend std::istream& operator>>(std::istream& in, SQuaternion& q);

    operator Ogre::Quaternion() const;
    operator btQuaternion() const;
    static SQuaternion ogreToSQuaternion(const Ogre::Quaternion& ogreQuaternion);
    static SQuaternion bulletToQuaternion(const btQuaternion& t_bullet_quaternion);

    SQuaternion inverse();
    double lenght();
    double dot(const SQuaternion& qother);
    double angle(const SQuaternion& other);


   

  private:
    double m_x;
    double m_y;
    double m_z;
    double m_w;
};
#endif