#include "PlayerController.h"

PlayerController::PlayerController()
    : m_playerSpeed(3.0f)
    , m_active(true)
    , m_mainCamera(new Camera())
{
}

PlayerController::PlayerController(float t_playerSpeed)
    : m_playerSpeed(t_playerSpeed)
    , m_active(true)
    , m_mainCamera(new Camera())
{
}

PlayerController::~PlayerController()
{
    delete m_mainCamera;
}

void PlayerController::initComponent()
{
    m_transform = m_mngr->getComponent<Transform>(m_ent);
}

void PlayerController::movePlayer(float t_vertical, float t_horizontal)
{
    m_transform->translate(SVector3(t_horizontal, 0, t_vertical));
}

void PlayerController::handleInput()
{
    auto& ihldr = ih();
    ihldr.refresh();

    if (ihldr.keyDownEvent())
    {
        if (ihldr.isKeyDown(SDLK_w))
        {
            movePlayer(m_playerSpeed, 0.0f);
        }
        else if (ihldr.isKeyDown(SDLK_s))
        {
            movePlayer(-m_playerSpeed, 0.0f);
        }
        if (ihldr.isKeyDown(SDLK_a))
        {
            movePlayer(0.0f, -m_playerSpeed);
        }
        else if (ihldr.isKeyDown(SDLK_d))
        {
            movePlayer(0.0f, m_playerSpeed);
        }
    }
    /*else
    {
        movePlayer(0, 0);
    }*/
}
