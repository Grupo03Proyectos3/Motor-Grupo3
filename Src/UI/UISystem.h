#ifndef __UISYSTEM_H__
#define __UISYSTEM_H__
#pragma once

#include <CEGUI/Cegui.h>
#include "ECS/System.h"
#include <unordered_map>

namespace CEGUI
{
    class Window;
    class OgreRenderer;
    class WindowManager;
    class DefaultWindow;
    class GUIContext;
    class UDim;
    class EventArgs;
} // namespace CEGUI

namespace Ogre{
    class RenderWindow;
}

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