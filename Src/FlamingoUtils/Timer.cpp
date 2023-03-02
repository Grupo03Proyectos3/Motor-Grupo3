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

    void Timer::reset()
    {
        m_initTime = GetTickCount64();
    }

    unsigned long long Timer::getElapsedTime()
    {
        return GetTickCount64() - m_initTime;
    }

}