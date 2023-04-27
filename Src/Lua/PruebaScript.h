#pragma once
#ifndef __PRUEBA_SCRIPT_H__
#define __PRUEBA_SCRIPT_H__

#include "BehaviourScript.h"
//
//namespace luabridge
//{
//    class LuaRef;
//    class LuaResult;
//} // namespace luabridge
//class lua_State;
namespace Flamingo
{

    struct PruebaScript : public BehaviourScript
    {
      public:
        __SYSTEM_ID_DECL__(_cmp_BEHAVIOUR_SCRIPT)

        PruebaScript();
        virtual ~PruebaScript();

        // Clases que podrán ser overrideadas por el desarrollador, para definir a su gusto
        void initValues() override;
        void initComponent() override; // == start() ?

        BehaviourScript* clone() override;

        void update(float t_delta_time) override;

        /**
         * @brief Se llama una vez al comienzo de collisionar con otro cuerpo
         *
         *
         *
         * @param[in] t_other GameObject* GameObject del cuerpo contra el que ha colisionado
         * @return
         */
        void onCollisionEnter(GameObject* t_other) override;

        /**
         * @brief Se llama continuamente al collisionar con otro cuerpo
         *
         *
         * @param[in] t_other GameObject* GameObject del cuerpo contra el que colisiona
         * @return
         */
        void onCollisionStay(GameObject* t_other) override;

        /**
         * @brief Se llama al salir de la colision con otro cuerpo
         *
         *
         * @param[in] t_other GameObject* GameObject del cuerpo con el que ha terminado la colision
         * @return
         */
        void onCollisionExit(GameObject* t_other) override;

      private:
    };
} // namespace Flamingo
#endif // !define __BEHAVIOUR_SCRIPT_H__
