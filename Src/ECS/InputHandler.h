// This file is part of the course TPV2@UCM - Samir Genaim

#pragma once

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

    virtual ~InputHandler();

    void clearState();

    // update the state with a new event
    inline void update(const SDL_Event& event)
    {
        int whichOne;
        switch (event.type)
        {
            case SDL_KEYDOWN:
                onKeyDown(event);
                break;
            case SDL_KEYUP:
                onKeyUp(event);
                break;
            case SDL_MOUSEMOTION:
                onMouseMotion(event);
                break;
            case SDL_MOUSEBUTTONDOWN:
                onMouseButtonChange(event, true);
                break;
            case SDL_MOUSEBUTTONUP:
                onMouseButtonChange(event, false);
                break;
            case SDL_WINDOWEVENT:
                handleWindowEvent(event);
                break;
            default:
                break;
        }
    }

    // refresh
    inline void refresh()
    {
        SDL_Event event;

        clearState();
        while (SDL_PollEvent(&event))
            update(event);
    }

    // close window event
    inline bool closeWindowEvent()
    {
        return isCloseWindoEvent_;
    }

    // keyboard
    inline bool keyDownEvent()
    {
        return isKeyDownEvent_;
    }

    inline bool keyUpEvent()
    {
        return isKeyUpEvent_;
    }

    inline bool isKeyDown(SDL_Scancode key)
    {
        return keyDownEvent() && kbState_[key] == 1;
    }

    inline bool isKeyDown(SDL_Keycode key)
    {
        return isKeyDown(SDL_GetScancodeFromKey(key));
    }

    inline bool isKeyUp(SDL_Scancode key)
    {
        return keyUpEvent() && kbState_[key] == 0;
    }

    inline bool isKeyUp(SDL_Keycode key)
    {
        return isKeyUp(SDL_GetScancodeFromKey(key));
    }

    // mouse
    inline bool mouseMotionEvent()
    {
        return isMouseMotionEvent_;
    }

    inline bool mouseButtonEvent()
    {
        return isMouseButtonEvent_;
    }

    inline const std::pair<Sint32, Sint32>& getMousePos()
    {
        return mousePos_;
    }

    inline int getMouseButtonState(MOUSEBUTTON b)
    {
        return mbState_[b];
    }

  private:
    InputHandler()
    {
        kbState_ = SDL_GetKeyboardState(0);
        clearState();
    }

    inline void onKeyDown(const SDL_Event&)
    {
        isKeyDownEvent_ = true;
    }

    inline void onKeyUp(const SDL_Event&)
    {
        isKeyUpEvent_ = true;
    }

    inline void onMouseMotion(const SDL_Event& event)
    {
        isMouseMotionEvent_ = true;
        mousePos_.first = event.motion.x;
        mousePos_.second = event.motion.y;
    }

    inline void onMouseButtonChange(const SDL_Event& event, bool isDown)
    {
        isMouseButtonEvent_ = true;
        switch (event.button.button)
        {
            case SDL_BUTTON_LEFT:
                mbState_[LEFT] = isDown;
                break;
            case SDL_BUTTON_MIDDLE:
                mbState_[MIDDLE] = isDown;
                break;
            case SDL_BUTTON_RIGHT:
                mbState_[RIGHT] = isDown;
                break;
            default:
                break;
        }
    }

    inline void handleWindowEvent(const SDL_Event& event)
    {
        switch (event.window.event)
        {
            case SDL_WINDOWEVENT_CLOSE:
                isCloseWindoEvent_ = true;
                break;
            default:
                break;
        }
    }

    bool isCloseWindoEvent_;
    bool isKeyUpEvent_;
    bool isKeyDownEvent_;
    bool isMouseMotionEvent_;
    bool isMouseButtonEvent_;
    std::pair<Sint32, Sint32> mousePos_;
    std::array<bool, 3> mbState_;
    const Uint8* kbState_;
};

// This macro defines a compact way for using the singleton InputHandler, instead of
// writing InputHandler::instance()->method() we write ih().method()
//
inline InputHandler& ih()
{
    return *InputHandler::instance();
}
