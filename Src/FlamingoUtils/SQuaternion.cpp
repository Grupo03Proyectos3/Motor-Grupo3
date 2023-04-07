#include "SQuaternion.h"
#include <btBulletCollisionCommon.h>
#include <iostream>
#include <math.h>
#include <CEGUI/Quaternion.h>
#define M_PI 3.14159265358979323846

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

SQuaternion::SQuaternion(double angle, const SVector3& axis)
{
    btQuaternion v(axis, static_cast<btScalar>(angle * (M_PI / 180.0)));
    m_x = v.getX();
    m_y = v.getY();
    m_z = v.getZ();
    m_w = v.getW();
}

SQuaternion::SQuaternion(Ogre::Degree angle, const SVector3& axis)
{
    btQuaternion v(axis, angle.valueRadians());
    m_x = v.getX();
    m_y = v.getY();
    m_z = v.getZ();
    m_w = v.getW();
}

void SQuaternion::setQuaternion(double t_x, double t_y, double t_z, double t_w)
{
    m_x = t_x;
    m_y = t_y;
    m_z = t_z;
    m_w = t_w;
}

void SQuaternion::setQuaternion(double angle, SVector3& axis)
{
    btQuaternion v(axis, static_cast<btScalar>(angle * (M_PI / 180.0)));
    m_x = v.getX();
    m_y = v.getY();
    m_z = v.getZ();
    m_w = v.getW();
}

SQuaternion SQuaternion::inverse()
{
    auto v = btQuaternion((btScalar)m_x, (btScalar)m_y, (btScalar)m_z, (btScalar)m_w).inverse();
    return SQuaternion(v.getX(), v.getY(), v.getZ(), v.getW());
}

double SQuaternion::lenght()
{
    return btQuaternion((btScalar)m_x, (btScalar)m_y, (btScalar)m_z, (btScalar)m_w).length();
}

double SQuaternion::dot(const SQuaternion& other)
{
    return btQuaternion((btScalar)m_x, (btScalar)m_y, (btScalar)m_z, (btScalar)m_w).dot(btQuaternion((btScalar)other.m_x, (btScalar)other.m_y, (btScalar)other.m_z, (btScalar)other.m_w));
}

double SQuaternion::angle(const SQuaternion& other)
{
    return btQuaternion((btScalar)m_x, (btScalar)m_y, (btScalar)m_z, (btScalar)m_w).angle(btQuaternion((btScalar)other.m_x, (btScalar)other.m_y, (btScalar)other.m_z, (btScalar)other.m_w));
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

void SQuaternion::operator*=(const SQuaternion& other)
{
    auto v = btQuaternion((btScalar)m_x, (btScalar)m_y, (btScalar)m_z, (btScalar)m_w) * btQuaternion((btScalar)other.m_x, (btScalar)other.m_y, (btScalar)other.m_z, (btScalar)other.m_w);
    m_x = v.getX();
    m_y = v.getY();
    m_z = v.getZ();
    m_w = v.getW();
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
    return Ogre::Quaternion((btScalar)m_w, (btScalar)m_x, (btScalar)m_y, (btScalar)m_z);
}

SQuaternion::operator btQuaternion() const
{
    return btQuaternion((btScalar)m_x, (btScalar)m_y, (btScalar)m_z, (btScalar)m_w);
}

SQuaternion::operator CEGUI::Quaternion()
{
    return CEGUI::Quaternion((btScalar)m_x, (btScalar)m_y, (btScalar)m_z, (btScalar)m_w);
}

SQuaternion SQuaternion::ogreToSQuaternion(const Ogre::Quaternion& ogreQuaternion)
{
    return SQuaternion((btScalar)ogreQuaternion.x, (btScalar)ogreQuaternion.y, (btScalar)ogreQuaternion.z, (btScalar)ogreQuaternion.w);
}

SQuaternion SQuaternion::bulletToQuaternion(const btQuaternion& t_bullet_quaternion)
{
    return SQuaternion((double)t_bullet_quaternion.x(), (double)t_bullet_quaternion.y(), (double)t_bullet_quaternion.z(), (double)t_bullet_quaternion.w());
}

SQuaternion SQuaternion::ceguiToSQuaternion(const CEGUI::Quaternion& ceguiQuaternion){
    return SQuaternion((double)ceguiQuaternion.d_x, (double)ceguiQuaternion.d_y, (double)ceguiQuaternion.d_z, (double)ceguiQuaternion.d_w);
}
