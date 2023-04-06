function changeVPcolor()
    local mycamera = cam1
    mycamera:setViewPortBackgroundColour(color)
end 

function autoAspectRatio()
    local mycamera = cam1
    mycamera:setAutoAspectRatio(autoradio)
end 

function setFarClipDist()
    local mycamera = cam1
    mycamera:setFarClipDistance(farClip)
end

function setNearClipDist()
    local mycamera = cam1
    mycamera:setNearClipDistance(nearClip)
end

function lookAtCam()
    local mycamera = cam1
    mycamera:lookAt(lookAtVec, transformspace)
end 