#pragma once

#ifndef __SQUATERNION_H__
#define __SQUATERNION_H__

#include "SVector3.h"
#include "FlamingoExport/FlamingoAPI.h"

class btQuaternion;

namespace Ogre
{
    class Degree;
    class Quaternion;
} // namespace Ogre
namespace CEGUI
{
    class Quaternion;
}

/**
 * Clase base que usaremos como interprete entre todos los demás quaterniones presentes en el motor (ogreQuaternion, bulletQuaternion...)
 * Almacena los valores de un Quaternion y cuenta con setters, getters, conversores a las otras clases Quaternion y métodos que se irán añadiendo
 * relacionados con transformaciones en éste.
 */
namespace Flamingo
{
    class SQuaternion
    {
      public:
        FLAMINGOEXPORT_API SQuaternion();
        FLAMINGOEXPORT_API SQuaternion(double t_x, double t_y, double t_z, double t_w);
        FLAMINGOEXPORT_API SQuaternion(double angle, const SVector3& axis);
        FLAMINGOEXPORT_API SQuaternion(Ogre::Degree angle, const SVector3& axis);
        FLAMINGOEXPORT_API ~SQuaternion() = default;
        FLAMINGOEXPORT_API void setQuaternion(double t_x, double t_y, double t_z, double t_w);
        FLAMINGOEXPORT_API void setQuaternion(double angle, SVector3& axis);

        FLAMINGOEXPORT_API double getX();
        FLAMINGOEXPORT_API double getY();
        FLAMINGOEXPORT_API double getZ();
        FLAMINGOEXPORT_API double getW();

        FLAMINGOEXPORT_API void operator*=(const SQuaternion& other);
        FLAMINGOEXPORT_API SQuaternion operator+(const SQuaternion& other);
        FLAMINGOEXPORT_API SQuaternion operator-(const SQuaternion& other);

        FLAMINGOEXPORT_API friend std::ostream& operator<<(std::ostream& out, const SQuaternion& q);
        FLAMINGOEXPORT_API friend std::istream& operator>>(std::istream& in, SQuaternion& q);

        FLAMINGOEXPORT_API operator Ogre::Quaternion() const;
        FLAMINGOEXPORT_API operator btQuaternion() const;
        FLAMINGOEXPORT_API operator CEGUI::Quaternion();

        static SQuaternion ogreToSQuaternion(const Ogre::Quaternion& ogreQuaternion);
        static SQuaternion bulletToQuaternion(const btQuaternion& t_bullet_quaternion);
        static SQuaternion ceguiToSQuaternion(const CEGUI::Quaternion& ceguiQuaternion);
        FLAMINGOEXPORT_API SQuaternion inverse();
        FLAMINGOEXPORT_API double lenght();
        FLAMINGOEXPORT_API double dot(const SQuaternion& qother);
        FLAMINGOEXPORT_API double angle(const SQuaternion& other);      

        FLAMINGOEXPORT_API SVector3 Rotate(SVector3 angle);
      private:
        double m_x;
        double m_y;
        double m_z;
        double m_w;
    };
} // namespace Flamingo
#endif