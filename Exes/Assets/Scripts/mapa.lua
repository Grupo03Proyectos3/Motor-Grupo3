
entities = {"Sinbad", "Mapa", "Enemy", "Arbol", "EspadaMetal", "EspadaMadera", "EspadaEspecial", "Slime", "EscudoMadera", "PocionRoja", "M1", "M2", "M3", "M4", "M5", "M6", 
"M7", "M8", "M9", "M10", "M11", "M12", "M13", "M14", "M15", "M16", "M17", "M18", "M19", "M20", "M21", "M22"}


Sinbad = {
    Name={
        t_name="player"
    },
   Transform = {
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
       t_entity_name= "player",
       t_node_x="25.0",
       t_node_y="25.0",
       t_node_z="25.0",
       t_mat_name= ""
   }
}
Mapa = {
    Name={
        t_name="mapa"
    },
    Transform = {
        positionX = "0.0",
        positionY = "0.0",
        positionZ = "0.0",
        scaleX = "1.0",
        scaleY = "1.0",
        scaleZ = "1.0",
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
        t_model_name = "Escenario.mesh",
        t_entity_name= "mapa",
        t_node_x="1.0",
        t_node_y="1.0",
        t_node_z="1.0",
        t_mat_name= ""
    }
}
Enemy = {
    Name={
        t_name="enemy"
    },
   Transform = {
       positionX= "200.0",
       positionY="260.0",
       positionZ="50.0",
       scaleX="150.0",
       scaleY="150",
       scaleZ="150.0",
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
       t_model_name = "slime06.mesh",
       t_entity_name= "enemy",
       t_node_x=" 0.0",
       t_node_y="0.0",
       t_node_z="0.0",
       t_mat_name= ""
   }
}
Arbol = {
    Name={
        t_name="dragon"
    },
    Transform = {
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
    Animator={
        t_name="dragon"
    }
}
EspadaMetal = {
    Name={
        t_name="espadam",
    },
    Transform = {
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
    Transform = {
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
    Transform = {
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
    Transform = {
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
    Transform = {
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
    Transform = {
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
M1 = {
    Name={
        t_name="m1"
    },
    Transform = {
        positionX = "-25000.0",
        positionY = "200.0",
        positionZ = "17000.0",
        scaleX = "8.0",
        scaleY = "8.0",
        scaleZ = "8.0",
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
        t_model_name = "Mountain_3.mesh",
        t_entity_name= "m1",
        t_node_x=" 1.0",
        t_node_y="1.0",
        t_node_z="1.0",
        t_mat_name= ""
    }
}
M2 = {
    Name={
        t_name="m2"
    },
    Transform = {
        positionX = "-38000.0",
        positionY = "2000.0",
        positionZ = "17000.0",
        scaleX = "5.0",
        scaleY = "5.0",
        scaleZ = "5.0",
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
        t_model_name = "Mountain_2.mesh",
        t_entity_name= "m2",
        t_node_x=" 1.0",
        t_node_y="1.0",
        t_node_z="1.0",
        t_mat_name= ""
    }
}
M3 = {
    Name={
        t_name="m3"
    },
    Transform = {
        positionX = "-16500.0",
        positionY = "2000.0",
        positionZ = "17000.0",
        scaleX = "5.0",
        scaleY = "5.0",
        scaleZ = "5.0",
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
        t_model_name = "Mountain_1.mesh",
        t_entity_name= "m3",
        t_node_x=" 1.0",
        t_node_y="1.0",
        t_node_z="1.0",
        t_mat_name= ""
    }
}
M4 = {
    Name={
        t_name="m4"
    },
    Transform = {
        positionX = "-9500.0",
        positionY = "1000.0",
        positionZ = "14000.0",
        scaleX = "3.0",
        scaleY = "3.0",
        scaleZ = "3.0",
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
        t_model_name = "Mountain_4.mesh",
        t_entity_name= "m4",
        t_node_x=" 1.0",
        t_node_y="1.0",
        t_node_z="1.0",
        t_mat_name= ""
    }
}
M5 = {
    Name={
        t_name="m5"
    },
    Transform = {
        positionX = "-2000.0",
        positionY = "200.0",
        positionZ = "12000.0",
        scaleX = "2.5",
        scaleY = "2.5",
        scaleZ = "2.5",
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
        t_model_name = "Mountain_5.mesh",
        t_entity_name= "m5",
        t_node_x=" 1.0",
        t_node_y="1.0",
        t_node_z="1.0",
        t_mat_name= ""
    }
}
M6 = {
    Name={
        t_name="m6"
    },
    Transform = {
        positionX = "6000.0",
        positionY = "1500.0",
        positionZ = "16500.0",
        scaleX = "3.2",
        scaleY = "3.2",
        scaleZ = "3.2",
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
        t_model_name = "Mountain_6.mesh",
        t_entity_name= "m6",
        t_node_x=" 1.0",
        t_node_y="1.0",
        t_node_z="1.0",
        t_mat_name= ""
    }
}
M7 = {
    Name={
        t_name="m7"
    },
    Transform = {
        positionX = "5500.0",
        positionY = "1500.0",
        positionZ = "24000.0",
        scaleX = "2",
        scaleY = "2",
        scaleZ = "2",
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
        t_model_name = "Mountain_7.mesh",
        t_entity_name= "m7",
        t_node_x=" 1.0",
        t_node_y="1.0",
        t_node_z="1.0",
        t_mat_name= ""
    }
}
M8 = {
    Name={
        t_name="m8"
    },
    Transform = {
        positionX = "-49000.0",
        positionY = "200.0",
        positionZ = "20000.0",
        scaleX = "8.0",
        scaleY = "8.0",
        scaleZ = "8.0",
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
        t_model_name = "Mountain_8.mesh",
        t_entity_name= "m8",
        t_node_x=" 1.0",
        t_node_y="1.0",
        t_node_z="1.0",
        t_mat_name= ""
    }
}
M9 = {
    Name={
        t_name="m9"
    },
    Transform = {
        positionX = "-58500.0",
        positionY = "1500.0",
        positionZ = "14500.0",
        scaleX = "5.0",
        scaleY = "5.0",
        scaleZ = "5.0",
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
        t_model_name = "Mountain_9.mesh",
        t_entity_name= "m9",
        t_node_x=" 1.0",
        t_node_y="1.0",
        t_node_z="1.0",
        t_mat_name= ""
    }
}
M10 = {
    Name={
        t_name="m10"
    },
    Transform = {
        positionX = "-62000.0",
        positionY = "500.0",
        positionZ = "6500.0",
        scaleX = "5.0",
        scaleY = "5.0",
        scaleZ = "5.0",
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
        t_model_name = "Mountain_10.mesh",
        t_entity_name= "m10",
        t_node_x=" 1.0",
        t_node_y="1.0",
        t_node_z="1.0",
        t_mat_name= ""
    }
}
M11 = {
    Name={
        t_name="m11"
    },
    Transform = {
        positionX = "-64000.0",
        positionY = "2000.0",
        positionZ = "-3500.0",
        scaleX = "6.0",
        scaleY = "3.0",
        scaleZ = "6.0",
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
        t_model_name = "Mountain_11.mesh",
        t_entity_name= "m11",
        t_node_x=" 1.0",
        t_node_y="1.0",
        t_node_z="1.0",
        t_mat_name= ""
    }
}
M12 = {
    Name={
        t_name="m12"
    },
    Transform = {
        positionX = "-68000.0",
        positionY = "500.0",
        positionZ = "-12500.0",
        scaleX = "5.0",
        scaleY = "5.0",
        scaleZ = "5.0",
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
        t_model_name = "Mountain_12.mesh",
        t_entity_name= "m12",
        t_node_x=" 1.0",
        t_node_y="1.0",
        t_node_z="1.0",
        t_mat_name= ""
    }
}
M13 = {
    Name={
        t_name="m13"
    },
    Transform = {
        positionX = "-57000.0",
        positionY = "1000.0",
        positionZ = "-17000.0",
        scaleX = "6.0",
        scaleY = "2.0",
        scaleZ = "6.0",
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
        t_model_name = "Mountain_13.mesh",
        t_entity_name= "m13",
        t_node_x=" 1.0",
        t_node_y="1.0",
        t_node_z="1.0",
        t_mat_name= ""
    }
}
M14 = {
    Name={
        t_name="m14"
    },
    Transform = {
        positionX = "-48000.0",
        positionY = "500.0",
        positionZ = "-20000.0",
        scaleX = "5.0",
        scaleY = "5.0",
        scaleZ = "5.0",
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
        t_model_name = "Mountain_12.mesh",
        t_entity_name= "m14",
        t_node_x=" 1.0",
        t_node_y="1.0",
        t_node_z="1.0",
        t_mat_name= ""
    }
}
M15 = {
    Name={
        t_name="m15"
    },
    Transform = {
        positionX = "-37000.0",
        positionY = "2000.0",
        positionZ = "-23500.0",
        scaleX = "3.0",
        scaleY = "3.0",
        scaleZ = "3.0",
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
        t_model_name = "Mountain_15.mesh",
        t_entity_name= "m15",
        t_node_x=" 1.0",
        t_node_y="1.0",
        t_node_z="1.0",
        t_mat_name= ""
    }
}
M16 = {
    Name={
        t_name="m16"
    },
    Transform = {
        positionX = "-22000.0",
        positionY = "2000.0",
        positionZ = "-28000.0",
        scaleX = "3.0",
        scaleY = "3.0",
        scaleZ = "3.0",
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
        t_model_name = "Mountain_16.mesh",
        t_entity_name= "m16",
        t_node_x=" 1.0",
        t_node_y="1.0",
        t_node_z="1.0",
        t_mat_name= ""
    }
}
M17 = {
    Name={
        t_name="m17"
    },
    Transform = {
        positionX = "-5000.0",
        positionY = "2000.0",
        positionZ = "-32000.0",
        scaleX = "2.0",
        scaleY = "2.0",
        scaleZ = "2.0",
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
        t_model_name = "Mountain_17.mesh",
        t_entity_name= "m17",
        t_node_x=" 1.0",
        t_node_y="1.0",
        t_node_z="1.0",
        t_mat_name= ""
    }
}
M18 = {
    Name={
        t_name="m18"
    },
    Transform = {
        positionX = "7500.0",
        positionY = "2000.0",
        positionZ = "-31000.0",
        scaleX = "2.5",
        scaleY = "2.5",
        scaleZ = "2.5",
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
        t_model_name = "Mountain_18.mesh",
        t_entity_name= "m18",
        t_node_x=" 1.0",
        t_node_y="1.0",
        t_node_z="1.0",
        t_mat_name= ""
    }
}
M19 = {
    Name={
        t_name="m19"
    },
    Transform = {
        positionX = "13000.0",
        positionY = "2000.0",
        positionZ = "-28000.0",
        scaleX = "2.5",
        scaleY = "2.5",
        scaleZ = "2.5",
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
        t_model_name = "Mountain_19.mesh",
        t_entity_name= "m19",
        t_node_x=" 1.0",
        t_node_y="1.0",
        t_node_z="1.0",
        t_mat_name= ""
    }
}
M20 = {
    Name={
        t_name="m20"
    },
    Transform = {
        positionX = "15000.0",
        positionY = "2000.0",
        positionZ = "-22000.0",
        scaleX = "2.5",
        scaleY = "2.5",
        scaleZ = "2.5",
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
        t_model_name = "Mountain_20.mesh",
        t_entity_name= "m20",
        t_node_x=" 1.0",
        t_node_y="1.0",
        t_node_z="1.0",
        t_mat_name= ""
    }
}
M21 = {
    Name={
        t_name="m21"
    },
    Transform = {
        positionX = "20000.0",
        positionY = "1500.0",
        positionZ = "-16000.0",
        scaleX = "2.5",
        scaleY = "2.5",
        scaleZ = "2.5",
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
        t_model_name = "Mountain_21.mesh",
        t_entity_name= "m21",
        t_node_x=" 1.0",
        t_node_y="1.0",
        t_node_z="1.0",
        t_mat_name= ""
    }
}
M22 = {
    Name={
        t_name="m22"
    },
    Transform = {
        positionX = "29000.0",
        positionY = "1500.0",
        positionZ = "-13000.0",
        scaleX = "2.5",
        scaleY = "2.5",
        scaleZ = "2.5",
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
        t_model_name = "Mountain_22.mesh",
        t_entity_name= "m22",
        t_node_x=" 1.0",
        t_node_y="1.0",
        t_node_z="1.0",
        t_mat_name= ""
    }
}