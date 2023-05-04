#pragma once

#ifndef __SVECTOR3_H__
#define __SVECTOR3_H__

#include <iostream>
#include "FlamingoExport/FlamingoAPI.h"

namespace Ogre
{
    typedef float Real;
    template <int dims, typename T>
    class Vector;
    typedef Vector<3, Real> Vector3;
} // namespace Ogre

class btVector3;
//#include <fmod_common.h>

namespace Flamingo
{
    /**
     * Clase base que usaremos como interprete entre todos los demás vector3 presentes en el motor (ogreVector3, FModVector3...)
     * Almacena los valores de un Vector3 y cuenta con setters, getters, conversores a las otras clases Vector3 y métodos que se irán añadiendo
     * relacionados con transformaciones en éste.
     */
    class SVector3
    {
      public:
        FLAMINGOEXPORT_API SVector3();
        FLAMINGOEXPORT_API SVector3(double t_x, double t_y, double t_z);
        FLAMINGOEXPORT_API ~SVector3() = default;
        FLAMINGOEXPORT_API void setVector3(double t_x, double t_y, double t_z);

        FLAMINGOEXPORT_API double getX();
        FLAMINGOEXPORT_API double getY();
        FLAMINGOEXPORT_API double getZ();

        FLAMINGOEXPORT_API void operator+=(const SVector3& other);
        FLAMINGOEXPORT_API void operator-=(const SVector3& other);

        FLAMINGOEXPORT_API void operator*=(float v);
        FLAMINGOEXPORT_API void operator/=(float v);

        FLAMINGOEXPORT_API bool operator==(const SVector3& other);
        FLAMINGOEXPORT_API bool operator!=(const SVector3& other);

        FLAMINGOEXPORT_API SVector3 operator+(const SVector3& other);
        FLAMINGOEXPORT_API SVector3 operator-(const SVector3& other);
        FLAMINGOEXPORT_API SVector3 operator*(const SVector3& other);
        FLAMINGOEXPORT_API SVector3 operator*(const float& v);
        FLAMINGOEXPORT_API SVector3 operator*(const double& v);
        FLAMINGOEXPORT_API SVector3 operator/(const float& v);

        FLAMINGOEXPORT_API friend std::ostream& operator<<(std::ostream& out, const SVector3& v);
        FLAMINGOEXPORT_API friend std::istream& operator>>(std::istream& in, SVector3& v);

        FLAMINGOEXPORT_API double magnitude();
        FLAMINGOEXPORT_API double sqrMagnitude();
        FLAMINGOEXPORT_API SVector3 normalized();
        FLAMINGOEXPORT_API void normalize();

        FLAMINGOEXPORT_API static double distance(const SVector3& a, const SVector3& b);
        FLAMINGOEXPORT_API static double angle(const SVector3& a, const SVector3& b);

        // static Ogre::Vector3 sVectorToOgre(const SVector3& sVector);
        operator Ogre::Vector3() const;
        operator btVector3() const;
        // operator FMOD_VECTOR() const;
        static SVector3 ogreToSVector3(const Ogre::Vector3& t_ogreVector);
        static SVector3 bulletToSVector3(const btVector3& t_bulletVector);
        // static SVector3 fmodToSVector3(const FMOD_VECTOR& fModVector);

        FLAMINGOEXPORT_API double lenght();

      private:
        double m_x;
        double m_y;
        double m_z;
    };
} // namespace Flamingo
#endif
