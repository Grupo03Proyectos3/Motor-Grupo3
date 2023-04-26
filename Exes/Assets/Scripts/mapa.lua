entities = {"Sinbad", "Cesped", "Torus", "Arbol", "EspadaMetal", "EspadaMadera", "EspadaEspecial", "Slime", "EscudoMadera", "PocionRoja"}

Sinbad = {
    Name={
        t_name="simbad"
    },
   AATransform = {
       positionX = "200.0",
       positionY="200.0",
       positionZ="0.0",
       scaleX="25.0",
       scaleY="25.0",
       scaleZ="25.0",
       rotationX="0.0",
       rotationY="0.0",
       rotationZ="0.0",
       rotationW="1.0"
   },
   PlayerController = {
       t_speed = "20"
   },
   RigidBody = {
       t_mass = "20.0",
       t_trigger = "0",
       t_static = "0"
   },
   MeshRenderer = {
       t_model_name = "Sinbad.mesh",
       t_entity_name= "simbad",
       t_node_x="25.0",
       t_node_y="25.0",
       t_node_z="25.0",
       t_mat_name= ""
   }
}
Cesped = {
    Name={
        t_name="cesped"
    },
    AATransform = {
        positionX = "0.0",
        positionY = "0.0",
        positionZ = "0.0",
        scaleX = "50.0",
        scaleY = "0.2",
        scaleZ = "50.0",
        rotationX = "0.0",
        rotationY = "0.0",
        rotationZ = "0.0",
        rotationW = "1.0"
    },
    RigidBody = {
        t_mass = "20.0",
        t_trigger = "0",
        t_static = "1"
    },
    MeshRenderer = {
        t_model_name = "cube.mesh",
        t_entity_name= "cesped",
        t_node_x=" 100.0",
        t_node_y="0.2",
        t_node_z="100.0",
        t_mat_name= "Prueba/cesped"
    }
}
Torus = {
    Name={
        t_name="torus"
    },
   AATransform = {
       positionX= "200.0",
       positionY="260.0",
       positionZ="50.0",
       scaleX="50.0",
       scaleY="50",
       scaleZ="50.0",
       rotationX="0.0",
       rotationY="0.0",
       rotationZ="0.0",
       rotationW="1.0"
   },
   RigidBody = {
       t_mass = "20.0",
       t_trigger = "0",
       t_static = "1"
   },
   MeshRenderer = {
       t_model_name = "Torus.mesh",
       t_entity_name= "torus",
       t_node_x=" 100.0",
       t_node_y="0.2",
       t_node_z="100.0",
       t_mat_name= "Prueba/cesped"
   }
}
Arbol = {
    Name={
        t_name="dragon"
    },
    AATransform = {
        positionX = "0.0",
        positionY = "100.0",
        positionZ = "0.0",
        scaleX = "20",
        scaleY = "20",
        scaleZ = "20",
        rotationX = "-1.0",
        rotationY = "0.0",
        rotationZ = "0.0",
        rotationW = "1.0"
    },
    RigidBody = {
        t_mass = "20.0",
        t_trigger = "0",
        t_static = "1"
    },
    MeshRenderer = {
        t_model_name = "dragon.mesh",
        t_entity_name= "dragon",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    },
    ZAnimator={
        t_name="dragon"
    }
}

EspadaMetal = {
    Name={
        t_name="espadam",
    },
    AATransform = {
        positionX = "-500.0",
        positionY = "50.0",
        positionZ = "0.0",
        scaleX = "20",
        scaleY = "20",
        scaleZ = "20",
        rotationX = "1.0",
        rotationY = "0.0",
        rotationZ = "0.0",
        rotationW = "1.0"
    },
    RigidBody = {
        t_mass = "20.0",
        t_trigger = "0",
        t_static = "1"
    },
    MeshRenderer = {
        t_model_name = "EspadaMetal.mesh",
        t_entity_name= "espadam",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
EspadaMadera = {
    Name={
        t_name="espada",
    },
    AATransform = {
        positionX = "-400.0",
        positionY = "50.0",
        positionZ = "0.0",
        scaleX = "20",
        scaleY = "20",
        scaleZ = "20",
        rotationX = "1.0",
        rotationY = "0.0",
        rotationZ = "0.0",
        rotationW = "1.0"
    },
    RigidBody = {
        t_mass = "20.0",
        t_trigger = "0",
        t_static = "1"
    },
    MeshRenderer = {
        t_model_name = "EspadaMadera.mesh",
        t_entity_name= "espada",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
EspadaEspecial = {
    Name={
        t_name="espadae",
    },
    AATransform = {
        positionX = "-300.0",
        positionY = "50.0",
        positionZ = "0.0",
        scaleX = "10",
        scaleY = "10",
        scaleZ = "10",
        rotationX = "0.0",
        rotationY = "0.0",
        rotationZ = "0.0",
        rotationW = "1.0"
    },
    RigidBody = {
        t_mass = "20.0",
        t_trigger = "0",
        t_static = "1"
    },
    MeshRenderer = {
        t_model_name = "EspadaEspecial.mesh",
        t_entity_name= "espadae",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
Slime = {
    Name={
        t_name="slime02",
    },
    AATransform = {
        positionX = "-300.0",
        positionY = "50.0",
        positionZ = "200.0",
        scaleX = "150",
        scaleY = "150",
        scaleZ = "150",
        rotationX = "0.0",
        rotationY = "0.0",
        rotationZ = "0.0",
        rotationW = "1.0"
    },
    RigidBody = {
        t_mass = "20.0",
        t_trigger = "0",
        t_static = "1"
    },
    MeshRenderer = {
        t_model_name = "slime07.mesh",
        t_entity_name= "slime02",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
EscudoMadera = {
    Name={
        t_name="escudom",
    },
    AATransform = {
        positionX = "-500.0",
        positionY = "50.0",
        positionZ = "200.0",
        scaleX = "50",
        scaleY = "50",
        scaleZ = "50",
        rotationX = "0.0",
        rotationY = "0.0",
        rotationZ = "0.0",
        rotationW = "1.0"
    },
    RigidBody = {
        t_mass = "20.0",
        t_trigger = "0",
        t_static = "1"
    },
    MeshRenderer = {
        t_model_name = "EscudoMadera.mesh",
        t_entity_name= "escudom",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
PocionRoja = {
    Name={
        t_name="pocionr",
    },
    AATransform = {
        positionX = "500.0",
        positionY = "50.0",
        positionZ = "200.0",
        scaleX = "20",
        scaleY = "20",
        scaleZ = "20",
        rotationX = "1.0",
        rotationY = "0.0",
        rotationZ = "0.0",
        rotationW = "1.0"
    },
    RigidBody = {
        t_mass = "20.0",
        t_trigger = "0",
        t_static = "1"
    },
    MeshRenderer = {
        t_model_name = "PocionRosa.mesh",
        t_entity_name= "pocionr",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}