#pragma once
#ifndef __SCRIPTFACTORY_H__
#define __SCRIPTFACTORY_H__

#include "Factory.h"
#include "Lua/BehaviourScript.h"
#include <map>
/*Factoria para crear todos los scripts del proyecto.
 *Factoria especial ya que realiza funciones de comprobación y detección de duplicados extra
 * para poder gestionar los diferentes scripts que heredan de BehaviourScript correctamente.
 * Reduce significativamente las competencias del manager dejando en sus manos solo la asignación del
 * script en cuestión y la eliminación de scripts duplicados.
 * Para añadir tipos de scripts:
 *   <PunteroAInstanciaDeEstaClase>->addGameScript("NombreRelacionado", new ScriptHeredaBehaviourScript());
 */
class ScriptFactory : public Factory
{
  public:
    ScriptFactory();

    ecs::Component* createComponent(ecs::GameObject* gO, const std::unordered_map<std::string, std::string>& args) override;

   /*Método que añade un nuevo tipo de script a la lista de scripts, así como almacena su indice de script para poder realizar comprobaciones a la 
   * hora de añadir nuevos scripts o eliminarlos
   */
    void addGameScript(std::string t_n, BehaviourScript* t_s)
    {
        if (m_scriptsIndex.count(typeid(t_s).name()))
            return;

        m_scriptsIndex.insert({typeid(t_s).name(), m_scriptsIndex.size() + 1});
        m_gameScripts.emplace(t_n, t_s);
    }

    /*Método que localiza en la lista de componentes de un GameObject un script del indice dado y lo elimina llamando al Manager*/
    void deleteOtherScript(int t_scriptIndex, ecs::GameObject* t_gO);

  private:
    std::map<std::string, BehaviourScript*> m_gameScripts;
    std::map<std::string, int> m_scriptsIndex;
};

/*Para realizar pruebas:
*  auto s = new ScriptFactory();
    s->addGameScript("PruebaScript", new PruebaScript());
    ecs::GameObject* g = m_mngr->addGameObject();
    ecs::AddComponent<Transform>(g);
    std::unordered_map<std::string, std::string> m;
    m.insert({"t_scriptName", "PruebaScript"});
    auto v = s->createComponent(g, m);
    v = s->createComponent(g, m);
    PruebaScript* gg = dynamic_cast<PruebaScript*>(v);
    gg->initComponent();
*/
#endif