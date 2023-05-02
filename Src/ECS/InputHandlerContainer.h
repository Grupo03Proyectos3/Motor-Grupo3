#pragma once

#ifndef __INPUT_HANDLER_CONTAINER_H__
#define __INPUT_HANDLER_CONTAINER_H__

#include "FlamingoUtils/FlamingoKeys.h"
#include <ECS/SingletonECS.h>

namespace Flamingo
{
    class InputHandler;

    class __declspec(dllexport) InputHandlerContainer : public SingletonECS<InputHandlerContainer>
    {
        friend SingletonECS<InputHandlerContainer>;

      public:
        InputHandlerContainer();

        virtual ~InputHandlerContainer();

        void clearState();

        // close window event
        bool closeWindowEvent();

        // resize event
        bool resizeWindowEvent();

        // keyboard
        bool keyDownEvent();

        bool keyUpEvent();

        bool isKeyDown(FLM_KeyCode t_key);

        bool isKeyUp(FLM_KeyCode t_key);

        // mouse
        bool mouseMotionEvent();

        bool mouseButtonEvent();

        const std::pair<int32_t, int32_t>& getMousePos();

        const std::pair<int32_t, int32_t>& getMouseMotionPos();

        int getMouseButtonState(MOUSEBUTTON t_b);

      private:
        InputHandler& m_inputHandler;
    };
    // This macro defines a compact way for using the singleton InputHandler
    //
    __declspec(dllexport)InputHandlerContainer& Input();

    // Export the InputHandlerContainer class
    template class __declspec(dllexport) SingletonECS<InputHandlerContainer>;

} // namespace Flamingo
#endif
