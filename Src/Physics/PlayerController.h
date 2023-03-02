#pragma once
#ifndef __PLAYER_CONTROLLER_H__
#define __PLAYER_CONTROLLER_H__

#include "ECS/Component.h"
#include "ECS/Entity.h"
#include "ECS/Manager.h"
#include "Render/Camera.h"

struct PlayerController : public ecs::Component
{
  public:
    __SYSTEM_ID_DECL__(ecs::_cmp_PLAYER_CONTROLLER)

    PlayerController();

    virtual ~PlayerController();

    virtual void initComponent();

    void movePlayer(float t_horizontal, float t_vertical);
    void dash();
    // Métodos para el input del jugador
    void handleInput();

  private:
    bool m_active;
    GameObject m_playerGo;
    /*
     * Input del jugador
     */
    float m_horizontal;
    float m_vertical;
    /*
     * Movimiento del personaje
     */
    float m_playerSpeed;
    /*
     * Cámara
     */
    Camera m_mainCamera;
    SVector3 m_cameraPosition;
    /*
     * Edministración de estado
     */
    float m_health;
    bool m_isDashing;
};

#endif
