#pragma once
#ifndef __LUA_SYSTEM_H__
#define __LUA_SYSTEM_H__

#include "ECS/System.h"
#include "ECS/Manager.h"
#include "FlamingoBase/ComponentsFactory.h"
#include "FlamingoBase/SceneManager.h"

//LUA
extern "C"
{
    #include "lua.h"
    #include "lauxlib.h"
    #include "lualib.h"
}

#include <LuaBridge\LuaBridge.h>

#include <unordered_map>
#include <string>

#define PATH_PREFIX "Assets/Scripts/"
#define FILE_EXTENSION ".lua"

using Data = std::unordered_map<std::string, std::string>;

class lua_State;

namespace luabridge
{
    class LuaRef;
    class LuaResult;
} // namespace luabridge

// LUA

namespace Flamingo
{
    class ScriptingSystem : public System
    {
      public:
        __SYSTEM_ID_DECL__(_sys_LUA)

        ScriptingSystem();
        virtual ~ScriptingSystem();

        void initSystem() override;
        void update(float t_delta_time) override;
        void recieve(const Message& t_m) override;

        lua_State* getLuaState();

        /**
         * @brief Permite leer scripts de lua
         *
         * @param[in] t_name std::string Nombre del script sin la extension .lua
         * @return
         */
        void readScript(const std::string& t_name);
        /**
         * @brief Permite llamar a una funcion almacenada en lua
         *
         * @param[in] t_name Nombre de la funcion
         * @return
         */
        void callLuaFunction(std::string t_name);
        /**
         * @brief Permite cargar una escena desde un script de lua
         *
         * @param[in] t_name std::string Nombre de la escena
         * @param[in] t_first bool Si es la primera escena
         * @return
         */
        bool loadScene(std::string t_scene, bool t_first = true);

         /**
         * @brief Añade a lua una variable
         *
         * @param[in] t_var Tipo de variable
         * @param[in] t_name Nombre de la variable
         * @return
         */
        template <typename T>
        void addVarToLua(T t_var, std::string t_name) 
        {
            luabridge::push(lua_state, t_var);
            lua_setglobal(lua_state, t_name.c_str());
        }
        /**
         * @brief Permite cargar los gameObjects de una escena
         *
         * @param[in] t_scene Nombre de la escena
         * @return
         */
        void loadObjects(std::string t_scene);
      private:
        lua_State* lua_state;
        ComponentsFactory* m_componentFactory;
        SceneManager& m_scene_mngr;
        Data m_data;
        Manager* m_mngr;

        void addFactories();
        bool isComponent(std::string t_name);
        //Metodo interno para obtener variables guardadas en lua
        luabridge::LuaRef getFromLua(std::string t_name);
    };
} // namespace Flamingo


#endif