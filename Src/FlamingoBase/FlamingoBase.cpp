#include "FlamingoBase.h"

//Audio
#include "Audio/AudioSystem.h"

//Carga de mapas
#include "MapReader.h"
#include "ResourcesLoader/Loader.h"

//ECS
#include "ECS/Manager.h"

//Físicas
#include "Physics/PhysicsSystem.h"

//FlamingoBase
#include "FlamingoUtils/Timer.h"

//LUA
#include <Lua/LuaSystem.h>

//Render3D
#include "Render/RenderSystem.h"

//INCLUDES TEMPORALES PARA LA ESCENA DE JUEGO



namespace Flamingo
{
    FlamingoBase::FlamingoBase()
    {
    }

    FlamingoBase::~FlamingoBase()
    {
    }

    bool FlamingoBase::loadScene(RenderSystem* t_sys)
    {
        try
        {
            MapReader* map_reader = new MapReader(t_sys);

            map_reader->readMap("Assets/Maps/mapPrueba.json");

            delete map_reader;
        }
        catch (...)
        {
            return false;
        }

        return true;
    }

    bool FlamingoBase::FlamingoInit()
    {
        Loader l;
        l.loadDirectories();

        std::string s = "Motor";
        ecs::Manager* m_mngr = ecs::Manager::instance();
        m_mngr->init();

        RenderSystem* render_sys = m_mngr->addSystem<RenderSystem>(s);
        PhysicsSystem* physics_sys = m_mngr->addSystem<PhysicsSystem>();
        AudioSystem* audio_sys = m_mngr->addSystem<AudioSystem>();
        Flamingo::LuaSystem* lua_system = m_mngr->addSystem<Flamingo::LuaSystem>();

        if (!loadScene(render_sys))
        {
            std::cout << "No ha sido posible cargar la escena";
            return false;
        }

        return true;
    }

    void FlamingoBase::FlamingoLoop()
    {
        bool motor_running = true;

        Flamingo::Timer* player_timer = new Flamingo::Timer();
        auto time = player_timer->getElapsedTime();
        auto dt = player_timer->getElapsedTime() - time;

        ecs::Manager* m_mngr = ecs::Manager::instance();

        auto render_sys = m_mngr->getSystem<RenderSystem>();

        auto& ihldr = ih();


        while (motor_running && !render_sys->getWindow()->isWindowClosed())
        {
            // Delta time en milisegundos
            dt = player_timer->getElapsedTime() - time;
            // Tiempo transcurrido desde el inicio del programa en milisegundos
            time = player_timer->getElapsedTime();

            // leer entrada

            for (auto sys : m_mngr->getSystems())
            {
                if (sys)
                {
                    sys->update(dt);
                }
            }

            // m_controller->handleInput();
            render_sys->manipulateCamera();
            ihldr.refresh();

            m_mngr->refresh();
            m_mngr->flushMessages();
        }
        //  ui_sys->eraseContext();
        render_sys->getWindow()->closeWindow();
        delete player_timer;
    }

    bool FlamingoBase::FlamingoExit()
    {
        return false;
    }
}
