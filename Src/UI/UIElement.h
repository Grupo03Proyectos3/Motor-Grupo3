#pragma once

#ifndef __UIELEMENT_H__
#define __UIELEMENT_H__

#include "ECS/Component.h"
#include <CEGUI/WindowRenderer.h>
#include <string>
#include "FlamingoBase/Transform.h"
namespace Flamingo{
    class SVector2;
    class UISystem;
}

namespace Flamingo{
    /*
    * ES NECESARIO PARA EL CORRECTO FUNCIONAMIENTO DE ESTE COMPONENTE Q EL GAMEOBJECT QUE LO CONTIENE ESTA ESTE EN EL GRUPO DE ENTIDADES DE UI
    */
    struct UIElement : ecs::Component{
        public:
        __SYSTEM_ID_DECL__(ecs::_cmp_UIELEMENT)
        UIElement();
        virtual ~UIElement();
        void initComponent() override;
        void setPosition(SVector3 pos);
        void setSize(SVector3 size);
        void setRotation(SQuaternion rot);
        void setText(const std::string& text);
        void setAlpha(float alpha);
        void setActive(bool valor);

        bool isActive();
        SVector2 getPivotCenter();
        void addChild(CEGUI::Window* windowChild);
        CEGUI::Window* getChild(const std::string& childName);
        void setElementWidget(const std::string& widget,const std::string& name);

        protected:
            CEGUI::Window* getWindowElement();
            void setElement(CEGUI::Window* element);
            CEGUI::Window* m_element;
            UISystem* m_uiSys;       
    };
} // namespace Flamingo
#endif __UIELEMENT_H__