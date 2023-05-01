#pragma once
#ifndef __FLAMINGO_CORE_H__
#define __FLAMINGO_CORE_H__

#include "FlamingoAPI.h"
#include <vector>
#include <string>

#include <Lua/BehaviourScript.h>

namespace Flamingo
{
    class Manager;
    class SceneManager;
    class RenderSystem;

    class FLAMINGOEXPORT_API FlamingoCore
    {
      public:
        FlamingoCore();
        ~FlamingoCore();

        /**
        @brief Inicializa los sistemas y carga la escena inicial
        *
        @return
        */
        bool FlamingoInit();
        void FlamingoLoop();
        bool FlamingoExit();

        void setFirstScene(std::string t_name);
        void addSceneToLoad(std::string t_name);
        std::string getFirstScene();

        void addGameScript(std::string t_n, BehaviourScript* t_s);

        static FlamingoCore* instance();
        static Manager* getManager();
        static SceneManager* getSceneManager();

      private:

        static FlamingoCore* m_instance;

        std::string m_first_scene = "mapa"; // TO DO : poner un nombre por defecto? para una escena por defecto?
        std::vector<std::string> m_scenes_to_load;
    };

    //extern "C" FLAMINGOEXPORT_API void setFirstScene(std::string t_scene_name);
    //extern "C" FLAMINGOEXPORT_API void addScene(std::string t_scene_name);

} // namespace Flamingo
#endif