#include "UISystem.h"
#include "UIElement.h"
#include <CEGUI/Base.h>
#include <CEGUI/RendererModules/Ogre/ResourceProvider.h>
#include <CEGUI/System.h>
#include <CEGUI/Window.h>
#include <OgreRenderWindow.h>
#include <iostream>
#include <ECS/Manager.h>
#include <functional>
#include <iostream>
#include "ECS/InputHandlerContainer.h"

namespace Flamingo
{
    UISystem::UISystem()
    {
    }

    UISystem::~UISystem()
    {
        winMngr->destroyAllWindows();
    }

    void UISystem::recieve(const Message& m){

        if (!(m.id == MSG_WINDOW_RESIZED || m.id == MSG_TRANSFORM_MOVE || m.id == MSG_TRANSFORM_ROTATE || 
            m.id == MSG_TRANSFORM_SCALING || m.id == MSG_MOUSE_CLICK || m.id == MSG_MOUSE_MOVE))
        {
            return;
        }

        UIElement* element = nullptr;
        Transform* transform = nullptr;
        if (m.id == MSG_MOUSE_MOVE){

            guiContext->injectMousePosition(m.moveMouse.x, m.moveMouse.y);
            
            //std::cout << "x: " << m.moveMouse.x << " ,y: " << m.moveMouse.y << "\n";
            //std::cout << "x2: " << guiContext->getMouseCursor().getPosition().d_x << " ,y2: " << guiContext->getMouseCursor().getPosition().d_y << "\n";
        }
        else  if (m.id == MSG_MOUSE_CLICK){
               // injectMouseButtonClick(CEGUI::MouseButton::LeftButton);
            if (guiContext->injectMouseButtonDown(CEGUI::MouseButton::LeftButton)){
                std::cout << "sasdaasd\n";
            }
            if (guiContext->injectMouseButtonUp(CEGUI::MouseButton::LeftButton))
            {
                std::cout << "ekhriweh\n";
            }

            //if (guiContext->injectMouseButtonClick(CEGUI::MouseButton::LeftButton))
            //   std::cout << "lima\n";

            //CEGUI::System::getSingletonPtr()->injectTimePulse(10.0f);
            
        }
        else if (m.id != MSG_WINDOW_RESIZED){
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
                element->setPosition(transform->getPosition()/100);
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

    void UISystem::update(float t_delta_time){


        renderer->beginRendering();
        guiContext->draw();
        renderer->endRendering();

        //CEGUI::System::getSingletonPtr()->injectTimePulse(t_delta_time);
    }

    void UISystem::initContext()
    {
        auto sys = m_mngr->getSystem<RenderSystem>();
        // Seleccionamos el RenderTarget que usamos de ogre que usamos de Root de Renderizado
        renderer = &CEGUI::OgreRenderer::bootstrapSystem(*sys->getWindow()->getRenderWindow());
        renderer->setUsingShaders(true);
        guiContext = &CEGUI::System::getSingleton().createGUIContext(renderer->getDefaultRenderTarget());
        winMngr = CEGUI::WindowManager::getSingletonPtr();
        renderer->setRenderingEnabled(true);

        initRoot();
        loadScheme("FlamingoDefaultUI.scheme");
    }

    void UISystem::initRoot()
    {
        eraseMainRoot();
        root = winMngr->createWindow("DefaultWindow", "Root");
        root->setSize(CEGUI::USize(CEGUI::UDim(0, renderer->getDisplaySize().d_width*2), 
            CEGUI::UDim(0, renderer->getDisplaySize().d_height*2)));

        root->setUsingAutoRenderingSurface(true);
        guiContext->setRootWindow(root);

        //root->activate();
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
        renderer->setUsingShaders(false);
        eraseMainRoot();
        CEGUI::System::getSingleton().destroyGUIContext(*guiContext);
        renderer->destroySystem();
    }

    void UISystem::eraseMainRoot()
    {
        if (root != nullptr)
            root->destroy();

        root = nullptr;
    }

    void UISystem::loadScheme(const std::string& schemeFile)
    {
        auto x = CEGUI::SchemeManager::getSingletonPtr();
        x->createFromFile(schemeFile);
    }

    void UISystem::setFont(const std::string& fontFile)
    {
        CEGUI::FontManager::getSingleton().createFromFile(fontFile + ".font");
        guiContext->setDefaultFont(fontFile);
    }

    CEGUI::Window* UISystem::createWidget(const std::string& type, const std::string& name)
    {
        CEGUI::Window* newWindow = winMngr->createWindow(type, name);
        root->addChild(newWindow);
        newWindow->activate();
        newWindow->setPosition(CEGUI::UVector2(CEGUI::UDim(0.5, 0.5), CEGUI::UDim(0.5, 0.5)));
        newWindow->setSize(CEGUI::USize(CEGUI::UDim(0.3, 0.3), CEGUI::UDim(0.2, 0.5)));
        return newWindow;
    }

    CEGUI::Window* UISystem::createEmptyWindow(const std::string& name)
    {
        CEGUI::Window* newWindow = winMngr->createWindow("DefaultWindow", name);
        root->addChild(newWindow);
        newWindow->activate();
        newWindow->setPosition(CEGUI::UVector2(CEGUI::UDim(0.5, 0.5), CEGUI::UDim(0.5, 0.5)));
        newWindow->setSize(CEGUI::USize(CEGUI::UDim(0.3, 0.3), CEGUI::UDim(0.2, 0.5)));
        return newWindow;
    }

    void UISystem::chageScreenSize(int width, int height)
    {
        renderer->setDisplaySize(CEGUI::Size<float>(width, height));
        CEGUI::System::getSingleton().notifyDisplaySizeChanged(CEGUI::Size<float>(width, height));
    }       
} // namespace Flamingo