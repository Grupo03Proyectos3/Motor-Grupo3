#pragma once
#ifndef __SCOLOR_H__
#define __SCOLOR_H__

#include <OgreColourValue.h>
namespace Flamingo
{
    class SColor
    {
      public:
        SColor(float t_r = 1.0f, float t_g = 1.0f, float t_b = 1.0f, float t_a = 1.0f);
        ~SColor() = default;

        void setColor(float t_r, float t_g, float t_b, float t_a = 1.0f);

        bool operator==(const SColor& other);
        bool operator!=(const SColor& other);

        SColor operator+(const SColor& other);
        SColor operator-(const SColor& other);
        SColor operator*(const float& t_scalar);
        SColor operator*(const SColor& other);
        SColor operator/(const float& t_scalar);
        SColor operator/(const SColor& other);

        void operator+=(const SColor& other);
        void operator-=(const SColor& other);
        void operator*=(const float& t_scalar);
        void operator/=(const float& t_scalar);

        friend std::ostream& operator<<(std::ostream& out, const SColor& v);

        operator Ogre::ColourValue() const;
        static SColor ogreToSColor(const Ogre::ColourValue& t_ogre_color);

      private:
        float m_r;
        float m_g;
        float m_b;
        float m_a;

        void saturate();
        void saturate(SColor& t_c);
    };
} // namespace Flamingo
#endif
