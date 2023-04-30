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
    FLAMINGOEXPORT_API class SVector3
    {
      public:
        SVector3();
        SVector3(double t_x, double t_y, double t_z);
        ~SVector3() = default;
        void setVector3(double t_x, double t_y, double t_z);

        double getX();
        double getY();
        double getZ();

        void operator+=(const SVector3& other);
        void operator-=(const SVector3& other);

        void operator*=(float v);
        void operator/=(float v);

        bool operator==(const SVector3& other);
        bool operator!=(const SVector3& other);

        SVector3 operator+(const SVector3& other);
        SVector3 operator-(const SVector3& other);
        SVector3 operator*(const float& v);
        SVector3 operator/(const float& v);

        friend std::ostream& operator<<(std::ostream& out, const SVector3& v);
        friend std::istream& operator>>(std::istream& in, SVector3& v);

        double magnitude();
        double sqrMagnitude();
        SVector3 normalized();
        void normalize();

        static double distance(const SVector3& a, const SVector3& b);
        static double angle(const SVector3& a, const SVector3& b);

        // static Ogre::Vector3 sVectorToOgre(const SVector3& sVector);
        operator Ogre::Vector3() const;
        operator btVector3() const;
        // operator FMOD_VECTOR() const;
        static SVector3 ogreToSVector3(const Ogre::Vector3& t_ogreVector);
        static SVector3 bulletToSVector3(const btVector3& t_bulletVector);
        // static SVector3 fmodToSVector3(const FMOD_VECTOR& fModVector);

        double lenght();

      private:
        double m_x;
        double m_y;
        double m_z;
    };
} // namespace Flamingo
#endif
