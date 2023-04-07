function type()
    local mylight = light1
    mylight:setType(ltype)
end 

function direction()
    local mylight = light1
    mylight:setDirection(lightdirection)
end

function specularColor()
    local mylight = light1
    mylight:setSpecularColour(lightspecular, lightspecular, lightspecular)
end

function diffuseColor()
    local mylight = light1
    mylight:setSpecularColour(lightdiffuse, lightdiffuse, lightdiffuse)
end

function castShadows()
    local mylight = light1
    mylight:setCastShadows(castshadow)
end

function shadowFarClipDistance()
    local mylight = light1
    mylight:setShadowFarClipDistance(farclip)
end

function shadowNearClipDistance()
    local mylight = light1
    mylight:setShadowNearClipDistance(nearclip)
end

function shadowFarDistance()
    local mylight = light1
    mylight:setShadowFarDistance(fardistance)
end

function spotlightFalloff()
    local mylight = light1
    mylight:setSpotlightFalloff(falloff)
end

function spotlightInnerAngle()
    local mylight = light1
    mylight:setSpotlightInnerAngle(innerangle)
end

function spotlightOuterAngle()
    local mylight = light1
    mylight:setSpotlightOuterAngle(outerangle)
end

function spotlightNearClipDistance()
    local mylight = light1
    mylight:setSpotlightNearClipDistance(spotnearclip)
end