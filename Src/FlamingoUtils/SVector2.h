#pragma once

#ifndef __SVECTOR2_H__
#define __SVECTOR2_H__



#include <iostream>
#include "FlamingoExport/FlamingoAPI.h" 

namespace Ogre
{
    typedef float Real;
    template <int dims, typename T>
    class Vector;
    typedef Vector<2, Real> Vector2;
} // namespace Ogre
namespace CEGUI
{
    template<typename T>
    class Vector2;

    template<typename T>
    using Vector2_value_type = typename Vector2<T>::value_type;
}
/**
 * Clase base que usaremos como interprete entre todos los demás vector3 presentes en el motor (ogreVector3, FModVector3...)
 * Almacena los valores de un Vector3 y cuenta con setters, getters, conversores a las otras clases Vector3 y métodos que se irán añadiendo
 * relacionados con transformaciones en éste.
 */
namespace Flamingo
{

    class SVector2
    {
      public:
        FLAMINGOEXPORT_API SVector2();
        FLAMINGOEXPORT_API SVector2(double t_x, double t_y);
        FLAMINGOEXPORT_API ~SVector2() = default;
        FLAMINGOEXPORT_API void setVector2(double t_x, double t_y);

        FLAMINGOEXPORT_API double getX();
        FLAMINGOEXPORT_API double getY();

        FLAMINGOEXPORT_API void operator+=(const SVector2& other);
        FLAMINGOEXPORT_API void operator-=(const SVector2& other);

        FLAMINGOEXPORT_API void operator*=(float v);
        FLAMINGOEXPORT_API void operator/=(float v);

        FLAMINGOEXPORT_API bool operator==(const SVector2& other);
        FLAMINGOEXPORT_API bool operator!=(const SVector2& other);

        FLAMINGOEXPORT_API SVector2 operator+(const SVector2& other);
        FLAMINGOEXPORT_API SVector2 operator-(const SVector2& other);
        FLAMINGOEXPORT_API SVector2 operator*(const float& v);
        FLAMINGOEXPORT_API SVector2 operator/(const float& v);

        FLAMINGOEXPORT_API friend std::ostream& operator<<(std::ostream& out, const SVector2& v);
        FLAMINGOEXPORT_API friend std::istream& operator>>(std::istream& in, SVector2& v);

        FLAMINGOEXPORT_API double magnitude();
        FLAMINGOEXPORT_API double sqrMagnitude();
        FLAMINGOEXPORT_API SVector2 normalized();
        FLAMINGOEXPORT_API void normalize();

        FLAMINGOEXPORT_API static double distance(const SVector2& a, const SVector2& b);
        FLAMINGOEXPORT_API static double angle(const SVector2& a, const SVector2& b);

        // static Ogre::Vector3 sVectorToOgre(const SVector3& sVector);
        operator Ogre::Vector2() const;
        operator CEGUI::Vector2<double>() const;
        operator CEGUI::Vector2<int>() const;
        operator CEGUI::Vector2<float>() const;
        // operator FMOD_VECTOR() const;
        static SVector2 ogreToSVector2(const Ogre::Vector2& t_ogreVector);
        static SVector2 ceguiToSVector2(const CEGUI::Vector2<double>& t_ogreVector);
        static SVector2 ceguiToSVector2(const CEGUI::Vector2<int>& t_ogreVector);
        static SVector2 ceguiToSVector2(const CEGUI::Vector2<float>& t_ogreVector);
        // static SVector3 fmodToSVector3(const FMOD_VECTOR& fModVector);

      private:
        double m_x;
        double m_y;
    };
} // namespace Flamingo
#endif
