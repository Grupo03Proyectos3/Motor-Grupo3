#include "SingletonECS.h"

template <typename T>
SingletonECS<T>::SingletonECS()
{
}

template <typename T>
SingletonECS<T>::~SingletonECS()
{
}

template <typename T>
void SingletonECS<T>::close()
{
    m_instance.reset();
}

template <typename T>
T* SingletonECS<T>::instance()
{
    // you can replace the "if" by assert(instance_.get() != nullptr)
    // to force initialisation at the beginning
    //
    if (m_instance.get() == nullptr)
    {
        init();
    }
    return m_instance.get();
}
