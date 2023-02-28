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
    Window::Window(const Ogre::String& appName){
        mRoot = nullptr;
        mAppName = appName;
        mFSLayer = new Ogre::FileSystemLayer(mAppName);
        mWindow.native = nullptr;
        mWindow.render = nullptr;
        mShaderGenerator = nullptr;
        mSceneManager = nullptr;
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
              
        mSceneManager = new OgreScene::SceneManager(mAppName + " - SceneManager");
       
        //mSceneManager = mRoot->createSceneManager(Ogre::DefaultSceneManagerFactory::FACTORY_TYPE_NAME, mAppName);
        
        //SI NO LO PONGO NO PILLA NINGUN RENDER ACTIVO **NO NECESARIO CON config(), ya lo hace auto **
        //mRenderSystem = mRoot->getRenderSystemByName("Direct3D11 Rendering Subsystem");
        //mRoot->setRenderSystem(mRenderSystem);
    }

    bool Window::config(){
        if (!mRoot->restoreConfig()){
            return mRoot->showConfigDialog(nullptr);
        }
        return true;
    }

    void Window::setUp(){
        mRoot->initialise(false);
        mSceneManager->init(mRoot);
        createWindow(mAppName);

        locateResources();      
        initialiseRTShaderSystem();
        loadResources();
       
        //VENTOS DE VENTANA 
        //mRoot->addFrameListener(this);
    }

    NativeWindowPair Window::createWindow(Ogre::String& appName)
    {
        uint32_t w, h;
        Ogre::NameValuePairList miscParams;
        Ogre::ConfigOptionMap ropts = mRoot->getRenderSystem()->getConfigOptions();
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

        mWindow.native = SDL_CreateWindow(appName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, flags);

        SDL_SysWMinfo wmInfo;
        SDL_VERSION(&wmInfo.version);
        SDL_GetWindowWMInfo(mWindow.native, &wmInfo);

        miscParams["externalWindowHandle"] = Ogre::StringConverter::toString(size_t(wmInfo.info.win.window));

        mWindow.render = mRoot->createRenderWindow(appName, w, h, false, &miscParams);
        return mWindow;
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
                mShaderGenerator->addSceneManager(mSceneManager->getSceneActive()->getSceneManger());
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

        if (mWindow.native == nullptr)
            return; // SDL events not initialized

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    mRoot->queueEndRendering();
                    break;
                case SDL_WINDOWEVENT:
                    if (event.window.windowID == SDL_GetWindowID(mWindow.native))
                    {
                        if (event.window.event == SDL_WINDOWEVENT_RESIZED)
                        {
                            Ogre::RenderWindow* win = mWindow.render;
                            // win->resize(event.window.data1, event.window.data2);  // IG2: ERROR
                            win->windowMovedOrResized();
                        }
                        // Agregar el caso SDL_WINDOWEVENT_CLOSE
                        else if (event.window.event == SDL_WINDOWEVENT_CLOSE){
                            mRoot->queueEndRendering();
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

    void Window::loadResources(){
        Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
    }

    void Window::locateResources() {
        Ogre::String sec_name, type_name, arch_name;

        sec_name = Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME; // miro a ver si ya se han cargado los recursos en el resourceManager
        const Ogre::ResourceGroupManager::LocationList genLocs2 = Ogre::ResourceGroupManager::getSingleton().getResourceLocationList(sec_name);

        if (genLocs2.empty())// si no estan cargados los cargo
            bringResources(sec_name, type_name, arch_name);
    }

    void Window::shutdown(){
        destroyRTShaderSystem();
        if (mWindow.render != nullptr){
            mRoot->destroyRenderTarget(mWindow.render);
            mWindow.render = nullptr;
        }
        if (mWindow.native != nullptr)
        {
            SDL_DestroyWindow(mWindow.native);
            SDL_QuitSubSystem(SDL_INIT_VIDEO);
            mWindow.native = nullptr;
        }
        if (mRoot != nullptr){
            delete mSceneManager;
            mSceneManager = nullptr;
            delete mRoot;
            mRoot = nullptr;
        }   
    }

    void Window::closeWindow(){
        if (mRoot != nullptr){
            mRoot->saveConfig();
        }
        if (getRenderSystem() != nullptr)
            shutdown(); 
        delete mSceneManager;
        delete mRoot;
        mRoot = nullptr;
    }

    void Window::bringResources(Ogre::String& sec_name, Ogre::String& type_name, Ogre::String& arch_name){
        Ogre::ConfigFile cf;
        cf.load("resources.cfg");

        Ogre::ConfigFile::SettingsBySection_ seci = cf.getSettingsBySection();
        for (auto i = seci.begin(); i != seci.end(); i++){
            sec_name = i->first;
            Ogre::ConfigFile::SettingsMultiMap settings = i->second;
            Ogre::ConfigFile::SettingsMultiMap::iterator mmi;
            for (mmi = settings.begin(); mmi != settings.end(); ++mmi){
                type_name = mmi->first;
                arch_name = mmi->second;
                Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
                    arch_name, type_name, sec_name);
            }
        }
        sec_name = Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME;
        auto genLocs = Ogre::ResourceGroupManager::getSingleton().getResourceLocationList(sec_name);

        arch_name = genLocs.front().archive->getName();
        type_name = genLocs.front().archive->getType();

        // AÑADIR LOS LENGUAJES DE PROGRAMACION DE LOS SHADERS
        // Add locations for supported shader languages
        /*if (Ogre::GpuProgramManager::getSingleton().isSyntaxSupported("glsles")){
            Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch_name + "/programs/GLSLES", type_name, sec_name);
        }*/
        if (Ogre::GpuProgramManager::getSingleton().isSyntaxSupported("glsl")){
            Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch_name + "/programs/GLSL120", type_name, sec_name);

            if (Ogre::GpuProgramManager::getSingleton().isSyntaxSupported("glsl150")){
                Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch_name + "/programs/GLSL150", type_name, sec_name);
            }
            else{
                Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch_name + "/programs/GLSL", type_name, sec_name);
            }

            if (Ogre::GpuProgramManager::getSingleton().isSyntaxSupported("glsl400")){
                Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch_name + "/programs/GLSL400", type_name, sec_name);
            }
        }
       /* else if (Ogre::GpuProgramManager::getSingleton().isSyntaxSupported("hlsl")){
            Ogre::ResourceGroupManager::getSingleton().addResourceLocation(arch_name + "/programs/HLSL", type_name, sec_name);
        }*/

        Ogre::String mRTShaderLibPath = arch_name + "/RTShaderLib";
        Ogre::ResourceGroupManager::getSingleton().addResourceLocation(mRTShaderLibPath + "/materials", type_name, sec_name);
        Ogre::ResourceGroupManager::getSingleton().addResourceLocation(mRTShaderLibPath + "/GLSL", type_name, sec_name); // CARGO GLSL 
    }

} // namespace OgreWindow