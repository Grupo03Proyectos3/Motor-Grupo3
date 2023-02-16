#include "Biblioteca/Biblioteca.h"
#include <OgreRoot.h>
#include <btBulletCollisionCommon.h>
#include <chrono>
#include <crtdbg.h>
#include <fstream>
#include <iostream>

#include <Ogre.h>
#include <OgreRenderSystem.h>
#include <OgreRenderWindow.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>
#include <OgreCamera.h>
#include <OgreSceneNode.h>
#include <OgreLight.h>

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

void demoLoadFirstMesh(Ogre::SceneManager* t_sceneMgr)
{
    Ogre::Entity* entity = t_sceneMgr->createEntity("myEntity", "cube.mesh");
    Ogre::SceneNode* node = t_sceneMgr->getRootSceneNode()->createChildSceneNode();

    node->attachObject(entity);

    Ogre::Light* light = t_sceneMgr->createLight("myLight");
    Ogre::SceneNode* lightNode = t_sceneMgr->getRootSceneNode()->createChildSceneNode();
    light->setType(Ogre::Light::LT_DIRECTIONAL);
    lightNode->setDirection(Ogre::Vector3(0, -1, 0));
    light->setDiffuseColour(Ogre::ColourValue(1.0f, 1.0f, 1.0f));
    light->setSpecularColour(Ogre::ColourValue(0.5f, 0.5f, 0.5f));
    lightNode->attachObject(light);

    // Crear una cámara y ubicarla en una posición adecuada
    Ogre::Camera* camera = t_sceneMgr->createCamera("myCamera");
    Ogre::SceneNode* camNode = t_sceneMgr->getRootSceneNode()->createChildSceneNode();
    camNode->setPosition(0, 0, -30);
    camNode->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TransformSpace::TS_WORLD);
    camNode->attachObject(camera);
}

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

     Ogre::Root* root = new Ogre::Root();

    // Configurar el render system
    Ogre::RenderSystem* rs = root->getRenderSystemByName("Direct3D11 Rendering Subsystem");
    root->setRenderSystem(rs);

    // Configurar las opciones de la ventana
    rs->setConfigOption("Video Mode", "800 x 600 @ 32-bit colour");
    rs->setConfigOption("Full Screen", "No");

    Ogre::RenderWindow* window = root->initialise(true, "Motor");

    try
    {
        loadResources();
    }
    catch (Ogre::FileNotFoundException &excepcion)
    {
        std::cerr << "Se produjo un error: " << excepcion.what() << '\n';
        exit(1);
    }

    Ogre::SceneManager* sceneMgr = root->createSceneManager();

    demoLoadFirstMesh(sceneMgr);

    // Mostrar la ventana
    window->setVisible(true);
   

    /* std::fstream f("Assets\\mapa.txt");
    if (f.is_open()) {
        std::cout << "FICHERO ABIERTO\n";
        f.close();
    }
    else {
        std::cerr << "FICHERO NO ABIERTO";
        return 1;
    }*/

    // Game-loop
    bool game_playing = true;

    auto start_time = std::chrono::high_resolution_clock::now();
    auto previous_time = std::chrono::duration_cast<std::chrono::milliseconds>(start_time - start_time);
    while (game_playing)
    {
        // leer entrada

        // actualizar con delta_time
        auto now = std::chrono::high_resolution_clock::now();
        auto actual_time = std::chrono::duration_cast<std::chrono::milliseconds>(now - start_time);
        unsigned long long int delta_time = (actual_time - previous_time).count();
        previous_time = actual_time;

        // renderizar
        root->renderOneFrame();
        window->update();
        //std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }


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