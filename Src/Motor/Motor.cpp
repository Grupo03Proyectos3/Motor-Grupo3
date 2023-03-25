#include <crtdbg.h>

// ENTITY COMPONENT SYSTEM
#include "ECS/Components.h"
#include "ECS/GameObject.h"
#include "ECS/InputHandler.h"
#include "ECS/Manager.h"


// PHYSICS
#include "Physics/PhysicsSystem.h"
#include "Physics/PlayerController.h"
#include "Physics/RigidBody.h"

// RENDER
#include "Render/Animator.h"
#include "Render/Light.h"
#include "Render/MeshRenderer.h"
#include "Render/RenderSystem.h"
#include "Render/ParticleSystem.h"

//LUA
#include "Lua/LuaSystem.h"

// BASE
#include "FlamingoBase/SceneManager.h"
#include "FlamingoBase/Transform.h"

// UTILS
#include "FlamingoUtils/Timer.h"

// EXTERNAL
#include <fmod.h>

// C++
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Carga de mapas
#include "FlamingoBase/MapReader.h"

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
        else
        {
            std::string x = entry.path().string();
            std::string aux = x.substr(x.size() - 3, 1) + x.substr(x.size() - 2, 1) + x.substr(x.size() - 1, 1);
            if (aux == "zip")
            {
                x = parsePath(x);
                t_output << "Zip=" << x << '\n';
            }
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

void loadScene(RenderSystem* t_render_sys)
{
    MapReader* map_reader = new MapReader();

    map_reader->readMap("Assets/Maps/mapPrueba.json", t_render_sys);

    delete map_reader; // TO DO
}

int main(int argc, char* argv[])
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);  

    loadDirectories();

    // Game-loop
    bool game_playing = true;

    Ogre::String s = "Motor";
    ecs::Manager* m_mngr = ecs::Manager::instance();
    m_mngr->init();

    RenderSystem* render_sys = m_mngr->addSystem<RenderSystem>(s);
    PhysicsSystem* physics_sys = m_mngr->addSystem<PhysicsSystem>();
   // LuaSystem* lua_system = m_mngr->addSystem<LuaSystem>();
    auto& ihldr = ih();

    Flamingo::Timer* player_timer = new Flamingo::Timer();
    auto time = player_timer->getElapsedTime();
    auto dt = player_timer->getElapsedTime() - time;

    loadScene(render_sys);

    //// Sinbad
    // ecs::GameObject* sinbad_go = m_mngr->addGameObject(render_sys->getSceneManager()->getSceneActive()->getSceneRoot(), {ecs::GROUP_RENDER, ecs::GROUP_PHYSICS});
    // auto cmp = ecs::AddComponent<MeshRenderer>(sinbad_go);
    // cmp->initValues(sinbad_go->getNode(), render_sys->getSceneManager()->getSceneActive()->getSceneManger(), /*"cube.mesh"*/ "Sinbad.mesh", "myEntity");
    //// cmp->changeMaterial("Prueba/espana");
    // Transform* cmp_tr = ecs::AddComponent<Transform>(sinbad_go);
    // cmp_tr->initValues(sinbad_go->getNode());
    // cmp_tr->setScale(SVector3(25, 25, 25));
    // cmp_tr->setPosition({0, 200, 0});
    // Flamingo::Animator* animator = ecs::AddComponent<Flamingo::Animator>(sinbad_go);
    // animator->initValues(render_sys->getSceneManager()->getSceneActive()->getSceneManger());
    // animator->setAnimation("Dance", true, true);
    //// TODO Falta probarlo:
    //// m_mngr->setHandler(ecs::HANDLER_EXAMPLE, go);
    // render_sys->getSceneManager()->getSceneActive()->addObjects(sinbad_go);
    // PlayerController* m_controller = ecs::AddComponent<PlayerController>(sinbad_go);
    // m_controller->initValues(20.0f);
    ////RigidBody* m_rigid_body = ecs::AddComponent<RigidBody>(sinbad_go);
    ////m_rigid_body->initValues(1.0f, false, true);

    // ecs::GameObject* ground = m_mngr->addGameObject(render_sys->getSceneManager()->getSceneActive()->getSceneRoot(), {ecs::GROUP_RENDER});
    // cmp = ecs::AddComponent<MeshRenderer>(ground);
    // cmp->initValues(ground->getNode(), render_sys->getSceneManager()->getSceneActive()->getSceneManger(), "cube.mesh", "mygroundEntity");
    //// cmp->changeMaterial("Prueba/espana");
    // cmp_tr = ecs::AddComponent<Transform>(ground);
    // cmp_tr->initValues(ground->getNode());
    // cmp_tr->setPosition(SVector3(0, 0, 0));
    // cmp_tr->setScale(SVector3(50, 0.5, 50));
    // animator = ecs::AddComponent<Flamingo::Animator>(ground);
    // animator->initValues(render_sys->getSceneManager()->getSceneActive()->getSceneManger());
    // cmp->changeMaterial("Prueba/cesped");

    // animator->setAnimation("Dance", true, true);
    //  Falta probarlo:
    //  m_mngr->setHandler(ecs::HANDLER_EXAMPLE, go);
    // render_sys->getSceneManager()->getSceneActive()->addObjects(ground);

    auto nodo = render_sys->getSceneManager()->getSceneActive()->getSceneRoot();
    ecs::GameObject* cube_go = m_mngr->addGameObject({ecs::GROUP_RENDER});
    auto cmp2 = ecs::AddComponent<MeshRenderer>(cube_go);
    cmp2->initValues(nodo, render_sys->getSceneManager()->getSceneActive()->getSceneManger(), "cube.mesh", "CubeEntity");
    cmp2->changeMaterial("Prueba/MichaelScott");
    Transform* cmp_tr2 = ecs::AddComponent<Transform>(cube_go);
    cmp_tr2->initValues(nodo->createChildSceneNode());
    cmp_tr2->setPosition(SVector3(0, 0, 0));
    render_sys->getSceneManager()->getSceneActive()->addObjects(cube_go);

    ecs::GameObject* light_go = m_mngr->addGameObject({ecs::GROUP_RENDER});
    Light* cmp_light = ecs::AddComponent<Light>(light_go);
    cmp_light->initValues(render_sys->getSceneManager()->getSceneActive()->getSceneManger(), nodo->createChildSceneNode(), "myLight");
    cmp_light->initComponent();
    cmp_light->setType(Light::DIRECTIONAL);
    SVector3 direction = SVector3(-1, -1, 0);
    // direction *= -1;
    cmp_light->setDirection(direction);
    cmp_light->setSpecularColour();
    cmp_light->setDiffuseColour();
    render_sys->getSceneManager()->getSceneActive()->addObjects(light_go);

    ecs::GameObject* cam_go = m_mngr->addGameObject({ecs::GROUP_RENDER});
    auto m_camera = ecs::AddComponent<Camera>(cam_go);
    m_camera->initValues(render_sys->getSceneManager()->getSceneActive()->getSceneManger(), nodo->createChildSceneNode(), render_sys->getWindow(), "myCamera");
    m_camera->initComponent();
    m_camera->setViewPortBackgroundColour(Ogre::ColourValue(0.3f, 0.2f, 0.6f));
    // m_camera->setViewPortBackgroundColour(Ogre::ColourValue(0.0, 0.0, 0.0));
    m_camera->lookAt(SVector3(0, 0, 0), Camera::WORLD);
    m_camera->setNearClipDistance(1);
    m_camera->setFarClipDistance(10000);
    render_sys->getSceneManager()->getSceneActive()->addObjects(cam_go);

    Ogre::ParticleSystem* pSys = render_sys->getSceneManager()->getSceneActive()->getSceneManger()->createParticleSystem("psBomba", "PsPrueba/Smoke");

    pSys->setEmitting(true);
    Ogre::SceneNode* prueba = render_sys->getSceneManager()->getSceneActive()->getSceneRoot()->createChildSceneNode();
    prueba->setPosition({0, 60, 0});
    prueba->attachObject(pSys);

 //   Flamingo::ParticleSystem* pSys = ecs::AddComponent<Flamingo::ParticleSystem>(sinbad_go, scene_active->getSceneManger(), scene_active->getSceneRoot()->createChildSceneNode());
  
    while (game_playing && !render_sys->getWindow()->isWindowClosed())
    {
        // Delta time en milisegundos
        dt = player_timer->getElapsedTime() - time;
        // Tiempo transcurrido desde el inicio del programa en milisegundos
        time = player_timer->getElapsedTime();

        // leer entrada

        physics_sys->update(dt);
        render_sys->update(dt);

        // m_controller->handleInput();
        render_sys->manipulateCamera();
        ihldr.refresh(); 
        /*
        if (ihldr.keyDownEvent())
        {
            if (ihldr.isKeyDown(SDLK_0))
                std::cout << "prueba";
        }
        */

        m_mngr->refresh();
        m_mngr->flushMessages();
    }

    render_sys->getWindow()->closeWindow();
    delete player_timer;

    _CrtDumpMemoryLeaks();
    return 0;
}