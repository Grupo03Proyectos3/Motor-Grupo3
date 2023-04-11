function setCastShadows()
    local myMeshRenderer = mesh
    myMeshRenderer:setCastShadows(castShadows)
end 

function setDebugVisibility()
    local myMeshRenderer = mesh
    myMeshRenderer:setDebugVisibility(debugVisibility)
end 

function changeMaterial()
    local myMeshRenderer = mesh
    myMeshRenderer:changeMaterial(materialName)
end

function setRenderingDistance()
    local myMeshRenderer = mesh
    myMeshRenderer:setRenderingDistance(farClip)
end 
