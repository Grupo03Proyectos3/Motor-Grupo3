#include "MapReader.h"
#include "FlamingoBase/JSON.h"
#include "ECS/GameObject.h"

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
                    std::string id = vObj["id"]->AsString();

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
                                    std::string scriptType = vObjS["scriptType"]->AsString();
                                    std::string value = vObjS["value"]->AsString();
                                    
                                    mdata.insert({value, value});

                                    mComponentFactory->addComponent(g0, scriptType, mdata);


                                }

                            }
                        }
                    }


                }
            }
        }

    }



}

//
//JSONObject root = jValueRoot->AsObject();
//JSONValue* jValue = nullptr;
//
//jValue = root["credits"];
//if (jValue != nullptr)
//{
//    if (jValue->IsArray())
//    {
//        for (auto& v : jValue->AsArray())
//        {
//            if (v->IsObject())
//            {
//                JSONObject vObj = v->AsObject();
//                std::string key = vObj["name"]->AsString();
//                credits_.push_back(key);
//            }
//        }
//    }
//}