#include "UISystem.h"
#include <CEGUI/Base.h>
#include <CEGUI/Window.h>
#include <iostream>
#include <OgreRenderWindow.h>
#include <CEGUI/RendererModules/Ogre/ResourceProvider.h>
#include <CEGUI/System.h>

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
        renderer->setUsingShaders(true);
        guiContext = &CEGUI::System::getSingleton().createGUIContext(renderer->getDefaultRenderTarget());
        winMngr = CEGUI::WindowManager::getSingletonPtr();
        renderer->setRenderingEnabled(true);

        

        //initUIResources(); // HAY Q HACERLO AUTOMATICAMENTE COMO OGRE
        initRoot();
    }

    void UISystem::update(float t_delta_time){
        renderer->beginRendering();
        guiContext->draw();
        renderer->endRendering();
    }

    void UISystem::initRoot(){
        eraseMainRoot();
        root = winMngr->createWindow("DefaultWindow", "Root"); // Ventana por defecto a modo de GameObject
        root->setUsingAutoRenderingSurface(true);
        guiContext->setRootWindow(root);
        root->activate();

    }

    void UISystem::initUIResources(){

      /*  CEGUI::DefaultResourceProvider* rp = static_cast<CEGUI::DefaultResourceProvider*>(CEGUI::System::getSingleton().getResourceProvider()); 
        rp->setResourceGroupDirectory("Imagesets", "Exes/Assets/UI/imagesets/");
        rp->setResourceGroupDirectory("Fonts", "Exes/Assets/UI/fonts/");
        rp->setResourceGroupDirectory("Schemes", "Exes/Assets/UI/schemes/");
        rp->setResourceGroupDirectory("LookNFeel", "Exes/Assets/UI/looknfeel/");
        rp->setResourceGroupDirectory("Layouts", "Exes/Assets/UI/layouts/");*/

        CEGUI::ImageManager::setImagesetDefaultResourceGroup("Imagesets");
        CEGUI::Font::setDefaultResourceGroup("Fonts");
        CEGUI::Scheme::setDefaultResourceGroup("Schemes");
        CEGUI::WidgetLookManager::setDefaultResourceGroup("LookNFeel");
        CEGUI::WindowManager::setDefaultResourceGroup("Layouts");
    }

    void UISystem::eraseContext(){
        renderer->setUsingShaders(false);
        //eraseMainRoot();
        //CEGUI::System::getSingleton().destroyGUIContext(*guiContext);
        //renderer->destroySystem();
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

    CEGUI::Window* UISystem::createWidget(const std::string& type, float xPerc, float yPerc, float xPix, float yPix, const std::string& name){
        CEGUI::Window* newWindow = winMngr->createWindow(type, name);
        root->addChild(newWindow);
        newWindow->setPosition(CEGUI::UVector2(CEGUI::UDim(xPerc, xPix), CEGUI::UDim(yPerc, yPix)));
        newWindow->setSize(CEGUI::USize(CEGUI::UDim(xPerc, xPix), CEGUI::UDim(yPerc, yPix)));
        return newWindow;
    }

    void UISystem::pruebas(){
        loadScheme("TaharezLook.scheme");
        setFont("DejaVuSans-10");
        createWidget("TaharezLook/Button", 0.5f, 0.5f, 0.1f, 0.05f);
    }
} // namespace Flamingo