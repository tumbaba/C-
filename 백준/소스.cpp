#include <iostream>
#include <memory>
using namespace std;

void usePointer() {
    std::unique_ptr<int> Unique = std::make_unique<int>(100);

    // 원시 포인터를 가져오기
    int* Pointer = Unique.get();

    std::cout << "Value through unique_ptr: " << *Unique << std::endl;
    std::cout << "Value through raw pointer: " << *Pointer << std::endl;

    // unique_ptr이 scope를 벗어나면 자동으로 객체 메모리 해제
    // Unique는 이 시점에서 소멸되고 메모리는 해제됨
    // Pointer는 dangling pointer가 됨
}

struct FSharedTest : public std::enable_shared_from_this<FSharedTest>
{
    FSharedTest() {}
    FSharedTest(int InA) : A(InA) {}

    void Hello()
    {
        std::cout << "Hello " << A << std::endl;
    }

    int A = 100;
};

int main() {
    usePointer();

    shared_ptr<FSharedTest> Shared = make_shared<FSharedTest>(1234);

    {
        FSharedTest* Test = Shared.get();
        Test->Hello();
        Test->A = 123456;
        Test->Hello();
        shared_ptr<FSharedTest> SharedTest = Test->shared_from_this();
       
        Test->Hello();
        

        weak_ptr<FSharedTest> WeakTest = Test->weak_from_this();
        Shared.reset(); // reset을 한다고 하더라도 delete되는 것이 아니다! (해당 인스턴스의) 참조만 까는 것이다.
        SharedTest = nullptr; // 모든 참조가 nullptr 또는 reset 되어야 memory가 해제된다.
        // 따라서 내가 원하는 시점에 delete하기는 번거롭다
        if (WeakTest.expired())
        {
            std::cout << "expired!!\n";
        }
    }
}