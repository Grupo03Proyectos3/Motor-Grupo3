#pragma once

#ifndef __INPUT_HANDLER_CONTAINER_H__
#define __INPUT_HANDLER_CONTAINER_H__


#include "FlamingoUtils/FlamingoKeys.h"
#include "FlamingoExport/FlamingoAPI.h"
#include <ECS/SingletonECS.h>
namespace Flamingo{
    class InputHandler;

    __declspec(dllexport) class InputHandlerContainer : public SingletonECS<InputHandlerContainer>
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

        const std::pair<Sint32, Sint32>& getMousePos();

        const std::pair<Sint32, Sint32>& getMouseMotionPos();

        int getMouseButtonState(MOUSEBUTTON t_b);

      private:
        InputHandler& m_inputHandler;
    };
    // This macro defines a compact way for using the singleton InputHandler
    //
    InputHandlerContainer& Input();
} // namespace Flamingo
#endif
