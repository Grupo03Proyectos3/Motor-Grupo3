#ifndef __Window_H__
#define __Window_H__
#pragma once
#include <OgreFileSystemLayer.h>
#include <OgreRTShaderSystem.h>
#include <OgreFrameListener.h>
#include <SDL.h>


#include "SGTechniqueResolverListener.h"


namespace OgreWindow{
    typedef SDL_Window NativeWindowType;
    struct NativeWindowPair{
        Ogre::RenderWindow* render = nullptr;
        NativeWindowType* native = nullptr; // ES NECESARIO UNA VENTANA TIPO SDL CON EL MISMO NOMBRE DE CARA A LAS LIBRERIAS DE UI
    };
    class Window {
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
        void bringResources(Ogre::String& sec_name, Ogre::String& type_name, Ogre::String& arch_name);

        void pollEvents();

        void shutdown();
        void closeWindow();
       
        inline Ogre::SceneManager* getSceneManger() { return mSceneManager; };

        Ogre::Root* getRoot() { return mRoot; };
        inline Ogre::RenderWindow* getRenderWindow() { return mWindow.render; };
        inline Ogre::RenderSystem* getRenderSystem() { return mRenderSystem; };       
        bool isWindowClosed() { return isClosed; };
      protected:
        Ogre::Root* mRoot;                  // OGRE root
        Ogre::RenderSystem* mRenderSystem;  //OGRE renderSystem;
        Ogre::SceneManager* mSceneManager;  //OGRE sceneManager de la escena que gestiona
        NativeWindowPair mWindow;           // La venatna
        Ogre::FileSystemLayer* mFSLayer;    //Fichero de recursos
        Ogre::String mAppName;              //Nombre de la app
        bool isClosed= false;

        //Pipeline
        Ogre::String mRTShaderLibPath;
        Ogre::RTShader::ShaderGenerator* mShaderGenerator; // The Shader generator instance.
        OgreSGTechique::SGTechniqueResolverListener* mMaterialMgrListener;
           
        //crearSitemaDeGention de Escenas
        //OgreScene::SceneManager* sceneManager;
    };
} // namespace OgreWindow
#endif