#include "SColor.h"
namespace Flamingo
{
    SColor::SColor(float t_r, float t_g, float t_b, float t_a)
        : m_r(t_r)
        , m_g(t_g)
        , m_b(t_b)
        , m_a(t_a)
    {
        saturate();
    }

    void SColor::setColor(float t_r, float t_g, float t_b, float t_a)
    {
        m_r = t_r;
        m_g = t_g;
        m_b = t_b;
        m_a = t_a;

        saturate();
    }

    bool SColor::operator==(const SColor& other)
    {
        return (m_r == other.m_r && m_g == other.m_g && m_b == other.m_b && m_a == other.m_a);
    }

    bool SColor::operator!=(const SColor& other)
    {
        return (m_r != other.m_r || m_g != other.m_g || m_b != other.m_b || m_a != other.m_a);
    }

    SColor SColor::operator+(const SColor& other)
    {
        SColor c;

        c.m_r = m_r + other.m_r;
        c.m_g = m_g + other.m_g;
        c.m_b = m_b + other.m_b;
        c.m_a = m_a + other.m_a;
        saturate(c);

        return c;
    }

    SColor SColor::operator-(const SColor& other)
    {
        SColor c;

        c.m_r = m_r - other.m_r;
        c.m_g = m_g - other.m_g;
        c.m_b = m_b - other.m_b;
        c.m_a = m_a - other.m_a;
        saturate(c);

        return c;
    }

    SColor SColor::operator*(const float& t_scalar)
    {
        SColor c;

        c.m_r = t_scalar * m_r;
        c.m_g = t_scalar * m_g;
        c.m_b = t_scalar * m_b;
        c.m_a = t_scalar * m_a;
        saturate(c);

        return c;
    }

    SColor SColor::operator*(const SColor& other)
    {
        SColor c;

        c.m_r = other.m_r * m_r;
        c.m_g = other.m_g * m_g;
        c.m_b = other.m_b * m_b;
        c.m_a = other.m_a * m_a;
        saturate(c);

        return c;
    }

    SColor SColor::operator/(const float& t_scalar)
    {
        if (t_scalar != 0.0)
        {
            SColor c;

            float fInv = 1.0f / t_scalar;
            c.m_r = m_r * fInv;
            c.m_g = m_g * fInv;
            c.m_b = m_b * fInv;
            c.m_a = m_a * fInv;
            saturate(c);

            return c;
        }
        else
            return *this;
    }

    SColor SColor::operator/(const SColor& other)
    {
        SColor c;

        c.m_r = m_r / other.m_r;
        c.m_g = m_g / other.m_g;
        c.m_b = m_b / other.m_b;
        c.m_a = m_a / other.m_a;
        saturate(c);

        return c;
    }

    void SColor::operator+=(const SColor& other)
    {
        m_r += other.m_r;
        m_g += other.m_g;
        m_b += other.m_b;
        m_a += other.m_a;

        saturate();
    }

    void SColor::operator-=(const SColor& other)
    {
        m_r -= other.m_r;
        m_g -= other.m_g;
        m_b -= other.m_b;
        m_a -= other.m_a;

        saturate();
    }

    void SColor::operator*=(const float& t_scalar)
    {
        m_r *= t_scalar;
        m_g *= t_scalar;
        m_b *= t_scalar;
        m_a *= t_scalar;

        saturate();
    }

    void SColor::operator/=(const float& t_scalar)
    {
        if (t_scalar != 0.0)
        {
            float fInv = 1.0f / t_scalar;

            m_r *= fInv;
            m_g *= fInv;
            m_b *= fInv;
            m_a *= fInv;

            saturate();
        }
    }

    SColor::operator Ogre::ColourValue() const
    {
        return Ogre::ColourValue(m_r, m_g, m_b, m_a);
    }

    SColor SColor::ogreToSColor(const Ogre::ColourValue& t_ogre_color)
    {
        return SColor(t_ogre_color.r, t_ogre_color.g, t_ogre_color.b, t_ogre_color.a);
    }

    void SColor::saturate()
    {
        if (m_r < 0)
            m_r = 0;
        else if (m_r > 1)
            m_r = 1;

        if (m_g < 0)
            m_g = 0;
        else if (m_g > 1)
            m_g = 1;

        if (m_b < 0)
            m_b = 0;
        else if (m_b > 1)
            m_b = 1;

        if (m_a < 0)
            m_a = 0;
        else if (m_a > 1)
            m_a = 1;
    }

    void SColor::saturate(SColor& t_c)
    {
        if (t_c.m_r < 0)
            t_c.m_r = 0;
        else if (t_c.m_r > 1)
            t_c.m_r = 1;

        if (t_c.m_g < 0)
            t_c.m_g = 0;
        else if (t_c.m_g > 1)
            t_c.m_g = 1;

        if (t_c.m_b < 0)
            t_c.m_b = 0;
        else if (t_c.m_b > 1)
            t_c.m_b = 1;

        if (t_c.m_a < 0)
            t_c.m_a = 0;
        else if (t_c.m_a > 1)
            t_c.m_a = 1;
    }

    std::ostream& operator<<(std::ostream& out, const SColor& c)
    {
        out << "Colour(" << c.m_r << ", " << c.m_g << ", " << c.m_b << ", " << c.m_a << ")";
        return out;
    }
} // namespace Flamingo