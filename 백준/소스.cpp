#include <iostream>
#include <memory>
using namespace std;

void usePointer() {
    std::unique_ptr<int> Unique = std::make_unique<int>(100);

    // ���� �����͸� ��������
    int* Pointer = Unique.get();

    std::cout << "Value through unique_ptr: " << *Unique << std::endl;
    std::cout << "Value through raw pointer: " << *Pointer << std::endl;

    // unique_ptr�� scope�� ����� �ڵ����� ��ü �޸� ����
    // Unique�� �� �������� �Ҹ�ǰ� �޸𸮴� ������
    // Pointer�� dangling pointer�� ��
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
        Shared.reset(); // reset�� �Ѵٰ� �ϴ��� delete�Ǵ� ���� �ƴϴ�! (�ش� �ν��Ͻ���) ������ ��� ���̴�.
        SharedTest = nullptr; // ��� ������ nullptr �Ǵ� reset �Ǿ�� memory�� �����ȴ�.
        // ���� ���� ���ϴ� ������ delete�ϱ�� ���ŷӴ�
        if (WeakTest.expired())
        {
            std::cout << "expired!!\n";
        }
    }
}