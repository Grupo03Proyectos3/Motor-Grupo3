#pragma once
#ifndef __TIMER_H__
#define __TIMER_H__

namespace Flamingo
{
    class Timer
    {
    public:
        Timer();
        ~Timer();

        void reset();
        unsigned long long getElapsedTime();
            
    private:      
        unsigned long long m_initTime;
    };
}


#endif 
