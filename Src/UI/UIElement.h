#pragma once

#ifndef __UIELEMENT_H__
#define __UIELEMENT_H__

#include "ECS/Component.h"
#include <CEGUI/WindowRenderer.h>
#include <string>
#include "FlamingoBase/Transform.h"
namespace Flamingo{
    class SVector2;
}

namespace Flamingo{
    /*
    * ES NECESARIO PARA EL CORRECTO FUNCIONAMIENTO DE ESTE COMPONENTE Q EL GAMEOBJECT QUE LO CONTIENE ESTA ESTE EN EL GRUPO DE ENTIDADES DE UI
    */
    class UIElement : ecs::Component{
        public:
        __SYSTEM_ID_DECL__(ecs::_cmp_UIELEMENT)
        UIElement(const std::string& type, const std::string& name);
        virtual ~UIElement();
        void initComponent() override;
        void setPosition();
        void setSize();
        void setText(const std::string& text);
        void setAlpha(float alpha);
        void setActive(bool valor);

        bool isActive();
        SVector2 getPivotCenter();
        void addChild(CEGUI::Window* windowChild);
        CEGUI::Window* getChild(const std::string& childName);
        

        protected:
            CEGUI::Window* getWindowElement();
            void setElement(CEGUI::Window* element);
            CEGUI::Window* m_element;
            Transform* m_transform;
        private:
             std::string type;
             std::string name;
    };
} // namespace Flamingo
#endif __UIELEMENT_H__