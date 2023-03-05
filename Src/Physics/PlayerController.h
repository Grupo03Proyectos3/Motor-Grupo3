#pragma once
#ifndef __PLAYER_CONTROLLER_H__
#define __PLAYER_CONTROLLER_H__

#include "ECS/Component.h"
#include "ECS/GameObject.h"
#include "ECS/Manager.h"
#include "ECS/InputHandler.h"
#include "Render/Camera.h"
#include "FlamingoBase/Transform.h"


struct PlayerController : public ecs::Component
{
  public:
    __SYSTEM_ID_DECL__(ecs::_cmp_PLAYER_CONTROLLER)

    PlayerController();
    PlayerController(float t_playerSpeed, Transform* t_transform);

    virtual ~PlayerController();

    void movePlayer(float t_horizontal, float t_vertical);
    
    // Métodos para el input del jugador
    void handleInput();

  private:
    bool m_active;
    ecs::GameObject* m_go;
    Transform* m_transform;
    Ogre::SceneNode* m_player_node;
    /*
     * Movimiento del personaje
     */
    float m_playerSpeed;
    /*
     * Cámara
     */
    Camera* m_mainCamera;
    //SVector3 m_cameraPosition;
    
};

#endif
