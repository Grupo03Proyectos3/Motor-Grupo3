#ifndef __UISYSTEM_H__
#define __UISYSTEM_H__
#pragma once

#include "ECS/System.h"

#include <ECS/Manager.h>
#include <Render/RenderSystem.h>

namespace CEGUI
{
    class Window;
    class OgreRenderer;
    class GUIContext;
    class WindowManager;
}

namespace Flamingo{
    class UISystem : public System{
      public:
        __SYSTEM_ID_DECL__(_sys_UI)
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

        CEGUI::Window* createWidget(const std::string& type, const std::string& name = " "); 
        CEGUI::Window* createEmptyWindow(const std::string& name = " "); 
        CEGUI::Window* createRootScene(const std::string& name = " "); 

        void chageScreenSize(int widht,int height);

      private:
        
        CEGUI::WindowManager* m_winMngr;
        CEGUI::OgreRenderer* m_renderer;
        CEGUI::Window* m_root = nullptr;
        CEGUI::GUIContext* m_guiContext;
        std::array<bool, 3> m_estadoBotones;
        std::list<std::string> m_schemes;
    };
} // namespace Flamingo
#endif