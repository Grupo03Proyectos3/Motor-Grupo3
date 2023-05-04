#pragma once
#ifndef __FLAMINGO_CORE_H__
#define __FLAMINGO_CORE_H__

#include "FlamingoAPI.h"
#include <vector>
#include <string>

#include <Scripting/BehaviourScript.h>

namespace Flamingo
{
    class Manager;
    class SceneManager;
    class RenderSystem;
    class MapReader;
    class FLAMINGOEXPORT_API FlamingoCore
    {
      public:
        FlamingoCore();
        ~FlamingoCore();

        /**
        @brief Inicializa los sistemas y carga la escena inicial
        *
        @return bool True si  se logró inicializar el motor correctamente
        */
        bool FlamingoInit();

        /**
        @brief Bucle principal del motor donde se actualizan los sistemas que gestionan los componentes
        *
        */
        void FlamingoLoop();

        /**
        @brief Libera los recursos del motor, comprobando 
        *
        @return bool Devuelve false si no estaba inicializado el motor. True si elimina los recursos del motor con éxito.
        */
        bool FlamingoExit();

        //Exportables

        /**
        @brief Indica el nombre de la primera escena a ejecutarse
        *
        */
        void setFirstScene(std::string t_name);
        void addSceneToLoad(std::string t_name);
        std::string getFirstScene();

        void addGameScript(std::string t_n, BehaviourScript* t_s);

        static FlamingoCore* instance();
        static Manager* getManager();
        static SceneManager* getSceneManager();

        void setLUA(bool lua);

        void endRunning();

      private:

        static FlamingoCore* m_instance;

        std::string m_first_scene = "mapa"; // TO DO : poner un nombre por defecto? para una escena por defecto?
        std::vector<std::string> m_scenes_to_load;

        bool initialized;
        bool m_motor_running;
        MapReader* mapReader;

        bool readLua = true;

    };

    //extern "C" FLAMINGOEXPORT_API void setFirstScene(std::string t_scene_name);
    //extern "C" FLAMINGOEXPORT_API void addScene(std::string t_scene_name);

} // namespace Flamingo
#endif