//#include "SmartPointer.h"
//#include <iostream>
//
//template<typename T>
//SmartPointer<T>::SmartPointer(T* basePointer) : basePointer(basePointer), pointersCount(*new size_t(1)) { }
//
//template<typename T>
//SmartPointer<T>::~SmartPointer()
//{
//    if (basePointer != nullptr) Release();
//}
//
//template<typename T>
//SmartPointer<T>::SmartPointer(const SmartPointer<T>& otherPointer)
//{
//    if (basePointer != nullptr) Release();
//
//    basePointer(otherPointer.basePointer);
//    pointersCount(++otherPointer.pointersCount);
//}
//
//template<typename T>
//SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer<T>& otherPointer)
//{
//    this(otherPointer);
//    return *this;
//}
//
//template<typename T>
//T* const SmartPointer<T>::operator->() const
//{
//    if (basePointer == nullptr) throw std::runtime_error("Instance point to nullptr.");
//    return basePointer;
//}
//
//template<typename T>
//T SmartPointer<T>::operator*() const
//{
//    if (basePointer == nullptr) throw std::runtime_error("Instance point to nullptr.");
//    return *basePointer;
//}
//
//template<typename T>
//const T& SmartPointer<T>::Get() const
//{
//    if (basePointer == nullptr) throw std::runtime_error("Instance point to nullptr.");
//    return *basePointer;
//}
//
//template<typename T>
//void SmartPointer<T>::Set(const T& value)
//{
//    if (basePointer == nullptr) throw std::runtime_error("Instance point to nullptr.");
//    *basePointer = value;
//}
//
//template<typename T>
//void SmartPointer<T>::Release()
//{
//    if (basePointer == nullptr) throw std::runtime_error("Instance point to nullptr.");
//
//    if (--pointersCount == 0)
//    {
//        delete pointersCount;
//        delete basePointer;
//    }
//
//    basePointer = nullptr;
//}

#ifndef SMARTPOINTER_SMARTPOINTER_H
#define SMARTPOINTER_SMARTPOINTER_H

#include <cstddef>
#include <iostream>

template <typename T>
class SmartPointer
{
public:
    explicit SmartPointer(T* basePointer) : basePointer(basePointer) { }

    ~SmartPointer()
    {
        if (basePointer != nullptr) Release();
    }

    SmartPointer(const SmartPointer<T>& otherPointer)
    {
        if (basePointer != nullptr) Release();

        basePointer = otherPointer.basePointer;
        pointersCount = otherPointer.pointersCount;
        (*pointersCount)++;
    }

    SmartPointer<T>& operator=(const SmartPointer<T>& otherPointer)
    {
        if (basePointer != nullptr) Release();

        basePointer = otherPointer.basePointer;
        pointersCount = otherPointer.pointersCount;
        (*pointersCount)++;

        return *this;
    }

    T* const operator->() const
    {
        if (basePointer == nullptr) throw std::runtime_error("Instance point to nullptr.");
        return basePointer;
    }

    T operator*() const
    {
        if (basePointer == nullptr) throw std::runtime_error("Instance point to nullptr.");
        return *basePointer;
    }

    const T& Get() const
    {
        if (basePointer == nullptr) throw std::runtime_error("Instance point to nullptr.");
        return *basePointer;
    }

    void Set(const T& value)
    {
        if (basePointer == nullptr) throw std::runtime_error("Instance point to nullptr.");
        *basePointer = value;
    }

    void Release()
    {
        if (basePointer == nullptr) throw std::runtime_error("Instance point to nullptr.");

        if (--(*pointersCount) == 0)
        {
            delete pointersCount;
            delete basePointer;
        }

        basePointer = nullptr;
    }

private:
    T* basePointer = nullptr;
    size_t* pointersCount = new size_t(1);
};


#endif //SMARTPOINTER_SMARTPOINTER_H
