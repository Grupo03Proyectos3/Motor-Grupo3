#include "PlayerController.h"

PlayerController::PlayerController()
{
}

PlayerController::~PlayerController()
{
}

void PlayerController::initComponent()
{
}

void PlayerController::movePlayer(float t_horizontal, float t_vertical)
{
    
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
        }
        else if (ihldr.isKeyDown(SDLK_s))
        {
        }
        else if (ihldr.isKeyDown(SDLK_a))
        {
        }
        else if (ihldr.isKeyDown(SDLK_d))
        {
        }
    }
}
