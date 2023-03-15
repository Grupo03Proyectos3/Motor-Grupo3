#include "MapReader.h"
#include "ECS/GameObject.h"
#include "FlamingoBase/JSON.h"

MapReader::MapReader()
{
    mComponentFactory = new ComponentsFactory();
}

MapReader::~MapReader()
{
    delete mComponentFactory;
}

void MapReader::readMap(std::string filename)
{
    std::unique_ptr<JSONValue> jValueRoot(JSON::ParseFromFile(filename));

    if (jValueRoot == nullptr || !jValueRoot->IsObject())
        throw "Something went wrong while load/parsing '" + filename + "'";

    JSONObject root = jValueRoot->AsObject();
    JSONValue* jValue = nullptr;

    jValue = root["objects"];
    if (jValue != nullptr)
    {
        if (jValue->IsArray())
        {
            for (auto& v : jValue->AsArray())
            {
                if (v->IsObject())
                {
                    ecs::GameObject* gO = new ecs::GameObject();
                    JSONObject vObj = v->AsObject();

                    // obtener nombre de la variable ???
                    try
                    {
                        std::string id = vObj["id"]->AsString();
                    }
                    catch(const std::exception&)
                    {
                        throw new std::exception("Nombre id incorrecto");
                    }
                  
                    JSONValue* jValueS = nullptr;
                    jValueS = root["scripts"];
                    if (jValueS != nullptr)
                    {
                        if (jValueS->IsArray())
                        {
                            for (auto& w : jValueS->AsArray())
                            {
                                if (w->IsObject())
                                {
                                    JSONObject vObjS = w->AsObject();
                                    std::string scriptType = vObjS[w->AsString()]->AsString();
                                    std::string nameValue = w->AsString();
                                    std::string value = vObjS[nameValue]->AsString();
                                    mdata.insert({nameValue, value});
                                    mComponentFactory->addComponent(gO, scriptType, mdata);
                                    mdata.clear();
                                }
                                else
                                {
                                    throw "'scripts' array in '" + filename + "' includes and invalid value";
                                }
                            }

                        }
                    }
                    
                    //POSICION
                    mdata.insert({ v->AsString(), vObj[v->AsString()]->AsString()});
                    mdata.insert({ v->AsString(), vObj[v->AsString()]->AsString()});
                    mdata.insert({ v->AsString(), vObj[v->AsString()]->AsString()});
                   
                    //SCALE
                    mdata.insert({v->AsString(), vObj[v->AsString()]->AsString()});
                    mdata.insert({v->AsString(), vObj[v->AsString()]->AsString()});
                    mdata.insert({v->AsString(), vObj[v->AsString()]->AsString()});

                    //ROTATION
                    mdata.insert({v->AsString(), vObj[v->AsString()]->AsString()});
                    mdata.insert({v->AsString(), vObj[v->AsString()]->AsString()});
                    mdata.insert({v->AsString(), vObj[v->AsString()]->AsString()});
                    mdata.insert({v->AsString(), vObj[v->AsString()]->AsString()});

                    //Creacion del componente Transform
                    mComponentFactory->addComponent(gO, "3", mdata);
                    mdata.clear();
                }
                else
                {
                    throw "'objects' array in '" + filename + "' includes and invalid value";
                }
               
            }
        }
    }
}