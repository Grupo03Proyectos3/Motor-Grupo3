
entities = {"Sinbad", "Cesped", "Torus", "Arbol"}

Sinbad = {
--    AATransform = {
--        positionX = "200.0",
--        positionY="200.0",
--        positionZ="0.0",
--        scaleX="25.0",
--        scaleY="25.0",
--        scaleZ="25.0",
--        rotationX="0.0",
--        rotationY="0.0",
--        rotationZ="0.0",
--        rotationW="1.0",
--    },
--    PlayerController = {
--        t_speed = "20",
--    },
--    RigidBody = {
--        t_mass = "20.0",
--        t_trigger = "0",
--        t_static = "0",
--    },
--    MeshRenderer = {
--        t_model_name = "Sinbad.mesh",
--        t_entity_name= "simbad",
--        t_node_x="25.0",
--        t_node_y="25.0",
--        t_node_z="25.0",
--        t_mat_name= "",
--    }
}
Cesped = {
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
--    AATransform = {
--        positionX= "200.0",
--        positionY="260.0",
--        positionZ="50.0",
--        scaleX="50.0",
--        scaleY="50",
--        scaleZ="50.0",
--        rotationX="0.0",
--        rotationY="0.0",
--        rotationZ="0.0",
--        rotationW="1.0",
--    },
--    RigidBody = {
--        t_mass = "20.0",
--        t_trigger = "0",
--        t_static = "1",
--    },
--    MeshRenderer = {
--        t_model_name = "Torus.mesh",
--        t_entity_name= "torus",
--        t_node_x=" 100.0",
--        t_node_y="0.2",
--        t_node_z="100.0",
--        t_mat_name= "Prueba/cesped",
--    }
}
Arbol = {
    AATransform = {
        positionX = "0.0",
        positionY = "100.0",
        positionZ = "0.0",
        scaleX = "0.1",
        scaleY = "0.1",
        scaleZ = "0.1",
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
        t_model_name = "Arbol10.mesh",
        t_entity_name= "arbol01",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= "",
    }
}