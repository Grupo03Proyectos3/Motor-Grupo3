entities = {"Sinbad", "Mapa", "Enemy", "Arbol", "EspadaMetal", "EspadaMadera", "EspadaEspecial", "Slime", "EscudoMadera", "PocionRoja", "M1", "M2", "M3", "M4", "M5", "M6", 
"M7", "M8", "M9", "M10", "M11", "M12", "M13", "M14", "M15", "M16", "M17", "M18", "M19", "M20", "M21", "M22", "A81", "A82", "A83", "A84", "A85", "A86", "A87", "A88",
"A89", "A810", "A811", "A812", "A813", "A814", "A815", "A816", "A817", "A818", "A819", "A820", "A821", "A822", "A823", "A824", "A825", "A21", "A22", "A23", "A24", "A25",
"A26", "A27", "A28", "A29", "A210", "A211", "A212", "A213", "A214", "A215", "A216", "A217", "A218", "A219", "A220", "A221", "A222", "A223", "A224", "A225", "A226", "A227",
"A228", "A229", "A230", "A231", "A232", "A233", "A234", "A235", "A236", "A237", "A238", "A239", "A240", "A241", "A242", "A243", "A244", "A245", "A246", "A247", "A248",
"A249", "A250", "A251", "A252", "A253", "A254", "A255", "A256", "A257", "A258", "A259", "A260", "A261", "A262", "A263", "A264", "A265", "A266", "A267", "A268", "A269",
"A270", "A271", "A272", "A273", "A274", "A275", "A276", "A277", "A278", "A279", "A280", "A281", "A282", "A283", "A284", "A285", "A286", "A287", "A288", "A289", "A290",
"A291", "A292", "A293", "A294", "A295", "A296", "A297", "A298", "A299", "A2100", "A2101", "A2102", "A2103", "A2104", "A2105", "A2106", "A2107", "A2108", "A2109", "A2110", "A2111",
"A2112"}

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
        positionX = "1000.0",
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
        positionY = "1500.0",
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
A81 = {
    Name={
        t_name="a81"
    },
    Transform = {
        positionX = "-50000.0",
        positionY = "560.0",
        positionZ = "500.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a81",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A82 = {
    Name={
        t_name="a82"
    },
    Transform = {
        positionX = "-43000.0",
        positionY = "560.0",
        positionZ = "4000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a82",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A83 = {
    Name={
        t_name="a83"
    },
    Transform = {
        positionX = "-46500.0",
        positionY = "560.0",
        positionZ = "10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a83",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A84 = {
    Name={
        t_name="a84"
    },
    Transform = {
        positionX = "-54000.0",
        positionY = "560.0",
        positionZ = "-8000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a84",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A85 = {
    Name={
        t_name="a85"
    },
    Transform = {
        positionX = "-49000.0",
        positionY = "560.0",
        positionZ = "-10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a85",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A86 = {
    Name={
        t_name="a86"
    },
    Transform = {
        positionX = "-42000.0",
        positionY = "560.0",
        positionZ = "-7000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a86",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A87 = {
    Name={
        t_name="a87"
    },
    Transform = {
        positionX = "-51000.0",
        positionY = "560.0",
        positionZ = "8700.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a87",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A88 = {
    Name={
        t_name="a88"
    },
    Transform = {
        positionX = "-58000.0",
        positionY = "560.0",
        positionZ = "7000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a88",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A89 = {
    Name={
        t_name="a89"
    },
    Transform = {
        positionX = "-45000.0",
        positionY = "560.0",
        positionZ = "-3000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a89",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A810 = {
    Name={
        t_name="a810"
    },
    Transform = {
        positionX = "-41000.0",
        positionY = "560.0",
        positionZ = "-15000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a810",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A811 = {
    Name={
        t_name="a811"
    },
    Transform = {
        positionX = "-52000.0",
        positionY = "560.0",
        positionZ = "-3000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a811",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A812 = {
    Name={
        t_name="a812"
    },
    Transform = {
        positionX = "-48000.0",
        positionY = "560.0",
        positionZ = "15000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a812",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A813 = {
    Name={
        t_name="a813"
    },
    Transform = {
        positionX = "-48000.0",
        positionY = "560.0",
        positionZ = "4000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a813",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A814 = {
    Name={
        t_name="a814"
    },
    Transform = {
        positionX = "-60000.0",
        positionY = "560.0",
        positionZ = "-9000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a814",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A815 = {
    Name={
        t_name="a815"
    },
    Transform = {
        positionX = "-56000.0",
        positionY = "560.0",
        positionZ = "-5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a815",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A816 = {
    Name={
        t_name="a816"
    },
    Transform = {
        positionX = "-55700.0",
        positionY = "560.0",
        positionZ = "000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a816",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A817 = {
    Name={
        t_name="a817"
    },
    Transform = {
        positionX = "-40000.0",
        positionY = "560.0",
        positionZ = "000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a817",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A818 = {
    Name={
        t_name="a818"
    },
    Transform = {
        positionX = "-40000.0",
        positionY = "560.0",
        positionZ = "8000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a818",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A819 = {
    Name={
        t_name="a819"
    },
    Transform = {
        positionX = "-33000.0",
        positionY = "560.0",
        positionZ = "10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a819",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A820 = {
    Name={
        t_name="a820"
    },
    Transform = {
        positionX = "-46000.0",
        positionY = "560.0",
        positionZ = "-14500.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a820",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A821 = {
    Name={
        t_name="a821"
    },
    Transform = {
        positionX = "-53000.0",
        positionY = "560.0",
        positionZ = "-13000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a821",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A822 = {
    Name={
        t_name="a822"
    },
    Transform = {
        positionX = "-42000.0",
        positionY = "560.0",
        positionZ = "-12000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a822",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A823 = {
    Name={
        t_name="a823"
    },
    Transform = {
        positionX = "-57000.0",
        positionY = "560.0",
        positionZ = "-11000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a823",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A824 = {
    Name={
        t_name="a824"
    },
    Transform = {
        positionX = "-57000.0",
        positionY = "560.0",
        positionZ = "4000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a824",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A825 = {
    Name={
        t_name="a825"
    },
    Transform = {
        positionX = "-52000.0",
        positionY = "560.0",
        positionZ = "5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol08.mesh",
        t_entity_name= "a825",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A21 = {
    Name={
        t_name="a21"
    },
    Transform = {
        positionX = "-32000.0",
        positionY = "390.0",
        positionZ = "0.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a21",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A22 = {
    Name={
        t_name="a22"
    },
    Transform = {
        positionX = "-32000.0",
        positionY = "390.0",
        positionZ = "5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a22",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A23 = {
    Name={
        t_name="a23"
    },
    Transform = {
        positionX = "-32000.0",
        positionY = "390.0",
        positionZ = "-5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a23",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A24 = {
    Name={
        t_name="a24"
    },
    Transform = {
        positionX = "-32000.0",
        positionY = "390.0",
        positionZ = "-10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a24",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A25 = {
    Name={
        t_name="a25"
    },
    Transform = {
        positionX = "-32000.0",
        positionY = "390.0",
        positionZ = "-15000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a25",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A26 = {
    Name={
        t_name="a26"
    },
    Transform = {
        positionX = "-32000.0",
        positionY = "390.0",
        positionZ = "-19000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a26",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A27 = {
    Name={
        t_name="a27"
    },
    Transform = {
        positionX = "-28000.0",
        positionY = "390.0",
        positionZ = "0.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a27",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A28 = {
    Name={
        t_name="a28"
    },
    Transform = {
        positionX = "-28000.0",
        positionY = "390.0",
        positionZ = "5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a28",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A24 = {
    Name={
        t_name="a24"
    },
    Transform = {
        positionX = "-28000.0",
        positionY = "390.0",
        positionZ = "-5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a24",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A29 = {
    Name={
        t_name="a29"
    },
    Transform = {
        positionX = "-28000.0",
        positionY = "390.0",
        positionZ = "-10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a29",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A210 = {
    Name={
        t_name="a210"
    },
    Transform = {
        positionX = "-28000.0",
        positionY = "390.0",
        positionZ = "-15000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a210",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A211 = {
    Name={
        t_name="a211"
    },
    Transform = {
        positionX = "-28000.0",
        positionY = "390.0",
        positionZ = "-19000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a211",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A212 = {
    Name={
        t_name="a212"
    },
    Transform = {
        positionX = "-24000.0",
        positionY = "390.0",
        positionZ = "0.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a212",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A213 = {
    Name={
        t_name="a213"
    },
    Transform = {
        positionX = "-24000.0",
        positionY = "390.0",
        positionZ = "5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a213",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A214 = {
    Name={
        t_name="a214"
    },
    Transform = {
        positionX = "-24000.0",
        positionY = "390.0",
        positionZ = "-5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a214",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A215 = {
    Name={
        t_name="a215"
    },
    Transform = {
        positionX = "-24000.0",
        positionY = "390.0",
        positionZ = "-10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a215",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A216 = {
    Name={
        t_name="a216"
    },
    Transform = {
        positionX = "-24000.0",
        positionY = "390.0",
        positionZ = "-15000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a216",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A217 = {
    Name={
        t_name="a217"
    },
    Transform = {
        positionX = "-24000.0",
        positionY = "390.0",
        positionZ = "-19000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a217",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A218 = {
    Name={
        t_name="a218"
    },
    Transform = {
        positionX = "-24000.0",
        positionY = "390.0",
        positionZ = "10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a218",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A219 = {
    Name={
        t_name="a219"
    },
    Transform = {
        positionX = "-20000.0",
        positionY = "390.0",
        positionZ = "0.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a219",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A220 = {
    Name={
        t_name="a220"
    },
    Transform = {
        positionX = "-20000.0",
        positionY = "390.0",
        positionZ = "5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a220",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A221 = {
    Name={
        t_name="a221"
    },
    Transform = {
        positionX = "-20000.0",
        positionY = "390.0",
        positionZ = "-5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a221",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A222 = {
    Name={
        t_name="a222"
    },
    Transform = {
        positionX = "-20000.0",
        positionY = "390.0",
        positionZ = "-10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a222",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A223 = {
    Name={
        t_name="a223"
    },
    Transform = {
        positionX = "-20000.0",
        positionY = "390.0",
        positionZ = "-15000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a223",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A224 = {
    Name={
        t_name="a224"
    },
    Transform = {
        positionX = "-20000.0",
        positionY = "390.0",
        positionZ = "-19000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a224",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A225 = {
    Name={
        t_name="a225"
    },
    Transform = {
        positionX = "-20000.0",
        positionY = "390.0",
        positionZ = "10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a225",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A226 = {
    Name={
        t_name="a226"
    },
    Transform = {
        positionX = "-20000.0",
        positionY = "390.0",
        positionZ = "-23000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a226",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A227 = {
    Name={
        t_name="a227"
    },
    Transform = {
        positionX = "-16000.0",
        positionY = "390.0",
        positionZ = "0.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a227",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A228 = {
    Name={
        t_name="a228"
    },
    Transform = {
        positionX = "-16000.0",
        positionY = "390.0",
        positionZ = "5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a228",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A229 = {
    Name={
        t_name="a229"
    },
    Transform = {
        positionX = "-16000.0",
        positionY = "390.0",
        positionZ = "-5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a229",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A230 = {
    Name={
        t_name="a230"
    },
    Transform = {
        positionX = "-16000.0",
        positionY = "390.0",
        positionZ = "-10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a230",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A231 = {
    Name={
        t_name="a231"
    },
    Transform = {
        positionX = "-16000.0",
        positionY = "390.0",
        positionZ = "-15000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a231",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A232 = {
    Name={
        t_name="a232"
    },
    Transform = {
        positionX = "-16000.0",
        positionY = "390.0",
        positionZ = "-19000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a232",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A233 = {
    Name={
        t_name="a233"
    },
    Transform = {
        positionX = "-16000.0",
        positionY = "390.0",
        positionZ = "10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a233",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A234 = {
    Name={
        t_name="a234"
    },
    Transform = {
        positionX = "-16000.0",
        positionY = "390.0",
        positionZ = "-23000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a234",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A235 = {
    Name={
        t_name="a235"
    },
    Transform = {
        positionX = "-12000.0",
        positionY = "390.0",
        positionZ = "0.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a235",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A236 = {
    Name={
        t_name="a236"
    },
    Transform = {
        positionX = "-12000.0",
        positionY = "390.0",
        positionZ = "5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a236",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A237 = {
    Name={
        t_name="a237"
    },
    Transform = {
        positionX = "-12000.0",
        positionY = "390.0",
        positionZ = "-5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a237",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A238 = {
    Name={
        t_name="a238"
    },
    Transform = {
        positionX = "-12000.0",
        positionY = "390.0",
        positionZ = "-10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a238",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A239 = {
    Name={
        t_name="a239"
    },
    Transform = {
        positionX = "-12000.0",
        positionY = "390.0",
        positionZ = "-15000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a239",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A240 = {
    Name={
        t_name="a240"
    },
    Transform = {
        positionX = "-12000.0",
        positionY = "390.0",
        positionZ = "-19000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a240",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A241 = {
    Name={
        t_name="a241"
    },
    Transform = {
        positionX = "-12000.0",
        positionY = "390.0",
        positionZ = "-26000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a241",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A242 = {
    Name={
        t_name="a242"
    },
    Transform = {
        positionX = "-12000.0",
        positionY = "390.0",
        positionZ = "-23000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a242",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A243 = {
    Name={
        t_name="a243"
    },
    Transform = {
        positionX = "-8000.0",
        positionY = "390.0",
        positionZ = "0.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a243",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A244 = {
    Name={
        t_name="a244"
    },
    Transform = {
        positionX = "-8000.0",
        positionY = "390.0",
        positionZ = "5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a244",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A245 = {
    Name={
        t_name="a245"
    },
    Transform = {
        positionX = "-8000.0",
        positionY = "390.0",
        positionZ = "-5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a245",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A246 = {
    Name={
        t_name="a246"
    },
    Transform = {
        positionX = "-8000.0",
        positionY = "390.0",
        positionZ = "-10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a246",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A247 = {
    Name={
        t_name="a247"
    },
    Transform = {
        positionX = "-8000.0",
        positionY = "390.0",
        positionZ = "-26000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a247",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A248 = {
    Name={
        t_name="a248"
    },
    Transform = {
        positionX = "0.0",
        positionY = "390.0",
        positionZ = "0.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a248",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A249 = {
    Name={
        t_name="a249"
    },
    Transform = {
        positionX = "0.0",
        positionY = "390.0",
        positionZ = "5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a249",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A250 = {
    Name={
        t_name="a250"
    },
    Transform = {
        positionX = "0.0",
        positionY = "390.0",
        positionZ = "-5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a250",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A251 = {
    Name={
        t_name="a251"
    },
    Transform = {
        positionX = "0.0",
        positionY = "390.0",
        positionZ = "-10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a251",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A252 = {
    Name={
        t_name="a252"
    },
    Transform = {
        positionX = "0.0",
        positionY = "390.0",
        positionZ = "-15000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a252",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A253 = {
    Name={
        t_name="a253"
    },
    Transform = {
        positionX = "0.0",
        positionY = "390.0",
        positionZ = "-19000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a253",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A254 = {
    Name={
        t_name="a254"
    },
    Transform = {
        positionX = "0.0",
        positionY = "390.0",
        positionZ = "-26000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a254",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A255 = {
    Name={
        t_name="a255"
    },
    Transform = {
        positionX = "0.0",
        positionY = "390.0",
        positionZ = "-23000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a255",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A256 = {
    Name={
        t_name="a256"
    },
    Transform = {
        positionX = "4000.0",
        positionY = "390.0",
        positionZ = "0.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a256",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A257 = {
    Name={
        t_name="a257"
    },
    Transform = {
        positionX = "4000.0",
        positionY = "390.0",
        positionZ = "5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a257",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A258 = {
    Name={
        t_name="a258"
    },
    Transform = {
        positionX = "4000.0",
        positionY = "390.0",
        positionZ = "-5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a258",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A259 = {
    Name={
        t_name="a259"
    },
    Transform = {
        positionX = "4000.0",
        positionY = "390.0",
        positionZ = "-10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a259",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A260 = {
    Name={
        t_name="a260"
    },
    Transform = {
        positionX = "4000.0",
        positionY = "390.0",
        positionZ = "-15000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a260",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A261 = {
    Name={
        t_name="a261"
    },
    Transform = {
        positionX = "4000.0",
        positionY = "390.0",
        positionZ = "-19000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a261",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A262 = {
    Name={
        t_name="a262"
    },
    Transform = {
        positionX = "4000.0",
        positionY = "390.0",
        positionZ = "-26000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a262",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A263 = {
    Name={
        t_name="a263"
    },
    Transform = {
        positionX = "4000.0",
        positionY = "390.0",
        positionZ = "-23000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a263",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A264 = {
    Name={
        t_name="a264"
    },
    Transform = {
        positionX = "4000.0",
        positionY = "390.0",
        positionZ = "10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a264",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A265 = {
    Name={
        t_name="a265"
    },
    Transform = {
        positionX = "8000.0",
        positionY = "390.0",
        positionZ = "0.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a265",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A266 = {
    Name={
        t_name="a266"
    },
    Transform = {
        positionX = "8000.0",
        positionY = "390.0",
        positionZ = "10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a266",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A267 = {
    Name={
        t_name="a267"
    },
    Transform = {
        positionX = "8000.0",
        positionY = "390.0",
        positionZ = "-5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a267",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A268 = {
    Name={
        t_name="a268"
    },
    Transform = {
        positionX = "8000.0",
        positionY = "390.0",
        positionZ = "-10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a268",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A269 = {
    Name={
        t_name="a269"
    },
    Transform = {
        positionX = "8000.0",
        positionY = "390.0",
        positionZ = "-15000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a269",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A270 = {
    Name={
        t_name="a270"
    },
    Transform = {
        positionX = "8000.0",
        positionY = "390.0",
        positionZ = "-19000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a270",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A271 = {
    Name={
        t_name="a271"
    },
    Transform = {
        positionX = "8000.0",
        positionY = "390.0",
        positionZ = "-26000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a271",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A272 = {
    Name={
        t_name="a272"
    },
    Transform = {
        positionX = "8000.0",
        positionY = "390.0",
        positionZ = "-23000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a272",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A273 = {
    Name={
        t_name="a273"
    },
    Transform = {
        positionX = "12000.0",
        positionY = "390.0",
        positionZ = "0.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a273",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A274 = {
    Name={
        t_name="a274"
    },
    Transform = {
        positionX = "12000.0",
        positionY = "390.0",
        positionZ = "5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a274",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A275 = {
    Name={
        t_name="a275"
    },
    Transform = {
        positionX = "12000.0",
        positionY = "390.0",
        positionZ = "-5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a275",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A276 = {
    Name={
        t_name="a276"
    },
    Transform = {
        positionX = "12000.0",
        positionY = "390.0",
        positionZ = "-10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a276",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A277 = {
    Name={
        t_name="a277"
    },
    Transform = {
        positionX = "12000.0",
        positionY = "390.0",
        positionZ = "-15000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a277",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A278 = {
    Name={
        t_name="a278"
    },
    Transform = {
        positionX = "12000.0",
        positionY = "390.0",
        positionZ = "-19000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a278",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A279 = {
    Name={
        t_name="a279"
    },
    Transform = {
        positionX = "12000.0",
        positionY = "390.0",
        positionZ = "25000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a279",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A280 = {
    Name={
        t_name="a280"
    },
    Transform = {
        positionX = "12000.0",
        positionY = "390.0",
        positionZ = "20000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a280",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A281 = {
    Name={
        t_name="a281"
    },
    Transform = {
        positionX = "12000.0",
        positionY = "390.0",
        positionZ = "10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a281",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A282 = {
    Name={
        t_name="a282"
    },
    Transform = {
        positionX = "16000.0",
        positionY = "390.0",
        positionZ = "0.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a282",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A283 = {
    Name={
        t_name="a283"
    },
    Transform = {
        positionX = "16000.0",
        positionY = "390.0",
        positionZ = "5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a283",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A284 = {
    Name={
        t_name="a284"
    },
    Transform = {
        positionX = "16000.0",
        positionY = "390.0",
        positionZ = "-5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a284",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A285 = {
    Name={
        t_name="a285"
    },
    Transform = {
        positionX = "16000.0",
        positionY = "390.0",
        positionZ = "-10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a285",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A286 = {
    Name={
        t_name="a286"
    },
    Transform = {
        positionX = "16000.0",
        positionY = "390.0",
        positionZ = "10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a286",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A287 = {
    Name={
        t_name="a287"
    },
    Transform = {
        positionX = "16000.0",
        positionY = "390.0",
        positionZ = "15000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a287",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A288 = {
    Name={
        t_name="a288"
    },
    Transform = {
        positionX = "16000.0",
        positionY = "390.0",
        positionZ = "25000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a288",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A289 = {
    Name={
        t_name="a289"
    },
    Transform = {
        positionX = "16000.0",
        positionY = "390.0",
        positionZ = "20000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a289",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A290 = {
    Name={
        t_name="a290"
    },
    Transform = {
        positionX = "20000.0",
        positionY = "390.0",
        positionZ = "0.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a290",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A291 = {
    Name={
        t_name="a291"
    },
    Transform = {
        positionX = "20000.0",
        positionY = "390.0",
        positionZ = "5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a291",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A292 = {
    Name={
        t_name="a292"
    },
    Transform = {
        positionX = "20000.0",
        positionY = "390.0",
        positionZ = "-5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a292",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A293 = {
    Name={
        t_name="a293"
    },
    Transform = {
        positionX = "20000.0",
        positionY = "390.0",
        positionZ = "-10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a293",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A294 = {
    Name={
        t_name="a294"
    },
    Transform = {
        positionX = "20000.0",
        positionY = "390.0",
        positionZ = "10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a294",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A295 = {
    Name={
        t_name="a295"
    },
    Transform = {
        positionX = "20000.0",
        positionY = "390.0",
        positionZ = "15000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a295",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A296 = {
    Name={
        t_name="a296"
    },
    Transform = {
        positionX = "20000.0",
        positionY = "390.0",
        positionZ = "25000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a296",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A297 = {
    Name={
        t_name="a297"
    },
    Transform = {
        positionX = "20000.0",
        positionY = "390.0",
        positionZ = "20000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a297",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A298 = {
    Name={
        t_name="a298"
    },
    Transform = {
        positionX = "24000.0",
        positionY = "390.0",
        positionZ = "0.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a298",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A299 = {
    Name={
        t_name="a299"
    },
    Transform = {
        positionX = "24000.0",
        positionY = "390.0",
        positionZ = "5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a299",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A2100 = {
    Name={
        t_name="a2100"
    },
    Transform = {
        positionX = "24000.0",
        positionY = "390.0",
        positionZ = "-5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a2100",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A2101 = {
    Name={
        t_name="a2101"
    },
    Transform = {
        positionX = "24000.0",
        positionY = "390.0",
        positionZ = "-10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a2101",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A2102 = {
    Name={
        t_name="a102"
    },
    Transform = {
        positionX = "24000.0",
        positionY = "390.0",
        positionZ = "10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a102",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A2103 = {
    Name={
        t_name="a2103"
    },
    Transform = {
        positionX = "24000.0",
        positionY = "390.0",
        positionZ = "15000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a103",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A2104 = {
    Name={
        t_name="a2104"
    },
    Transform = {
        positionX = "24000.0",
        positionY = "390.0",
        positionZ = "25000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a2104",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A2105 = {
    Name={
        t_name="a2105"
    },
    Transform = {
        positionX = "24000.0",
        positionY = "390.0",
        positionZ = "20000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a2105",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A2106 = {
    Name={
        t_name="a2106"
    },
    Transform = {
        positionX = "28000.0",
        positionY = "390.0",
        positionZ = "0.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a2106",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A2107 = {
    Name={
        t_name="a2107"
    },
    Transform = {
        positionX = "28000.0",
        positionY = "390.0",
        positionZ = "5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a2107",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A2108 = {
    Name={
        t_name="a2108"
    },
    Transform = {
        positionX = "28000.0",
        positionY = "390.0",
        positionZ = "-5000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a2108",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A2109 = {
    Name={
        t_name="a2109"
    },
    Transform = {
        positionX = "28000.0",
        positionY = "390.0",
        positionZ = "-10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a2109",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A2110 = {
    Name={
        t_name="a110"
    },
    Transform = {
        positionX = "28000.0",
        positionY = "390.0",
        positionZ = "10000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a110",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A2111 = {
    Name={
        t_name="a2111"
    },
    Transform = {
        positionX = "28000.0",
        positionY = "390.0",
        positionZ = "15000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a111",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
A2112 = {
    Name={
        t_name="a2112"
    },
    Transform = {
        positionX = "28000.0",
        positionY = "390.0",
        positionZ = "20000.0",
        scaleX = "0.2",
        scaleY = "0.2",
        scaleZ = "0.2",
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
        t_model_name = "Arbol02.mesh",
        t_entity_name= "a2112",
        t_node_x="0",
        t_node_y="0",
        t_node_z="0",
        t_mat_name= ""
    }
}
