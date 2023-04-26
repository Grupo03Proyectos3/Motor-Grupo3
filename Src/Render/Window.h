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
        NativeWindowType* native = nullptr;
    };
    class Window {
      public:
        Window(const std::string& appName, Ogre::Root* t_root);
        ~Window();       

        NativeWindowPair createWindow(std::string& appName); //NO EXPORTAR

        bool initialiseRTShaderSystem();
        void destroyRTShaderSystem();
       
        void update();

        void shutdown();
        void closeWindow();
       
        inline Ogre::RenderWindow* getRenderWindow() { return m_window.render; } //NO EXPORTAR
        inline void setSceneManager(Flamingo::SceneManager* t_sm) { m_scene_mngr = t_sm; }
        
        bool isWindowClosed() { return isClosed; }

      protected:      

        void addRTShaderSystem(Ogre::SceneManager* t_mng); 

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