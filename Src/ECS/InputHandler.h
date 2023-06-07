

#pragma once

#ifndef __INPUT_HANDLER_H__
#define __INPUT_HANDLER_H__

#include "FlamingoUtils/FlamingoKeys.h"
#include "SingletonECS.h"
#include <SDL.h>
#include <array>
#include <iostream>
#include <vector>
#include "System.h"
namespace Flamingo
{
    class InputHandler : public SingletonECS<InputHandler>, public System
    {
        friend SingletonECS<InputHandler>;

      public:
        InputHandler();

        virtual ~InputHandler();

        void clearState();

        /**
         * @brief Actualiza el estado con un nuevo evento
         *
         * @param[in]  t_event const SDL_Event& evento a recibir
         */
        void updateKeys(const SDL_Event& t_event);

        // refresh
        void update(float t_delta_time) override;

        // close window event
        bool closeWindowEvent();

        // resize event
        bool resizeWindowEvent();

        // keyboard
        bool keyDownEvent();

        bool keyUpEvent();

        bool isKeyDown(SDL_Keycode t_key);

        bool isKeyUp(SDL_Keycode t_key);

        // mouse
        bool mouseMotionEvent();

        bool mouseButtonEvent();

        const std::pair<Sint32, Sint32>& getMousePos();

        const std::pair<Sint32, Sint32>& getMouseMotionPos();

        int getMouseButtonState(MOUSEBUTTON t_b);

      private:
        // pulsar/levantar tecla
        bool isKeyDown(SDL_Scancode t_key);

        bool isKeyUp(SDL_Scancode t_key);

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
        std::pair<Sint32, Sint32> m_mouse_MotionPos;
        std::array<bool, 3> m_mB_state;
        const Uint8* m_kB_state;
    };

    InputHandler& ih();
} // namespace Flamingo
#endif