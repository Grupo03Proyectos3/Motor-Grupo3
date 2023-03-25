#include "UISystem.h"
#include <CEGUI/Base.h>
#include <CEGUI/Window.h>
#include <iostream>
#include <OgreRenderWindow.h>



namespace Flamingo{
    UISystem::UISystem(){
    }

    UISystem::~UISystem(){
        eraseContext();
    }

    void UISystem::recieve(const Message&){
    }

    void UISystem::initSystem(){
        auto sys = m_mngr->getSystem<RenderSystem>();
        // Seleccionamos el RenderTarget que usamos de ogre que usamos de Root de Renderizado
        renderer = &CEGUI::OgreRenderer::bootstrapSystem(*sys->getWindow()->getRenderWindow());
        guiContext = &CEGUI::System::getSingleton().createGUIContext(renderer->getDefaultRenderTarget());
        winMngr = CEGUI::WindowManager::getSingletonPtr();
        initUIResources(); // HAY Q HACERLO AUTOMATICAMENTE COMO OGRE
        initRoot(); 
    }

    void UISystem::update(float t_delta_time){
        guiContext->draw();
    }

    void UISystem::initRoot(){
        eraseMainRoot();
        root = winMngr->createWindow("Default", "Root"); // Ventana por defecto a modo de GameObject
        root->setUsingAutoRenderingSurface(true);
        guiContext->setRootWindow(root);
        root->activate();
    }

    void UISystem::initUIResources(){
        CEGUI::ImageManager::setImagesetDefaultResourceGroup("UI/Imagesets");
        CEGUI::Font::setDefaultResourceGroup("UI/Fonts");
        CEGUI::Scheme::setDefaultResourceGroup("UI/Schemes");
        CEGUI::WidgetLookManager::setDefaultResourceGroup("UI/LookNFeel");
        CEGUI::WindowManager::setDefaultResourceGroup("UI/Layouts");
    }

    void UISystem::eraseContext(){
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
        
    }
} // namespace Flamingo