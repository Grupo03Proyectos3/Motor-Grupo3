#include "InputHandlerContainer.h"
namespace Flamingo{
    InputHandlerContainer::InputHandlerContainer()
        : m_inputHandler(ih())  // inicializa el objeto InputHandler
    {        
    }

    InputHandlerContainer::~InputHandlerContainer()
    {
    }

    void InputHandlerContainer::clearState()
    {
        m_inputHandler.clearState();
    }

    bool InputHandlerContainer::closeWindowEvent()
    {
        return m_inputHandler.closeWindowEvent();
    }

    bool InputHandlerContainer::resizeWindowEvent()
    {
        return m_inputHandler.resizeWindowEvent();
    }

    bool InputHandlerContainer::keyDownEvent()
    {
        return m_inputHandler.keyDownEvent();
    }

    bool InputHandlerContainer::keyUpEvent()
    {
        return m_inputHandler.keyUpEvent();
    }

    bool InputHandlerContainer::isKeyDown(FLM_KeyCode t_key)
    {
        return m_inputHandler.isKeyDown(t_key);
    }

    bool InputHandlerContainer::isKeyUp(FLM_KeyCode t_key)
    {
        return m_inputHandler.isKeyUp(t_key);
    }

    bool InputHandlerContainer::mouseMotionEvent()
    {
        return m_inputHandler.mouseMotionEvent();
    }

    bool InputHandlerContainer::mouseButtonEvent()
    {
        return m_inputHandler.mouseButtonEvent();
    }

    const std::pair<Sint32, Sint32>& InputHandlerContainer::getMousePos()
    {
        return m_inputHandler.getMousePos();
    }

    int InputHandlerContainer::getMouseButtonState(MOUSEBUTTON t_b)
    {
        return m_inputHandler.getMouseButtonState(t_b);
    }
    InputHandlerContainer& Input()
    {
        return *InputHandlerContainer::instance();
    }
} // namespace Flamingo