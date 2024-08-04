

#include "Function.h"

using namespace std;


int GInt = 1234;
std::shared_ptr<FStruct> GShardPtrStruct;
std::weak_ptr<FStruct> GWeakPtrStruct;

int main()
{

#pragma region 01. 표준 입출력 (cout, cin)
	{
		
	}
#pragma endregion

#pragma region 02. 리터럴(literal)
    {
        // 리터럴은 코드에 표시한 숫나 문자열과 같은 값 을 의미
       
    }
#pragma endregion

#pragma region 03. 변수(Variable)*
    {
       
        // 형변환(Cast): 서로 다른 타입으로 변환
        // C++에는 타입(int, float, ...)있기 때문에 타입간 변환이
        // 필요한 상황이 발생합니다.
        {
            float Float{ 3.14f };
            int Int = Float;    // 묵시적 casting "경고"
            int Int2 = (int)Float; // 명시적 casting, C스타일 cast
            int Int3 = int(Float);  // 명시적 casting, C스타일
            int Int4 = static_cast<int>(Float); // C++ 버전의 명시적 Cast

            // 2Byte 정수
            short Short{ 10 };
            // 4Btye 정수
            int Int5 = Short; // 묵시적 casting
            // int(4Byte)가 short(2Byte)보다 더 크고,
            // 둘다 정수 타입이기 때문에 경고가 발생하지 않습니다.

            /*int Int6 = 999999;
            short Short1 = Int6;*/ // 값이 잘림!, 경고도 발생하지 않는데 주의해서 사용 해야 겠습니다.
        }
    }
#pragma endregion

#pragma region 04. 지역변수, 전역변수와 메모리
    {
        // 지역변수는 지금까지 사용한 바와 같이 스코프({})의 시작과 끝 내부에서 선언되는
        // 변수를 의미합니다.

        // 전역변수는 함수 밖에서 선언된 변수를 의미합니다.
        // 선언된 전역변수는 선언 이후에서는 스코프 내부에서 접근 가능
        GInt = 500;

        // 유저 영역의 메모리 공간은 크게 4구획을 나누어 져있다고 생각하시면 편합니다.
        // [코드 영역]   : 소스코드가 기계어로 변환되어 실제 로직을 수행하는 코드 정보
        // [데이터 영역] : 전역변수, static변수 등
        // [Heap]        : 동적 할당 (아직 배우지 않음)
        // [Stack]       : 지역 변수


        // [프로그램의 메모리 구조]
        // ---------------- 소스 코드 영역 -------------
        // ... 여러분 또는 누군가가 작성해둔 코드가 어셈으로 기록되어 있다
        // -----------------데이터 영역 ----------------
        // ... 전역변수, static(정적) 변수
        // ----------------- Heap 영역 -----------------
        // ... 동적 할당 (실행 중에 메모리 요청을 하는 것)
        // ..
        // ..
        // 
        // 
        // 
        // 
        // (RBP + 상대주소(0)) [a] (4byte)
        // (RBP + 상대주소(1)) [b] (4byte)
        // (RBP + 상대주소(2)) [c] (4byte)
        // (RBP + 상대주소(3)) [d] (4byte)
        // (RBP + 상대주소(4)) [e] (4byte)
        // (함수의 변수목록의 시작주소인 RBP 기준으로 + 상대 주소)
        // ....
        // --------------- Stack 영역 ------------------

        /*
        [Code 영역]
        {
            (0x00007FF7AF454FB3) Main함수 기준점으로 부터 Stack의 시작 지점으로 부터 일정 위치가 떨어진 곳에 1을 넣어라
        }

        [Stack 영역]
        {
            - Main의 stack 시작 위치
            - (0x00000003FA99F7A8)a = 10
            - b = ...
        }
        */
        int a, b, c, d, e, f, g, h, i, j, k;

        a = 10;
        b = 20;
        c = 30;
        d = 40;
        e = 50;
    }
#pragma endregion

#pragma region 05. 연산자들
    {



        // 비트 단위 연산
        {
            // AND 연산
            {
                // 둘다 1이면 결과가 1
                // 하나라도 0이면 결과가 0
                // 
                // 0010 = 2
                // 1111 = 2^3 + 2^2 + 2^1 + 2^0 = 8 + 4 + 2 + 1 = 15
                // --------- AND
                // 0010 = 2
                char c1 = 0b0010;
                char c2 = 0b1111;
                char c3 = c1 & c2; // 2
            }
            // OR 연산
            {
                // 둘중에 하나라도 1이면 결과가 1
                // 둘다 0이면 결과가 0
                //
                // 0010         // 2
                // 1110         // 14
                // --------- OR
                // 1110         // 14
                char c1 = 0b0010;
                char c2 = 0b1110;
                char c3 = c1 | c2; // 14
            }
            // XOR 연산 (exclusive or)
            {
                // 서로 다르면 결과가 1
                // 서로 같으면 결과가 0
                //
                // 0010
                // 1111
                // -------- XOR
                // 1101         // 2^3 + 2^2 + 2^0 = 13

                char c1 = 0b0010;
                char c2 = 0b1111;
                char c3 = c1 ^ c2; // 13

                // 1101
                // 0010
                // -------- XOR
                // 1111
                c3 = c3 ^ c1;
                c3 = c3 ^ c1;
                c3 = c3 ^ c1;
                c3 = c3 ^ c1;
                c3 = c3 ^ c1;
            }

            // 비트 이동(shift) 연산
            {
                // 왼쪽으로 비트 이동
                {
                    // 0000 0001
                    // 왼쪽으로 한칸 이동
                    // 0000 0010
                    unsigned char C0 = 5;       // 0000 0101 : 5
                    unsigned char C1 = C0 << 1; // 0000 1010 : 8 + 2 = 10
                    unsigned char C2 = C0 << 2; // 0001 0100 : 20
                    unsigned char C3 = C0 << 3; // 0010 1000 : 40
                    unsigned char C4 = C0 << 4; // 0101 0000 : 80
                    unsigned char C5 = C0 << 5; // 1010 0000 : 160
                    unsigned char C6 = C0 << 6; // 0100 0000 : 64
                    unsigned char C7 = C0 << 7; // 1000 0000 : 128
                    unsigned char C8 = C0 << 8; // 0000 0000 : 0
                }
                // 오른쪽으로 비트 이동
                {
                    unsigned char C0 = 80;      // 0101 0000 : 80
                    unsigned char C1 = C0 >> 1; // 0010 1000 : 40
                    unsigned char C2 = C0 >> 2; // 0001 0100 : 20
                    unsigned char C3 = C0 >> 3; // 0000 1010 : 10
                    unsigned char C4 = C0 >> 4; // 0000 0101 : 5
                    unsigned char C5 = C0 >> 5; // 0000 0010 : 2
                    unsigned char C6 = C0 >> 6; // 0000 0001 : 1
                    unsigned char C7 = C0 >> 7; // 0000 0000 : 0
                    unsigned char C8 = C0 >> 8; // 0000 0000 : 0
                }
                // 음수의 경우 비트 이동이 조금 다르게 동작
                {
                    // MSB(Most Significant Bit) '1'111 1111
                    char C0 = -1;       // 1111 1111 : -1
                    {
                        char C1 = C0 >> 1;  // 1111 1111 : -1
                    }
                    {
                        char C1 = C0 << 1;  // 1111 1110 : -2
                        char C2 = C0 << 2;  // 1111 1100 : -4
                        char C7 = C0 << 7;  // 1000 0000 : -128
                        char C8 = C0 << 8;  // 0000 0000 : 0
                    }
                }
            }
        }

        // 삼항 연산자(temary operator) / 조건 연산자
        {
            int i = 0;

            //      (조건문) ? 참일때 : 거짓일때
            // 조건을 만족하면 : 기준으로 왼쪽 결과
            // 조건을 만족하지 않으면 : 기준으로 오른족 결과
            int k1 = (i == 0) ? 10 : -10;
            int k2 = (i != 0) ? 10 : -10;
        }

        // 연산자 우선순위
        {
            int i1 = 10 - 5 * 5; // 10 - 25 = -15
            int i2 = (10 - 5) * 5; // 5 * 5 = 25
        }
    }
#pragma endregion

#pragma region 06. 열거형(enum; enumerated type; 이넘)*
    {
        {
            const int Iron = 0;
            const int Bronze = 1;
            const int Silver = 2;
            const int Gold = 3;

            int MyTier = Gold;
            if (MyTier == Gold)
            {
                std::cout << "골드 티어 입니다.\n";
            }
        }
        {
            enum class ETier : unsigned char
            {
                Iron,
                Bronze /*= 10*/,
                Silver,
                Gold,
            };

            unsigned char MyTier = (unsigned char)ETier::Gold;
            ETier MyTier2 = ETier::Silver;
            ETier MyTier3 = (ETier)3; // ETier::Gold
            if (MyTier2 == ETier::Silver)
            {
                std::cout << "실버 티어 입니다.\n";
            }
            if (MyTier2 == ETier::Gold)
            {
                std::cout << "골드 티어 입니다.\n";
            }
        }
    }
#pragma endregion

#pragma region 07. 구조체(struct)***
    {
        enum class ETier : unsigned char
        {
            None,
            Iron,
            Bronze,
            Silver,
            Gold,
        };

        int HP = 10;
        int MP = 20;
        ETier Tier = ETier::None;
        //HP = 20;

        struct FPlayer
        {
            int HP = 10;
            int MP = 20;
            ETier Tier = ETier::None;
            // 3Byte padding
        };

        // FPlayer: 구조체 타입 (구조체: 데이터를 묶어둠)
        // Player: 인스턴스(instance; 실체화된 사례) (메모리에 만들어진 것)
        FPlayer Player{ .MP = 100, .Tier = ETier::Gold };
        FPlayer Player2;
        Player2.HP = 200;
        Player2.MP = 300;
        Player2.Tier = ETier::Iron;



#pragma pack(push, 1)
        struct FPadding
        {
            char C;
            // 3Byte padding이 숨겨져 있다
            // 지금 가장 큰 기본 자료형 크기가 4Byte라서 4Byte padding이 잡힌다

            int I;

            char C1;
            // 3Byte padding이 잡힌다.
            // 이런 상황을 피하려면 padding을 고려해서 C1 변수를 C아래쪽으로 옮겨야
            // 낭비되는 byte를 줄일 수 있다.
        };
        /*struct FPadding1
        {
            char C1;
            int I;
        };*/
#pragma pack(pop)

        /*struct FPadding2
        {
            char C1;
            int I;
        };*/

        // 64bit(8Byte) 환경에서 한번에 접근해서 연산할수 있는 최대 단위가 8Byte
        // padding을 비활성화 해서 다음과 같은 경우
        // char / dobule (9Byte)
        // [00] / [00 00 00 00 00 00 00 00]
        // [00] / [00 00 00 00 00 00 00]    // [00]  // double을 읽어오기 위해서 2번 접근할 수 있다.

        // padding을 넣게 되면
        // [00] 00 00 00 00 00 00 00 / [00 00 00 00 00 00 00 00]

        // double에 값을 쓰거나 읽으려고 했을때 padding이 잡혀있지 않으면
        // 2번 접근해야 하는 상황이 발생할 수 있다.
        // 그렇기 때문에 읽고 쓰는 속도가 느려질 수 있다.
    }
#pragma endregion

#pragma region 08. 조건문(if / switch)***
    {

    }
#pragma endregion

#pragma region 09. 논리 연산자**
    {

    }
#pragma endregion

#pragma region 10. 함수(fucntion)***
    {
        // 규모가 큰 프로그램에서 모든 코드를 main함수 안에 담게 되면
        // 관리적인 측면에서 힘들 것 같습니다.
        // 코드 가독성(읽기 쉬운 정도)을 높히려면 코드를 간결하고 명확한
        // 함수 단위로 나는 것이 좋겠습니다.

        // C++에서 함수를 사용하려면 먼저 함수 선언을 해야합니다.
        // 반환타입    함수이름      (입력 파라미터(옵션; 있어도 되고 없어도 됨))
        // void       FunctionName (int a, int b)

        // 디버거가 붙어 있는 상황에서 F11을 눌러서 함수 내부로
        // 진입할 수 있다.

        // 함수도 시작 주소가 있습니다.
        // 함수를 호출한다는건
        // >> 돌아올 다음주소를 Stack에 Backup 해두고
        // >> 호출할 함수의 주소로 이동
        // >> 함수 수행
        // >> ret을 만나면 Backup해둔 주소로 이동
        FunctionName(10, 20);

        // 이 함수를 호출하는 위치 기준으로 이 라인보다 위에 함수가
        // 있다는 것을 알려주지 않으면 함수를 찾을 수 없습니다.
        Function2();

        // 콜링 컨벤션(Calling Conventions)
        // 함수를 호출하는 방식
        // __cdecl, __stdcall, __thiscall, __fastcall

        int Result = AddFunction(10, 20);

        // 파라미터를 던지는 경우 특정 레지스터(메모리)에 값을 backup 했다가
        // 함수 내부로 진입해서 그 레지스터(메모리)에서 다른 메모리로 값을 복원한다
        // 추가적으로 함수로 이동하는 과정 (비용) 추가적으로 발생
        // 함수 호출의 오버해드라고 표현 합니다.
        int a = 10, b = 20;
        // int InA = a;
        // int InB = b;
        int Result2 = AddFunction(a, b);
        double Result3 = AddFunction(10.34, 3.14);

        // 재귀 함수 호출이 많이 발생하는 경우
        // Debug 설정일 때 함수 호출 오버해드로 인해서
        // 한번의 함수 호출로 구현해둔 함수에 비해 느릴 수 있다.
        unsigned long long Result4 = Factorial(10);
        std::cout << Result4 << std::endl;
    }
#pragma endregion

#pragma region 11. Bit flag
    {
        unsigned char Property1 = EPropertyFlags::EProperty1;
        HasFlags(Property1);
        unsigned char Property3 = EPropertyFlags::EProperty3;
        HasFlags(Property3);

        // 0000 0001
        // 0000 0100
        // --------- OR
        // 0000 0101
        unsigned char Property13 = EPropertyFlags::EProperty1 | EPropertyFlags::EProperty3;
        HasFlags(Property13);

        unsigned char Property135 = Property13;
        //Property135 = Property135 | EPropertyFlags::EProperty5;
        Property135 |= EPropertyFlags::EProperty5;
        HasFlags(Property135);

        unsigned char Property35 = Property135;

        // EPropertyFlags::EProperty1 : 0000 0001
        // ~EPropertyFlags::EProperty1: 1111 1110
        // 0001 0101
        // 1111 1110
        // --------- AND
        // 0001 0100

        Property35 = Property35 & ~EPropertyFlags::EProperty1;
        HasFlags(Property35);

        // 0000 0010
        // 0000 1000
        // ---------- OR
        // 0000 1010
        unsigned char Toggle = EProperty2 | EProperty4;
        HasFlags(Toggle);

        // 0000 1010 (2, 4)
        // 0000 1000 (4)
        // --------- XOR (같으면 0 다르면 1)
        // 0000 0010 (2)
        Toggle ^= EProperty4;
        HasFlags(Toggle);
        // 0000 0010 (2)
        // 0000 1000 (4)
        // --------- XOR
        // 0000 1010 (2,4)
        Toggle = Toggle ^ EProperty4;
        HasFlags(Toggle);

        unsigned char Flags = EPropertyFlags::ENone;
        // 지정
        Flags = EProperty1;

        // 켜기
        Flags |= EProperty2;

        // 끄기
        Flags &= ~EProperty2;

        // 토글(껏다 켰다)
        Flags ^= EProperty3;    // 켜짐
        Flags ^= EProperty3;    // 꺼짐
        Flags ^= EProperty3;    // 켜짐
        Flags ^= EProperty3;    // 꺼짐
    }
#pragma endregion

#pragma region 12. 배열(array)
    {

    }
#pragma endregion

#pragma region 13. 반복문(loop)**
    {

    }
#pragma endregion

#pragma region 14. 포인터와 동적 할당(pointer*****, dynamic allocation) + 레퍼런스*****(Reference; 참조)
    {
     // 메모리 할당과 이를 관리하는 것은 C++프로그래밍에서 문제가 발생하기 쉬운 영역입니다.
     // 품질이 뛰어난 C++프로그램을 작성하기 위해서는 메모리 내부 작동 방식을 이해하고 있어야 합니다.
     // 이번 시간에는 동적 메모리를 다루는 과정에서 어떤 위험에 빠지기 쉬운지 알아보고 이런 상황을
     // 해결하거나 애초에 방지하는 방법을 알아보겠습니다.
     
     // low-level(저수준; 낮은수준) 메모리 연산 방법은 new, new[], delete, delete[]
     // 또는 C스타일의 malloc(memory allocation), free라는 함수를 사용하는 방법이 있습니다.
     // 요즘 와서는 로우레벨 메모리 연산을 최대한 피하는 추세라고 생각됩니다.
     // 저도 실무에서 활동할때 저수준의 동적 할당을 사용했던 적이 몇번 없었던 것 같습니다.
     // 예를 들면 표준 라이브러리에서 제공하는 vector라는 컨테이너(동적 배열)가 있는데
     // 이를 사용하면 필요할 때 메모리를 늘리거나 줄일 수 있습니다.
     // 또는 동적으로 할당한 메모리를 사용하지 않으면 자동으로 해제해주는 shared_ptr 등의
     // 스마트 포인터를 사용하기도 합니다.
     
     // 동적 메모리를 이용하면 컴파일 시간에 크기를 확정할 수 없는 데이터를 다룰 수 있습니다.
     
    // 실행시간(런타임;Run time)에 동적으로 메모리 공간이 필요한 경우 OS(운영체제; Operating System)
      // 에 메모리를 요청해야 하는데, 이런 과정에서 커널에 요청할 필요가 있습니다.
      // 커널은 OS 중 항상 메모리에 올라가 있는 운영체제의 핵심 부분으로, 하드웨어와 응용 프로그램
      // 사이에서 인터페이스 역할을 제공합니다.
      // 커널에 요청하는 경우 이를 system call이라고 합니다. (메모리 할당을 할때마다 system call이 발생
      // 하지는 않을 수 있습니다)
      // 이 system call은 유저 영역과 커널 영역을 넘나드는 호출로서 상당한 비용을 지불하게 됩니다.
     
//////////////////////////////////////////////////////////////////////////////////////
     //힙 메모리를 할당하고 포인터가 스코프를 벗어나는 경우, 해당 메모리 블록에 대한 접근이 사라질 수 있습니다.
     // 이 경우, 메모리 누수가 발생할 수 있으며, 메모리가 해제되지 않고 계속 점유됩니다.
    //포인터가 스코프를 벗어나는 경우: 포인터 자체는 스코프를 벗어나면 더 이상 유효하지 않습니다.
    // 그러나 포인터가 가리키는 메모리가 힙 영역에 할당된 경우, 해당 메모리는 명시적으로 해제되기 전까지 계속 존재합니다.
//////////////////////////////////////////////////////////////////////////////////////

    // https://en.wikipedia.org/wiki/Magic_number_(programming)

    // 댕글링 포인터: 이미 해제된 메모리 주소를 들고 있는 상황
    // 이떄 해당 memory에 write하는 경우 프로그램이 죽을수도 있고
    // 잘 동작 할 수 도 있다. 하지만 잠재적인 위험이 아주 높다.
    // 가끔 잘 동작하다가 죽는 버그 원인을 찾았더니 댕글링 포인터가 원인인
    // 경우들이 종종 발견 됩니다.


        int a = 0;
        int b = 999;
        int* Pointer = &a;
        int* inPointer = Pointer;
        *inPointer = 1234;
        *Pointer = 1234;

        int* const PointerLikeReference = &a;
        // PointerLikeReference = &b; // * 오른쪽에 const가 붙어 있으면 가리키던 대상을 바꿀 수 없다
        *PointerLikeReference = 10000;
        const int* ConstPointer = &a; // * 왼쪽에 const가 붙어 있으면 가리키던 대상의 값을 바꿀 수 없다.
        //*ConstPointer = 9999;
        ConstPointer = &b;

        const int* const PointerCantChnage = &a; // 둘다 변경 불가!
        /*PointerCantChnage = &b;
        *PointerCantChnage = 1000;*/

        //int* const PointerLikeReference = &a;
        //이거와 비슷
        int& Reference = a; // 처음 초기화 시점에 반드시 대상이 와야하며, 이후 변경할 수 없다.
        Reference = b;      // 주소가 바뀌는 것이 아니라, 처음 연동한 a의 값이 b에 있는 값(1234)로 변경 된다.
        // Reference = &b;  // 이후 가리키던 주소를 변경할 수 없다.

        // 메크로라고 하고
        // 왼쪽에 있는 이름으로 사용하고, 이는 오른쪽으로 대체된다
        #define SAFE_DELETE(Var) delete Var;\
        	Var = nullptr;
        #define Wow int
        #define HI std::cout <<"Hi~\n";
        #define Hmm(a, b) a < b



    }
#pragma endregion

#pragma region 15. SmartPointer**
    {
#include <memory>
        // unique_ptr
        {
            // unique_ptr 생성 및 역참조
            // 소멸자 호출이 되면서 Heap memory를 delete 한다
            {
                unique_ptr<int> Unique = make_unique<int>(100);
                *Unique = 1000;
            }
            // 다른 unique_ptr에 대입을 할 수 없다.
            {
                unique_ptr<int> Unique = make_unique<int>(100);
                *Unique = 1000;
                //unique_ptr<int> Unique2 = Unique;
                int* Pointer = Unique.get();
                *Pointer = 999;
                CallByPointer(Unique.get());
                TestUnique(Unique);
                TestUnique(&Unique);

                // 소유권 이전을 통해서 unique_ptr 전달 가능
                unique_ptr<int> Unique2 = std::move(Unique);
                int* Pointer2 = Unique.get();
                int* Pointer3 = Unique2.get();

                //GUnique = move(Unique2);

                //std::unique_ptr와 get() 함수
                //get() 함수는 std::unique_ptr가 관리하는 객체의 원시 포인터(raw pointer)를 반환합니다.
                // 이 함수는 unique_ptr가 소유하는 객체에 대한 직접적인 접근을 제공하지만, unique_ptr의 소유권을 직접적으로 변경하지 않습니다.
                //소유권과 메모리 관리:
                // get()으로 반환된 원시 포인터를 통해 객체에 접근할 수 있지만, 이 포인터를 사용하여 객체를 해제하거나 소멸시키면 안 됩니다.
                // 객체의 해제는 unique_ptr이 자동으로 수행해야 합니다.
                // 원시 포인터를 사용하여 객체에 접근할 때는 주의가 필요합니다.
                // 객체가 소멸된 후에 원시 포인터를 사용하면 정의되지 않은 동작을 초래할 수 있습니다.\

                // 유니크포인터가 해제 되면 get을 통해 접근을 얻은 변수도 해제 접근 권한을 잃는다.

                // unique_ptr이 scope를 벗어나면 자동으로 객체 메모리 해제
                //GUnique = move(Unique2);
            }
            //int* Test222 = GUnique.get();




            // shared_ptr
            {
                // 레퍼런스 카운팅 방식으로, 참조 횟수를 저장하고 있다가
                // 0이되면 실제로 Memory를 delete한다
                shared_ptr<int> SharedPtr;
                {
                    shared_ptr<int> Shared = make_shared<int>(100);
                    long Count = Shared.use_count();
                    shared_ptr<int> Shared2 = Shared;
                    long Count2 = Shared.use_count();
                    SharedPtr = Shared;
                    long Count3 = Shared.use_count();

                    TestShared(Shared);
                }
                long Count4 = SharedPtr.use_count();
                {
                    shared_ptr<FParam> Shared = make_shared<FParam>();
                    shared_ptr<FParam> Shared2 = Shared;
                }
                {
                    std::array<shared_ptr<FParam>, 10> Vector;
                    for (size_t i = 0; i < 10; ++i)
                    {
                        Vector[i] = make_shared<FParam>();
                    }
                }
            }
            // shared_ptr + weak_ptr
            {
                weak_ptr<FParam> Weak;
                {
                    shared_ptr<FParam> Shared = make_shared<FParam>();
                    shared_ptr<FParam> Shared2 = Shared;
                    Weak = Shared;
                    TestWeak(Shared);
                    TestWeak(Weak);
                }

                if (!Weak.expired())
                {
                    cout << "";
                }
                TestWeak(Weak);
            }

            // weak_ptr::lock()
            // std::weak_ptr가 관리하는 객체가 여전히 유효한지 확인하고, 객체가 유효하다면 std::shared_ptr로 변환합니다.
            // 
            // weak_ptr::expired()는 std::weak_ptr가 참조하는 객체가 이미 소멸되었는지 확인하는 함수입니다.
            // 반환 타입 : bool



            // shared_ptr -> .get()으로 Pointer를 뽑아온 다음에
            // 그 Pointer를 다시 shared_ptr로 바꾸는 방법
            {
                shared_ptr<FSharedTest> Shared = make_shared<FSharedTest>(1234);

                {
                    FSharedTest* Test = Shared.get();
                    Test->Hello();
                    Test->A = 123456;
                    Test->Hello();
                    shared_ptr<FSharedTest> SharedTest = Test->shared_from_this();
                    SharedTestFunction(SharedTest);
                    Test->Hello();
                    SharedTestFunction(Test->shared_from_this());

                    weak_ptr<FSharedTest> WeakTest = Test->weak_from_this();
                    SharedTest.reset(); // reset을 한다고 하더라도 delete되는 것이 아니다! (해당 인스턴스의) 참조만 까는 것이다.
                    Shared = nullptr; // 모든 참조가 nullptr 또는 reset 되어야 memory가 해제된다.
                    // 따라서 내가 원하는 시점에 delete하기는 번거롭다
                    if (WeakTest.expired())
                    {
                        std::cout << "expired!!\n";
                    }
                }
            }
        }
    }
#pragma endregion

#pragma region 16. RVO(Return Value Optimization), NRVO(Named Return Value Optimization)
    {
        /*RVO (Return Value Optimization)와 NRVO (Named Return Value Optimization)
          RVO와 NRVO는 C++ 컴파일러 최적화 기법으로, 함수의 반환 값과 관련된 불필요한 객체 복사를 줄여 성능을 향상시키는 데 중요한 역할을 합니다.
          
          FOddsAndEvens SeperateOddsAndEvens(const std::array<int, 10>& const InNumbers)
{
    // RVO
    std::vector<int> Odds, Evens;
    for (int Value : InNumbers)
    {
        std::cout << Value << std::endl;

        // 홀수 판정
        // 1 / 2: 몫:0 나머지:1 => 홀수
        // 2 / 2: 몫:0 나머지:0 => 짝수
        // 3 / 2: 몫:1 나머지:1 => 홀수
        // 4 / 2: 몫:2 나머지:0 => 짝수
        if (Value % 2 == 1) // 홀수(나머지가 1)
        {
            Odds.push_back(Value);
        }
        else if (Value % 2 == 0) // 짝수(나머지가 0)
        {
            Evens.push_back(Value);
        }
        else
        {
            // 혹시 여기 들어오면 한번 쯤 봐야겠다...
            _ASSERT(false);
        }
    }

    return FOddsAndEvens(Odds, Evens);
}



          Return Value Optimization (RVO)
          RVO는 함수가 객체를 반환할 때, 컴파일러가 중간의 임시 객체 생성을 생략하고,
          반환 객체를 호출자가 제공한 메모리 공간에 직접 생성하는 최적화입니다. 이는 임시 객체의 생성과 소멸을 줄여 성능을 향상시킵니다.

          FOddsAndEvens SeperateOddsAndEvens2(const std::array<int, 10>& const InNumbers)
{
    // NRVO
    FOddsAndEvens OddsAndEvens;
    for (int Value : InNumbers)
    {
        std::cout << Value << std::endl;

        // 홀수 판정
        // 1 / 2: 몫:0 나머지:1 => 홀수
        // 2 / 2: 몫:0 나머지:0 => 짝수
        // 3 / 2: 몫:1 나머지:1 => 홀수
        // 4 / 2: 몫:2 나머지:0 => 짝수
        if (Value % 2 == 1) // 홀수(나머지가 1)
        {
            OddsAndEvens.Odds.push_back(Value);
        }
        else if (Value % 2 == 0) // 짝수(나머지가 0)
        {
            OddsAndEvens.Evens.push_back(Value);
        }
        else
        {
            // 혹시 여기 들어오면 한번 쯤 봐야겠다...
            _ASSERT(false);
        }
    }
    return OddsAndEvens;
}
        */
    }
#pragma endregion

#pragma region 17. Memory 누수(leak, 릭) 탐지
    {
        _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
        //_crtBreakAlloc = 405;  이걸로 누수되는 위치를 찾을 수 있다.
        int* Pointer = new int(10);
        delete Pointer;

        double* DoublePointer = new double(3.14);
        delete DoublePointer;
    }
#pragma endregion

#pragma region 18. 구조적 바인딩(structured binding)
    {
        // 생성자가 없는 경우 사용 가능
        struct FStruct
        {
            // FStruct() {}
            // FStruct(int InA) : a(InA) {}
            int a = 0;
            int b{ 10 };
            int c = 20;
        };

        FStruct Instance{};
        FStruct Instance2{ .a = 10 };
        FStruct Instance3{ .b = 20, .c = 100 };
    }
#pragma endregion

#pragma region 19. 타입 앨리어스(type alias)
    {
        typedef int Hello;
        int a = 50;
        Hello b = 500;

        typedef int* IntPtr;
        IntPtr aa = nullptr;
        aa = &a;

        // 타입 앨리어스
        using Hello2 = int;  //     이거
        Hello2 cc = 100;

        using V = std::vector<int>;  //이거
        V vv = V{ 1,2,3,4,5 };
        vv.push_back(100);
        std::vector<int> vvv = std::vector<int>{ 1,2,3,4,5 };
    }
#pragma endregion

#pragma region 20. 문자열(string)**
    {
        // [Stack]                                      // [data]
        // [0xfff..] Text(8Byte) = 0x100...             (0x100...)"Hello World!"
        const char* Text = "Hello World!";
       //문자열은 변수가 달라도 값이 같으면 같은 주소를 가진다.

        std::wstring WString = L"Hello 한글 こんにちは 哈罗 صباح الخير\n";
        WString[6] = L'갈';
        std::wstring WString2 = TEXT("Hello 한글 こんにちは 哈罗 صباح الخير\n");
    }
#pragma endregion

#pragma region 21. Class(클래스)*****
    {
        // 구조체: 함수랑 변수를 묶어서 관리
        struct FStruct
        {
            // 접근지정자
            // 기본 접근지정자: public
        public:

// 생성자: 인스턴스가 만들어질 때 호출
//      - 전역변수(Data): 프로그램이 시작할 때
//      - 지역변수(Stack): FStruct Instance; 이 코드가 실행되는 시점
//      - 동적할당(Heap): new를 호출하는 경우
FStruct()
{
    a = 1234;
    this->b = 6666;
}

// 소멸자: 인스턴스의 수명이 끝날 때 호출
//      - 전역변수(Data): 프로그램이 종료되기 전
//      - 지역변수(Stack): 스코프({})를 벗어나는 경우
//      - 동적할당(Heap): delete를 호출하는 경우
~FStruct()
{

}

int a = 0;
        private:    // 외부에서는 접근 불가
            int b = 20;
        };

        // Code 영역에 함수
        // 생성자() 코드
        // 소멸자() 코드

        // instance는
        // [int a = 0]
        // [int b = 20]
        FStruct Instance;
        Instance.a = 999;
        //Instance.b = 1234;

        class FClass
        {
            // 접근지정자
            // 기본 접근지정자: private
        public:
            FClass()
            {
            }

            FClass(const int NewB)
                : b(NewB) {}

            ~FClass() {}

            void Hello()
            {
                SetB(999);
                std::cout << std::format("A: {}, B: {}\n", a, b);
            }

            void SetA(const int NewA)
            {
                this->a = NewA;
            }

            [[nodiscard]] int GetA() const
            {
                // 함수 선언 뒤에 const를 붙히면
                // this pointer가 const this*로 된다.
                // 즉 맴버 변수를 수정할 수 없고
                // 맴버 함수는 const가 동일하게 붙어있는 맴버 함수만 호출 할 수 있다.
                //SetA(10);
                //int bb = GetB();

                return this->a;
            }

            [[nodiscard]] int GetB() const
            {
                return b;
            }

        private:
            void SetB(const int NewB)
            {
                b = NewB;
            }

            int a = 0;
            int b = 10;
        };

        FClass ClassInstance;
        ClassInstance.SetA(100);
        int A = ClassInstance.GetA();
        int B = ClassInstance.GetB();
        FClass ClassInstance2 = FClass(1234);
        int B2 = ClassInstance2.GetB();
        ClassInstance2.Hello();
        B2 = ClassInstance2.GetB();
    }
#pragma endregion

#pragma region 01-01 memory 동적할당
    {

        int** DoublePointer{ nullptr };

        // Stack                                // Heap
        // [8Byte]Pointer{0xHeapAddress} -----> [8Byte]*DoublePointer{trash(0xcdcdcdcdcdcdcdcd)}
        DoublePointer = new int*;

        // Stack                                // Heap
        // [8Byte]Pointer{0xHeapAddress} -----> [8Byte]*DoublePointer{0xHeapAddress}
        //                                          ∇
        //                                      [4Byte]**DoublePointer{10}
        *DoublePointer = new int{ 10 };

        **DoublePointer = 1234;
        // Double Pointer tip(COM; Component Object Model 공부 해보시면 도움이 됩니다)
        {
            int* Pointer = nullptr;
            /*int* InPointer = Pointer;
            int* InPointer = nullptr;
            InPointer = new int;*/
            //AllocateWrong(Pointer);
            AllocateCorrect(&Pointer);
            int* Pointer2 = nullptr;
            AllocateCorrect2(Pointer2);
            //Deallocate(Pointer);
            Deallocate2(&Pointer);
            Deallocate2(&Pointer2);
            //delete Pointer;
        }

    }
#pragma endregion

#pragma region 01-01 memory 배열
    {
        // 함수에 배열을 포인터로 전달
        {
            int Array[1000]{};
            InitArray(Array, 1000);

            // 버퍼 오버플로우: 지정된 공간을 넘어서 데이터를 씀
            //InitArray(Array, 2000);
            //int Array2[1000];
        }
        

    }
#pragma endregion

#pragma region 01-01 memory 스마트 포인터
    {
        // 함수에 배열을 포인터로 전달
        {
            int Array[1000]{};
            InitArray(Array, 1000);

            // 버퍼 오버플로우: 지정된 공간을 넘어서 데이터를 씀
            //InitArray(Array, 2000);
            //int Array2[1000];
        }

        // Smart Pointer
        {
            // unique_ptr
            {
                // 단 하나의 동적할당된 인스턴스만 동시에 존재할 수 있다
                std::unique_ptr<int> Unique = std::make_unique<int>(10);
                *Unique = 1000;
                *Unique.get() = 1234;
            }
            // unique_ptr custom deleter
            {
                std::unique_ptr<int, decltype(&CustomDeleterInt)> Unique(new int(124), CustomDeleterInt);
            }
            {
                FStruct Struct = FStruct();
                FStruct Copy = FStruct(Struct);
                Copy = Struct;

                std::unique_ptr<FStruct> Unique = std::make_unique<FStruct>(10);
                std::unique_ptr<FStruct> UniqueCopy = std::make_unique<FStruct>(Unique);
                UniqueCopy->SetValue(1234);
                std::unique_ptr<FStruct> UniqueCopy2 = std::make_unique<FStruct>(*UniqueCopy);

                std::unique_ptr<FStruct> UniqueTest = move(Unique);
            }
            // shared_ptr
            {
                //std::shared_ptr<int> SharedPtr{ std::make_shared<int>(100)};
                std::shared_ptr<int> SharedPtr{ new int, CustomDeleterInt };
                std::shared_ptr<int> SharedPtr2 = SharedPtr;
                long Count = SharedPtr.use_count();
            }
            {
                std::shared_ptr<FStruct> SharedPtr = std::make_shared<FStruct>(10);
                GShardPtrStruct = SharedPtr;
                //GWeakPtrStruct = GShardPtrStruct;
                SharedParam(GShardPtrStruct);
                GShardPtrStruct = nullptr;
                SharedPtr.reset();
                WeakParam(GWeakPtrStruct);
            }
        }


    }
#pragma endregion

#pragma region 01-01 memory auto
    {
       // 컴파일러가 타입을 추론할 수 있는 경우 타입을 추론해주는 기능
       // 컴파일러가 타입을 추론해야 하기 때문에 컴파일 시간이 살짝 늘어나는 단점
       // (하지만 소소하게 쓰면 의미 없는 시간 이다)
    }
#pragma endregion

#pragma region 01-01 memory 함수 포인터(Function Pointer)
    {
        // 함수도 주소가 부여되어 있다.
        // C++에서는 함수의 주소를 구해서 변수처럼 사용할 수 있다.
        {
            bool(*FunctionName)(void) = ReturnTrue;
            bool bResult = FunctionName();
            FunctionName = ReturnFalse;
            bResult = FunctionName();

            using FFunctionPointer = bool(*) ();
            FFunctionPointer FunctionTest = ReturnTrue;
            bool bResult2 = FunctionTest();
            FunctionTest = ReturnFalse;
            bResult2 = FunctionTest();
        }
        {
            std::function Function = ReturnTrue;
            std::function<bool()> Function2 = ReturnTrue;
            bool bResult = Function2();
            Function2 = ReturnFalse;
            bResult = Function2();
        }
        {
            std::function<int(int, int)> Function = SumFunction;
            //std::function<int(int, int)> Function2 = ReturnTrue;
            int Result = Function(10, 20);
            int Result2 = Function(30, 20);
        }
        {
            FStruct Instance;
            Instance.SetValue(100);

            // 맴버 함수의 경우
            // 입력 인자가 있는 경우 std::placeholders::_1, std::placeholders::_2, ...
            // 인자의 갯수 만큼 뒤에 추가로 붙혀 주어야 한다
            //std::function<void(int)> Function = std::bind(&FStruct::SetValue, &Instance, std::placeholders::_1);
            auto Function = std::bind(&FStruct::SetValue, &Instance, std::placeholders::_1);
            Function(1234);
            std::function<void()> Function2 = std::bind(&FStruct::Hello, &Instance);
            Function2();
            //auto Function2 = std::bind(&FStruct::Hello, &Instance);
        }
    }
#pragma endregion

#pragma region 01-01 memory 람다(Lambda)
    {
        // 이름 없는 함수라고 부르기도 함
        {
            // 이렇게 선언만 하면 호출 불가!
            []()
                {
                    std::cout << "Lambda Function!\n";
                };

            []()
                {
                    std::cout << "Lambda Function!\n";
                }(); // () 를 여기에 추가하면 함수 호출 가능

            std::function Lambda = []()
                {
                    std::cout << "Lambda Function!\n";
                };

            for (int i = 0; i < 10; ++i)
            {
                //std::cout << "Lambda Function!\n";
                Lambda();
            }

            Lambda();
            //std::cout << "Lambda Function!\n";
        }
        // 람다를 사용해서 파라미터 처리
        {
            std::function Lambda = [](const int InVale)
                {
                    std::cout << InVale << std::endl;
                };

            for (int i = 0; i < 10; ++i)
            {
                Lambda(i);
            }

            Lambda(60);
        }
        // 람다를 사용해서 리턴 처리
        {
            // 람다 함수의 리턴 타입(추론 가능한 경우 생략 가능)
            std::function Lambda = [](const int InValue) -> int
                {
                    // GInt = 999; // 전역 변수는 Capture 하지 않아도 원래 가능
                    std::cout << InValue << std::endl;
                    return InValue + 100;
                };

            int Value = Lambda(100);
        }
        // 람다를 사용해서 외부 변수 캡처
        {
            {
                int a = 10, b = 20, c = 30;
                // 명시적으로 특정 변수를 Capture(&없으면 값으로 캡처되고, 값을 수정할 수 없다(읽기 전용))
                // &로 캡처하면 수정 가능
                std::function Lambda = [a, b, &c](const int InValue) -> int
                    {
                        c = 10;
                        std::cout << a << std::endl;
                        std::cout << b << std::endl;
                        std::cout << c << std::endl;
                        return InValue + 100;
                    };

                int Value = Lambda(100);
            }
            {
                int a = 10, b = 20, c = 30;
                // =를 사용하면 명시하지 않은 변수를 값으로 Capture 한다
                std::function Lambda = [=, &c](const int InValue) -> int
                    {
                        c = 10;
                        std::cout << a << std::endl;
                        std::cout << b << std::endl;
                        std::cout << c << std::endl;
                        return InValue + 100;
                    };

                int Value = Lambda(100);
            }
            {
                int a = 10, b = 20, c = 30;
                // &를 사용하면 명시하지 않은 변수를 참조로 Capture 한다
                // 명시적으로 a와 같이 캡처 하는 경우 값으로 Capture 한다
                std::function Lambda = [&, a](const int InValue) -> int
                    {
                        // a = 20;
                        b = 30;
                        c = 10;
                        std::cout << a << std::endl;
                        std::cout << b << std::endl;
                        std::cout << c << std::endl;
                        return InValue + 100;
                    };
                a = 999; // 이미 a값이 Lambda에 10으로 Capture되어 있어서
                // 여기서 999로 바꿔도 Lambda 내부에서는 10이다
                int Value = Lambda(100);
            }
            // Struct를 캡처 하는 경우
            {
                FStruct Struct;
                Struct.SetValue(100);
                std::function Lambda = [Struct]()
                    {
                        std::cout << "Lambda\n";
                    };
                Struct.SetValue(1000);
                Lambda();
            }
        }
        // 함수와 람다
        {
            Function(Test);
            Function(
                []()
                {
                    for (int i = 0; i < 10; ++i)
                    {
                        std::cout << std::format("Lambda!! {}\n", i);
                    }
                }
            );
            int Count = 10;
            std::cout << std::endl;
            //std::cout << "input: ";
            //std::cin >> Count;
            Function(
                [Count]()
                {
                    for (int i = 0; i < Count; ++i)
                    {
                        std::cout << std::format("Lambda!! {}\n", i);
                    }
                }
            );

            FStruct Struct = FStruct(
                []()
                {
                    std::cout << "Hello~\n";
                }
            );

            Struct.SetValue(1000);
            std::cout << "Test\n";
        }
        // 람다를 사용할때 주의점
        {
            // 만약 등록해둔 람다 함수가 늦게 호출되는 경우
            // 늦게라는 의미는 아래처럼 즉시 함수호출 후 람다가 실행되는 경우가 아닌
            // Ex) 스레드, 엔진에서 다른 시점에 호출되는 경우
            // 람다로 &나 pointer로 capture 해둔 변수에 접근하는 경우 해당 변수가 유효한지
            // 확인해야 합니다.
            // 그렇지 않은 경우 잠재적인 문제가 발생할 수 있습니다.
            // 쉽게 생각하면 댕글링 포인터와 비슷한 이슈라고 할 수 있습니다.
            int* Pointer = new int(100);
            FStruct Struct;
            {
                int a = 100;
                Struct = FStruct(
                    [Pointer, &a]()
                    {
                        a = 1000;
                        std::cout << "Hello: " << *Pointer << std::endl;
                    }
                );
            }
            Struct.SetValue(100);
            //FStruct의 Function 멤버 변수에 저장됩니다. 람다함수가

            delete Pointer;
            Struct.SetValue(100);
        }
    }
#pragma endregion

#pragma region 01-01 memory random, sort
    {
        // 컴퓨터에서 random 함수는 진짜 random이 아닐 수 있다.
        // 좋은 random 함수를 사용해야 더 random에 가깝다.

        std::random_device RD;
        std::mt19937 Gen(RD());
        std::uniform_int_distribution<int> Dist(0, 999);
        int RamdomValue = Dist(Gen);

        std::vector<int> Vector;
        Vector.resize(100);
        std::cout << "Random start ---- \n";
        for (int& i : Vector)
        {
            i = Dist(Gen);
            std::cout << i << ", ";
        }
        std::cout << "\nRandom end ---- \n";

        // 오름차순 정렬
        std::sort(Vector.begin(), Vector.end(), std::less<int>{});

        std::cout << "오름차순 sort start ---- \n";
        for (int i : Vector)
        {
            std::cout << i << ", ";
        }
        std::cout << "\nRandom end ---- \n";

        // 내림차순 정렬
        std::sort(Vector.begin(), Vector.end(), std::greater<int>{});

        std::cout << "내림차순 sort start ---- \n";
        for (int i : Vector)
        {
            std::cout << i << ", ";
        }
        std::cout << "\nRandom end ---- \n";
    }
#pragma endregion


#pragma region 01-02 string C스타일 문자열
    {
        // stack								 // data
        // [8byte]String {0xDataAreaAddress} --> // char[0]{'H'}
                                                 // char[1]{'e'}
                                                 // char[2]{'l'}
                                                 // char[3]{'l'}
                                                 // char[4]{'o'}
                                                 // char[5]{'\0'}
        const char* String = "Hello";
        // stack
        // [8byte]String {0xDataAreaAddress} --> 위와 동일한 주소
        const char* String2 = "Hello";
        // String2[0] = 'A';

        // 장점
        // - 사용법과 구조가 간단하다
        // - 가겹다. 메모리를 꼭 필요한 만큼만 사용한다
        // - 저수준(low level)이다. 메모리 조작이 쉽다

        // 단점
        // - 편의 기능(복사, 사이즈 확인 등등)을 관련 기능을 찾거나 구현하려면 별도의 노력이 든다
        // - 찾기 힘든 메모리 관련 버그가 발생하기 쉽다
        // - C++의 객체지향적인 특성을 활용하지 못한다
    }
#pragma endregion

#pragma region C++ 문자열(String)
    {
        int a;
        std::string A = "Hello ";
        std::string B;// = "World!";
        B = "World!";

        std::string C = A + B;	// Hello World!

        A += B; // Hello World!
        A.append(B); // Hello World!World!
        {
            const char* StringA{ "Hello" };	// Data영역
            const char StringB[]{ "Hello" };// Stack영역
            const char* StringC{ "Hello" };	// Data영역

            // 주소를 비교하는 것으로, 문자열 비교를 의미하지 않음
            // 아래는 Data영역 주소와 Stack 영역 주소를 비교하고 있기 때문에
            // 서로 다르다고 처리된다
            if (StringA == StringB)
            {
                std::cout << "StringA == StringB\n";
            }
            else
            {
                std::cout << "else StringA == StringB\n";
            }
        }

        //int strcmp(string A, string B) 문자열비교 다른만큼 수가 증가함
        // const int Result = strcmp(StringA, StringB);
        // 
        //bool bResult = AA._Equal(BB);


        // -시간 및 언어->언어 및 지역->기본 언어 설정 -> (국가 또는 지역)->관리자 옵션->시스템 로캘 변경(Beta UTF - 8)
            // - Visual stduio 우측 상단 -> 파일 -> 다른 이름으로 xx저장 -> 다이얼로그 우측 하단 저장 버튼 오른쪽에 있는
                // 화살표 클릭 -> 인코딩 하여 저장 -> UTF-8로 되어 있는지 확인해야 문제가 없습니다.
            // 한국 로캘에서는 기본적으로 한국어 코드페이지(949)로 되어 있으나 이러면 한글 주석, 문자열 등이
            // 깃 등에 업로드 하면 깨져서 나옵니다.

            // visual studio에서 .editconfig라는 파일을 만들어서 원하는 확장자 파일의 코드 페이지를 설정하면
            // 신규로 만드는 파이르이 경우 해당 코드 페이지를 사용하게 됩니다.

        std::wstring String{ L"안녕 Hello!" };
        std::wstring String2{ TEXT("안녕 Hello!") };

        //문자열 검색 : std::wstring::find와 같은 문자열 검색 함수가 특정 문자열을 찾지 못했을 때,
        // 함수는 std::wstring::npos를 반환합니다.

        std::wstring Wstring;
        if (Wstring.empty())
        {
            Wstring = TEXT("Hello World!");

            const size_t FindIndex = Wstring.find(TEXT("d!"));
            const size_t FindIndex2 = Wstring.find(TEXT("!!!!"));
            if (FindIndex != std::wstring::npos)
            {
                std::cout << std::format("\nd! index = {}\n", FindIndex);
                Wstring.replace(FindIndex, 1, TEXT("@!#$"));
            }
            if (FindIndex2 == std::wstring::npos)
            {
                std::cout << "not found!\n";
            }
        }

        // 문자열을 다른 자료형으로 변환
 
        //int Number = std::stoi(string)
        //std::wstring WString = std::to_wstring(1000);
        //std::string String = std::to_string(1000);
        //float Float = std::stof(String);
        // UTF-8 -> WString(UTF-16)
        {
            std::string String = "Hello 한글 こんにちは 哈罗 صباح الخير\n";
            std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
            std::wstring WString = converter.from_bytes(String);

            // 정상 동작 불가
            // std::wstring WString = std::wstring(String.begin(), String.end());
        }


    }
#pragma endregion

#pragma region 01-02 string StringView
    {
        // C++17에 추가된 읽기 전용 String class

        std::wstring String{ TEXT("Hello") };
        // 복사가 발생!
        std::wstring String2 = String;
        String2[0] = TEXT('A');

        // 이렇게 해도 string이 복사되지 않는다
        std::wstring& StringReference = String;
        std::wstring* const StringPointer = &String;
        StringReference[0] = TEXT('W');

        // 복사가 발생 하지 않음
        std::wstring_view WStringView = String;
        std::wstring_view WStringView2 = TEXT("Hello");
        WStringView2 = String;

        auto Function1 = [](std::wstring InString)
            {

            };
        auto Function2 = [](std::wstring_view InStringView)
            {
                std::wcout << InStringView << std::endl;
            };
        auto Function3 = [](const std::wstring& InString)
            {
                std::wcout << InString << std::endl;
            };

        Function1(TEXT("asdasd"));
        Function2(TEXT("asdasd"));

        // Data영역에 있던 asdasd가 
        // const wstring& 로 변환되기 위해서는
        // wstring 임시객체가 만들어 져야 한다.
        // 그래서 불필요한 복사가 발생할 수 있다.
        // 하지만 wstring_view를 사용하면 TEXT("asdfasdf") 사용할때와, 그냥 wstring을 넘길때 둘다 복사없이 사용 가능

        // 복사가 발생!
        Function3(TEXT("asdasd"));
        std::wstring TestString = TEXT("asdfasdf");
        // 복사가 발생하지 않음
        Function3(TestString);

        // 복사가 발생하지 않음
        Function2(TestString);
    }
#pragma endregion

#pragma region 01-03 class 
    {
        // FClass라는 설계도(청사진)를 기반으로
        // 실체화된 사례(instance)를 만든다
        // An Object is an instance of a class
    }
#pragma endregion

	return 0;
}

void Test()
{
    std::cout << "Test" << std::endl;
}

void Function(std::function<void()> InFunction)
{
    std::cout << __FUNCTION__ << std::endl;
    InFunction();
    std::cout << __FUNCTION__ << " end" << std::endl;
}

int SumFunction(int a, int b)
{
    return a + b;
}

bool ReturnTrue()
{
    return true;
}

bool ReturnFalse()
{
    return false;
}


void Function2()
{

}


void AllocateCorrect(int** InDoublePointer)
{
    *InDoublePointer = new int{ 10 };
}

void AllocateCorrect2(int*& InDoublePointer)
{
    InDoublePointer = new int{ 10 };
}

void Deallocate2(int** InDoublePointer)
{
    delete* InDoublePointer;
    *InDoublePointer = nullptr;
}

void AllocateWrong(int* InPointer)
{
    // Memory 누수!
    InPointer = new int{ 10 };
}

void InitArray(int* const InOutArray, const size_t InSize)
{
    for (size_t i = 0; i < InSize; i++)
    {
        InOutArray[i] = i;
    }
}

struct FStruct
{
    FStruct() = default;
    FStruct(const int InValue);
    FStruct(std::function<void()> InFunction)
        : Function(InFunction)
    {

    }
    FStruct(const FStruct& InOther)
        : Value(InOther.Value)
    {
        std::cout << "Copy Constructor\n";
    }
    FStruct(const std::unique_ptr<FStruct>& InOther)
        : Value(InOther->Value)
    {
    }
    ~FStruct();

    FStruct& operator=(const FStruct&) = default;

    //void SetValue(const int InValue) { Value = InValue; }
    void Hello() { std::cout << "Hello\n"; }
    void SetValue(const int InValue);

private:
    int Value = 0;
    std::function<void()> Function;
};


void CustomDeleterInt(int* InPointer)
{
    std::cout << "Hello~ : " << std::to_string(*InPointer) << std::endl;
    delete InPointer;
}

void SharedParam(std::shared_ptr<FStruct> InPointer)
{
}

void WeakParam(std::weak_ptr<FStruct> InPointer)
{
    if (InPointer.expired())
    {
        return;
    }
}