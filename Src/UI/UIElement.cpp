#include "UIElement.h"
#include <CEGUI/CEGUI.h>
#include <iostream>
#include "FlamingoUtils/SVector2.h"
#include "ECS/Manager.h"
#include "UISystem.h"
#include "FlamingoUtils/SVector3.h"
#include "FlamingoUtils/SQuaternion.h"
namespace Flamingo{
    UIElement::UIElement() {
        m_element = nullptr;
        m_uiSys = nullptr;
    }
    UIElement::~UIElement(){
       //if(m_element!=nullptr) m_element->destroy();
    }
    void UIElement::initComponent(){       
        m_uiSys = m_mngr->getSystem<Flamingo::UISystem>();
       //m_element = nullptr;
        auto m_transform = m_mngr->getComponent<Transform>(m_ent); // accedo al componente transform
       if (m_transform == nullptr){
           std::cout << m_ent->getName() << "Add Trasnform component to set uielement component\n";
           exit(1);
       }
    }

    void UIElement::setText(const std::string& text){
        m_element->setText(text);
    }

    void UIElement::setAlpha(float alpha){
        m_element->setAlpha(alpha);
    }

    void UIElement::setActive(bool valor){
        if (valor) m_element->activate();
        else m_element->deactivate();
    }

    bool UIElement::isActive(){
        return m_element->isActive();
    }

    void UIElement::addChild(CEGUI::Window* windowChild){
        m_element->addChild(windowChild);
    }

    CEGUI::Window* UIElement::getChild(const std::string& childName){
        return m_element->getChild(childName);        
    }

    void UIElement::setPosition( SVector3 pos)
    {
        m_element->setPosition(CEGUI::UVector2(CEGUI::UDim(0, pos.getX()), CEGUI::UDim(0,pos.getY())));
    }

    void UIElement::setSize( SVector3 size)
    {
        m_element->setPosition(CEGUI::UVector2(CEGUI::UDim(size.getX(), 0), CEGUI::UDim(size.getY(), 0)));
    }

    void UIElement::setRotation(SQuaternion rot){
        m_element->setRotation(rot);
    }

    Flamingo::SVector2 UIElement::getPivotCenter(){

        float i = m_element->getOuterRectClipper().d_min.d_x;
        float j = m_element->getOuterRectClipper().d_max.d_x;

        float w = m_element->getOuterRectClipper().d_min.d_y;
        float k = m_element->getOuterRectClipper().d_max.d_y;

        return Flamingo::SVector2((i + j) / 2, (w + k) / 2);
    }
   
    CEGUI::Window* UIElement::getWindowElement(){
        return m_element;
    }

    void UIElement::setElement(CEGUI::Window* element){
        if (m_element != nullptr) m_element->destroy();
        m_element = element;
    }
    void UIElement::setElementWidget(const std::string& widget,const  std::string& name){
        //solucionar lo de k no se llmae al init
        if (m_uiSys == nullptr) m_uiSys = m_mngr->getSystem<Flamingo::UISystem>();
        auto m_transform = m_mngr->getComponent<Transform>(m_ent);
        //QUITAR
        if (m_element != nullptr) m_element->destroy();
        // habria k meter este objecto el gfrupo de entidades de UI
        m_element = m_uiSys->createWidget(widget, name); // obtengo el widget cargado por el usuario      
        // seteo los datos de transform
        setPosition(m_transform->getPosition());
        setSize(m_transform->getScale());
        setRotation(m_transform->getRotation());
    }
} // namespace Flamingo