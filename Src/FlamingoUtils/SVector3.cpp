#include "SVector3.h"

#include <math.h>
#include <LinearMath/btVector3.h>
#include <OgreVector3.h>
//#include <OgreVector3.h>

namespace Flamingo
{
    SVector3::SVector3()
        : m_x(0)
        , m_y(0)
        , m_z(0)
    {
    }

    SVector3::SVector3(double t_x, double t_y, double t_z)
        : m_x(t_x)
        , m_y(t_y)
        , m_z(t_z)
    {
    }

    void SVector3::setVector3(double t_x, double t_y, double t_z)
    {
        m_x = t_x;
        m_y = t_y;
        m_z = t_z;
    }

    double SVector3::getX()
    {
        return m_x;
    }

    double SVector3::getY()
    {
        return m_y;
    }

    double SVector3::getZ()
    {
        return m_z;
    }

    void SVector3::operator+=(const SVector3& other)
    {
        m_x += other.m_x;
        m_y += other.m_y;
        m_z += other.m_z;
    }

    void SVector3::operator-=(const SVector3& other)
    {
        m_x -= other.m_x;
        m_y -= other.m_y;
        m_z -= other.m_z;
    }

    void SVector3::operator*=(float v)
    {
        m_x *= v;
        m_y *= v;
        m_z *= v;
    }

    void SVector3::operator/=(float v)
    {
        m_x /= v;
        m_y /= v;
        m_z /= v;
    }

    bool SVector3::operator==(const SVector3& other)
    {
        return m_x == other.m_x && m_y == other.m_y && m_z == other.m_z;
    }

    bool SVector3::operator!=(const SVector3& other)
    {
        return m_x != other.m_x || m_y != other.m_y || m_z != other.m_z;
    }

    SVector3 SVector3::operator+(const SVector3& other)
    {
        return SVector3(m_x + other.m_x, m_y + other.m_y, m_z + other.m_z);
    }

    SVector3 SVector3::operator-(const SVector3& other)
    {
        return SVector3(m_x - other.m_x, m_y - other.m_y, m_z - other.m_z);
    }

    SVector3 SVector3::operator*(const float& v)
    {
        return SVector3(m_x * v, m_y * v, m_z * v);
    }

    SVector3 SVector3::operator*(const double& v)
    {
        return SVector3(m_x * v, m_y * v, m_z * v);
    }

    SVector3 SVector3::operator/(const float& v)
    {
        return SVector3(m_x / v, m_y / v, m_z / v);
    }

    std::ostream& operator<<(std::ostream& out, const SVector3& v)
    {
        out << v.m_x << " "
            << v.m_y << " "
            << v.m_z << std::endl;
        return out;
    }

    std::istream& operator>>(std::istream& in, SVector3& v)
    {
        in >> v.m_x;
        in >> v.m_y;
        in >> v.m_z;
        return in;
    }

    double SVector3::magnitude()
    {
        return sqrtf((m_x * m_x) + (m_y * m_y) + (m_z * m_z));
    }

    double SVector3::sqrMagnitude()
    {
        return (m_x * m_x) + (m_y * m_y) + (m_z * m_z);
    }

    SVector3 SVector3::normalized()
    {
        auto v = magnitude();

        if (v == 0)
            return SVector3(m_x, m_y, m_z);
        else
            return SVector3(m_x / v, m_y / v, m_z / v);
    }

    void SVector3::normalize()
    {
        auto v = magnitude();
        if (v != 0)
        {
            m_x /= v;
            m_y /= v;
            m_z /= v;
        }
    }

    double SVector3::distance(const SVector3& a, const SVector3& b)
    {
        return sqrtf(pow(a.m_x - b.m_x, 2) + pow(a.m_y - b.m_y, 2) + pow(a.m_z - b.m_z, 2));
    }

#define M_PI 3.14159265358979323846
    double SVector3::angle(const SVector3& a, const SVector3& b)
    {
        auto cos = ((a.m_x * b.m_x) + (a.m_y * b.m_y) + (a.m_z * b.m_z)) / (sqrtf(a.m_x * a.m_x + a.m_y * a.m_y + a.m_z * a.m_z) * sqrtf(b.m_x * b.m_x + b.m_y * b.m_y + b.m_z * b.m_z));

        return acos(cos) * (180. / M_PI);
    }

    // Ogre::Vector3 SVector3::sVectorToOgre(const SVector3& sVector)
    //{
    //     return Ogre::Vector3(sVector.m_x, sVector.m_y, sVector.m_z);
    // }

    SVector3::operator Ogre::Vector3() const
    {
        return Ogre::Vector3(/*-*/ (Ogre::Real)m_x, /*-*/ (Ogre::Real)m_y, (Ogre::Real)m_z);
    }

    SVector3::operator btVector3() const
    {
        return btVector3((btScalar)m_x, (btScalar)m_y, (btScalar)m_z);
    }

    // SVector3::operator FMOD_VECTOR() const
    //{
    //     FMOD_VECTOR v;
    //     v.x = m_x;
    //     v.y = m_y;
    //     v.z = m_z;
    //     return v;
    // }

    SVector3 SVector3::ogreToSVector3(const Ogre::Vector3& t_ogre_vector)
    {
        return SVector3(t_ogre_vector.x, t_ogre_vector.y, t_ogre_vector.z);
    }

    SVector3 SVector3::bulletToSVector3(const btVector3& t_bullet_vector)
    {
        return SVector3(t_bullet_vector.x(), t_bullet_vector.y(), t_bullet_vector.z());
    }

    double SVector3::lenght(){
        return std::sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
    }

    // SVector3 SVector3::fmodToSVector3(const FMOD_VECTOR& fModVector)
    //{
    //     return SVector3(fModVector.x, fModVector.y, fModVector.z);
    // }
} // namespace Flamingo
