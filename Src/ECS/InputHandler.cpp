#include "InputHandler.h"



InputHandler::~InputHandler()
{
}

void InputHandler::clearState()
{
    isCloseWindoEvent_ = false;
    isKeyDownEvent_ = false;
    isKeyUpEvent_ = false;
    isMouseButtonEvent_ = false;
    isMouseMotionEvent_ = false;
    for (auto i = 0u; i < 3; i++)
    {
        mbState_[i] = false;
    }
}
