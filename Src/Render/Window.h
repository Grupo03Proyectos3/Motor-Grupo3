#ifndef __Window_H__
#define __Window_H__



#include <string>

namespace Ogre
{
    class FileSystemLayer;
    class RenderWindow;
    class RenderSystem;
    class Root;
    class SceneManager;
    namespace RTShader
    {
        class ShaderGenerator;
    }
} // namespace Ogre
namespace OgreSGTechique
{
    class SGTechniqueResolverListener;
}


#include "FlamingoBase/SceneManager.h"

class SDL_Window;

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
       
        Ogre::RenderWindow* getRenderWindow(); // NO EXPORTAR
        
        bool isWindowClosed();

      protected:      

        void addRTShaderSystem(Ogre::SceneManager* t_mng); 

        Ogre::Root* m_root;                  // OGRE root
        Ogre::RenderSystem* m_render_system;  //OGRE renderSystem
        NativeWindowPair m_window;           // La venatna
        Ogre::FileSystemLayer* m_fs_layer;    //Fichero de recursos
        std::string m_app_name;              //Nombre de la app
        bool isClosed;

        //Pipeline
        std::string mRTShaderLibPath;
        Ogre::RTShader::ShaderGenerator* mShaderGenerator; // The Shader generator instance.
        OgreSGTechique::SGTechniqueResolverListener* mMaterialMgrListener;
    };
} // namespace OgreWindow
#endif