#include "Render/Render.h"

#include "ECS/Manager.h"

#include "IMGUI/imgui.h"

#include <OgreRoot.h>
#include <crtdbg.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <Ogre.h>
#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLight.h>
#include <OgreRenderSystem.h>
#include <OgreRenderWindow.h>
#include <OgreSceneNode.h>
#include <OgreViewport.h>
#include <OgreBullet.h>
#include <OgreRTShaderSystem.h>
#include <fmod.h>

#include "MyWindowEventListener.h"
#include "WindowEventUtilities.h"
#include "Window.h"

#include "Motor/GameObject.h"

// Convierte la ruta obtenida al formato de resources.cfg
std::string parsePath(std::string t_path)
{
    std::string new_Path = t_path;          // Creo otro string del mimo tama�o que "path"
    for (int i = 0; i < t_path.size(); i++) // En "newPath" me guardo la ruta pero con el formato adecuado
    {
        if (t_path[i] == '\\')
        {
            new_Path[i] = '/';
        }
        else
            new_Path[i] = t_path[i];
    }
    return new_Path;
}

void findDir(std::filesystem::directory_iterator t_dir, std::ofstream& t_output)
{
    for (const auto& entry : t_dir) // Burco los directorios dentro de "directory"
    {
        if (entry.is_directory()) // Si es un fichero tipo directorio
        {
            std::string path = entry.path().string(); // Me guardo su ruta en "path"
            std::string new_Path = parsePath(path);
            // Escribe en el archivo todas las rutas que encuentro
            t_output << "FileSystem=" << new_Path << '\n';
            std::filesystem::directory_iterator d(new_Path);
            findDir(d, t_output);
        }
    }
}

void loadDirectories()
{
    std::string directory = "./Assets";    // Directorio donde estan todos los recursos que buscar
    std::ifstream infile("resources.cfg"); // Archivo de input
    std::string line;                      // Linea donde se guarda cada linea leida
    std::vector<std::string> text;         // Vector donde me guardo todo el texto leido. Cada componente del vector es una linea

    // si no puede abrir resources.cfg ERROR
    try
    {
        if (!infile)
        {
            throw std::ifstream::failure("resources.cfg dont found");
        }
    }
    catch (std::ifstream::failure& excepcion)
    {
        std::cerr << "Error: " << excepcion.what() << '\n';
        exit(1);
    }

    while (line != "FileSystem=./Assets") // Leo hasta "FileSystem=./Assets" que es lo que no quiero sobreescribir
    {
        getline(infile, line);
        text.push_back(line);
    }
    infile.close(); // Cierro el archivo

    std::ofstream output("resources.cfg" /*, std::ios::app | std::ios::ate*/); // Archivo para output
    for (int i = 0; i < text.size(); i++)                                      // Escribo en el archivo todas las lineas anteriores que quiero conservar
    {
        line = text[i];
        output << line << '\n';
    }
    std::filesystem::directory_iterator dir;

    // abrimos el directorio y si lanza excepcion la capturamos
    try
    {
        dir = std::filesystem::directory_iterator(directory); // si no existe la carpeta de Assets lanzamos excepcion
    }
    catch (std::filesystem::filesystem_error& e)
    {
        std::cerr << "ERROR: " << e.what() << "\n";
        exit(1);
    }
    // Metod recursivo para buscar todos los directorios
    findDir(dir, output);

    output.close(); // Cierro el archivo ���IMPORTANTE PARA QUE SE HAGA BIEN LA LECTURA Y ESCRITURA!!!
}

Ogre::Camera* demoLoadFirstMesh(Ogre::SceneManager* t_sceneMgr)
{
    Ogre::SceneNode* root_scene_node = t_sceneMgr->getRootSceneNode();

    Ogre::Entity* entity = t_sceneMgr->createEntity("myEntity", "cube.mesh");
    Ogre::SceneNode* node = root_scene_node->createChildSceneNode();
    node->attachObject(entity);
    node->setPosition(Ogre::Vector3(0, 0, 0));

    Ogre::Light* light = t_sceneMgr->createLight("myLight");
    Ogre::SceneNode* light_node = root_scene_node->createChildSceneNode();
    light->setType(Ogre::Light::LT_DIRECTIONAL);
    light_node->setDirection(Ogre::Vector3(0, -1, 0));
    light->setDiffuseColour(Ogre::ColourValue(1.0f, 1.0f, 1.0f));
    light->setSpecularColour(Ogre::ColourValue(0.5f, 0.5f, 0.5f));
    light_node->attachObject(light);

    // Crear una c�mara y ubicarla en una posici�n adecuada
    Ogre::Camera* cam = t_sceneMgr->createCamera("myCamera");
    Ogre::SceneNode* cam_node = root_scene_node->createChildSceneNode();
    cam_node->translate(0, 1000, -10);
    cam_node->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TransformSpace::TS_WORLD);
    cam_node->attachObject(cam);
 

    return cam;
}

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);      

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;

    saluda("MARAVILLOSOS DESARROLLADORES");

    OgreWindow::Window* myWindow = new OgreWindow::Window("Motor");
    loadDirectories();
    myWindow->initApp();    
    Ogre::SceneManager* scene_mgr = myWindow->getSceneManger();   

    //QUITAR
    Ogre::Camera* cam = demoLoadFirstMesh(scene_mgr);
    // creamos viewport
    Ogre::Viewport* viewport = myWindow->getRenderWindow()->addViewport(cam);
    viewport->setBackgroundColour(Ogre::ColourValue(0.3, 0.2, 0.6));
    viewport->setDimensions(0, 0, 1, 1); // Tamaño completo de la ventana
    //QUITAR

    // Game-loop
    bool game_playing = true;

    /*auto start_time = std::chrono::high_resolution_clock::now();
    auto previous_time = std::chrono::duration_cast<std::chrono::milliseconds>(start_time - start_time);

    std::chrono::steady_clock::time_point now = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds actual_time;
    std::chrono::milliseconds delta_time;*/

    ecs::Manager* manager = new ecs::Manager();

    /*
        InputSystem* input_system = new InputSystem();
        RenderSystem* render_system = new RenderSystem();
        PhysicsSystem* physics_system = new PhysicsSystem();
        AudioSystem* audio_system = new AudioSystem();
        UISystem* ui_system = new UISystem();
        ScriptingSystem* scripting_system = new ScriptingSystem();

        input_system = manager->addSystem<InputSystem>();
        render_system = manager->addSystem<RenderSystem>();
        physics_system = manager->addSystem<PhysicsSystem>();
        audio_system = manager->addSystem<AudioSystem>();
        ui_system = manager->addSystem<UISystem>();
        scripting_system = manager->addSystem<ScriptingSystem>();
    */

    while (game_playing)
    {             
        // leer entrada
        myWindow->pollEvents();

        // actualizar con delta_time
        /*now = std::chrono::high_resolution_clock::now();
        actual_time = std::chrono::duration_cast<std::chrono::milliseconds>(now - start_time);
        delta_time = actual_time - previous_time;
        std::cout << delta_time.count() << std::endl;
        previous_time = actual_time;*/

        myWindow->getRoot()->renderOneFrame();       

        /*
            input_system->update();
            render_system->update();
            physics_system->update();
            audio_system->update();
            ui_system->update();
            scripting_system->update();
        */

        manager->refresh();
        manager->flushMessages();
    }
    myWindow->shutdown();
    delete myWindow;
    myWindow = nullptr;

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