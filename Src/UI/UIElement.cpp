#include "UIElement.h"
#include <CEGUI/CEGUI.h>
#include <iostream>
#include "FlamingoUtils/SVector2.h"
#include "ECS/Manager.h"
#include "UISystem.h"

namespace Flamingo{
    UIElement::UIElement(const std::string& type, const std::string& name){      
        this->type = type;
        this->name = name;
    }
    UIElement::~UIElement(){
       if(m_element!=nullptr) m_element->destroy();
    }
    void UIElement::initComponent(){       
        //habria k meter este objecto el gfrupo de entidades de UI       
        m_element= m_mngr->getSystem<Flamingo::UISystem>()->createWidget(type, name); //obtengo el widget cargado por el usuario
        m_transform = m_mngr->getComponent<Transform>(m_ent); // accedo al componente transform
        if (m_transform == nullptr){
            std::cout << m_ent->getName() << "ADD TRANSFORM COMPONENT TO SET ANIMATOR COMPONENT\n";
            exit(1);
        }
        //seteo los datos de transform
        setPosition(); 
        setSize();
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

    void UIElement::setPosition(){
        m_element->setPosition(CEGUI::UVector2(CEGUI::UDim(0, m_transform->getPosition().getX()), CEGUI::UDim(0, m_transform->getPosition().getY())));
    }

    void UIElement::setSize(){
        m_element->setPosition(CEGUI::UVector2(CEGUI::UDim(m_transform->getScale().getX(), 0), CEGUI::UDim(m_transform->getScale().getY(), 0)));
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

} // namespace Flamingo