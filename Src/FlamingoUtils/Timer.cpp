#include "Timer.h"
#include <Windows.h>


namespace Flamingo
{
    Timer::Timer()
    {
        reset();
    }

    Timer::~Timer() 
    {
    }

    /// <summary>
    /// Comienza el contador de tiempo a 0 de nuevo
    /// </summary>
    void Timer::reset()
    {
        m_initTime = GetTickCount64();
    }

    /// <summary>
    /// getTime() usa GetTickCount64() que, al contrario que GetTickCount() que sufre overflow cada 64 días.
    /// </summary>
    /// <returns>Devuelve el tiempo desde que se lanzó el timer en milisegundos. Para cambiar a segundos, dividir entre 1000.</returns>
    unsigned long long Timer::getElapsedTime()
    {
        return m_initTime - GetTickCount64();
    }

}