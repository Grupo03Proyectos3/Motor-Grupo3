#include "Biblioteca/Biblioteca.h"
#include "IMGUI/imgui.h"

#include <OgreRoot.h>
#include <btBulletCollisionCommon.h>
#include <chrono>
#include <crtdbg.h>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

#include <Ogre.h>
#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLight.h>
#include <OgreRenderSystem.h>
#include <OgreRenderWindow.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreViewport.h>


#include <fmod.h>

#include "MyWindowEventListener.h"
#include "WindowEventUtilities.h"


void loadDirectories() {
    std::string directory = "./Assets";    //Directorio donde estan todos los recursos que buscar
    std::ifstream infile("resources.cfg"); //Archivo de input
    std::string line;                      //Linea donde se guarda cada linea leida
    std::vector<std::string> text;         //Vector donde me guardo todo el texto leido. Cada componente del vector es una linea

    while (line != "FileSystem=./Assets")  //Leo hasta "FileSystem=./Assets" que es lo que no quiero sobreescribir
    {
        getline(infile, line);
        text.push_back(line);
    }
    infile.close(); //Cierro el archivo

    std::ofstream output("resources.cfg" /*, std::ios::app | std::ios::ate*/); //Archivo para output
    for (int i = 0; i < text.size(); i++) //Escribo en el archivo todas las lineas anteriores que quiero conservar
    {
        line = text[i];
        output << line << '\n';
    }

    for (const auto& entry : std::filesystem::directory_iterator(directory)) //Burco los directorios dentro de "directory"
    {
        if (entry.is_directory()) //Si es un fichero tipo directorio
        {
            std::string path = entry.path().string(); //Me guardo su ruta en "path"
            std::string newPath = path;               //Creo otro string del mimo tamaño que "path"
            for (int i = 0; i < path.size(); i++)     //En "newPath" me guardo la ruta pero con el formato adecuado
            {
                if (path[i] == '\\')
                {
                    newPath[i] = '/';
                }
                else
                    newPath[i] = path[i];
            }
            // Escribe en el archivo todas las rutas que encuentro
            output << "FileSystem=" << newPath;
        }
    }
    output.close(); //Cierro el archivo ¡¡¡IMPORTANTE PARA QUE SE HAGA BIEN LA LECTURA Y ESCRITURA!!!
}

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

    // Crear una cámara y ubicarla en una posición adecuada
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
    //Ogre::RenderWindow* window = Ogre::Root::getSingleton().getAutoCreatedWindow();

    if (!window)
    {
        Ogre::LogManager::getSingleton().logError("Error al crear la ventana!");
        return 1;
    }
   
    try {
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
    viewport->setDimensions(0, 0, 1, 1); // Tamaño completo de la ventana
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