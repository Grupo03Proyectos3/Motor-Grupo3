#pragma once
#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include "ECS/Component.h"
#include <FlamingoUtils/SVector3.h>
#include <FlamingoUtils/SQuaternion.h>
#include "FlamingoExport/FlamingoAPI.h"

/**
 *  Componente que se encarga de almacenar y manejar información 
 *  sobre la posición, rotación y escala de un GameObject
 */
namespace Flamingo
{
    enum STransformSpace
    {
        WORLD,
        LOCAL,
        PARENT
    };
    struct __declspec(dllexport) Transform : public Component
    {
      public:
        __SYSTEM_ID_DECL__(_cpm_TRANSFORM)

        Transform();
        virtual ~Transform(){};
        void initValues(SVector3 t_position = SVector3(0.0, 0.0, 0.0), SQuaternion t_rotation = SQuaternion(0.0, 0.0, 0.0, 1.0), SVector3 t_scale = SVector3(1.0, 1.0, 1.0));
        void initComponent() override;

        /**
         * @brief Se llama para obtener la posición actual del Transform.
         * @return
         */
        SVector3 getPosition();
        SQuaternion getRotation();
        SVector3 getScale();
        /**
         * @brief Se llama para colocar el Transform en la posición deseada.
         *
         *
         * @param[in] t_pos SVector3 posición en la que se desea colocar
         * @return
         */
        void setPosition(SVector3 t_pos);
        /**
         * @brief Se llama para rotar el Transform en el ángulo deseado.
         *
         *
         * @param[in] t_rotation SQuaternion rotación en la que se desea colocar
         * @return
         */
        void setRotation(SQuaternion t_rotation, STransformSpace t_trs = STransformSpace::LOCAL);
        void setPositionPerPhysics(SVector3 t_pos);
        void setRotationPerPhysics(SQuaternion t_rotation);
        /**
         * @brief Se llama para escalar el Transform en el tamaño deseado.
         *
         *
         * @param[in] t_scale SVector3 escala en la que se desea tener.
         * @return
         */
        void setScale(SVector3 t_scale);
        /**
         * @brief Se llama para trasladar el Transform en una determinada dirección.
         *
         *
         * @param[in] t_translate SVector3 dirección en la que se desea mover.
         * @return
         */
        void translate(SVector3 t_translate, STransformSpace t_trs = STransformSpace::PARENT);

      private:
        SVector3 m_position;
        SQuaternion m_rotation;
        SVector3 m_scale;
    };
} // namespace Flamingo
#endif