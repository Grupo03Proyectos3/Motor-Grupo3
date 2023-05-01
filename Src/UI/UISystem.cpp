#include "UISystem.h"
#include "ECS/InputHandlerContainer.h"
#include "UIElement.h"
#include <ECS/Manager.h>
#include <OgreRenderWindow.h>
#include <functional>
#include <iostream>

// CEGUI
#include "FlamingoUtils/SVector2.h"
#include <CEGUI/Base.h>
#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/Ogre/Renderer.h>
#include <CEGUI/RendererModules/Ogre/ResourceProvider.h>
#include <CEGUI/SchemeManager.h>
#include <CEGUI/System.h>
#include <CEGUI/Window.h>

namespace Flamingo
{
    UISystem::UISystem()
    {
    }

    UISystem::~UISystem()
    {
        // CEGUI::System::getSingleton().destroy();
    }

    void UISystem::recieve(const Message& m)
    {
        if (!(m.id == MSG_WINDOW_RESIZED || m.id == MSG_TRANSFORM_MOVE || m.id == MSG_TRANSFORM_ROTATE ||
              m.id == MSG_TRANSFORM_SCALING || m.id == MSG_MOUSE_CLICK || m.id == MSG_MOUSE_MOVE))
        {
            return;
        }

        UIElement* element = nullptr;
        Transform* transform = nullptr;
        if (m.id == MSG_MOUSE_MOVE)
        {
            m_guiContext->injectMousePosition(m.moveMouse.mouseX, m.moveMouse.mouseY);

            // std::cout << "x: " << m.moveMouse.x << " ,y: " << m.moveMouse.y << "\n";
            // std::cout << "x2: " << guiContext->getMouseCursor().getPosition().d_x << " ,y2: " << guiContext->getMouseCursor().getPosition().d_y << "\n";
        }
        else if (m.id == MSG_MOUSE_CLICK)
        {
            // injectMouseButtonClick(CEGUI::MouseButton::LeftButton);

            if (m.ui_input.mouse_states[0] != m_estadoBotones[0])
            {
                if (m.ui_input.mouse_states[0])
                {
                    if (m_guiContext->injectMouseButtonDown(CEGUI::MouseButton::LeftButton))
                    {
                        std::cout << "LEFT DOWN\n";
                    }
                }
                else if (m_guiContext->injectMouseButtonUp(CEGUI::MouseButton::LeftButton))
                {
                    std::cout << "LEFT UP\n";
                }

                m_estadoBotones[0] = m.ui_input.mouse_states[0];
            }

            if (m.ui_input.mouse_states[1] != m_estadoBotones[1])
            {
                if (m.ui_input.mouse_states[1])
                {
                    if (m_guiContext->injectMouseButtonDown(CEGUI::MouseButton::MiddleButton))
                    {
                        std::cout << "MIDDLE DOWN\n";
                    }
                }
                else if (m_guiContext->injectMouseButtonUp(CEGUI::MouseButton::MiddleButton))
                {
                    std::cout << "MIDDLE UP\n";
                }
                m_estadoBotones[1] = m.ui_input.mouse_states[1];
            }

            if (m.ui_input.mouse_states[2] != m_estadoBotones[2])
            {
                if (m.ui_input.mouse_states[2])
                {
                    if (m_guiContext->injectMouseButtonDown(CEGUI::MouseButton::RightButton))
                    {
                        std::cout << "RIGHT DOWN\n";
                    }
                }
                else if (m_guiContext->injectMouseButtonUp(CEGUI::MouseButton::RightButton))
                {
                    std::cout << "RIGHT UP\n";
                }
                m_estadoBotones[2] = m.ui_input.mouse_states[2];
            }
            // if (guiContext->injectMouseButtonClick(CEGUI::MouseButton::LeftButton))
            //    std::cout << "lima\n";

            // CEGUI::System::getSingletonPtr()->injectTimePulse(10.0f);
        }
        else if (m.id != MSG_WINDOW_RESIZED)
        {
            element = m_mngr->getComponent<UIElement>(m.entity_affected);
            transform = m_mngr->getComponent<Transform>(m.entity_affected);
            if (element == nullptr)
                return;
        }
        switch (m.id)
        {
            case MSG_WINDOW_RESIZED:
                chageScreenSize(m_mngr->getSystem<RenderSystem>()->getWindow()->getRenderWindow()->getWidth(), m_mngr->getSystem<RenderSystem>()->getWindow()->getRenderWindow()->getHeight());
                break;
            case MSG_TRANSFORM_MOVE:
            {
                element->setPosition(transform->getPosition() / 100);
                break;
            }
            case MSG_TRANSFORM_ROTATE:
            {
                element->setRotation(transform->getRotation());
                break;
            }
            case MSG_TRANSFORM_SCALING:
            {
                element->setSize(transform->getScale());
                break;
            }
            default:
                break;
        }
    }

    void UISystem::initSystem()
    {
        initUIResources();
    }

    void UISystem::update(float t_delta_time)
    {
        m_renderer->beginRendering();
        m_guiContext->draw();
        m_renderer->endRendering();

        // CEGUI::System::getSingletonPtr()->injectTimePulse(t_delta_time);
    }

    void UISystem::initContext()
    {
        auto sys = m_mngr->getSystem<RenderSystem>();
        // Seleccionamos el RenderTarget que usamos de ogre que usamos de Root de Renderizado
        m_renderer = &CEGUI::OgreRenderer::bootstrapSystem(*sys->getWindow()->getRenderWindow());
        m_renderer->setUsingShaders(true);
        m_guiContext = &CEGUI::System::getSingleton().createGUIContext(m_renderer->getDefaultRenderTarget());
        m_winMngr = CEGUI::WindowManager::getSingletonPtr();
        m_renderer->setRenderingEnabled(true);

        initRoot();
        loadScheme("FlamingoDefaultUI.scheme");
    }

    void UISystem::initRoot()
    {
        eraseMainRoot();
        m_root = m_winMngr->createWindow("DefaultWindow", "Root");
        m_root->setSize(CEGUI::USize(CEGUI::UDim(0, m_renderer->getDisplaySize().d_width * 2),
                                     CEGUI::UDim(0, m_renderer->getDisplaySize().d_height * 2)));

        m_root->setUsingAutoRenderingSurface(true);
        m_guiContext->setRootWindow(m_root);
    }

    void UISystem::initUIResources()
    {
        CEGUI::ImageManager::setImagesetDefaultResourceGroup("General");
        CEGUI::Font::setDefaultResourceGroup("General");
        CEGUI::Scheme::setDefaultResourceGroup("General");
        CEGUI::WidgetLookManager::setDefaultResourceGroup("General");
        CEGUI::WindowManager::setDefaultResourceGroup("General");
    }

    void UISystem::eraseContext()
    {
        m_winMngr->destroyAllWindows();
        for (auto scheme : m_schemes)
        {
            CEGUI::SchemeManager::getSingleton().destroy(scheme);
        }
        m_schemes.clear();

        // eraseMainRoot();
        m_renderer->setUsingShaders(false);
        CEGUI::System::getSingleton().destroyGUIContext(*m_guiContext);

        m_renderer->destroySystem();

        CEGUI::System::destroy();
    }

    void UISystem::eraseMainRoot()
    {
        if (m_root != nullptr)
        {
            m_root->destroy();
        }

        m_root = nullptr;
    }

    void UISystem::loadScheme(const std::string& schemeFile)
    {
        auto x = CEGUI::SchemeManager::getSingletonPtr();
        x->createFromFile(schemeFile);
        m_schemes.push_back(schemeFile);
    }

    void UISystem::setFont(const std::string& fontFile)
    {
        CEGUI::FontManager::getSingleton().createFromFile(fontFile + ".font");
        m_guiContext->setDefaultFont(fontFile);
    }

    CEGUI::Window* UISystem::createWidget(const std::string& type, const std::string& name)
    {
        try
        {
            CEGUI::Window* newWindow = m_winMngr->createWindow(type, name);
            FlamingoSceneManager().getSceneActive()->getCeguiRoot()->addChild(newWindow);
            newWindow->activate();
            newWindow->setPosition(CEGUI::UVector2(CEGUI::UDim(0.5, 0.5), CEGUI::UDim(0.5, 0.5)));
            newWindow->setSize(CEGUI::USize(CEGUI::UDim(0.3, 0.3), CEGUI::UDim(0.2, 0.5)));
            return newWindow;
        }
        catch (CEGUI::Exception e)
        {
            throw std::runtime_error(e.what());
        }
    }

    CEGUI::Window* UISystem::createEmptyWindow(const std::string& name)
    {
        try
        {
            CEGUI::Window* newWindow = m_winMngr->createWindow("DefaultWindow", name);
            // m_root->addChild(newWindow);
            FlamingoSceneManager().getSceneActive()->getCeguiRoot()->addChild(newWindow);
            newWindow->activate();
            newWindow->setPosition(CEGUI::UVector2(CEGUI::UDim(0.5, 0.5), CEGUI::UDim(0.5, 0.5)));
            newWindow->setSize(CEGUI::USize(CEGUI::UDim(0.3, 0.3), CEGUI::UDim(0.2, 0.5)));
            return newWindow;
        }
        catch (CEGUI::Exception e)
        {
            throw std::runtime_error(e.what());
        }
    }

    CEGUI::Window* UISystem::createRootScene(const std::string& name)
    {
        try
        {
            CEGUI::Window* newWindow = m_winMngr->createWindow("DefaultWindow", name);
            m_root->addChild(newWindow);
            newWindow->activate();
            newWindow->setPosition(m_root->getPosition());
            newWindow->setSize(m_root->getSize());
            return newWindow;
        }
        catch (CEGUI::Exception e)
        {
            throw std::runtime_error(e.what());
        }
    }

    void UISystem::chageScreenSize(int width, int height)
    {
        m_renderer->setDisplaySize(CEGUI::Size<float>(width, height));
        CEGUI::System::getSingleton().notifyDisplaySizeChanged(CEGUI::Size<float>(width, height));
    }

} // namespace Flamingo