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