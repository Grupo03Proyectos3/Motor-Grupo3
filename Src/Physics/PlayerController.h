#pragma once
#ifndef __PLAYER_CONTROLLER_H__
#define __PLAYER_CONTROLLER_H__

#include "ECS/Component.h"
#include "ECS/GameObject.h"
#include "ECS/InputHandler.h"
#include "ECS/Manager.h"
#include "FlamingoBase/Transform.h"
#include "Render/Camera.h"

struct PlayerController : public ecs::Component
{
  public:
    __SYSTEM_ID_DECL__(ecs::_cmp_PLAYER_CONTROLLER)

    PlayerController();
    PlayerController(float t_playerSpeed);

    virtual ~PlayerController();
    virtual void initComponent();

    void movePlayer(float t_horizontal, float t_vertical);
    void rotatePlayer(double t_angle, SVector3 t_axis);

    // Métodos para el input del jugador
    void handleInput();

  private:
    bool m_active;

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
    // SVector3 m_cameraPosition;
};

#endif
