
entities = {"Sinbad", "Cesped", "Torus", "Arbol", "Espada"}

Sinbad = {
    Name={
        t_name="simbad",
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
       rotationW="1.0",
   },
   PlayerController = {
       t_speed = "20",
   },
   RigidBody = {
       t_mass = "20.0",
       t_trigger = "0",
       t_static = "0",
   },
   MeshRenderer = {
       t_model_name = "Sinbad.mesh",
       t_entity_name= "simbad",
       t_node_x="25.0",
       t_node_y="25.0",
       t_node_z="25.0",
       t_mat_name= "",
   }
}
Cesped = {
    Name={
        t_name="cesped",
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
        rotationW = "1.0",
    },
    RigidBody = {
        t_mass = "20.0",
        t_trigger = "0",
        t_static = "1",
    },
    MeshRenderer = {
        t_model_name = "cube.mesh",
        t_entity_name= "cesped",
        t_node_x=" 100.0",
        t_node_y="0.2",
        t_node_z="100.0",
        t_mat_name= "Prueba/cesped",
    }
}
Torus = {
    Name={
        t_name="torus",
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
       rotationW="1.0",
   },
   RigidBody = {
       t_mass = "20.0",
       t_trigger = "0",
       t_static = "1",
   },
   MeshRenderer = {
       t_model_name = "Torus.mesh",
       t_entity_name= "torus",
       t_node_x=" 100.0",
       t_node_y="0.2",
       t_node_z="100.0",
       t_mat_name= "Prueba/cesped",
   }
}
Arbol = {
    Name={
        t_name="dragon",
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
        rotationW = "1.0",
    },
    RigidBody = {
        t_mass = "20.0",
        t_trigger = "0",
        t_static = "1",
    },
    MeshRenderer = {
        t_model_name = "dragon.mesh",
        t_entity_name= "dragon",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= "",
    },
    ZAnimator={
        t_name="dragon",
    }
}

Espada = {
    Name={
        t_name="espadam",
    },
    AATransform = {
        positionX = "-400.0",
        positionY = "50.0",
        positionZ = "0.0",
        scaleX = "250",
        scaleY = "250",
        scaleZ = "250",
        rotationX = "1.0",
        rotationY = "0.0",
        rotationZ = "0.0",
        rotationW = "1.0",
    },
    RigidBody = {
        t_mass = "20.0",
        t_trigger = "0",
        t_static = "1",
    },
    MeshRenderer = {
        t_model_name = "EspadaMadera.mesh",
        t_entity_name= "espadam",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= "",
    }
}