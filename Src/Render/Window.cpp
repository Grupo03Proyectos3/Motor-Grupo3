#include "Window.h"
#include "WindowEventUtilities.h"
#include <OgreRoot.h>
#include <SDL_video.h>
#include <SDL_syswm.h>
#include <OgreConfigFile.h>
#include <OgreRenderWindow.h>
#include <OgreGpuProgramManager.h>

namespace OgreWindow
{
    Window::Window(const Ogre::String& t_app_name, Ogre::Root* t_root)
        : isClosed(false)
        , m_root(t_root)
        , m_app_name(t_app_name)
        , m_scene_mngr(nullptr) 
    {
        m_window.native = nullptr;
        m_window.render = nullptr;
        mShaderGenerator = nullptr;
    }

    Window::~Window(){
        delete m_fs_layer;
       
    }

    NativeWindowPair Window::createWindow(Ogre::String& appName)
    {
        uint32_t w, h;
        Ogre::NameValuePairList miscParams;
        Ogre::ConfigOptionMap ropts = m_root->getRenderSystem()->getConfigOptions();
        std::istringstream mode(ropts["Video Mode"].currentValue);
        Ogre::String token;
        mode >> w;     // width
        mode >> token; // 'x' as seperator between width and height
        mode >> h;     // height

        miscParams["FSAA"] = ropts["FSAA"].currentValue;
        miscParams["vsync"] = ropts["VSync"].currentValue;
        miscParams["gamma"] = ropts["sRGB Gamma Conversion"].currentValue;

        if (!SDL_WasInit(SDL_INIT_VIDEO))
            SDL_InitSubSystem(SDL_INIT_VIDEO);

        Uint32 flags = SDL_WINDOW_RESIZABLE;

        if (ropts["Full Screen"].currentValue == "Yes")flags = SDL_WINDOW_FULLSCREEN;
        // else  flags = SDL_WINDOW_RESIZABLE;

        m_window.native = SDL_CreateWindow(appName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, flags);

        SDL_SysWMinfo wmInfo;
        SDL_VERSION(&wmInfo.version);
        SDL_GetWindowWMInfo(m_window.native, &wmInfo);

        miscParams["externalWindowHandle"] = Ogre::StringConverter::toString(size_t(wmInfo.info.win.window));

        m_window.render = m_root->createRenderWindow(appName, w, h, false, &miscParams);
        return m_window;
    }

    void Window::addRTShaderSystem(Ogre::SceneManager* t_mng){
        Ogre::RTShader::ShaderGenerator::getSingletonPtr()->addSceneManager(t_mng);
    }

    bool Window::initialiseRTShaderSystem()
    {
        if (Ogre::RTShader::ShaderGenerator::initialize()){
            mShaderGenerator = Ogre::RTShader::ShaderGenerator::getSingletonPtr();

            if (!mMaterialMgrListener){
                mMaterialMgrListener = new OgreSGTechique::SGTechniqueResolverListener(mShaderGenerator);
                Ogre::MaterialManager::getSingleton().addListener(mMaterialMgrListener);
                mShaderGenerator->addSceneManager(m_scene_mngr->getSceneActive()->getSceneManger());
            }
            return true;
        }
    }

    void Window::destroyRTShaderSystem() {
        // Restore default scheme.
        Ogre::MaterialManager::getSingleton().setActiveScheme(Ogre::MaterialManager::DEFAULT_SCHEME_NAME);

        // Unregister the material manager listener.
        if (mMaterialMgrListener != nullptr)
        {
            Ogre::MaterialManager::getSingleton().removeListener(mMaterialMgrListener);
            delete mMaterialMgrListener;
            mMaterialMgrListener = nullptr;
        }

        // Destroy RTShader system.
        if (mShaderGenerator != nullptr)
        {
            Ogre::RTShader::ShaderGenerator::destroy();
            mShaderGenerator = nullptr;
        }
    }

    void Window::pollEvents() {

        if (m_window.native == nullptr)
            return; // SDL events not initialized

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    m_root->queueEndRendering();
                    break;
                case SDL_WINDOWEVENT:
                    if (event.window.windowID == SDL_GetWindowID(m_window.native))
                    {
                        if (event.window.event == SDL_WINDOWEVENT_RESIZED)
                        {
                            Ogre::RenderWindow* win = m_window.render;
                            // win->resize(event.window.data1, event.window.data2);  // IG2: ERROR
                            win->windowMovedOrResized();
                        }
                        // Agregar el caso SDL_WINDOWEVENT_CLOSE
                        else if (event.window.event == SDL_WINDOWEVENT_CLOSE){
                            m_root->queueEndRendering();
                            isClosed = true;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        // just avoid "window not responding"
        WindowEvents::WindowEventUtilities::messagePump();
    }

    void Window::shutdown(){
        destroyRTShaderSystem();
        if (m_window.render != nullptr){
            m_root->destroyRenderTarget(m_window.render);
            m_window.render = nullptr;
        }
        if (m_window.native != nullptr)
        {
            SDL_DestroyWindow(m_window.native);
            SDL_QuitSubSystem(SDL_INIT_VIDEO);
            m_window.native = nullptr;
        }
        if (m_root != nullptr){
            delete m_scene_mngr;
            m_scene_mngr = nullptr;
            delete m_root;
            m_root = nullptr;
        }   
    }

    void Window::closeWindow(){
        if (m_root != nullptr){
            m_root->saveConfig();
        }
        if (getRenderSystem() != nullptr)
            shutdown(); 
        delete m_scene_mngr;
        delete m_root;
        m_root = nullptr;
    }

} // namespace OgreWindow