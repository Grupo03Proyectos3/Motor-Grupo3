#include <crtdbg.h>

#include "ECS/InputHandler.h"
#include "FlamingoUtils/Timer.h"
#include "IMGUI/imgui.h"
#include "Physics/PhysicsSystem.h"
#include "Render/RenderSystem.h"
#include <OgreRoot.h> // MEMORY LEAK
#include <filesystem>
#include <fmod.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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

    /*auto start_time = std::chrono::high_resolution_clock::now();
    auto previous_time = std::chrono::duration_cast<std::chrono::milliseconds>(start_time - start_time);

    std::chrono::steady_clock::time_point now = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds actual_time;
    std::chrono::milliseconds delta_time;*/

    /*
        InputSystem* input_system = new InputSystem();
        PhysicsSystem* physics_system = new PhysicsSystem();
        AudioSystem* audio_system = new AudioSystem();
        UISystem* ui_system = new UISystem();
        ScriptingSystem* scripting_system = new ScriptingSystem();

        input_system = manager->addSystem<InputSystem>();
        physics_system = manager->addSystem<PhysicsSystem>();
        audio_system = manager->addSystem<AudioSystem>();
        ui_system = manager->addSystem<UISystem>();
        scripting_system = manager->addSystem<ScriptingSystem>();
    */

    Ogre::String s = "Motor";
    ecs::Manager* m_mngr = ecs::Manager::instance();
    m_mngr->init();
    RenderSystem* render_sys = m_mngr->addSystem<RenderSystem>(s);
    PhysicsSystem* physics_system = m_mngr->addSystem<PhysicsSystem>();
    //  auto& ihldr = ih();

    Flamingo::Timer* playerTimer = new Flamingo::Timer();
    auto time = playerTimer->getElapsedTime();
    auto dt = playerTimer->getElapsedTime() - time;   

    while (game_playing && !render_sys->getWindow()->isWindowClosed())
    {
        // Delta time en milisegundos
        dt = playerTimer->getElapsedTime() - time;
        // Tiempo transcurrido desde el inicio del programa en milisegundos
        time = playerTimer->getElapsedTime();
        // leer entrada
       

        // actualizar con delta_time
        /*now = std::chrono::high_resolution_clock::now();
        actual_time = std::chrono::duration_cast<std::chrono::milliseconds>(now - start_time);
        delta_time = actual_time - previous_time;
        std::cout << delta_time.count() << std::endl;
        previous_time = actual_time;*/

        render_sys->update(dt);
        /*
            input_system->update();
            render_system->update();
            physics_system->update();
            audio_system->update();
            ui_system->update();
            scripting_system->update();
        */
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

    // delete manager; // Elimina todos los systems

    ImGui::DestroyContext();

    _CrtDumpMemoryLeaks();
    return 0;
}