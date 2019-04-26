#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include "../SmartPointerLib/SmartPointer.h"
#include "../SmartPointerLib/SmartPointer.cpp"

class TestClass
{
    int X;

public:

    size_t Count = 1;

    TestClass(const TestClass& Other)
    {
        X = Other.X;
        printf("New Test Object %d\n", X);
    }

    TestClass()
    {
        X = 0;
        printf("New Test Object 0\n");
    }

    explicit TestClass(int X1) : X(X1)
    {
        printf("New Test Object %d\n", X);
    }

    ~TestClass()
    {
        printf("Deleted Test Object, %d\n", X);
    }
};

TEST(SmartPointerTest, EmptyTests)
{
    SmartPointer<TestClass> p1(new TestClass(5));
    SmartPointer<TestClass> p2(new TestClass(10));
    p1 = p2;
    SmartPointer<TestClass> p3(p2);
}
