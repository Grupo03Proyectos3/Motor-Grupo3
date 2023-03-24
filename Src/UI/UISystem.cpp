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
    }
    void UISystem::update(float t_delta_time){
    }
} // namespace Flamingo