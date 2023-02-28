#include "SVector3.h"

SVector3::SVector3()
    : m_x(0)
    , m_y(0)
    , m_z(0)
{
    m_vector3 = Ogre::Vector3(m_x, m_y, m_z);
}

SVector3::SVector3(double t_x, double t_y, double t_z)
    : m_x(t_x)
    , m_y(t_y)
    , m_z(t_z)
{
    m_vector3 = Ogre::Vector3(m_x, m_y, m_z);
}

void SVector3::setVector3(double t_x, double t_y, double t_z)
{
    m_x = t_x;
    m_y = t_y;
    m_z = t_z;
    m_vector3 = Ogre::Vector3(m_x, m_y, m_z);
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
