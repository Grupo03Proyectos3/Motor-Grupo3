// This file is part of the course TPV2@UCM - Samir Genaim

#pragma once

#ifndef __INPUT_HANDLER_H__
#define __INPUT_HANDLER_H__

#include "SingletonECS.h"
#include <SDL.h>
#include <array>
#include <iostream>
#include <vector>

class InputHandler : public SingletonECS<InputHandler>
{
    friend SingletonECS<InputHandler>;

  public:
    enum MOUSEBUTTON : uint8_t
    {
        LEFT = 0,
        MIDDLE = 1,
        RIGHT = 2
    };

    InputHandler();

    virtual ~InputHandler();

    void clearState();

    // update the state with a new event
    void update(const SDL_Event& t_event);

    // refresh
    void refresh();

    // close window event
    bool closeWindowEvent();

    //resize event
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

    int getMouseButtonState(MOUSEBUTTON t_b);

  private:

    void onKeyDown(const SDL_Event&);

    void onKeyUp(const SDL_Event&);

    void onMouseMotion(const SDL_Event& t_event);

    void onMouseButtonChange(const SDL_Event& t_event, bool t_is_down);

    void handleWindowEvent(const SDL_Event& t_event);

    void sendMessageWindowResized();

    bool m_is_close_window;
    bool m_is_resized_window;
    bool m_is_key_up;
    bool m_is_key_down;
    bool m_is_mouse_motion;
    bool m_is_mouse_button;
    std::pair<Sint32, Sint32> m_mouse_pos;
    std::array<bool, 3> m_mB_state;
    const Uint8* m_kB_state;
};

// This macro defines a compact way for using the singleton InputHandler, instead of
// writing InputHandler::instance()->method() we write ih().method()
//
InputHandler& ih();

#endif