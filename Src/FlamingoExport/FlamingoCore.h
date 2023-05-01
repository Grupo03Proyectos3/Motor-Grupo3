#pragma once
#ifndef __FLAMINGO_CORE_H__
#define __FLAMINGO_CORE_H__

#include "FlamingoAPI.h"
#include <string>
#include <list>

#include "ECS/SingletonECS.h"
#include <string>


namespace Flamingo
{
    class RenderSystem;
    class FLAMINGOEXPORT_API FlamingoCore : public SingletonECS<FlamingoCore>
    {
        friend SingletonECS<FlamingoCore>;

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

        void setFirstScene(const std::string& t_name);
        void addSceneToLoad(const std::string& t_name);
        std::string getFirstScene();

        void prueba();

      private:

        std::string m_first_scene = "mapa"; // TO DO : poner un nombre por defecto? para una escena por defecto?
        std::list<std::string> m_scenes_to_load;
      
    };

    extern "C" FLAMINGOEXPORT_API void setFirstScene(const std::string& t_scene_name);
    extern "C" FLAMINGOEXPORT_API void addScene(const std::string& t_scene_name);
} // namespace Flamingo
#endif