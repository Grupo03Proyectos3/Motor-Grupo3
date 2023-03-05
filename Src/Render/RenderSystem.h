#pragma once
#ifndef __RENDER_SYSTEM_H__
#define __RENDER_SYSTEM_H__

#include "ECS/System.h"

#include "Camera.h"
#include "Window.h"

#include "PlayerController.h"


class RenderSystem : public ecs::System
{
  public:
    __SYSTEM_ID_DECL__(ecs::_sys_RENDER)

    RenderSystem(Ogre::String& t_app_name);
    virtual ~RenderSystem();

    void recieve(const Message&) override;
    void initSystem() override;
    void update(float t_delta_time) override;

    void createRoot();
    void setUp();
    void locateResources();
    void loadResources();
    void bringResources(Ogre::String& sec_name, Ogre::String& type_name, Ogre::String& arch_name);

    bool config();

    inline Flamingo::Window* getWindow() { return m_window; }
    inline Ogre::Root* getOgreRoot() { return m_root; }
    inline Flamingo::SceneManager* getSceneManager() { return m_scene_mngr; }    
    // en esta funcion se manipula la cámara
    void manipulateCamera();

    void Pruebas();

  private:
    Ogre::Root* m_root;                // OGRE root
    Ogre::FileSystemLayer* m_fs_layer; // Fichero de recursos
    Flamingo::Window* m_window = nullptr;
    Flamingo::SceneManager* m_scene_mngr = nullptr;
    Ogre::String m_app_name;    // Nombre de la app
    Camera* m_camera = nullptr; // cámara

    PlayerController* m_controller = nullptr;
};

#endif