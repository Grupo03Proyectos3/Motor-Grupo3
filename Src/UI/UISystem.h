#ifndef __UISYSTEM_H__
#define __UISYSTEM_H__
#pragma once

#include <CEGUI/CEGUI.h>
#include "ECS/System.h"

#include <ECS/Manager.h>
#include <Render/RenderSystem.h>
#include <CEGUI/RendererModules/Ogre/Renderer.h>

namespace Flamingo{
    class UISystem : public ecs::System{
      public:
        __SYSTEM_ID_DECL__(ecs::_sys_UI)
        UISystem();
        virtual ~UISystem();
        void recieve(const Message&) override;
        void initSystem() override;
        void update(float t_delta_time) override;

        void initContext();

        void initRoot();
        void initUIResources();

        void eraseContext();
        void eraseMainRoot();

        void loadScheme(const std::string& schemeFile);
        void setFont(const std::string& fontFile);

        CEGUI::Window* createWidget(const std::string& type, const std::string& name = " "); //NO EXPORTAR
        CEGUI::Window* createEmptyWindow(const std::string& name = " "); //NO EXPORTAR
        CEGUI::Window* createRootScene(const std::string& name = " "); //NO EXPORTAR

        void chageScreenSize(int widht,int height);
        void setSceneManager(SceneManager* sceneManager);

      private:
        
        CEGUI::WindowManager* m_winMngr;
        CEGUI::OgreRenderer* m_renderer;
        SceneManager* m_SceneManager;
        CEGUI::Window* m_root = nullptr;
        CEGUI::GUIContext* m_guiContext;
        std::array<bool, 3> m_estadoBotones;
    };
} // namespace Flamingo
#endif