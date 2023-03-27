#include "MapReader.h"
#include "ECS/GameObject.h"
#include "FlamingoBase/JSON.h"
//Include temporal
#include "Render/RenderSystem.h"


MapReader::MapReader(RenderSystem* t_renderSystem)
{
    
    m_componentFactory = ComponentsFactory::instance();
    m_mngr = ecs::Manager::instance();
   
    m_componentFactory->addFactory("PlayerController", new PlayerControllerFactory());
    m_componentFactory->addFactory("MeshRenderer", new MeshRendererFactory(t_renderSystem));
    m_componentFactory->addFactory("RigidBody", new RigidBodyFactory());
    m_componentFactory->addFactory("Transform", new TransformFactory());
    m_componentFactory->addFactory("Light", new LightFactory(t_renderSystem));
    m_componentFactory->addFactory("Camera", new CameraFactory(t_renderSystem));
    m_componentFactory->addFactory("Animator", new AnimatorFactory(t_renderSystem));
}

MapReader::~MapReader()
{
}

void MapReader::readMap(std::string filename)
{
    std::unique_ptr<JSONValue> jValueRoot(JSON::ParseFromFile(filename));

    if (jValueRoot == nullptr || !jValueRoot->IsObject())
    {
        std::cout<< "Something went wrong while load/parsing '" << filename << "'\n";
        return;
    }

    JSONObject root = jValueRoot->AsObject();
    JSONValue* jValue = nullptr;

    //Se mete en los datos de los objectos 
    jValue = root["objects"];
    if (jValue != nullptr)
    {
        if (jValue->IsArray())
        {
            //Por cada objeto
            for (auto& v : jValue->AsArray())
            {
                if (v->IsObject())
                {
                    //Creacion del GO
                    ecs::GameObject* gO = m_mngr->addGameObject({ecs::GROUP_EXAMPLE});
                    JSONObject vObj = v->AsObject();

                    //Obtengo el id
                    try
                    {
                        int id = vObj["id"]->AsNumber();
                    }
                    catch(const std::exception&)
                    {
                        throw new std::exception("Id incorrect");
                    }

                                        // Obtengo los datos del transform del objeto
                    try
                    {
                        // POSICION
                        std::string value = vObj["positionX"]->AsString();
                        m_data.insert({"positionX", value});
                        m_data.insert({"positionY", vObj["positionY"]->AsString()});
                        m_data.insert({"positionZ", vObj["positionZ"]->AsString()});

                        // SCALE
                        m_data.insert({"scaleX", vObj["scaleX"]->AsString()});
                        m_data.insert({"scaleY", vObj["scaleY"]->AsString()});
                        m_data.insert({"scaleZ", vObj["scaleZ"]->AsString()});

                        // ROTATION
                        m_data.insert({"rotationX", vObj["rotationX"]->AsString()});
                        m_data.insert({"rotationY", vObj["rotationY"]->AsString()});
                        m_data.insert({"rotationZ", vObj["rotationZ"]->AsString()});
                        m_data.insert({"rotationW", vObj["rotationW"]->AsString()});

                        // Creacion del componente Transform
                        m_componentFactory->addComponent(gO, "Transform", m_data);
                    }
                    catch (const std::exception&)
                    {
                        throw new std::exception("Params of Transform are incorrect");
                    }

                    m_data.clear();

                  
                    //Recorro cada uno de los scripts que tenga
                    JSONValue* jValueS = nullptr;

                    root = vObj;
                    jValueS = root["scripts"];
                    if (jValueS != nullptr)
                    {
                        if (jValueS->IsArray())
                        {
                            for (auto& w : jValueS->AsArray())
                            {
                                if (w->IsObject())
                                {
                                    //Por cada script obtengo el nombre 
                                    JSONObject vObjS = w->AsObject();
                                    try
                                    {
                                        std::string scriptType = vObjS["type"]->AsString();

                                        //Parametros de ese script
                                        JSONValue* jValueSP = nullptr;
                                        root = vObjS;
                                        jValueSP = root["allParams"];

                                        if (jValueSP != nullptr)
                                        {
                                            if (jValueSP->IsArray())
                                            {
                                                for (auto& b : jValueSP->AsArray())
                                                {
                                                    if (b->IsObject())
                                                    {
                                                        JSONObject vObjSP = b->AsObject();
                                                        try
                                                        {
                                                            std::string valueName = vObjSP["nameParam"]->AsString();
                                                            std::string valueParam = vObjSP["valueParam"]->AsString();
                                                            m_data.insert({valueName, valueParam});
                                                        }
                                                        catch (const std::exception&)
                                                        {
                                                            throw new std::exception("Params of script incorrect");
                                                        }

                                                    }
                                                    else
                                                    {
                                                        throw new std::exception("Param of script are are not correct");
                                                    }
                                                }
                                            }
                                        }
                                        else
                                        {
                                            throw "'allParams' is null";
                                        }
                                        //Se añade al componente
                                        m_componentFactory->addComponent(gO, scriptType, m_data);
                                        m_data.clear();
                                    }
                                    catch (const std::exception&)
                                    {
                                        throw new std::exception("Param of script are are not correct");
                                    }
                                    m_data.clear();
                                }
                                else
                                {
                                    throw "'scripts' array in '" + filename + "' includes and invalid value";
                                }
                            }
                        }
                    }
                    else
                    {
                        throw "'scripts' are null";
                    }
                   

                }
                else
                {
                    throw "'objects' array in '" + filename + "' includes and invalid value";
                }
               
            }
        }
    }
    else
    {
        throw "'objects' are null";
    }
}