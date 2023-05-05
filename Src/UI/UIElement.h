#pragma once

#ifndef __UIELEMENT_H__
#define __UIELEMENT_H__

#include "ECS/Component.h"
#include "FlamingoBase/Transform.h"
#include <string>
#include <unordered_map>

namespace Flamingo
{
    class SVector2;
    class UISystem;
    class BehaviourScript;
} // namespace Flamingo

namespace CEGUI
{
    class Window;
}

namespace Flamingo
{
    /*
     * ES NECESARIO PARA EL CORRECTO FUNCIONAMIENTO DE ESTE COMPONENTE Q EL GAMEOBJECT QUE LO CONTIENE ESTA ESTE EN EL GRUPO DE ENTIDADES DE UI
     */
    struct FLAMINGOEXPORT_API UIElement : Component
    {
      public:
        __SYSTEM_ID_DECL__(_cmp_UIELEMENT)
        UIElement();
        virtual ~UIElement();
        virtual void initComponent();
        virtual void initValues(std::string type, std::string name, std::string text, std::string image);
        void setPosition(SVector3 pos);
        SVector2 GetPosition();
        void setSize(SVector3 size);
        void setRotation(SQuaternion rot);
        void setText(const std::string& text);
        void setAlpha(float alpha);
        void setActive(bool valor);

        bool isActive();
        SVector2 getPivotCenter();
        void addChild(Flamingo::UIElement* element);
        Flamingo::UIElement* getChild(const std::string& childName);

        void setElementWidget(const std::string& widget, const std::string& name);
        void createEmptyWindow(const std::string& name);
        void setAxisAligment(bool set);

        void setImage(const std::string& property, const std::string& name, const std::string& file);
        void setProperty(const std::string& property, const std::string& file);

        void subsEvent(BehaviourScript* t_s);

       CEGUI::Window* getWindowElement();
      protected:
      
        void setElement(CEGUI::Window* element);
        void setToInitComponent();
        void setNewParent(CEGUI::Window* wnd);
        CEGUI::Window* m_element;
        UISystem* m_uiSys;
        std::unordered_map<std::string, Flamingo::UIElement*> childs;

        std::string m_type;
        std::string m_name;
        std::string m_text;
        std::string m_image;
    };
} // namespace Flamingo
#endif __UIELEMENT_H__