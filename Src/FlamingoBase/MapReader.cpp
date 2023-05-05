#include "MapReader.h"
#include "ECS/GameObject.h"
#include "FlamingoBase/JSON.h"

#include "FlamingoBase/Scene.h"
#include "Render/RenderSystem.h"
namespace Flamingo
{

    MapReader::MapReader(Flamingo::RenderSystem* t_renderSystem)
    {
        m_renderSystem = t_renderSystem;
        m_componentFactory = ComponentsFactory::instance();
        m_mngr = Manager::instance();
    }

    MapReader::~MapReader()
    {
        if (m_componentFactory != nullptr)
        {
            ComponentsFactory::close();
        }
    }

    void MapReader::initMapReader()
    {
        m_componentFactory->addFactory("MeshRenderer", new MeshRendererFactory(m_renderSystem));
        m_componentFactory->addFactory("RigidBody", new RigidBodyFactory());
        m_componentFactory->addFactory("Transform", new TransformFactory());
        m_componentFactory->addFactory("Light", new LightFactory(m_renderSystem));
        m_componentFactory->addFactory("Camera", new CameraFactory(m_renderSystem));
        m_componentFactory->addFactory("Animator", new AnimatorFactory(m_renderSystem));
        m_componentFactory->addFactory("UIElement", new UIElementFactory());
    }

    bool MapReader::readMap(std::string filename, Flamingo::Scene* t_scene)
    {
        std::unique_ptr<JSONValue> jValueRoot(JSON::ParseFromFile(filename));

        if (jValueRoot == nullptr || !jValueRoot->IsObject())
        {
            throw std::runtime_error("Something went wrong while load/parsing '" + filename + "'\n");
        }

        JSONObject root = jValueRoot->AsObject();
        JSONValue* jValue = nullptr;

        // Se mete en los datos de los objectos
        jValue = root["objects"];
        if (jValue != nullptr)
        {
            if (jValue->IsArray())
            {
                // Por cada objeto
                for (auto& v : jValue->AsArray())
                {
                    // Creacion del GO, se puede quitar grupo, hay que ajustar que se borre si no se consigue crear transform
                    gO = m_mngr->addGameObject({GROUP_EXAMPLE});
                    t_scene->addObjects(gO);

                    if (v->IsObject())
                    {
                        JSONObject vObj = v->AsObject();

                        // Obtengo el id
                        try
                        {
                            int id = vObj["id"]->AsNumber();
                        }
                        catch (...)
                        {
                            gO->setAlive(false);
                            throw  std::exception("Id incorrect");
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
                        catch (...)
                        {
                            gO->setAlive(false);
                            throw std::exception("Params of Transform are incorrect");
                        }

                        m_data.clear();

                        // Recorro cada uno de los scripts que tenga
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
                                        // Por cada script obtengo el nombre
                                        JSONObject vObjS = w->AsObject();
                                        try
                                        {
                                            std::string scriptType = vObjS["type"]->AsString();

                                            // Parametros de ese script
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
                                            // Se añade al componente
                                            m_componentFactory->addComponent(gO, scriptType, m_data);
                                            m_data.clear();
                                        }
                                        catch (...)
                                        {
                                            throw std::exception("Param of script are are not correct");
                                        }
                                        m_data.clear();
                                    }
                                    else
                                    {
                                        gO->setAlive(false);
                                        throw std::runtime_error("'scripts' array in '" + filename + "' includes and invalid value");
                                    }
                                }
                            }
                        }
                        else
                        {
                            gO->setAlive(false);
                            throw  std::runtime_error("'scripts' are null");
                        }
                    }
                    else
                    {
                        gO->setAlive(false);
                        throw std::runtime_error("'objects' array in '" + filename + "' includes and invalid value");
                    }
                }
            }
        }
        else
        {
            throw std::runtime_error("'objects' are null");
        }

        return true;
    }

} // namespace Flamingo