#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__
#pragma once
#include "ECS/SingletonECS.h"
#include "Scene.h"
#include <unordered_map>

namespace Flamingo
{
    class PhysicsSystem;
    class RenderSystem;
    class UISystem;
} // namespace Flamingo
namespace Ogre
{
    class Root;
    class SceneManager;
} // namespace Ogre

namespace Flamingo
{
    class FLAMINGOEXPORT_API SceneManager : public SingletonECS<Flamingo::SceneManager>
    {
        friend PhysicsSystem;
        friend RenderSystem;
        friend UISystem;
        friend SingletonECS<SceneManager>;

      public:
        SceneManager();
        ~SceneManager();
        void initManager(std::string t_Name, Manager* m_mng);

        /**
         * @brief Crea una nueva escena y la activa/desactiva
         *
         * @param[in] t_SceneName nombre de la nueva escena
         * @param[in] setActive si la escena estará activa o no
         *
         * @return Scene*
         */
        Scene* createScene(std::string t_SceneName, bool setActive = false);

         /**
         * @brief Borra una escena
         *
         * @param[in] t_SceneName nombre de la escena a borrar
         *
         * @return void
         */
        void delScene(std::string t_SceneName);

        /**
         * @brief Pone una escena como activa, desactivando antes la escena activa
         * Además se guarda referencias a esta nueva escena
         *
         * @param[in] t_SceneName nombre de la nueva escena activa
         *
         * @return void
         */
        void setSceneActive(std::string t_SceneName);

        /**
         * @brief Devuelve cual es la escena que esta actualmente activa
         *
         *
         * @return Scene*
         */
        Scene* getSceneActive();

        /**
         * @brief Obtiene la referencia a una escena en concreto
         *
         * @param[in] t_SceneName nombre de la escena
         * 
         * @return Scene*
         */
        Scene* getScene(std::string t_scene_name);

         /**
         * @brief Añade una escena al unordered_map m_scenes donde se guardan todas
         * las referencias a estas. Si ya existia una escena con ese nombre
         * salta un excepcion
         *
         * @param[in] t_Scene escena a añadir
         *
         * @return void
         */
        void addScene(Scene* t_Scene);

          /**
         * @brief Modifica el valor de m_reloadScene para permitir que se 
         * vuelva a recargar la escena actual
         *
         * 
         * @return void
         */
        void reloadScenePetition();

         /**
         * @brief Modifica el valor de m_reloadScene para permitir que se
         * vuelva a recargar la escena
         *
         * @param[in] t_sceneName escena que se quiere recargar
         *
         * @return void
         */
        void startScene(std::string t_sceneName);

         /**
         * @brief Si m_reloadScene es verdadero se borra la informacion de la escena a recargar una escena
         * para volverla a crear todos los elementos de esta, poniedola como activa
         *
         * @return void
         */
        void reloadScene();

        Scene* getSceneToAttach();
        void setSceneToAttach(Scene* t_sceneToAttach);

      private:
        Manager* m_mngr;

        std::unordered_map<std::string, Scene*> m_scenes;
        std::unordered_map<std::string, Scene*>::iterator itScene = m_scenes.end();
        std::string mNameSceneActive = "";
        std::string mName;

        bool m_reloadScene = false;
        Scene* m_sceneToReload;
        Scene* m_sceneToAsociated = nullptr;
    };
    // This macro defines a compact way for using the singleton
    //
    SceneManager& FlamingoSceneManager();
} // namespace Flamingo
#endif