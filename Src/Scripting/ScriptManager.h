#pragma once
#ifndef __SCRIPT_MANAGER_H__
#define __SCRIPT_MANAGER_H__

#include "ECS/SingletonECS.h"
#include <map>
#include <string>
#include "FlamingoExport/FlamingoAPI.h"
namespace Flamingo
{
    class GameObject;
    class Manager;
    class BehaviourScript;

    /*
    * Clase que se encarga de la gestión de scripts que hereden de BehaviorScript mediante nombres asociados a la clase y referencias a esta.
    * Se usa como capa de abstracción que ,en conjunto con el Manager, realiza las funciones necesarias sobre los componentes que si fueran propios del motor
    * y no creados por el ussuario llevaría a cabo el manager directamente. 
    */
    class FLAMINGOEXPORT_API ScriptManager : public SingletonECS<ScriptManager>
    {
      public:
        /* la constructora y destructora de las clases que hereden de singleton deben estar en el .h para que funcionen en el juego */
        ScriptManager();
        virtual ~ScriptManager();
      
        /**
         * @brief  obtener un script del tipo dado por un nombre
         *
         * @param[in] t_n nombre del script a buscar
         *
         * @return BehaviourScript*
         */
        BehaviourScript* getScript(std::string t_n);

       
        /**
         * @brief   obtener el tipo de un script dado un nombre usado por las factorias
         *
         * @param[in] t_n nombre del script a buscar
         *
         * @return string
         */
        std::string getScriptName(std::string t_n);

         /**
         * @brief Método que añade un nuevo tipo de script a la lista de scripts, así como almacena su indice de script para poder realizar comprobaciones a la
         * hora de añadir nuevos scripts o eliminarlos
         *
         * @param[in] t_n nombre del script 
         * @param[in] t_s script a añadir
         *
         * @return bool
         */
        bool addGameScript(std::string t_n, BehaviourScript* t_s);

         /**
         * @brief Método que añade a un gameObject dado el script en cuestiñon, eliminando uno similar si lo había, y devolviendolo
         *
         * @param[in] t_n nombre del script
         * @param[in] t_gO gameObject
         *
         * @return BehaviourScript*
         */
        BehaviourScript* addScript(std::string t_n, GameObject* t_gO);

      
        /**
         * @brief Método que devuelve el script si el gameObject lo posee o, en caso contrario, un puntero nulo
         *
         * @param[in] t_n nombre del script
         * @param[in] t_gO gameObject
         *
         * @return BehaviourScript*
         */
        BehaviourScript* getScript(std::string t_n, GameObject* t_gO);

        /**
         * @brief Método que localiza en la lista de componentes de un GameObject un script del indice dado y lo elimina llamando al Manager
         * 
         * @param[in] t_n nombre del script
         * @param[in] t_gO gameObject
         *
         * @return void
         */
        void removeScript(std::string t_n, GameObject* t_gO);

        /**
         * @brief Método que comprueba si el gameObject en cuestion contiene el script en cuestión
         *
         * @param[in] t_n nombre del script
         * @param[in] t_gO gameObject
         *
         * @return bool
         */
        bool hasScript(std::string t_n, GameObject* t_gO);

       
        /**
         * @brief Llama al star() de los componentes de juego
         *
         * @return void
         */
        void startComponents();

        void deleteScriptsTemplates();

      private:
        friend SingletonECS<Manager>;
        std::map<std::string, BehaviourScript*> m_gameScripts;
        std::map<std::string, int> m_scriptsIndex;
        std::map<std::string, std::string> m_nameScripts;
    };
} // namespace Flamingo
#endif
