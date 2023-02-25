#ifndef __Window_H__
#define __Window_H__
#pragma once
#include <Ogre.h>
#include <OgreFileSystemLayer.h>
#include <OgreRTShaderSystem.h>
#include "SGTechniqueResolverListener.h"
#include <SDL.h>

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
        NativeWindowPair createWindow(Ogre::String& appName);
        bool initialiseRTShaderSystem();
        void destroyRTShaderSystem();
        void loadResources();
        void locateResources();
        void pollEvents();
        void shutdown();
        void bringResources(Ogre::String& sec_name, Ogre::String& type_name, Ogre::String& arch_name);
        Ogre::Root* getRoot() { return mRoot; };
        Ogre::RenderWindow* getRenderWindow() { return mWindow.render; };
        Ogre::SceneManager* getSceneManger() { return mSceneManager; };
        Ogre::RenderSystem* getRenderSystem() { return mRenderSystem; };
      protected:
        Ogre::Root* mRoot;               // OGRE root
        Ogre::RenderSystem* mRenderSystem; //OGRE renderSystem;
        Ogre::SceneManager* mSceneManager;  //OGRE sceneManager de la escena que gestiona
        NativeWindowPair mWindow;        // La venatna
        Ogre::FileSystemLayer* mFSLayer; // 
        Ogre::String mAppName;           //Nombre de la app

        //Pipeline
        Ogre::String mRTShaderLibPath;
        Ogre::RTShader::ShaderGenerator* mShaderGenerator; // The Shader generator instance.
        OgreSGTechique::SGTechniqueResolverListener* mMaterialMgrListener;
           
        
    };
} // namespace OgreWindow
#endif