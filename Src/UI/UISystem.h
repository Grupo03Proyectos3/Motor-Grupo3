#ifndef __UISYSTEM_H__
#define __UISYSTEM_H__
#pragma once

#include <CEGUI/CEGUI.h>
#include "ECS/System.h"
//#include <unordered_map>

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

        void initRoot();
        void initUIResources();

        void eraseContext();
        void eraseMainRoot();

        void loadScheme(const std::string& schemeFile);
        void setFont(const std::string& fontFile);
        CEGUI::Window* createWidget(const std::string& type,float xPerc, float yPerc, float xPix, float yPix, const std::string& name = " ");

        // ELIMINAR
        void pruebas();
        // ELIMINAR

      private:
       
        CEGUI::WindowManager* winMngr;
        CEGUI::OgreRenderer* renderer;

        CEGUI::Window* root = nullptr;
        CEGUI::GUIContext* guiContext;

        //std::unordered_map<CEGUI::String, CEGUI::Window*> layouts;
    };
} // namespace Flamingo
#endif