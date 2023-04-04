#include "UISystem.h"
#include <CEGUI/Base.h>
#include <CEGUI/Window.h>
#include <iostream>
#include <OgreRenderWindow.h>
#include <CEGUI/RendererModules/Ogre/ResourceProvider.h>
#include <CEGUI/System.h>
#include "UIElement.h"

namespace Flamingo{
    UISystem::UISystem(){
    }

    UISystem::~UISystem(){
        winMngr->destroyAllWindows();  
    }

    void UISystem::recieve(const Message& m){
        switch (m.id)
        {
            case MSG_WINDOW_RESIZED:
                chageScreenSize(m_mngr->getSystem<RenderSystem>()->getWindow()->getRenderWindow()->getWidth(), m_mngr->getSystem<RenderSystem>()->getWindow()->getRenderWindow()->getHeight());
            default:
                break;
        }
    }

    void UISystem::initSystem(){
        auto sys = m_mngr->getSystem<RenderSystem>();
        // Seleccionamos el RenderTarget que usamos de ogre que usamos de Root de Renderizado       
        renderer = &CEGUI::OgreRenderer::bootstrapSystem(*sys->getWindow()->getRenderWindow());
        renderer->setUsingShaders(true);
        guiContext = &CEGUI::System::getSingleton().createGUIContext(renderer->getDefaultRenderTarget());
        winMngr = CEGUI::WindowManager::getSingletonPtr();
        renderer->setRenderingEnabled(true);
       
        initUIResources(); // HAY Q HACERLO AUTOMATICAMENTE COMO OGRE
        initRoot();
        //pruebas();
    }

    void UISystem::update(float t_delta_time){
        renderer->beginRendering();
        guiContext->draw();
        renderer->endRendering();

     /*   for (auto game_object : m_mngr->getEntities(ecs::GROUP_UI)){
            auto TR = m_mngr->getComponent<Transform>(game_object);
            auto uielement = m_mngr->getComponent<Flamingo::UIElement>(game_object)
        }*/
    }

    void UISystem::initRoot(){
        eraseMainRoot();     
        root = winMngr->createWindow("DefaultWindow", "Root");

        root->setUsingAutoRenderingSurface(true);

        guiContext->setRootWindow(root);

        root->activate();
    }

    void UISystem::initUIResources(){
        CEGUI::ImageManager::setImagesetDefaultResourceGroup("Imagesets");
        CEGUI::Font::setDefaultResourceGroup("Fonts");
        CEGUI::Scheme::setDefaultResourceGroup("Schemes");
        CEGUI::WidgetLookManager::setDefaultResourceGroup("LookNFeel");
        CEGUI::WindowManager::setDefaultResourceGroup("Layouts");
    }

    void UISystem::eraseContext(){
        renderer->setUsingShaders(false);
        eraseMainRoot();
        CEGUI::System::getSingleton().destroyGUIContext(*guiContext);
        renderer->destroySystem();
    }

    void UISystem::eraseMainRoot(){
        if (root != nullptr)
            root->destroy();

        root = nullptr;
    }

    void UISystem::loadScheme(const std::string& schemeFile){
       auto x= CEGUI::SchemeManager::getSingletonPtr();
        x->createFromFile(schemeFile);
    }

    void UISystem::setFont(const std::string& fontFile){
        CEGUI::FontManager::getSingleton().createFromFile(fontFile + ".font");
        guiContext->setDefaultFont(fontFile);
    }

    CEGUI::Window* UISystem::createWidget(const std::string& type, const std::string& name){
        CEGUI::Window* newWindow = winMngr->createWindow(type, name);
        root->addChild(newWindow);
        newWindow->activate();
        newWindow->setPosition(CEGUI::UVector2(CEGUI::UDim(0.5,0.5), CEGUI::UDim(0.5, 0.5)));
        newWindow->setSize(CEGUI::USize(CEGUI::UDim(0.3, 0.3), CEGUI::UDim(0.2, 0.5)));
        return newWindow;
    }

    void UISystem::chageScreenSize(int width, int height){
        renderer->setDisplaySize(CEGUI::Size<float>(width, height));
        CEGUI::System::getSingleton().notifyDisplaySizeChanged(CEGUI::Size<float>(width, height));        
    }

    void UISystem::pruebas(){
        loadScheme("TaharezLook.scheme");
        setFont("DejaVuSans-10");      
    }
} // namespace Flamingo