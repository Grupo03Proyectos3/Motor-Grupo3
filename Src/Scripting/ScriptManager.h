#pragma once
#ifndef __SCRIPT_MANAGER_H__
#define __SCRIPT_MANAGER_H__

#include "ECS/SingletonECS.h"
#include <map>
#include <string>

namespace Flamingo
{
 
    class GameObject;
    class Manager;
    class BehaviourScript;

    /*Clase que se encarga de la gesti�n de scripts que hereden de BehaviorScript mediante nombres asociados a la clase y referencias a esta.
    Se usa como capa de abstracci�n que ,en conjunto con el Manager, realiza las funciones necesarias sobre los componentes que si fueran propios del motor
    y no creados por el ussuario llevar�a a cabo el manager directamente. */
    class __declspec(dllexport) ScriptManager : public SingletonECS<ScriptManager>
    {
      public:
        /* la constructora y destructora de las clases que hereden de singleton deben estar en el .h para que funcionen en el juego */
        ScriptManager();
        virtual ~ScriptManager();
       

        /*M�todo para obtener un script del tipo dado por un nombre */
        BehaviourScript* getScript(std::string t_n);
        /*M�todo para obtener el tipo de un script dado un nombre usado por las factorias */
        std::string getScriptName(std::string t_n);

        /*M�todo que a�ade un nuevo tipo de script a la lista de scripts, as� como almacena su indice de script para poder realizar comprobaciones a la
         * hora de a�adir nuevos scripts o eliminarlos*/
        void addGameScript(std::string t_n, BehaviourScript* t_s);

        /*M�todo que a�ade a un gameObject dado el script en cuesti�on, eliminando uno similar si lo hab�a, y devolviendolo*/
        BehaviourScript* addScript(std::string t_n, GameObject* t_gO);

        /*M�todo que devuelve el script si el gameObject lo posee o, en caso contrario, un puntero nulo*/
        BehaviourScript* getScript(std::string t_n, GameObject* t_gO);

        /*M�todo que localiza en la lista de componentes de un GameObject un script del indice dado y lo elimina llamando al Manager*/
        void removeScript(std::string t_n, GameObject* t_gO);

        /*M�todo que comprueba si el gameObject en cuestion contiene el script en cuesti�n*/
        bool hasScript(std::string t_n, GameObject* t_gO);

        //Llama al star() de los componentes de juego
        void startComponents();

        void deleteScriptsTemplates();

      private:
        friend SingletonECS<Manager>;

        // falta limpiar esta lista de punteros
        std::map<std::string, BehaviourScript*> m_gameScripts;
        std::map<std::string, int> m_scriptsIndex;
        std::map<std::string, std::string> m_nameScripts;
    };
} // namespace Flamingo
#endif
