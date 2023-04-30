#include "SVector2.h"

#include <OgreVector2.h>
#include <math.h>
#include <CEGUI/Vector.h>
//#include <LinearMath/btVector2.h>
//#include <OgreVector3.h>

namespace Flamingo{
    SVector2::SVector2()
        : m_x(0)
        , m_y(0)
    {
    }

    SVector2::SVector2(double t_x, double t_y)
        : m_x(t_x)
        , m_y(t_y)
    {
    }

    void SVector2::setVector2(double t_x, double t_y)
    {
        m_x = t_x;
        m_y = t_y;
    }

    double SVector2::getX()
    {
        return m_x;
    }

    double SVector2::getY()
    {
        return m_y;
    }

    void SVector2::operator+=(const SVector2& other)
    {
        m_x += other.m_x;
        m_y += other.m_y;
    }

    void SVector2::operator-=(const SVector2& other)
    {
        m_x -= other.m_x;
        m_y -= other.m_y;
    }

    void SVector2::operator*=(float v)
    {
        m_x *= v;
        m_y *= v;
    }

    void SVector2::operator/=(float v)
    {
        m_x /= v;
        m_y /= v;
    }

    bool SVector2::operator==(const SVector2& other)
    {
        return m_x == other.m_x && m_y == other.m_y;
    }

    bool SVector2::operator!=(const SVector2& other)
    {
        return m_x != other.m_x || m_y != other.m_y;
    }

    SVector2 SVector2::operator+(const SVector2& other)
    {
        return SVector2(m_x + other.m_x, m_y + other.m_y);
    }

    SVector2 SVector2::operator-(const SVector2& other)
    {
        return SVector2(m_x - other.m_x, m_y - other.m_y);
    }

    SVector2 SVector2::operator*(const float& v)
    {
        return SVector2(m_x * v, m_y * v);
    }

    SVector2 SVector2::operator/(const float& v)
    {
        return SVector2(m_x / v, m_y / v);
    }

    std::ostream& operator<<(std::ostream& out, const SVector2& v)
    {
        out << v.m_x << " "
            << v.m_y << " "
            << std::endl;
        return out;
    }

    std::istream& operator>>(std::istream& in, SVector2& v)
    {
        in >> v.m_x;
        in >> v.m_y;
        return in;
    }

    double SVector2::magnitude()
    {
        return sqrtf((m_x * m_x) + (m_y * m_y));
    }

    double SVector2::sqrMagnitude()
    {
        return (m_x * m_x) + (m_y * m_y);
    }

    SVector2 SVector2::normalized()
    {
        auto v = magnitude();

        if (v == 0)
            return SVector2(m_x, m_y);
        else
            return SVector2(m_x / v, m_y / v);
    }

    void SVector2::normalize()
    {
        auto v = magnitude();
        if (v != 0)
        {
            m_x /= v;
            m_y /= v;
        }
    }

    double SVector2::distance(const SVector2& a, const SVector2& b)
    {
        return sqrtf(pow(a.m_x - b.m_x, 2) + pow(a.m_y - b.m_y, 2));
    }

#define M_PI 3.14159265358979323846
    double SVector2::angle(const SVector2& a, const SVector2& b)
    {
        auto cos = ((a.m_x * b.m_x) + (a.m_y * b.m_y)) / (sqrtf(a.m_x * a.m_x + a.m_y * a.m_y) * sqrtf(b.m_x * b.m_x + b.m_y * b.m_y));

        return acos(cos) * (180. / M_PI);
    }

    SVector2::operator Ogre::Vector2() const
    {
        return Ogre::Vector2(/*-*/ (Ogre::Real)m_x, /*-*/ (Ogre::Real)m_y);
    }

    SVector2::operator CEGUI::Vector2<double>() const
    {
        return CEGUI::Vector2<double>(/*-*/ m_x, /*-*/ m_y);
    }

    SVector2::operator CEGUI::Vector2<int>() const
    {
        return CEGUI::Vector2<int>(/*-*/ m_x, /*-*/ m_y);
    }

    SVector2::operator CEGUI::Vector2<float>() const
    {
        return CEGUI::Vector2<float>(/*-*/ m_x, /*-*/ m_y);
    }

    SVector2 SVector2::ogreToSVector2(const Ogre::Vector2& t_ogre_vector)
    {
        return SVector2(t_ogre_vector.x, t_ogre_vector.y);
    }

    SVector2 SVector2::ceguiToSVector2(const CEGUI::Vector2<double>& t_ceguiVector)
    {
        return SVector2((double)t_ceguiVector.d_x, (double)t_ceguiVector.d_y);
    }

    SVector2 SVector2::ceguiToSVector2(const CEGUI::Vector2<int>& t_ceguiVector)
    {
        return SVector2((double)t_ceguiVector.d_x, (double)t_ceguiVector.d_y);
    }

    SVector2 SVector2::ceguiToSVector2(const CEGUI::Vector2<float>& t_ceguiVector)
    {
        return SVector2((double)t_ceguiVector.d_x, (double)t_ceguiVector.d_y);
    }
} // namespace Flamingo
