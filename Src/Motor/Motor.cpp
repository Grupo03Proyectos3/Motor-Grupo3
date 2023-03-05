#include <crtdbg.h>

// ENTITY COMPONENT SYSTEM
#include "ECS/InputHandler.h"
#include "ECS/Components.h"
#include "ECS/GameObject.h"
#include "ECS/Manager.h"

// IMGUI
#include "IMGUI/imgui.h"

// PHYSICS
#include "Physics/PhysicsSystem.h"
#include "Physics/RigidBody.h"

// RENDER
#include "Render/RenderSystem.h"
#include "Render/PlayerController.h"
#include "Render/MeshRenderer.h"
#include "Render/Animator.h"

// BASE
#include "FlamingoBase/SceneManager.h"
#include "FlamingoBase/Transform.h"


// UTILS
#include "FlamingoUtils/Timer.h"

// EXTERNAL
#include <fmod.h>
#include <OgreRoot.h> // MEMORY LEAK

// C++
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

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
        else{
            std::string x = entry.path().string();
            std::string aux = x.substr(x.size() - 3, 1) + x.substr(x.size() - 2, 1) + x.substr(x.size() - 1, 1);           
            if (aux == "zip"){
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

int main(int argc, char* argv[])
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    // IMGUI
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;

    loadDirectories();

    // Game-loop
    bool game_playing = true;


    Ogre::String s = "Motor";
    ecs::Manager* m_mngr = ecs::Manager::instance();
    m_mngr->init();

    RenderSystem* render_sys = m_mngr->addSystem<RenderSystem>(s);
    PhysicsSystem* physics_sys = m_mngr->addSystem<PhysicsSystem>();
    //  auto& ihldr = ih();

    Flamingo::Timer* playerTimer = new Flamingo::Timer();
    auto time = playerTimer->getElapsedTime();
    auto dt = playerTimer->getElapsedTime() - time;   


    // Sinbad
    ecs::GameObject* sinbad_go = m_mngr->addGameObject(render_sys->getSceneManager()->getSceneActive()->getSceneRoot(), {ecs::GROUP_RENDER, ecs::GROUP_PHYSICS});
    auto cmp = ecs::AddComponent<MeshRenderer>(sinbad_go, sinbad_go->getNode(), render_sys->getSceneManager()->getSceneActive()->getSceneManger(), /*"cube.mesh"*/ "Sinbad.mesh", "myEntity");
    // cmp->changeMaterial("Prueba/espana");
    Transform* cmp_tr = ecs::AddComponent<Transform>(sinbad_go, sinbad_go->getNode());
    cmp_tr->setScale(SVector3(25, 25, 25));
    Flamingo::Animator* animator = ecs::AddComponent<Flamingo::Animator>(sinbad_go, render_sys->getSceneManager()->getSceneActive()->getSceneManger());
    animator->setAnimation("Dance", true, true);
    // TODO Falta probarlo:
    // m_mngr->setHandler(ecs::HANDLER_EXAMPLE, go);
    render_sys->getSceneManager()->getSceneActive()->addObjects(sinbad_go);
    PlayerController* m_controller = ecs::AddComponent<PlayerController>(sinbad_go, 20.0f);
    RigidBody* m_rigid_body = ecs::AddComponent<RigidBody>(sinbad_go, 1.0f, false, true);

    while (game_playing && !render_sys->getWindow()->isWindowClosed())
    {
        // Delta time en milisegundos
        dt = playerTimer->getElapsedTime() - time;
        // Tiempo transcurrido desde el inicio del programa en milisegundos
        time = playerTimer->getElapsedTime();

        // leer entrada
        m_controller->handleInput();

        physics_sys->update(dt);
        render_sys->update(dt);

        render_sys->manipulateCamera();
        /*ihldr.refresh();
        if (ihldr.keyDownEvent())
        {
            if (ihldr.isKeyDown(SDLK_0))
                std::cout << "prueba";
        }*/

        m_mngr->refresh();
        m_mngr->flushMessages();
    }

    render_sys->getWindow()->closeWindow();

    ImGui::DestroyContext();

    _CrtDumpMemoryLeaks();
    return 0;
}