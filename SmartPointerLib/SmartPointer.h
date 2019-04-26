#ifndef SMARTPOINTER_SMARTPOINTER_H
#define SMARTPOINTER_SMARTPOINTER_H


template <typename T>
class SmartPointer
{
public:
    SmartPointer(T* basePointer);
    ~SmartPointer();
    SmartPointer(const SmartPointer<T>& otherPointer);
    SmartPointer<T>& operator= (const SmartPointer<T>& otherPointer);
    T* const operator->() const;
    T operator*() const;

    const T& Get() const;
    void Set(const T& value);
    void Release();

private:
    T* basePointer;
};


#endif //SMARTPOINTER_SMARTPOINTER_H
