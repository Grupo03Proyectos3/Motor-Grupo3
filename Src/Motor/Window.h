
#ifndef __Window_H__
#define __Window_H__
#pragma once
#include <Ogre.h>
#include <OgreFileSystemLayer.h>
#include <OgreRTShaderSystem.h>
#include <OgreSGTechniqueResolverListener.h>
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
        Ogre::Root* getRoot() { return mRoot; };
        Ogre::RenderWindow* getRenderWindow() { return mWindow.render; };
        Ogre::SceneManager* getSceneManger() { return mSceneManager; };
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
        OgreBites::SGTechniqueResolverListener* mMaterialMgrListener; // Shader generator material manager listener.
        
    };
} // namespace OgreWindow
#endif