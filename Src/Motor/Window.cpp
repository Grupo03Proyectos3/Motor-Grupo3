#include "Window.h"
namespace OgreWindow
{
    Window::Window(const Ogre::String& appName){
        mRoot = nullptr;
        mAppName = appName;
        mFSLayer = new Ogre::FileSystemLayer(mAppName);
    }

    Window::~Window(){
        delete mFSLayer;
    }

    void Window::initApp(){
        createRoot();

        if (config())
            setUp();
    }

    void Window::createRoot(){
        Ogre::String pluginsPath;

        pluginsPath = mFSLayer->getConfigFilePath("plugins.cfg");
        if (!Ogre::FileSystemLayer::fileExists(pluginsPath)){             
            OGRE_EXCEPT(Ogre::Exception::ERR_FILE_NOT_FOUND, "plugins.cfg", mAppName + ": createRoot");
        }

        mRoot = new Ogre::Root(pluginsPath, mFSLayer->getWritablePath("ogre.cfg"), mFSLayer->getWritablePath("ogre.log"));
    }

    bool Window::config(){
        if (!mRoot->restoreConfig()){
            return mRoot->showConfigDialog(nullptr);
        }
        return true;
    }
    void Window::setUp(){
        mRoot->initialise(false);

    }
    void Window::createWindow(Ogre::String& appName){
        uint32_t w, h;
        Ogre::NameValuePairList miscParams;

    }
} // namespace OgreWindow