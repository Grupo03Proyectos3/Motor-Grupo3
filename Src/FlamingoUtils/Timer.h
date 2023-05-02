#pragma once
#ifndef __TIMER_H__
#define __TIMER_H__

#include "FlamingoExport/FlamingoAPI.h"

namespace Flamingo
{
    class FLAMINGOEXPORT_API Timer
    {
    public:
        Timer();
        ~Timer();

        /// <summary>
        /// Comienza el contador de tiempo a 0 de nuevo
        /// </summary>
        void reset();

        /// <summary>
        /// getTime() usa GetTickCount64() que, al contrario que GetTickCount() que sufre overflow cada 64 días.
        /// </summary>
        /// <returns>Devuelve el tiempo desde que se lanzó el timer en milisegundos. Para cambiar a segundos, dividir entre 1000.</returns>
        unsigned long long getElapsedTime();
       
    private:      
        unsigned long long m_initTime;
    };
}


#endif 
