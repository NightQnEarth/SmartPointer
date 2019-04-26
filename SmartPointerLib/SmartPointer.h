//#ifndef SMARTPOINTER_SMARTPOINTER_H
//#define SMARTPOINTER_SMARTPOINTER_H
//
//#include <cstddef>
//
//template <typename T>
//class SmartPointer
//{
//public:
//    explicit SmartPointer(T* basePointer) : basePointer(basePointer), pointersCount(*new size_t(1)) { }
//    ~SmartPointer()
//    {
//        if (basePointer != nullptr) Release();
//    }
//    SmartPointer(const SmartPointer<T>& otherPointer)
//    {
//        if (basePointer != nullptr) Release();
//
//        basePointer(otherPointer.basePointer);
//        pointersCount(++otherPointer.pointersCount);
//    }
//    SmartPointer<T>& operator=(const SmartPointer<T>& otherPointer)
//    {
//        this(otherPointer);
//        return *this;
//    }
//    T* const operator->() const
//    {
//        if (basePointer == nullptr) throw std::runtime_error("Instance point to nullptr.");
//        return basePointer;
//    }
//    T operator*() const
//    {
//        if (basePointer == nullptr) throw std::runtime_error("Instance point to nullptr.");
//        return *basePointer;
//    }
//
//    const T& Get() const
//    {
//        if (basePointer == nullptr) throw std::runtime_error("Instance point to nullptr.");
//        return *basePointer;
//    }
//    void Set(const T& value)
//    {
//        if (basePointer == nullptr) throw std::runtime_error("Instance point to nullptr.");
//        *basePointer = value;
//    }
//    void Release()
//    {
//        if (basePointer == nullptr) throw std::runtime_error("Instance point to nullptr.");
//
//        if (--pointersCount == 0)
//        {
//            delete pointersCount;
//            delete basePointer;
//        }
//
//        basePointer = nullptr;
//    }
//
//private:
//    T* basePointer = nullptr;
//    size_t& pointersCount;
//};
//
//
//#endif //SMARTPOINTER_SMARTPOINTER_H
