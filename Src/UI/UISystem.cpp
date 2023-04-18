#include "UISystem.h"
#include "UIElement.h"
#include <CEGUI/Base.h>
#include <CEGUI/RendererModules/Ogre/ResourceProvider.h>
#include <CEGUI/System.h>
#include <CEGUI/Window.h>
#include <OgreRenderWindow.h>
#include <iostream>
#include <Ogre.h>
#include <CEGUI/CEGUI.h>

namespace Flamingo
{
    UISystem::UISystem()
    {
    }

    UISystem::~UISystem()
    {
        winMngr->destroyAllWindows();
    }

    void UISystem::recieve(const Message& m)
    {
        if (!(m.id == MSG_WINDOW_RESIZED || m.id == MSG_TRANSFORM_MOVE || m.id == MSG_TRANSFORM_ROTATE || m.id == MSG_TRANSFORM_SCALING)){
            return;
        }

        UIElement* element = nullptr;
        Transform* transform = nullptr;
        if (m.id != MSG_WINDOW_RESIZED){
            element = m_mngr->getComponent<UIElement>(m.entity_affected);
            transform = m_mngr->getComponent<Transform>(m.entity_affected);
            if (element == nullptr)
            {
                return;
            }
        }
        switch (m.id) 
        {
            case MSG_WINDOW_RESIZED:
                chageScreenSize(m_mngr->getSystem<RenderSystem>()->getWindow()->getRenderWindow()->getWidth(), m_mngr->getSystem<RenderSystem>()->getWindow()->getRenderWindow()->getHeight());
                break;
            case MSG_TRANSFORM_MOVE:
            {
                element->setPosition(transform->getPosition());
                break;
            }
            case MSG_TRANSFORM_ROTATE:
            {
                element->setRotation(transform->getRotation());
                break;
            }
            case MSG_TRANSFORM_SCALING:
            {
                element->setPosition(transform->getScale());
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
        renderer->beginRendering();
        guiContext->draw();
        renderer->endRendering();
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
        pruebas();
        prueba2();
    }

    void UISystem::initRoot()
    {
        eraseMainRoot();
        root = winMngr->createWindow("DefaultWindow", "Root");

        root->setUsingAutoRenderingSurface(true);

        guiContext->setRootWindow(root);

        root->activate();
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

    void UISystem::pruebas()
    {
        loadScheme("TaharezLook.scheme");
        setFont("DejaVuSans-10");
    }
    void UISystem::prueba2()
    {
            ////CEGUI::Window* newWindow = winMngr->createWindow("TaharezLook/ImageButton", "ffsdfsdsdf");
            ////root->addChild(newWindow);
            ////newWindow->activate();
            ////newWindow->setPosition(CEGUI::UVector2(CEGUI::UDim(0.5, 0.5), CEGUI::UDim(0.5, 0.5)));
            ////newWindow->setSize(CEGUI::USize(CEGUI::UDim(0.3, 0.3), CEGUI::UDim(0.2, 0.5)));
            //////newWindow->setText("CEGUI");


            //Ogre::TexturePtr tex = m_mngr->getSystem<RenderSystem>()->getOgreRoot()->getTextureManager()->create("100.png", "General");
            //    /*->createManual(
            //    "RTT",
            //    Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
            //    Ogre::TEX_TYPE_2D,
            //    512,
            //    512,
            //    0,
            //    Ogre::PF_R8G8B8,
            //    Ogre::TU_RENDERTARGET);*/
            //CEGUI::Texture& guiTex = renderer->createTexture("RTT", tex);
            //const CEGUI::Rectf rect(CEGUI::Vector2f(0.0f, 0.0f), guiTex.getOriginalDataSize());
            //CEGUI::BasicImage* image = (CEGUI::BasicImage*)(&CEGUI::ImageManager::getSingleton().create("BasicImage", "RTTImage"));
            //image->setTexture(&guiTex);
            //image->setArea(rect);
            //image->setAutoScaled(CEGUI::ASM_Both);   

            //CEGUI::Window* si = CEGUI::WindowManager::getSingleton().createWindow("TaharezLook/StaticImage", "RTTWindow");
            //// si->setSize(CEGUI::UVector2(CEGUI::UDim(0.5f, 0),
            //si->setSize(CEGUI::USize(CEGUI::UDim(0.5f, 0),
            //                         CEGUI::UDim(0.4f, 0)));
            //si->setPosition(CEGUI::UVector2(CEGUI::UDim(0.5f, 0),
            //                                CEGUI::UDim(0.0f, 0)));
            //si->setProperty("Image", "RTTImage");

    }
} // namespace Flamingo