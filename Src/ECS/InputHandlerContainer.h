#pragma once

#ifndef __INPUT_HANDLER_CONTAINER_H__
#define __INPUT_HANDLER_CONTAINER_H__

#include "InputHandler.h"

class InputHandlerContainer
{
  public:
    InputHandlerContainer();

    virtual ~InputHandlerContainer();

    void clearState();

    // update the state with a new event
    void update(const SDL_Event& t_event);

    // refresh
    void refresh();

    // close window event
    bool closeWindowEvent();

    // resize event
    bool resizeWindowEvent();

    // keyboard
    bool keyDownEvent();

    bool keyUpEvent();

    bool isKeyDown(SDL_Scancode t_key);

    bool isKeyDown(SDL_Keycode t_key);

    bool isKeyUp(SDL_Scancode t_key);

    bool isKeyUp(SDL_Keycode t_key);

    // mouse
    bool mouseMotionEvent();

    bool mouseButtonEvent();

    const std::pair<Sint32, Sint32>& getMousePos();

    int getMouseButtonState(InputHandler::MOUSEBUTTON t_b);

  private:
    InputHandler m_inputHandler;
};

#endif
