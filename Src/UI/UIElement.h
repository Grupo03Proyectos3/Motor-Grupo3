#pragma once

#ifndef __UIELEMENT_H__
#define __UIELEMENT_H__

#include "ECS/Component.h"
#include <CEGUI/WindowRenderer.h>
#include <string>
#include "FlamingoBase/Transform.h"
#include <CEGUI/EventArgs.h>
#include <functional>
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
        void addChild(Flamingo::UIElement* element);
        Flamingo::UIElement* getChild(const std::string& childName);

        void setElementWidget(const std::string& widget,const std::string& name);
        void createEmptyWindow(const std::string& name);
        void setAxisAligment(bool set);

        void setImage(const std::string& name,const std::string& file);   

        template <class T>
        void subscribeEvent(void (T::*func)(), T* comp);
        void subscribeChildEvent(std::function<bool(const CEGUI::EventArgs&)> func);       
        void subscribeEvent(bool (*func)());

     
        void subs(void (*func)());
        void subscribeEvent(bool (*func)(const CEGUI::EventArgs& e));

        //void drawresult(std::function<void()>& f);
       

        protected:
            CEGUI::Window* getWindowElement();
            void setElement(CEGUI::Window* element);
            void setToInitComponent();
            void setNewParent(CEGUI::Window* wnd);
            CEGUI::Window* m_element;
            UISystem* m_uiSys;
            std::unordered_map<std::string, Flamingo::UIElement*> childs;
    };   
} // namespace Flamingo
#endif __UIELEMENT_H__