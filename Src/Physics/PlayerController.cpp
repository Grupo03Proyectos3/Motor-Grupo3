#include "PlayerController.h"

PlayerController::PlayerController()
    : m_playerSpeed(3.0f)
    , m_active(true)
    , m_mainCamera(new Camera())
{
}

PlayerController::PlayerController(float t_playerSpeed, Transform* t_transform)
    : m_playerSpeed(t_playerSpeed)
    , m_active(true)
    , m_go(m_ent)
    , m_mainCamera(new Camera())
    , m_transform(t_transform)
{
}

PlayerController::~PlayerController()
{
    delete m_go;
    delete m_mainCamera;
}

void PlayerController::movePlayer(float t_vertical, float t_horizontal)
{
    /*
    , m_go(m_mngr->getHandler(ecs::_cmp_PLAYER_CONTROLLER))*/
    /* auto aux = m_transform->getPosition();
     m_transform->setPosition(aux + SVector3(t_horizontal, t_vertical, 0));*/
    /*m_player_node.translate(t_horizontal, t_vertical, 0);*/
    m_go->getNode()->translate(t_horizontal, t_vertical, 0);
}

void PlayerController::handleInput()
{
    auto& ihldr = ih();
    ihldr.refresh();

    if (ihldr.keyDownEvent())
    {
        if (ihldr.isKeyDown(SDLK_w))
        {
            std::cout << "AAAAAAAAA ";
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
