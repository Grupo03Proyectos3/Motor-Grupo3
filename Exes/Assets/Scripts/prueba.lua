function changeNextScene()
    local manager = SceneManager.getSceneManager()
    manager:changeScene()
end 

function loadNextScene()
    local manager = SceneManager.getSceneManager()
    manager:nextScene(scene)
end 

function setMusicUp()
    local manager = AudioManager.getAudioManager()
    manager:upMusicVolume()
end

function setMusicDown()
    local manager = AudioManager.getAudioManager()
    manager:downMusicVolume()
end

function setFxUp()
    local manager = AudioManager.getAudioManager()
    manager:upFxVolume()
end

function setFxDown()
    local manager = AudioManager.getAudioManager()
    manager:downFxVolume()
end

function setResolutionUp()
    local manager = GraphicsManager.getGraphicsManager()
    manager:upResolution()
end

function setResolutionDown()
    local manager = GraphicsManager.getGraphicsManager()
    manager:downResolution()
end

function setPause()
    local manager = ElHornoBase.getElHornoBase()
    manager:pause()
end

function setExit()
    local manager = ElHornoBase.getElHornoBase()
    manager:exit()
end

function setLayoutVisibility()     
    local manager = UIManager.getUIManager()
    manager:setLayoutVisibility(button, vis)
end

function setLayoutWidgetText()     
    local manager = UIManager.getUIManager()
    -- print(texto)
    manager:setChildProperty(layout, child, "Text", hora)
end
