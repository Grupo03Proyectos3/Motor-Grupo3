#pragma once

#ifndef __SVECTOR3_H__
#define __SVECTOR3_H__

#include <OgreVector3.h>

class SVector3
{
  public:
    SVector3();
    SVector3(double t_x, double t_y, double t_z);
    ~SVector3() = default;
    void setVector3(double t_x, double t_y, double t_z);
    double getX();
    double getY();
    double getZ();

  private:
    double m_x;
    double m_y;
    double m_z;
    Ogre::Vector3 m_vector3;
};

#endif
