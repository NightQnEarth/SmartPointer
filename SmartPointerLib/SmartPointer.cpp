#include "SmartPointer.h"

template<typename T>
SmartPointer<T>::SmartPointer(T* basePointer)
{

}

template<typename T>
SmartPointer<T>::~SmartPointer()
{

}

template<typename T>
SmartPointer<T>::SmartPointer(const SmartPointer<T>& otherPointer)
{

}

template<typename T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer<T>& otherPointer)
{
    return ;
}

template<typename T>
T* const SmartPointer<T>::operator->() const
{
    return nullptr;
}

template<typename T>
T SmartPointer<T>::operator*() const
{
    return nullptr;
}

template<typename T>
const T& SmartPointer<T>::Get() const
{
    return ;
}

template<typename T>
void SmartPointer<T>::Set(const T& value)
{

}

template<typename T>
void SmartPointer<T>::Release()
{

}
