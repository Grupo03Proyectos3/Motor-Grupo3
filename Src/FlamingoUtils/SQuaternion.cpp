#include "SQuaternion.h"
#include <math.h>
#include <iostream>
#include <btBulletCollisionCommon.h>
SQuaternion::SQuaternion()
    : m_x(0)
    , m_y(0)
    , m_z(0)
    , m_w(1)
{
}

SQuaternion::SQuaternion(double t_x, double t_y, double t_z, double t_w)
    : m_x(t_x)
    , m_y(t_y)
    , m_z(t_z)
    , m_w(t_w)
{
}

void SQuaternion::setQuaternion(double t_x, double t_y, double t_z, double t_w)
{
    m_x = t_x;
    m_y = t_y;
    m_z = t_z;
    m_w = t_w;
}

double SQuaternion::getX()
{
    return m_x;
}

double SQuaternion::getY()
{
    return m_y;
}

double SQuaternion::getZ()
{
    return m_z;
}

double SQuaternion::getW()
{
    return m_w;
}

std::ostream& operator<<(std::ostream& out, const SQuaternion& q)
{
    out << q.m_x << " " 
        << q.m_y << " " 
        << q.m_z << " " 
        << q.m_w << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, SQuaternion& q)
{
    in >> q.m_x;
    in >> q.m_y;
    in >> q.m_z;
    in >> q.m_w;
    return in;
}

SQuaternion::operator Ogre::Quaternion() const
{
    return Ogre::Quaternion(m_x, m_y, m_z, m_w);
}

SQuaternion::operator btQuaternion() const
{
    return btQuaternion(m_x, m_y, m_z, m_w);
}

SQuaternion SQuaternion::ogreToSQuaternion(const Ogre::Quaternion& ogreQuaternion)
{
    return SQuaternion(ogreQuaternion.x, ogreQuaternion.y, ogreQuaternion.z, ogreQuaternion.w);
}


