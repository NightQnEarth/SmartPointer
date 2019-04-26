#ifndef SMARTPOINTER_SMARTPOINTER_H
#define SMARTPOINTER_SMARTPOINTER_H

#include <cstddef>

template <typename T>
class SmartPointer
{
public:
    explicit SmartPointer(T* basePointer);
    ~SmartPointer();
    SmartPointer(const SmartPointer<T>& otherPointer);
    SmartPointer<T>& operator= (const SmartPointer<T>& otherPointer);
    T* const operator->() const;
    T operator*() const;

    const T& Get() const;
    void Set(const T& value);
    void Release();

private:
    T* basePointer = nullptr;
    size_t& pointersCount;
};


#endif //SMARTPOINTER_SMARTPOINTER_H
