#pragma once
#ifndef __SCRIPT_MANAGER_H__
#define __SCRIPT_MANAGER_H__

#include "BehaviourScript.h"
#include "ECS/Manager.h"
#include <map>
namespace Flamingo
{
    struct ScriptManager : public SingletonECS<ScriptManager>
    {
      public:
        ScriptManager();
        virtual ~ScriptManager();

        /*M�todo para obtener un script del tipo dado por un nombre */
        BehaviourScript* getScript(std::string t_n);
        /*M�todo para obtener el tipo de un script dado un nombre usado por las factorias */
        std::string getScriptName(std::string t_n);

        /*M�todo que a�ade un nuevo tipo de script a la lista de scripts, as� como almacena su indice de script para poder realizar comprobaciones a la
         * hora de a�adir nuevos scripts o eliminarlos*/
        void addGameScript(std::string t_n, BehaviourScript* t_s);

        BehaviourScript* addScript(std::string t_n, GameObject* t_gO)
        {
            deleteOtherScript(t_n, t_gO);

            return Manager::instance()->addScript(t_gO, getScript(t_n), t_n);
        }

        /*M�todo que localiza en la lista de componentes de un GameObject un script del indice dado y lo elimina llamando al Manager*/
        void deleteOtherScript(std::string t_n, GameObject* t_gO);

      private:
        friend SingletonECS<Manager>;

        // falta limpiar esta lista de punteros
        std::map<std::string, BehaviourScript*> m_gameScripts;
        std::map<std::string, int> m_scriptsIndex;
        std::map<std::string, std::string> m_nameScripts;
    };
} // namespace Flamingo
#endif // !define __BEHAVIOUR_SCRIPT_H__
