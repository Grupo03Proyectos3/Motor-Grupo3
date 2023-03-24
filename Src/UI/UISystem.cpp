#include "UISystem.h"
#include <CEGUI/Base.h>
#include <CEGUI/Window.h>
#include <CEGUI/RendererModules/Ogre/Renderer.h>
#include <iostream>




namespace Flamingo{
    UISystem::UISystem(){

    }
    UISystem::~UISystem(){
        winMngr->destroyAllWindows();
        renderer->destroySystem();
    }
    void UISystem::recieve(const Message&){
    }
    void UISystem::initSystem(){
        //auto sys = m_mngr->getSystem<RenderSystem>();
        
        //CEGUI::OgreRenderer& auxiliar = CEGUI::OgreRenderer::bootstrapSystem(*renderWindow);
        //renderer = &auxiliar;

    }
    void UISystem::update(float t_delta_time){
    }
} // namespace Flamingo