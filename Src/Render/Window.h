#ifndef __Window_H__
#define __Window_H__

#include <OgreFileSystemLayer.h>
#include <OgreRTShaderSystem.h>
#include <OgreFrameListener.h>
#include <SDL.h>

#include "SGTechniqueResolverListener.h"
#include "FlamingoBase/SceneManager.h"

namespace Flamingo{
    typedef SDL_Window NativeWindowType;
    struct NativeWindowPair{
        Ogre::RenderWindow* render = nullptr;
        NativeWindowType* native = nullptr; // ES NECESARIO UNA VENTANA TIPO SDL CON EL MISMO NOMBRE DE CARA A LAS LIBRERIAS DE UI
    };
    class Window {
      public:
        Window(const Ogre::String& appName, Ogre::Root* t_root);
        ~Window();

        NativeWindowPair createWindow(Ogre::String& appName);

        void addRTShaderSystem(Ogre::SceneManager* t_mng);
        bool initialiseRTShaderSystem();
        void destroyRTShaderSystem();
       
        void update();

        void shutdown();
        void closeWindow();
       
        inline Ogre::RenderWindow* getRenderWindow() { return m_window.render; }
        inline Ogre::RenderSystem* getRenderSystem() { return m_render_system; }
        inline void setSceneManager(Flamingo::SceneManager* t_sm) { m_scene_mngr = t_sm; }
        
        bool isWindowClosed() { return isClosed; }

      protected:
        Ogre::Root* m_root;                  // OGRE root
        Ogre::RenderSystem* m_render_system;  //OGRE renderSystem
        Flamingo::SceneManager* m_scene_mngr; // Scenes Manager
        NativeWindowPair m_window;           // La venatna
        Ogre::FileSystemLayer* m_fs_layer;    //Fichero de recursos
        Ogre::String m_app_name;              //Nombre de la app
        bool isClosed;

        //Pipeline
        Ogre::String mRTShaderLibPath;
        Ogre::RTShader::ShaderGenerator* mShaderGenerator; // The Shader generator instance.
        OgreSGTechique::SGTechniqueResolverListener* mMaterialMgrListener;
    };
} // namespace OgreWindow
#endif