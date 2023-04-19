#pragma once
#ifndef __RENDER_SYSTEM_H__
#define __RENDER_SYSTEM_H__

#include "ECS/System.h"

#include "Camera.h"

//#include "Physics/PlayerController.h"


namespace Flamingo
{
    class Window;

	class RenderSystem : public ecs::System
    {
      public:
        __SYSTEM_ID_DECL__(ecs::_sys_RENDER)

        RenderSystem(){};
        RenderSystem(Ogre::String& t_app_name);
        virtual ~RenderSystem();

        void recieve(const Message&) override;
        void initSystem() override;
        void update(float t_delta_time) override;

        inline Flamingo::Window* getWindow() { return m_window; }
        inline Ogre::Root* getOgreRoot() { return m_root; }
        inline Flamingo::SceneManager* getSceneManager() { return m_scene_mngr; }
        inline Ogre::String getAppName() { return m_app_name; }
        // en esta funcion se manipula la cámara
        void manipulateCamera();

        void Pruebas();

      private:
        Ogre::Root* m_root = nullptr;                // OGRE root
        Ogre::FileSystemLayer* m_fs_layer = nullptr; // Fichero de recursos
        Flamingo::Window* m_window = nullptr;
        Flamingo::SceneManager* m_scene_mngr = nullptr;
        Ogre::String m_app_name;    // Nombre de la app
        Camera* m_camera = nullptr; // cámara

        void createRoot();
        void setUp();
        void loadResources();
        void locateResources();
        void bringResources(Ogre::String& sec_name, Ogre::String& type_name, Ogre::String& arch_name);
        bool config();
    };
}

#endif