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

function polygonMode()
    local mycamera = cam1
    mycamera:setPolygonMode(pmode)
end 

function pitchCam()
    local mycamera = cam1
    mycamera:pitch(degrees)
end 

function yawCam()
    local mycamera = cam1
    mycamera:yaw(degrees)
end 

function rollCam()
    local mycamera = cam1
    mycamera:roll(degrees)
end 