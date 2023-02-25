#include "Window.h"
#include "WindowEventUtilities.h"

namespace OgreWindow
{
    Window::Window(const Ogre::String& appName){
        mRoot = nullptr;
        mAppName = appName;
        mFSLayer = new Ogre::FileSystemLayer(mAppName);

        mShaderGenerator = nullptr;
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
        mSceneManager = mRoot->createSceneManager();

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
        createWindow(mAppName);

        locateResources();      
        initialiseRTShaderSystem();
        loadResources();
       
        //VENTOS DE VENTANA 
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

        mWindow.render = mRoot->createRenderWindow(appName, w, h, false, &miscParams);
        return mWindow;
    }

    bool Window::initialiseRTShaderSystem() {
        if (Ogre::RTShader::ShaderGenerator::initialize()){
            mShaderGenerator = Ogre::RTShader::ShaderGenerator::getSingletonPtr();

            if (!mMaterialMgrListener){
                mMaterialMgrListener = new OgreSGTechique::SGTechniqueResolverListener(mShaderGenerator);
                Ogre::MaterialManager::getSingleton().addListener(mMaterialMgrListener);
                mShaderGenerator->addSceneManager(mSceneManager);
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

        sec_name = Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME;
        auto genLocs = Ogre::ResourceGroupManager::getSingleton().getResourceLocationList(sec_name);

        arch_name = genLocs.front().archive->getName();
        type_name = genLocs.front().archive->getType();

        // AÑADIR LOS LENGUAJES DE PROGRAMACION DE LOS SHADERS

        Ogre::String mRTShaderLibPath = arch_name + "/RTShaderLib";
        Ogre::ResourceGroupManager::getSingleton().addResourceLocation(mRTShaderLibPath + "/materials", type_name, sec_name);
        Ogre::ResourceGroupManager::getSingleton().addResourceLocation(mRTShaderLibPath + "/GLSL", type_name, sec_name); // CARGO GLSL     
    }

    void Window::shutdown(){
        destroyRTShaderSystem();
        if (mWindow.render != nullptr){
            mRoot->destroyRenderTarget(mWindow.render);
            mWindow.render = nullptr;
        }
        if (mRoot != nullptr){
            delete mSceneManager;
            mSceneManager = nullptr;
            delete mRoot;
            mRoot = nullptr;
        }     
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
    }
} // namespace OgreWindow