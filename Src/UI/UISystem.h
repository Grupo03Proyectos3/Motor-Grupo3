#ifndef __UISYSTEM_H__
#define __UISYSTEM_H__
#pragma once

#include <CEGUI/Cegui.h>
#include "ECS/System.h"
#include <unordered_map>

#include <ECS/Manager.h>
#include <Render/RenderSystem.h>


namespace Flamingo{
    class UISystem : public ecs::System{
      public:
        __SYSTEM_ID_DECL__(ecs::_sys_UI)
        UISystem();
        virtual ~UISystem();
        void recieve(const Message&) override;
        void initSystem() override;
        void update(float t_delta_time) override;

      private:
        CEGUI::WindowManager* winMngr;
        CEGUI::OgreRenderer* renderer;

        CEGUI::Window* root = nullptr;
        CEGUI::GUIContext* guiContext;

        std::unordered_map<std::string, CEGUI::Window*> layouts;
    };
} // namespace Flamingo
#endif