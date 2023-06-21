#pragma once
#ifndef __BEHAVIOUR_SCRIPT_H__
#define __BEHAVIOUR_SCRIPT_H__

#include "ECS/Component.h"
#include "ECS/GameObject.h"
#include "FlamingoExport/FlamingoAPI.h"
namespace Flamingo
{
    struct FLAMINGOEXPORT_API BehaviourScript : public Flamingo::Component
    {
      public:
        __SYSTEM_ID_DECL__(Flamingo::_cmp_BEHAVIOUR_SCRIPT)

        BehaviourScript();
        ~BehaviourScript();

        virtual BehaviourScript* clone();

        std::string GetScriptName();

        // Clases que podrán ser overrideadas por el desarrollador, para definir a su gusto
        virtual bool initValues(std::unordered_map<std::string, std::string> = {}) {return true;}

        virtual void start(){};

        virtual void update(float t_delta_time){};

        /**
         * @brief Se llama una vez al comienzo de collisionar con otro cuerpo
         *
         * @param[in] t_other GameObject* GameObject del cuerpo contra el que ha colisionado
         * @return
         */
        virtual void onCollisionEnter(Flamingo::GameObject* t_other){};

        /**
         * @brief Se llama continuamente al collisionar con otro cuerpo
         *
         * @param[in] t_other GameObject* GameObject del cuerpo contra el que colisiona
         * @return
         */
        virtual void onCollisionStay(Flamingo::GameObject* t_other){};

        /**
         * @brief Se llama al salir de la colision con otro cuerpo
         *
         * @param[in] t_other GameObject* GameObject del cuerpo con el que ha terminado la colision
         * @return
         */
        virtual void onCollisionExit(Flamingo::GameObject* t_other){};

        virtual void clickFuntion(){};

      private:
    };
} // namespace Flamingo
#endif // !define __BEHAVIOUR_SCRIPT_H__
