#include "UIElement.h"
#include <CEGUI/CEGUI.h>
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
       //if(m_element!=nullptr) m_element->destroy();
    }

    void UIElement::initComponent(){       
        m_uiSys = m_mngr->getSystem<Flamingo::UISystem>();
        m_element = nullptr;
        if (m_mngr->getComponent<Transform>(m_ent) == nullptr){
            std::cout << m_ent->getName() << "Add Trasnform component to set uielement component\n";
            exit(1);
        }
        createEmptyWindow("");
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

    void UIElement::setPosition( SVector3 pos){
        m_element->setPosition(CEGUI::UVector2(CEGUI::UDim(0, pos.getX()), CEGUI::UDim(0,pos.getY())));
    }

    void UIElement::setSize( SVector3 size){
        m_element->setSize(CEGUI::USize(CEGUI::UDim(size.getX(), 0), CEGUI::UDim(size.getY(), 0)));
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
       /* if (!CEGUI::ImageManager::getSingleton().isDefined(file))
        CEGUI::ImageManager::getSingleton().addImageType(file);*/
        // PRUEBAS

       // CEGUI::ImageManager* im = CEGUI::ImageManager::getSingletonPtr();

        if (!CEGUI::ImageManager::getSingleton().isDefined(file)){
            CEGUI::ImageManager::getSingleton().addFromImageFile(name, file);

            CEGUI::Image& p = CEGUI::ImageManager::getSingletonPtr()->get(name);

            try
            {
                m_element->setProperty(property, name);
            }catch(const std::exception&) {
                std::cout << "Propiedad no compatible con este elemento\n";          
                exit(1);
            }
          
        }

     
    }

    //void UIElement::subscribeChildEvent(std::function<bool(const CEGUI::EventArgs&)> func){
    //    if (m_element != nullptr){
    //       m_element->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(func));
    //    }
    //}

    //template <class T>
    //void UIElement::subscribeEvent(void (T::*func)(), T* comp){
    //    if (m_element != nullptr){
    //       m_element->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(func, comp));
    //    }
    //}
    template <class T>
    void UIElement::subscribeEvent( void (T::*function)()){             
        if (m_element != nullptr){          
           m_element->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(function));
        }
    }     

   /* void UIElement::subs()
    {
        if (m_element != nullptr)
        {
            m_element->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(p));
        }
    }*/

   /* void UIElement::subscribeEvent(bool (*func)(const CEGUI::EventArgs& e))
    {
        if (m_element != nullptr){
           m_element->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(func));
        }
    }*/

    void p()
    {
        std::cout << "HOLACLICO\n";
    }
    void UIElement::pruebaSubEvent() {
        if (m_element != nullptr)
        {
            //m_element->activate();
            m_element->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(p));
        }
    }
} // namespace Flamingo