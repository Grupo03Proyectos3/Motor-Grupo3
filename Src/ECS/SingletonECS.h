// This file is part of the course TPV2 @UCM - Samir Genaim
#pragma once

#ifndef __SINGLETON_ECS_H__
#define __SINGLETON_ECS_H__

#include <cassert>
#include <memory>

/*
 * This is an attempt to have a single Singleton class that can be used
 * via inheritance to make some other class Singleton. It is just to avoid
 * copying the Singleton declarations each time.
 *
 * >>> Requirements:
 *
 * The class that inherits this class must implement a constructor
 * with no arguments, this is because of the call 'init()' in method
 * 'instance()'. In the case that defining such a constructor is against
 * your design, just define one that throws and exception.
 *
 * >>> Usage:
 *
 * class A : public Singleton<A> {
 *
 *    friend Singleton<A>; // this way Singleton can call the constructor of A
 *
 * private: // constructors are private
 *    A() {
 *      //....
 *    }
 *
 * public: // the rest of the functionality
 *    virtual ~A() {
 *    }
 * }
 *
 */

template <typename T>
class SingletonECS
{
  protected:
    SingletonECS();

  public:
    // no se pueden copiar objetos de este tipo
    SingletonECS<T>& operator=(const SingletonECS<T>& o) = delete;
    SingletonECS(const SingletonECS<T>& o) = delete;

    virtual ~SingletonECS();

    /// NO PODEMOS INICIALIZARLO EN EL CPP PORQUE SE NECESITAN 2 TEMPLATES
    // some singletons need to be initialised with some parameters, we
    // can call this method at the beginning of the program.
    template <typename... Targs>
    inline static T* init(Targs&&... args)
    {
        assert(instance_.get() == nullptr);
        instance_.reset(new T(std::forward<Targs>(args)...));
        return instance_.get();
    }

    // in some cases, when singletons depend on each other, you have
    // to close them in a specific order, This is why we have this close
    // method
    static void close();
    // get the singleton instance as a pointer
    //
    static T* instance();

  private:
    static std::unique_ptr<T> instance_;
};

template <typename T>
std::unique_ptr<T> SingletonECS<T>::instance_;
#endif
