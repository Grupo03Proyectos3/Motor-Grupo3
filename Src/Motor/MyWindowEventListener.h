#pragma once
#include <OgreRenderWindow.h>
#include "WindowEventUtilities.h"
class MyWindowEventListener : public Ogre::WindowEventListener
{
  public:
    MyWindowEventListener() {}
    ~MyWindowEventListener() {}

    void windowClosed(Ogre::RenderWindow* rw);

};