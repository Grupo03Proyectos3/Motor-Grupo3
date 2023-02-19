#include "Biblioteca/Biblioteca.h"
#include "IMGUI/imgui.h"

#include <OgreRoot.h>
#include <btBulletCollisionCommon.h>
#include <chrono>
#include <crtdbg.h>
#include <fstream>
#include <iostream>

#include <Ogre.h>
#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLight.h>
#include <OgreRenderSystem.h>
#include <OgreRenderWindow.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>

#include <fmod.h>

#include "MyWindowEventListener.h"
#include "WindowEventUtilities.h"


void loadResources()
{
    Ogre::ConfigFile cf;
    cf.load("resources.cfg");

    Ogre::String secName, typeName, archName;
    Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

    while (seci.hasMoreElements())
    {
        secName = seci.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap* settings = seci.getNext();
        Ogre::ConfigFile::SettingsMultiMap::iterator i;

        for (i = settings->begin(); i != settings->end(); ++i)
        {
            typeName = i->first;
            archName = i->second;
            Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
                archName, typeName, secName);
        }
    }
}

Ogre::Camera* demoLoadFirstMesh(Ogre::SceneManager* t_sceneMgr)
{
    Ogre::SceneNode* rootSceneNode = t_sceneMgr->getRootSceneNode();

   /* Ogre::Entity* entity = t_sceneMgr->createEntity("myEntity", "cube.mesh");
    Ogre::SceneNode* node = rootSceneNode->createChildSceneNode();
    node->attachObject(entity);*/
    //node->setPosition(Ogre::Vector3(0, 0, 50));

    Ogre::Light* light = t_sceneMgr->createLight("myLight");
    Ogre::SceneNode* lightNode = rootSceneNode->createChildSceneNode();
    light->setType(Ogre::Light::LT_DIRECTIONAL);
    lightNode->setDirection(Ogre::Vector3(0, -1, 0));
    light->setDiffuseColour(Ogre::ColourValue(1.0f, 1.0f, 1.0f));
    light->setSpecularColour(Ogre::ColourValue(0.5f, 0.5f, 0.5f));
    lightNode->attachObject(light);

    // Crear una c�mara y ubicarla en una posici�n adecuada
    Ogre::Camera* camera = t_sceneMgr->createCamera("myCamera");
    Ogre::SceneNode* camNode = rootSceneNode->createChildSceneNode();
    camNode->translate(0, 0, -10);
    camNode->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TransformSpace::TS_WORLD);
    camNode->attachObject(camera);
    camera->setNearClipDistance(0.1);
    camera->setFarClipDistance(50);
   
    return camera;
}

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Ogre::Root* root = new Ogre::Root();

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;

    // Configurar el render system
    Ogre::RenderSystem* rs = root->getRenderSystemByName("Direct3D11 Rendering Subsystem");
    root->setRenderSystem(rs);

    // Configurar las opciones de la ventana
    rs->setConfigOption("Video Mode", "800 x 600 @ 32-bit colour");
    rs->setConfigOption("Full Screen", "No");

    Ogre::RenderWindow* window = root->initialise(true, "Motor");

    if (!window)
    {
        Ogre::LogManager::getSingleton().logError("Error al crear la ventana!");
        return 1;
    }

    try
    {
        loadResources();
    }
    catch (Ogre::FileNotFoundException& excepcion)
    {
        std::cerr << "Se produjo un error: " << excepcion.what() << '\n';
        exit(1);
    }
    Ogre::SceneManager* sceneMgr = root->createSceneManager();

    Ogre::Camera* cam=demoLoadFirstMesh(sceneMgr);

    Ogre::Viewport* viewport = window->addViewport(cam);
    viewport->setBackgroundColour(Ogre::ColourValue(0.0, 0.0, 0.0));
    viewport->setDimensions(0, 0, 1, 1); // Tama�o completo de la ventana
    // Mostrar la ventana
    window->setVisible(true);

    // MyWindowEventListener* myWindowListener=new MyWindowEventListener();
    // WindowEvents::WindowEventUtilities::addWindowEventListener(window,myWindowListener);

    // Game-loop
    bool game_playing = true;

    auto start_time = std::chrono::high_resolution_clock::now();
    auto previous_time = std::chrono::duration_cast<std::chrono::milliseconds>(start_time - start_time);

    std::chrono::steady_clock::time_point now = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds actual_time;
    std::chrono::milliseconds delta_time;
    while (game_playing)
    {
        WindowEvents::WindowEventUtilities::messagePump();
        if (window->isClosed() || window->isHidden())
        {
            game_playing = false;
            break;
        }

        // leer entrada

        // actualizar con delta_time
        now = std::chrono::high_resolution_clock::now();
        actual_time = std::chrono::duration_cast<std::chrono::milliseconds>(now - start_time);
        delta_time = actual_time - previous_time;
        previous_time = actual_time;

        // renderizar la escena y actualizar la ventana
        root->renderOneFrame();
        window->update();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    window->destroy();

    if (root)
    {
        delete sceneMgr;
        sceneMgr = nullptr;
        delete window;
        window = nullptr;
        delete root;
        root = nullptr;    
    }

    _CrtDumpMemoryLeaks();
    return 0;
}
/* std::fstream f("Assets\\mapa.txt");
    if (f.is_open()) {
        std::cout << "FICHERO ABIERTO\n";
        f.close();
    }
    else {
        std::cerr << "FICHERO NO ABIERTO";
        return 1;
    }*/