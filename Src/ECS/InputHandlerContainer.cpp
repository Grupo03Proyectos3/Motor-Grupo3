#include "InputHandlerContainer.h"

InputHandlerContainer::InputHandlerContainer()
    : m_inputHandler() // inicializa el objeto InputHandler
{
}

InputHandlerContainer::~InputHandlerContainer()
{
}

void InputHandlerContainer::clearState()
{
    m_inputHandler.clearState();
}

void InputHandlerContainer::update(const SDL_Event& t_event)
{
    m_inputHandler.update(t_event);
}

void InputHandlerContainer::refresh()
{
    m_inputHandler.refresh();
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

bool InputHandlerContainer::isKeyDown(SDL_Scancode t_key)
{
    return m_inputHandler.isKeyDown(t_key);
}

bool InputHandlerContainer::isKeyDown(SDL_Keycode t_key)
{
    return m_inputHandler.isKeyDown(t_key);
}

bool InputHandlerContainer::isKeyUp(SDL_Scancode t_key)
{
    return m_inputHandler.isKeyUp(t_key);
}

bool InputHandlerContainer::isKeyUp(SDL_Keycode t_key)
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

int InputHandlerContainer::getMouseButtonState(InputHandler::MOUSEBUTTON t_b)
{
    return m_inputHandler.getMouseButtonState(t_b);
}
