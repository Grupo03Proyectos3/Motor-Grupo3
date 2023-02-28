#include "SQuaternion.h"

SQuaternion::SQuaternion()
    : m_x(0)
    , m_y(0)
    , m_z(0)
    , m_w(1)
{
    m_quaternion = Ogre::Quaternion(m_x, m_y, m_z, m_w);
}

SQuaternion::SQuaternion(double t_x, double t_y, double t_z, double t_w)
    : m_x(t_x)
    , m_y(t_y)
    , m_z(t_z)
    , m_w(t_w)
{
    m_quaternion = Ogre::Quaternion(m_x, m_y, m_z, m_w);
}

void SQuaternion::setQuaternion(double t_x, double t_y, double t_z, double t_w)
{
    m_x = t_x;
    m_y = t_y;
    m_z = t_z;
    m_w = t_w;

    m_quaternion = Ogre::Quaternion(m_x, m_y, m_z, m_w);
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
