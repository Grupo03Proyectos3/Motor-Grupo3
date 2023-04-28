#pragma once
#ifndef __SCRIPT_MANAGER_H__
#define __SCRIPT_MANAGER_H__

#include <map>
#include <string>
#include "ECS/SingletonECS.h"

class Manager;


namespace Flamingo
{
    class BehaviourScript;
    class GameObject;
    /*Clase que se encarga de la gestión de scripts que hereden de BehaviorScript mediante nombres asociados a la clase y referencias a esta.
    Se usa como capa de abstracción que ,en conjunto con el Manager, realiza las funciones necesarias sobre los componentes que si fueran propios del motor
    y no creados por el ussuario llevaría a cabo el manager directamente. */
    struct ScriptManager : public SingletonECS<ScriptManager>
    {
      public:
        ScriptManager();
        virtual ~ScriptManager();

        /*Método para obtener un script del tipo dado por un nombre */
        BehaviourScript* getScript(std::string t_n);
        /*Método para obtener el tipo de un script dado un nombre usado por las factorias */
        std::string getScriptName(std::string t_n);

        /*Método que añade un nuevo tipo de script a la lista de scripts, así como almacena su indice de script para poder realizar comprobaciones a la
         * hora de añadir nuevos scripts o eliminarlos*/
        void addGameScript(std::string t_n, BehaviourScript* t_s);

        /*Método que añade a un gameObject dado el script en cuestiñon, eliminando uno similar si lo había, y devolviendolo*/
        BehaviourScript* addScript(std::string t_n, GameObject* t_gO);

         /*Método que devuelve el script si el gameObject lo posee o, en caso contrario, un puntero nulo*/
        BehaviourScript* getScript(std::string t_n, GameObject* t_gO);

         /*Método que localiza en la lista de componentes de un GameObject un script del indice dado y lo elimina llamando al Manager*/
        void removeScript(std::string t_n, GameObject* t_gO);

        /*Método que comprueba si el gameObject en cuestion contiene el script en cuestión*/
        bool hasScript(std::string t_n, GameObject* t_gO);

      private:
        friend SingletonECS<Manager>;

        // falta limpiar esta lista de punteros
        std::map<std::string, BehaviourScript*> m_gameScripts;
        std::map<std::string, int> m_scriptsIndex;
        std::map<std::string, std::string> m_nameScripts;
    };
} // namespace Flamingo
#endif // !define __BEHAVIOUR_SCRIPT_H__
