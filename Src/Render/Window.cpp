#include "Window.h"
#include "ECS/InputHandler.h"
#include <OgreConfigFile.h>
#include <OgreGpuProgramManager.h>
#include <OgreRenderWindow.h>
#include <OgreRoot.h>
#include <SDL_syswm.h>
#include <SDL_video.h>
namespace Flamingo
{
    Window::Window(const std::string& t_app_name, Ogre::Root* t_root)
        : isClosed(false)
        , m_root(t_root)
        , m_app_name(t_app_name)
        , m_scene_mngr(nullptr)
    {
        m_window.native = nullptr;
        m_window.render = nullptr;
        mShaderGenerator = nullptr;
    }

    Window::~Window()
    {
        delete m_fs_layer; // TODO Check this ¿?
        m_fs_layer = nullptr;

        m_root = nullptr;
        m_render_system = nullptr;
        m_scene_mngr = nullptr;
    }

    NativeWindowPair Window::createWindow(std::string& appName)
    {
        Ogre::ConfigFile configFile;
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

        if (ropts["Full Screen"].currentValue == "Yes")
            flags = SDL_WINDOW_FULLSCREEN;
        // else  flags = SDL_WINDOW_RESIZABLE;

        m_window.native = SDL_CreateWindow(appName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, flags);

        SDL_SysWMinfo wmInfo;
        SDL_VERSION(&wmInfo.version);
        SDL_GetWindowWMInfo(m_window.native, &wmInfo);

        miscParams["externalWindowHandle"] = Ogre::StringConverter::toString(size_t(wmInfo.info.win.window));

        m_window.render = m_root->createRenderWindow(appName, w, h, false, &miscParams);
        return m_window;
    }

    void Window::addRTShaderSystem(Ogre::SceneManager* t_mng)
    {
        Ogre::RTShader::ShaderGenerator::getSingletonPtr()->addSceneManager(t_mng);
    }

    bool Window::initialiseRTShaderSystem()
    {
        if (Ogre::RTShader::ShaderGenerator::initialize())
        {
            mShaderGenerator = Ogre::RTShader::ShaderGenerator::getSingletonPtr();

            if (!mMaterialMgrListener)
            {
                mMaterialMgrListener = new OgreSGTechique::SGTechniqueResolverListener(mShaderGenerator);
                Ogre::MaterialManager::getSingleton().addListener(mMaterialMgrListener);
                mShaderGenerator->addSceneManager(m_scene_mngr->getSceneActive()->getSceneManger());
            }
            return true;
        }
        return false;
    }

    void Window::destroyRTShaderSystem()
    {
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

    void Window::update()
    {
        if (m_window.native == nullptr)
            return; // SDL events not initialized

        if (InputHandler::instance()->resizeWindowEvent())
        {
            m_window.render->windowMovedOrResized();
        }
        isClosed = InputHandler::instance()->closeWindowEvent();
        // std::cout << isClosed << "\n";
        if (isClosed)
            m_window.render->windowMovedOrResized();
    }

    void Window::shutdown()
    {
        if (m_window.render != nullptr)
        {
            m_root->destroyRenderTarget(m_window.render);
            m_window.render = nullptr;
        }
        if (m_window.native != nullptr)
        {
            SDL_DestroyWindow(m_window.native);
            SDL_QuitSubSystem(SDL_INIT_VIDEO);
            m_window.native = nullptr;
        }
    }

    void Window::closeWindow()
    {
        if (m_root != nullptr)
        {
            m_root->saveConfig();
        }
        /* if (getRenderSystem() != nullptr)
             shutdown();*/

        //  delete m_root;
        //  m_root = nullptr;
        //  m_scene_mngr = nullptr;
    }

} // namespace Flamingo