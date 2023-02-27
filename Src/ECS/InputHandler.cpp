#include "InputHandler.h"



InputHandler::~InputHandler()
{
}

void InputHandler::clearState()
{
    m_is_close_window = false;
    m_is_key_down = false;
    m_is_key_up = false;
    m_is_mouse_button = false;
    m_is_mouse_motion = false;
    for (auto i = 0u; i < 3; i++)
    {
        m_mB_state[i] = false;
    }
}

void InputHandler::update(const SDL_Event& t_event)
{
    int whichOne;
    switch (t_event.type)
    {
        case SDL_KEYDOWN:
            onKeyDown(t_event);
            break;
        case SDL_KEYUP:
            onKeyUp(t_event);
            break;
        case SDL_MOUSEMOTION:
            onMouseMotion(t_event);
            break;
        case SDL_MOUSEBUTTONDOWN:
            onMouseButtonChange(t_event, true);
            break;
        case SDL_MOUSEBUTTONUP:
            onMouseButtonChange(t_event, false);
            break;
        case SDL_WINDOWEVENT:
            handleWindowEvent(t_event);
            break;
        default:
            break;
    }
}

void InputHandler::refresh()
{
    SDL_Event event;

    clearState();
    while (SDL_PollEvent(&event))
        update(event);
}

bool InputHandler::closeWindowEvent()
{
    return m_is_close_window;
}

bool InputHandler::keyDownEvent()
{
    return m_is_key_down;
}

bool InputHandler::keyUpEvent()
{
    return m_is_key_up;
}

bool InputHandler::isKeyDown(SDL_Scancode t_key)
{
    return keyDownEvent() && m_kB_state[t_key] == 1;
}

bool InputHandler::isKeyDown(SDL_Keycode t_key)
{
    return isKeyDown(SDL_GetScancodeFromKey(t_key));
}

bool InputHandler::isKeyUp(SDL_Scancode t_key)
{
    return keyUpEvent() && m_kB_state[t_key] == 0;
}

bool InputHandler::isKeyUp(SDL_Keycode t_key)
{
    return isKeyUp(SDL_GetScancodeFromKey(t_key));
}

bool InputHandler::mouseMotionEvent()
{
    return m_is_mouse_motion;
}

bool InputHandler::mouseButtonEvent()
{
    return m_is_mouse_button;
}

const std::pair<Sint32, Sint32>& InputHandler::getMousePos()
{
    return m_mouse_pos;
}

int InputHandler::getMouseButtonState(MOUSEBUTTON t_b)
{
    return m_mB_state[t_b];
}

InputHandler::InputHandler()
{
    m_kB_state = SDL_GetKeyboardState(0);
    clearState();
}

void InputHandler::onKeyDown(const SDL_Event&)
{
    m_is_key_down = true;
}

void InputHandler::onKeyUp(const SDL_Event&)
{
    m_is_key_up = true;
}

void InputHandler::onMouseMotion(const SDL_Event& t_event)
{
    m_is_mouse_motion = true;
    m_mouse_pos.first = t_event.motion.x;
    m_mouse_pos.second = t_event.motion.y;
}

void InputHandler::onMouseButtonChange(const SDL_Event& t_event, bool t_is_down)
{
    m_is_mouse_button = true;
    switch (t_event.button.button)
    {
        case SDL_BUTTON_LEFT:
            m_mB_state[LEFT] = t_is_down;
            break;
        case SDL_BUTTON_MIDDLE:
            m_mB_state[MIDDLE] = t_is_down;
            break;
        case SDL_BUTTON_RIGHT:
            m_mB_state[RIGHT] = t_is_down;
            break;
        default:
            break;
    }
}

void InputHandler::handleWindowEvent(const SDL_Event& t_event)
{
    switch (t_event.window.event)
    {
        case SDL_WINDOWEVENT_CLOSE:
            m_is_close_window = true;
            break;
        default:
            break;
    }
}

InputHandler& ih()
{
    return *InputHandler::instance();
}
