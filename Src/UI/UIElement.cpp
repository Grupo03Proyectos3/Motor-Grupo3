#include "UIElement.h"
#include <iostream>
#include "FlamingoUtils/SVector2.h"
#include "ECS/Manager.h"
#include "UISystem.h"
#include "FlamingoUtils/SVector3.h"
#include "FlamingoUtils/SQuaternion.h"
#include "CEGUI/ImageManager.h"

namespace Flamingo{
    UIElement::UIElement() {
        m_element = nullptr;
        m_uiSys = nullptr;
    }

    UIElement::~UIElement(){
       
    }

    void UIElement::initComponent(){       
        m_uiSys = m_mngr->getSystem<Flamingo::UISystem>();
        m_element = nullptr;
        if (m_mngr->getComponent<Transform>(m_ent) == nullptr){
            throw std::runtime_error(m_ent->getName() + "Add Transform component to set uiElement Component\n");
        }
        createEmptyWindow("");

        setElementWidget(m_type, m_name);

        auto t = m_mngr->getComponent<Transform>(m_ent);
        t->setPosition({t->getPosition().getX(), t->getPosition().getY(), 0});
        t->setScale({t->getScale().getX(), t->getScale().getY(), 0});
        setText(m_text);

        if (m_image != "")
        setImage("Image", m_name ,m_image);
    }

    void UIElement::initValues(std::string type, std::string name, std::string text, const std::string image)
    {
        m_type = type;
        m_name = name;
        m_text = text;
        m_image = image;
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

    void UIElement::addChild(Flamingo::UIElement* element){
        m_element->addChild(element->getWindowElement());
        childs[element->m_element->getName().c_str()] = element;      
    }

    Flamingo::UIElement* UIElement::getChild(const std::string& childName){
        for (auto it : childs)       
            if(it.first==childName)return it.second;
        return nullptr;
    }

    void UIElement::setPosition(SVector3 pos)
    {
        m_element->setPosition(CEGUI::UVector2(CEGUI::UDim(pos.getX(), 0), CEGUI::UDim(pos.getY(), 0)));
    }

    SVector2 UIElement::GetPosition() {
        return SVector2(m_element->getPosition().d_x.d_scale, m_element->getPosition().d_y.d_scale);
    }

    void UIElement::setSize(SVector3 size)
    {
        m_element->setSize(CEGUI::USize(CEGUI::UDim(0, size.getX()), CEGUI::UDim(0, size.getY())));
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

    CEGUI::Window* UIElement::getWindowElement()
    {
        return m_element;
    }

    void UIElement::setElement(CEGUI::Window* element){
        if (m_element != nullptr) m_element->destroy();
        m_element = element;
    }

    void UIElement::setToInitComponent(){
        // seteo los datos de transform
        auto transform = m_mngr->getComponent<Transform>(m_ent);
        setPosition(transform->getPosition());
        setSize(transform->getScale());
        setRotation(transform->getRotation()); 
    }

    void UIElement::setNewParent(CEGUI::Window* wnd){
        for (auto it : childs)
            wnd->addChild(it.second->getWindowElement());

        if (m_element != nullptr) m_element->destroy();
        m_element = wnd;
    }

    void UIElement::setElementWidget(const std::string& widget,const  std::string& name){
        //solucionar lo de k no se llmae al init
        if (m_uiSys == nullptr) m_uiSys = m_mngr->getSystem<Flamingo::UISystem>();              
        setNewParent(m_uiSys->createWidget(widget, name));               
        setToInitComponent();
    }

    void UIElement::createEmptyWindow(const std::string& name){
        if (m_uiSys == nullptr) m_uiSys = m_mngr->getSystem<Flamingo::UISystem>();       
        setNewParent(m_uiSys->createEmptyWindow(name));
        setToInitComponent();     
    }

    void UIElement::setAxisAligment(bool set){
        m_element->setPixelAligned(set);
    }
    void UIElement::setImage(const std::string& property, const std::string& name, const std::string& file){

        if (!CEGUI::ImageManager::getSingleton().isDefined(file)){
            CEGUI::ImageManager::getSingleton().addFromImageFile(name, file);
            setProperty(property, name);
        }
    }

     void UIElement::setProperty(const std::string& property, const std::string& file)
     {
         try
         {
             m_element->setProperty(property, file);
         }
         catch (const std::exception&)
         {
             throw std::runtime_error("Propiedad" + property + "no compatible con este elemento");
         }
     }
} // namespace Flamingo