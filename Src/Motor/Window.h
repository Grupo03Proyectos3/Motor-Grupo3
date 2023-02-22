
#ifndef __Window_H__
#define __Window_H__
#pragma once
#include <Ogre.h>
#include <OgreFileSystemLayer.h>
namespace OgreWindow{
    struct NativeWindowPair
    {
        Ogre::RenderWindow* render = nullptr;
        // ES NECESARIO UNA VENTANA TIPO SDL CON EL MISMO NOMBRE DE CARA A LAS LIBRERIAS DE UI
    };
    class Window
    {
      public:
        Window(const Ogre::String& appName);
        ~Window();
        void initApp();
        void createRoot();
        bool config();
        void setUp();
        void createWindow(Ogre::String& appName);
      protected:
        Ogre::Root* mRoot;               // OGRE root
        NativeWindowPair mWindow;        // the window
        Ogre::FileSystemLayer* mFSLayer; // File system abstraction layer
        Ogre::String mAppName;
    };
} // namespace OgreWindow
#endif