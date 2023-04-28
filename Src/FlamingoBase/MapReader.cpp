#include "MapReader.h"
#include "ECS/GameObject.h"
#include "FlamingoBase/JSON.h"
// Include temporal
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
    }

    void MapReader::initMapReader()
    {
        m_componentFactory->addFactory("PlayerController", new PlayerControllerFactory());
        m_componentFactory->addFactory("MeshRenderer", new MeshRendererFactory(m_renderSystem));
        m_componentFactory->addFactory("RigidBody", new RigidBodyFactory());
        m_componentFactory->addFactory("Transform", new TransformFactory());
        m_componentFactory->addFactory("Light", new LightFactory(m_renderSystem));
        m_componentFactory->addFactory("Camera", new CameraFactory(m_renderSystem));
        m_componentFactory->addFactory("Animator", new AnimatorFactory(m_renderSystem));
        m_componentFactory->addFactory("UIElement", new UIElementFactory());
    }

    void MapReader::readMap(std::string filename, Flamingo::Scene* t_scene)
    {
        createCamera();

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
                    GameObject* gO = m_mngr->addGameObject({GROUP_EXAMPLE});
                    t_scene->addObjects(gO);

                    if (v->IsObject())
                    {
                        JSONObject vObj = v->AsObject();

                        // Obtengo el id
                        try
                        {
                            int id = vObj["id"]->AsNumber();
                        }
                        catch (const std::exception&)
                        {
                            gO->setAlive(false);
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
                            gO->setAlive(false);
                            throw new std::exception("Params of Transform are incorrect");
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
                                        catch (const std::exception&)
                                        {
                                            throw new std::exception("Param of script are are not correct");
                                        }
                                        m_data.clear();
                                    }
                                    else
                                    {
                                        gO->setAlive(false);
                                        throw std::runtime_error("'scripts' array in '" + filename + "' includes and invalid value");
                                    }
                                }

                                try
                                {
                                    for (auto c : gO->getCurrentComponents())
                                    {
                                        c.second->initComponent();
                                    }
                                }
                                catch (const std::exception&)
                                {
                                    throw std::runtime_error("failed to initialize components");
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
    }

    void MapReader::createCamera()
    {
        GameObject* gO = m_mngr->addGameObject({GROUP_RENDER});

        m_data.insert({"t_name", "m_camera"});
        m_data.insert({"t_entity_name", "camera"});
        m_componentFactory->addComponent(gO, "Camera", m_data);

        m_data.clear();

        // PASAR A FLAMINGOBASE
        auto m_camera = getComponent<Camera>(gO);
        m_camera->setViewPortBackgroundColour(SColor(0.3f, 0.2f, 0.6f));

        m_camera->lookAt(SVector3(0, 0, 0), Camera::WORLD);
        m_camera->setNearClipDistance(1);
        m_camera->setFarClipDistance(10000);
    }
} // namespace Flamingo