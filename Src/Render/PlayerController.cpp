#include "PlayerController.h"

PlayerController::PlayerController() 
{
}

PlayerController::PlayerController(float t_playerSpeed)
    : m_playerSpeed(t_playerSpeed)
{
}

PlayerController::~PlayerController() 
{
}

void PlayerController::initComponent()
{
}

void PlayerController::movePlayer(float t_vertical, float t_horizontal)
{
    //m_go = m_mngr->getHandler(ecs::HANDLER_EXAMPLE);
    /*m_playerTransform = m_mngr->getComponent<Transform>(m_ent);
    m_playerTransform->setPosition(m_playerTransform->getPosition() + SVector3(t_horizontal, t_vertical, 0));*/
}

void PlayerController::dash()
{
}

void PlayerController::handleInput()
{
    auto& ihldr = ih();
    ihldr.refresh();

    if (ihldr.keyDownEvent())
    {
        if (ihldr.isKeyDown(SDLK_w))
        {
            movePlayer(m_playerSpeed, 0);
        }
        else if (ihldr.isKeyDown(SDLK_s))
        {
            movePlayer(-m_playerSpeed, 0);
        }
        if (ihldr.isKeyDown(SDLK_a))
        {
            movePlayer(0, -m_playerSpeed);
        }
        else if (ihldr.isKeyDown(SDLK_d))
        {
            movePlayer(0, m_playerSpeed);
        }
    }
}
