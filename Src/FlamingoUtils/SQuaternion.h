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
    FLAMINGOEXPORT_API class SQuaternion
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
        operator CEGUI::Quaternion();

        static SQuaternion ogreToSQuaternion(const Ogre::Quaternion& ogreQuaternion);
        static SQuaternion bulletToQuaternion(const btQuaternion& t_bullet_quaternion);
        static SQuaternion ceguiToSQuaternion(const CEGUI::Quaternion& ceguiQuaternion);
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
} // namespace Flamingo
#endif