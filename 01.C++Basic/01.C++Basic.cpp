// 솔루션 탐색기 -> 모든 파일 표시로 변경

// 프로젝트 우클릭 -> 속성 -> 중간 디렉터리, 출력 디렉터리 변경
// 프로젝트 우클릭 -> 속성 -> C++20

// 솔루션(sln) 파일, 프로젝트(vcxproj) 파일 notepad로 열어서 봤다.
// - 프로젝트: xml이라는 문법으로 만들어져 있다.

// 빌드(Build)
// 실행 파일을 만드는 과정
// - 전처리(Preprocess): 소스코드에 담긴 메타 정보를 처리한다
// - 컴파일(Compile): 소스코드를 머신이 읽을 수 있는 파일로 변환한다
//                     (기계어 (바이너리(0,1))로 변환, 기계어를 사람이 읽을 수 있게 변환한게 어셈블리어)
// - 링크(Link): 컴파일 단계에서 변환된 여러 Object파일을 exe로 합친다
//               (우리가 작성한 소스코드 + 가져다 쓴 코드(라이브러리) 등을 합친다)

// *.pdb
// - 디버깅을 위한 기호 정보가 들어있다.
// - 실제로 유저에게 배포할때는 포함되면 안된다.

// 컴파일러
// - 컴파일러 제조사가 컴파일러를 표준 C++문법을 따라서 컴파일 되게 구현한 프로그램
//  - MSVC(MicroSoft Visual C, C++) Compiler
//  - gcc


// include 전처리 지시자
// (전처리 지시자는 컴파일러에게 알려주는 기능)
// include 뒤에 나오는 파일을 포함하겠다
// 포함이란 #include 부분에 대상 파일을 복사 붙혀넣기 한다

// Input Output Stream
//#pragma warning(disable:4789) // 특정 경고를 비활성화 할 수 있다
#include <iostream>
#include <format>
#include <array>
#include <string>
#include <windows.h>
#include "Function/Function.h"

int GInt = 0;
//std::unique_ptr<int> GUnique = std::make_unique<int>(100);
//int* GTest = new int(100);

bool FirstTrue()
{
    std::cout << "FirstTrue\n";
    return true;
}
bool FirstFalse()
{
    std::cout << "FirstFalse\n";
    return false;
}

void Function2();

int main()
{
    // 브레이크 포인트(Break point): F5로 프로그램을 실행(디버거를 붙혀서 실행)
    // 을 하면 Break point를 만날 때 까찌 실행된다.
    // 브레이크 포인트 생성 방법
    //  - 원하는 라인 왼쪽에 마우스를 올리면 흰색 원이 생기는데, 이를 클릭
    //  - 원하는 라인에 캣럿(클릭하면 생기는 깜박이는 수직선)을 두고 F9를 눌러서 켰다 껐다

    // F10: 처음에 프로그램을 디버거를 붙혀서 켜고 첫 시작점부터 멈춰 있는다
    //      이후 F10으로 한줄씩 실행이 가능하다
    // F5: 디버거를 붙혀서 프로그램을 실행하고 Break point를 만날 때 까지 쭉 실행

    // 디버거가 활성화된 상태에서 && BreakPoint 등으로 멈춰 있는 상태에서
    // 우클릭 -> 디스어셈블리로 이동을 클릭하시면 어셈블리 코드를 확인 하실 수 있습니다.

#pragma region 01. 표준 입출력 (cout, cin)
    //{
    //    // 변수
    //    // 변수타입 변수이름 = 초기값
    //    int a = 10;
    //    int b{ 0 };
    //    std::cout << "숫자를 입력해주세요: ";
    //    std::cin >> a;

    //    // std라는 namespace(카테고리)에 있는 cout 함수를 호출
    //    std::cout << "안녕하세요" << std::endl;
    //    std::cout << "안녕하세요 " << a << " " << 20 << std::endl;
    //}
    
    // Ctrl+K -> (Ctrl누르고 있는 상태에서 K키는 때고) C: 선택한 라인 주석
    // Ctrl+K -> (Ctrl누르고 있는 상태에서 K키는 때고) U: 선택한 라인 주석 제거
    //int a = 20;
    //std::cout << "안녕하세요 " << a << " " << 20 << std::endl;
#pragma endregion

#pragma region 02. 리터럴(literal)
    {
        // 리터럴은 코드에 표시한 숫나 문자열과 같은 값 을 의미
        // 십진수
        int V{ 100 };
        // 8진수 : 0144
        int V2{ 0144 }; // 쓸일 없다
        // 16진수 : 0x64
        int V3{ 0x64 };
        // 2진수 : 0b01100100 // 쓸일 없다
        int V4{ 0b01100100 };

        // 부동소수점(floating point): 3.14f
        float F{ 3.14f };

        // 배정도 부동소수점(double): 3.14
        double D{ 3.14 };

        // 단일 문자
        char C{ 'a' }; // ASCII 코드 표에 따라 숫자가 저장됨
        // 문자열 "Hello"

        char CC = 100;
    }
#pragma endregion

#pragma region 03. 변수(Variable)*
    {
        // 1Byte == 8bit (표현 가능한 범위 0~255)
        // 2진수로 나타내는 경우
        // 0000 0000 ~ 1111 1111
        //                     2^0 = 1
        //                    2^1  = 2
        //                   2^2   = 4
        //                  2^3    = 8
        //                2^4      = 16
        //               2^5       = 32
        //              2^6        = 64
        //             2^7         = 128
        // 10진수로 나타내는 경우 (위 값을 모두 더하면됨)
        // 0~255
        // 1024Byte == 1KB
        // 1024KB   == 1MB
        // 1024MB   == 1GB
        // 1024GB   == 1TB

        // 1000KiB  == 1MiB
        // 1000MiB  == 1GiB

        // 자료형: 타입 크기는 Byte에 해당
        // 정수형: char(1Byte), short(2Byte), int(4Byte), long(4Byte), long long(8Byte), __int64(8Byte)
        //         주로 사용: char, int
        // 실수형: float(4Byte), double(8Byte)
        {
            int Var{ 0 }; // 초기화 연산자로 변수를 선언과 동시에 초기화한다.
            Var = 10; // 대입 연산자를 사용해서 값을 변경
        }
        {
            // 4Byte 정수형 signed 타입
            // signed타입: 음수를 표현할 수 있다
            signed int Var{ -1 };
            Var = Var + 1;

            // unsigned를 붙히면 부호가 없는 타입
            unsigned int Var2{ (unsigned int)-1};
            Var2 = Var2 + 1;

            unsigned int Var3{ 4294967295 };
            Var3 = Var3 + 1;

            unsigned char C = 254;
            C = C + 1;
            C = C + 1000;
        }
        {
            // 2Byte 정수형
            // -32,768 ~ 32,767
            short S1{ 32767 };
            S1 = S1 + 1;    // -32,768
            S1 = S1 - 1;    // +32,767

            signed short S2{ 20 };
            unsigned short S3 = 30;
        }
        {
            // 4Byte 정수형
            long L1{ 14L };
        }
        {
            // 8Byte 정수형
            long long LL1{ 14LL };
            unsigned int Var3{ 4294967295 };
            unsigned int Var4{ (unsigned int)4294967296 };
            long long LL2{ 4294967296LL };
            //long long LL3{ (unsigned int)4294967296 };
        }
        {
            // 4Byte 실수형
            // 단정도(single) 부동소수점
            // 부동소수점은 컴퓨터에서 부동소수점을 표현하는
            // 특징으로 인해서 오차가 발생할 수 있다.
            float F{ 3.14F };
            int Int{ (int)3.14F };
            int Int2{ (int)3.999F }; // 소수점 부분 내림 처리

            // Debug 인 경우 메모리 뒷쪽에
            // 추가 정보가 기본적으로 들어가 있어서
            // 이를 비활성화 하면 변수 크기만큼만 딱 공간을 확보한다
            // 프로젝트 속성 -> C/C++ -> 코드 생성 -> 기본 런타임 검사 -> 기본값
        }
        {
            // 8Byte 실수형
            double D{ 3.14 };
        }
        {
            // 1Byte 정수형
            unsigned char C = 255;
            char C2 = (char)255;
            unsigned char C3 = 'A'; // ASCII 코드 표에 대응되는 수치로 변환해서 저장

            int Int = 'A';
            int Int2 = 65;
        }
        // 유니코드 (다국어 처리가 가능, char는 단일 char로는 불가능)
        {
            // 2Byte
            wchar_t W{ L'A' };
            wchar_t W2{ L'가' };
            wchar_t W3{ L'早' };
            //char C{L'가'}; // 표기 불가
        }
        // 부울타입(boolean) 참과 거짓
        {
            // 1Byte
            bool B0 = true; // 1
            bool B1 = false; // 0
            bool B2 = 0; // false
            bool B3 = 1; // true;
            bool B4 = 22; // true;
        }
        // 부동소수점 오차
        {
            double Value = 0.0;
            if (Value == 0.0)
            {
                std::cout << "Value가 0입니다.\n";
            }
            Value = Value + 0.1;
            Value = Value + 0.1;
            Value = Value + 0.1;

            if (Value == 0.3)
            {
                std::cout << "Value가 0.3입니다.\n";
            }
        }

        // 초기화(initailization)
        {
            int IntNoInit;  // 초기화를 하지 않은 변수
            // 초기화: 변수를 선언함과 동시에 값을 지정하는 것
            IntNoInit = 10; // 초기화가 아니라, 값을 대입

            int IntZeroInit = 0; // 선언과 동시에 값을 지정(초기화)
            int IntZeroInit2{ 0 };
            int IntZeroInit3{ };    // 자동으로 0으로 초기화
            float Float{};  // 0으로 초기화
        }
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
        // 단항(unary; 유너리) 연산자: 표현식(expression) 하나를 계산
        // 이항(binary; 바이너리) 연산자: 표현식 2개를 계산
        // 삼항(temary; 텀메리) 연산자: 표현식 3개를 계산

        // 대입 연산자[이항]: 오른쪽 값을 왼쪽의 표현식에 대입하는 연산자
        {
            int i;
            i = 0;
            int k;
            k = i;
        }
        // [단항] 표현식의 참 / 거짓 (참: 보통1, 0이 아닌 값 / 거짓: 0)
        {
            bool b1{ true };    // 참
            bool b2{ 1 };       // 참
            bool b3{ false };   // 거짓
            bool b4{ 0 };       // 거짓

            bool b5{ !true };   // 참이 아니다(부정, not) == 거짓(false)
            bool b6{ !false };  // 거짓이 아니다 == 참(true)
            
            bool b7{ true };    // 참
            bool b8{ !b7 };     // b7이 참인데 b7(참)이 아니다 == 거짓(false)
        }
        // [이항]사칙 연산
        {
            int a{ 1 + 2 }; // 1 + 2 = 3
            int b{ a + 3 }; // a + 3 = 3 + 3 = 6

            int c{ 1 - 2 }; // 1 - 2 = -1
            unsigned int c2{ unsigned int(1 - 2) }; // 1 - 2 = -1 -> unsigned int 엄청 큰 값

            int d{ c * 3 }; // -1 * 3 = -3

            int e{ 10 / 3 }; // 3
            float f{ 10 / 3 }; // int(10) / int(3) = int(3) -> float f = 3
            float f2{ 10.f / 3.f };
        }
        // [이항] mod, 나머지 연산자
        {
            int m{ 10 % 3 };    // 몫 3, 나머지 1
            int m2{ 5 % 2 };    // 몫 2, 나머지 1
            int m3{ 6 % 2 };    // 몫 3, 나머지 0
        }
        // [단항]후행 / 선행 연산자
        {
            // 후행 증가
            {
                int i{ 0 };
                // i++;
                int k = i++;    // k: 0, i: 1

                // 식 내부에 후행 연산자를 쓰지 마라
                // 실수할 여지가 많다
            }
            // 선행 증가
            {
                int i{ 0 };
                //++i;
                int k = ++i;    // k: 1, i: 1
            }
            // 후행 감소
            {
                int i{ 0 };
                //i--;
                int k{ i-- }; // k: 0, i: -1
            }
            // 선행 감소
            {
                int i{ 0 };
                //--i;
                int k{ --i }; // k: -1, i: -1
            }
        }
        
        // 사칙연산 축약 표현
        {
            int i{ 1 };
            int k{ 2 };

            //i = i + k; // 1 + 2 -> 3
            i += k; // 1 + 2 -> 3
            i += 2; // 3 + 2 -> 5

            i -= 2; // 5 - 2 = 3

            i *= 2; // 3 * 2 = 6
            i /= 2; // 6 / 2 = 3
            i %= 2; // 3 % 2 = 몫 1 나머지 1 <<
        }

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

        std::cout << "[Player Info]\n";
        std::cout << std::format("HP: {}, MP: {}, Tier: {}\n", Player2.HP, Player2.MP, (int)Player2.Tier);
        std::cout << "HP: " << Player2.HP << ", MP: " << Player2.MP << ", Tier: " << (int)Player2.Tier << std::endl;

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
        // if
        {
            int V = 0;
            if (V == 0)
            {
                std::cout << "V == 0\n";
            }

            int V2 = 0;
            //std::cin >> V2;
            if (V2 == 100)
            {
                std::cout << "V2 == 100\n";
            }
            else if (V2 == 70)
            {
                std::cout << "V2 == 70\n";
            }
            else if (V2 == 50)
            {
                std::cout << "V2 == 50\n";
            }
            else if (V2 == 60)
            {
                std::cout << "V2 == 60\n";
            }
            else
            {
                std::cout << std::format("V2 : {}\n", V2);
            }
        }

        // switch
        {
            int V2 = 0;
            //std::cin >> V2;
            switch (V2)
            {
            case 100:
                std::cout << "V2 == 100\n";
                break;
            case 50:
                std::cout << "V2 == 50\n";
                break;
            default: // if의 else와 같은 역할
                std::cout << "default\n";
                break;
            }

            enum class ETier : unsigned char
            {
                None,
                Iron,
                Bronze,
                Silver,
                Gold,
            };

            struct FPlayer
            {
                int HP = 10;
                int MP = 20;
                ETier Tier = ETier::None;
            };
            FPlayer Player{ .MP = 100, .Tier = ETier::Iron };

            std::cout << "[Player Info]\n";
            std::cout << std::format("HP: {}, MP: {}, ", Player.HP, Player.MP);
            
            switch (Player.Tier)
            {
            case ETier::None:
                std::cout << "ETier::None";
                break;
            case ETier::Iron:
                std::cout << "ETier::Iron";
                break;
            case ETier::Bronze:
                std::cout << "ETier::Bronze";
                break;
            case ETier::Silver:
                std::cout << "ETier::Silver";
                break;
            case ETier::Gold:
                std::cout << "ETier::Gold";
                break;
            default:
                break;
            }

            std::cout << std::endl;

            switch (Player.Tier)
            {
            case ETier::None:
                std::cout << "ETier::None";
                break;
            case ETier::Iron:
                std::cout << "Iron";
                [[fallthrough]]; // 에트리뷰트
            case ETier::Bronze:
            case ETier::Silver:
                std::cout << "Iron or Bronze or Silver";
                break;
            case ETier::Gold:
                std::cout << "ETier::Gold";
                break;
            default:
                break;
            }
            std::cout << std::endl;

            if (Player.Tier == ETier::None)
            {
                std::cout << "ETier::None";
            }
            else if (Player.Tier == ETier::Iron || Player.Tier == ETier::Bronze || Player.Tier == ETier::Silver)
            {
                if (Player.Tier == ETier::Iron)
                {
                    std::cout << "Iron";
                }
                std::cout << "Iron or Bronze or Silver";
            }
            else if (Player.Tier == ETier::Gold)
            {
                std::cout << "ETier::Gold";
            }
            else
            {

            }

        }
    }
#pragma endregion

#pragma region 09. 논리 연산자**
    {
        // !: 논리 부정
        if (!false) // !false == true
        {
            std::cout << "!false\n";
        }

        // 논리곱 (AND)
        // && : 양쪽 조건이 모두 참인경우 -> true
        //      하나라도 거짓인 경우 -> false
        int a = 10;
        int b = 20;
        // 1. a == 10 ? true
        // 2. b == 10 ? false
        // if(true && false) => false
        if (a == 10 && b == 10)
        {
            std::cout << "a == 10 && b == 10\n";
        }

        // 1. a == 10 ? true
        // 2. b == 20 ? true
        // if(true && true) => true
        if (a == 10 && b == 20)
        {
            std::cout << "a == 10 && b == 20\n";
        }

        int c = 30;
        // 1. a == 10 ? true
        // 2. b == 20 ? true
        // 3. c == 20 ? false
        // if(true && true && false) -> false
        if (a == 10 && b == 20 && c == 20)
        {
            std::cout << "a == 10 && b == 20 && c == 20\n";
        }

        //int a = 10;
        //int b = 20;
        // 논리합(OR)
        // 1. a == 10 ? true
        // if(true) -> true
        if (a == 10 || b == 10)
        {
            std::cout << "a == 10 || b == 10\n";
        }

        // 1. b == 10 ? false
        // 2. a == 10 ? true
        // if(false || true) -> true
        if (b == 10 || a == 10)
        {
            std::cout << "a == 10 || b == 10\n";
        }

        // 1. b == 50 ? false
        // 2. a == 60 ? false
        // if(false || false) -> false
        if (b == 50 || a == 60)
        {
            std::cout << "b == 50 || a == 60\n";
        }

        // 1. a == 10 ? true
        // 2. (b == 50 || c == 30) ? true
        //  b == 50 ? false
        //  c == 30 ? true
        //  false || true -> true
        // 3. true && (false || true)
        //     true && true -> true
        if (a == 10 && (b == 50 || c == 30))
        {
            std::cout << "a == 10 && (b == 50 || c == 30)\n";
        }
        else
        {
            std::cout << "false\n";
        }

        if (FirstFalse())
        {
            std::cout << "FirstTrue\n";
        }
        else
        {
            std::cout << "FirstFalse\n";
        }

        std::cout << "[Test]\n";
        // 1. FirstTrue -> true
        if (FirstTrue() || FirstFalse())
        {
            std::cout << "FirstTrue\n";
        }

        // 1. FirstFalse -> false
        // 2. FirstTrue -> true
        // if(false || true) -> true
        if (FirstFalse() || FirstTrue())
        {
            std::cout << "FirstTrue\n";
        }

        const bool bFirst = FirstTrue();
        const bool bSecond = FirstFalse();
        if (bFirst || bSecond)
        {
            std::cout << "true\n";
        }
    }
#pragma endregion

#pragma region 10. 함수(fucntion)***
    {
        // 규모가 큰 프로그램에서 모든 코드를 main함수 안에 담게 되면
        // 관리적인 측면에서 힘들 것 같습니다.
        // 코드 가독성(읽기 쉬운 정도)을 높히려면 코드를 간결하고 명확한
        // 함수 단위로 나는 것이 좋겠습니다.

        // C++에서 함수를 사용하려면 먼저 함수 선언을 해야합니다.
        // 반환타입    함수이름     (입력 파라미터(옵션; 있어도 되고 없어도 됨))
        // void        FunctionName (int a, int b)
        
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
        int a{}, b{}, c{};
        a = 1;
        b = 2;
        c = 3;

        // 1차원 배열
        {
            // int 데이터 5개(count)를 만들겠다
            int Array[5]{ 5,4,1,8,3 };
            int aa = 99;
            // 0번 index(또는 원소)에 1을 넣겠다
            // Array의 시작 주소로 부터 타입의 크기(int) * 인덱스만큼 건너뛴 메모리 값을 편집한다
            // Array 시작주소 + TypeSize(int) * index
            Array[0] = 1;
            Array[1] = 2;
            Array[2] = 3;
            Array[3] = 4;
            Array[4] = 5;
            //Array[5] = 6;

            int Size = sizeof(int);     // 4Byte
            int Size2 = sizeof(Size);   // 4Byte
            int ArraySize = sizeof(Array); // 20Byte: int(4) * 갯수(count:5) = 20
            int ArrayElemSize = sizeof(Array[0]);   // 4Byte
            int ArrayElemCount = ArraySize / ArrayElemSize; // 20 / 4 = 5
        }
        // 2차원 배열
        {
            // Array[0][0] Array[0][1] Array[0][2] Array[1][0] Array[1][1] Array[1][2]
            int Array[2][3]{};
            Array[0][0] = 0;
            Array[0][1] = 1;
            Array[0][2] = 2;
            Array[1][0] = 3;
            Array[1][1] = 4;
            Array[1][2] = 5;
        }
        
        // 1차원 배열 (std::array)
        {
            std::array<int, 5> Array{0,5,3,1,5};
            Array[0] = 0;
            Array[1] = 1;
            Array[2] = 2;
            Array[3] = 3;
            Array[4] = 4;

            // typedef unsigned __int64 size_t;
            // typedef는 왼쪽에 있는 타입을 오른족에 있는 이름으로 바꿔서 쓸 수 있게 해준다
            size_t Size = Array.size();
        }
    }
#pragma endregion

#pragma region 13. 반복문(loop)**
    {
        // while
        {
            int i = 0;
            while (i < 5)
            {
                std::cout << std::format("i: {}\n", i);
                ++i;

                if (i == 3)
                {
                    std::cout << "i가 3일때 탈출!\n";
                    break;
                }
            }
        }
        // do while
        {
            // while과는 다르게 조건을 만족하지 못했을 때도
            // 처음 한번은 실행 해준다
            int i{ 30 };
            do
            {
                std::cout << "Test\n";
            } while (i < 5);
        }
        // for
        {
            //  초기화;           판별식; for문이 한번 끝나고 실행될 코드
            for (int i = 0,j = 5; i < 5; ++i, ++j, FirstTrue())
            {
                std::cout << std::format("i: {}, j: {}\n", i, j);
            }
            // int i = 10;

            const int Size = 6;
            int Array[Size]{};
            for (int i = 0; i < Size; ++i)
            {
                //Array[0] = 0;
                //Array[1] = 1;
                Array[i] = i;
            }

            // 범위기반 for(range based for)
            for (int i : Array)
            {
                std::cout << i << std::endl;
            }

            std::array<int, Size> StdArray{};
            size_t ArraySize = StdArray.size();
            for (size_t i = 0; i < ArraySize; ++i)
            {
                StdArray[i] = i;
            }

            for (int i : StdArray)
            {
                std::cout << std::format("i값은: {}\n", i);
            }

            // CTAD(class template argument deduction: 클래스 템플릿 인수 추론)
            // C++20
            for (std::array Array2{ 1,2,3 }; int i : Array2)
            {
                std::cout << std::format("i값은: {}\n", i);
            }
            //Array2;

            // 추가적으로, if 도 조건문 이전에 int i = 0; 와 같이 초기화 구문을 넣을 수 있다.
            if (int i = 0; i < 10)
            {

            }
        }
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
        {
            // 지역변수는 시작과 끝 스코프({}) 내부에서 선언되는 변수를 의미합니다.

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
            // .. 
            // // 지역 변수, 함수 호출 이후 복귀 주소 등
            // --------------- Stack 영역 ------------------

            // 실행시간(런타임;Run time)에 동적으로 메모리 공간이 필요한 경우 OS(운영체제; Operating System)
            // 에 메모리를 요청해야 하는데, 이런 과정에서 커널에 요청할 필요가 있습니다.
            // 커널은 OS 중 항상 메모리에 올라가 있는 운영체제의 핵심 부분으로, 하드웨어와 응용 프로그램
            // 사이에서 인터페이스 역할을 제공합니다.
            // 커널에 요청하는 경우 이를 system call이라고 합니다. (메모리 할당을 할때마다 system call이 발생
            // 하지는 않을 수 있습니다)
            // 이 system call은 유저 영역과 커널 영역을 넘나드는 호출로서 상당한 비용을 지불하게 됩니다.
        }
        {
            // 64비트 환경에서는 포인터의 크기가 8Byte
            // 32비트 환경에서는 포인터의 크기가 4Byte
            // [Stack]                                      // [Heap]
            // [0xfff] Pointer(8Byte;64bit기준) = nullptr

            // Pointer 변수는 주소를 들고 있을 것이다.
            // 그리고, 그 주소로 접근하며 int 변수가 있을 것이다.
            int* Pointer{ nullptr }; // 실제 값은 0, 프로그래머를 위해서 0을
            // 쓰는 것 보다 nullptr을 넣어주면 더 명확하게 의미를 전달 할 수 있다.

            // 포인터의 크기는 플랫폼 bit수에(Ex.64 or 32) 대응해서 변경됩니다.
            // 32bit라면 최대 표현 가능한 주소가 FFFF FFFF(10진수로 4,294,967,295) 으로
            // unsigned int 범위에 해당한다. 즉 4byte만 있으면 모든 32bit 주소를 표현 할 수 있다.
            // 64bit 라면 FFFF FFFF FFFF FFFF 까지 총 8Byte로 모든 주소를 표현 할 수 있다.

            // [Stack]                                      // [Heap]
            // [0xfff..] Size (8Byte; size_t 의 크기가 64bit에서는 8Byte)
            // [0xfff..] Size2
            // int*의 의미는 지금 내가 가지고 있는 주소(*)로 가면 그 값은 int야 라는 의미
            size_t Size = sizeof(int*);
            // char*의 의미는 지금 내가 가지고 있는 주소(*)로 가면 그 값은 char야 라는 의미
            size_t Size2 = sizeof(char*);
        }
        {
            // [Stack]                                      // [Heap]
            // [0xfff...] a(4Byte) = 100
            // [0xfff...] 4Byte padding
            // [0xfff...] Pointer(8Byte) = nullptr
            // [0xfff...] b(4Byte) = 20
            int a = 100;
            int* Pointer{ nullptr };
            int b = 20;

            // [Stack]                                      // [Heap]
            // [0xfff...] a(4Byte) = 100
            // [0xfff...] 4Byte padding
            // [0xfff...] Pointer(8Byte) = 0x100   <-------    [0x100] int[4Byte] = 10
            // [0xfff...] b(4Byte) = 20
            Pointer = new int{ 10 };

            // [Stack]                                      // [Heap]
            // [0xfff...] Pointer(8Byte) = 0x100   <-------    [0x100] int[4Byte] = 10 -> 999
            // 이곳에 붙은 포인터 기호는 역참조 연산이라고 이야기 한다
            *Pointer = 999;

            // [Stack]                                      // [Heap]
            // [0xfff...] Pointer(8Byte) = 0x100   <-------    [0x100] int[4Byte] = 999
            // [0xfff...] Read(4Byte) = 999
            int Read = *Pointer;

            // 할당한 Memory를 해제
            delete Pointer;
            // int Read2 = *Pointer;

            // https://en.wikipedia.org/wiki/Magic_number_(programming)
            {
                // [Stack]                                      // [Heap]
                // [0xfffffff0] a(4Byte) = 100
                // ...
                // [0xfff...] Pointer2(8Byte) = 0xfffffff0;
                int* Ponter2 = &a;
                std::cout << std::format("Pointer2: {:X} &a: {:X}, *Pointer2: {}, a: {}\n", (size_t)Ponter2, (size_t)&a, *Ponter2, a);
                *Ponter2 = 1234;

                std::cout << std::format("Pointer2: {:X} &a: {:X}, *Pointer2: {}, a: {}\n", (size_t)Ponter2, (size_t)&a, *Ponter2, a);
                // int* Ponter3 = (int*)0xFFFFFFFFFFFFFFFF;
            }
        }
        {
            // [Stack]                                      // [Heap]
            // [0xfff...] Pointer(8Byte) = 0x100
            int* Pointer{ nullptr };

            // [Stack]                                      // [Heap]
            // [0xfff...] Pointer(8Byte) = 0x100   <-------    [0x100] int[4Byte] = 10
            Pointer = new int{ 10 };
            
            // 할당한 메모리를 해제하지 않고 넘어가는 경우 이를,
            // 메모리 누수(메모리 릭, memory leak)이라고 부릅니다.

            // 동적 할당한 메모리를 다른 주소로 덮어 쓰는 경우에도 
            // 원본 주소를 해제할 수 없다.
            // Pointer = (int*)10000;
            
            int* TempPointer = Pointer;
            *TempPointer = 100;
            delete Pointer;

            // 댕글링 포인터: 이미 해제된 메모리 주소를 들고 있는 상황
            // 이떄 해당 memory에 write하는 경우 프로그램이 죽을수도 있고
            // 잘 동작 할 수 도 있다. 하지만 잠재적인 위험이 아주 높다.
            // 가끔 잘 동작하다가 죽는 버그 원인을 찾았더니 댕글링 포인터가 원인인
            // 경우들이 종종 발견 됩니다.
            *TempPointer = 100;
        }
        {
            // C언어를 배우셨다면 malloc을 사용해서 메모리를 할당 했을 텐데,
            // C++에서도 사용할 수 있습니다.
            // malloc과 new는 큰 차이가 있습니다.
            // 아직 배우지는 않았지만, new와 delete는 초기화 및 struct 또는 class에서
            // 생성자와 소멸자를 호출해주는 역할을 수행합니다.
            // 그러나, malloc는 순수하게 memory 할당만 해줍니다.
            // int*를 new로 동적할당 할때는 초기화를 할 수 있었습니다.
            // 하지만, malloc은 초기화 불가
            int* Pointer = (int*)malloc(sizeof(int));
            *Pointer = 1000;
            free(Pointer);
        }
        {
            // [Stack]                                          // [Heap]
            // [0xfff...] Pointer(8Byte) = 0x100                0x100 [int][int][int][int][int][int]
            int* ArrayPointer = new int[6] {0, 1, 2, 3, 4, 5};
            ArrayPointer[0] = 1000;
            ArrayPointer[1] = 1200;

            // 0x100 + 0 * sizeof(int) = 0x100
            *ArrayPointer = 9999;
            // 0x100 + 1 * sizeof(int) = 0x104
            *(ArrayPointer + 1) = 8888;

            for (int i = 0; i < 6; ++i)
            {
                ArrayPointer[i] = i + 10;

                // Array(int*) + 0  Array + 1       Array + 2       Array + 3
                // [00 00 00 01]    [00 00 00 02]   [00 00 00 03]   [00 00 00 04]...
                *(ArrayPointer + i) = i;
            }
            // 1, 2,3 이렇게 주소로 부터 상대적으로 떨어진 위치를 말로 표현할때 offset이라고 이야기
            // 하는 경우가 있다.
            *((char*)ArrayPointer + 1) = 255;
            *((char*)ArrayPointer + 2) = 255;
            *((char*)ArrayPointer + 3) = 255;
            *((short*)ArrayPointer + 1) = 9999;
            *((__int64*)ArrayPointer + 0) = 9999;
            *((__int64*)ArrayPointer + 1) = 9999;
            delete[] ArrayPointer;

            // 2차원 이상 배열도 동적 할당으로 구현 가능하나,
            // 저는 실무에서 사용할 일이 없었습니다.
        }
        {
            struct FStruct
            {
                // 생성자: 인스턴스가 만들어질때 호출되는 함수
                // __thiscall: 호출하는 쪽에서 파라미터로 자기자신의 주소를 전달
                FStruct(/*FStruct* This*/)
                {
                    // this + 0Byte => Value
                    // this + 4Byte => Value2
                    this;
                    int a = this->Value;
                    int B = this->Value2;
                    std::cout << std::format("V: {}, V2: {}\n", this->Value, Value2);
                }
                FStruct(const int InValue)
                    // 초기화 순서는 변수를 선언한 순서대로 동작한다
                    : /*Value2(Value),*/ Value(InValue)/*, Value2(Value)*/
                {
                    std::cout << std::format("V: {}, V2: {}\n", Value, Value2);
                }
                // 소멸자: 인스턴스가 소멸되는 시점에 호출되는 함수
                // 컴파일러가 소멸예측 지점 (Stack: 스코프를 벗어나는 지점, Heap: delete를 하는 시점)
                // 에 코드에 소멸자를 호출하도록 심어둔다
                ~FStruct()
                {
                }
                int Value = 10;
                int Value2 = 20;
            };
            FStruct Struct = FStruct();
            Struct.Value;
            FStruct Struct2 = FStruct(100);

            FStruct* StructPointer = new FStruct(12);
            StructPointer->Value = 999;
            int* Test = (int*)StructPointer + 1;
            *Test = 888;
            delete StructPointer;

            {
                // malloc은 요청한 size만큼 메모리 블록만 할당.
                // new는 요청한 size만큼 메모리 블록을 할당 후 초기화(struct 와 같은 경우 생성자 호출)
                FStruct* MallocStruct = (FStruct*)malloc(sizeof(FStruct));

                // free는 해당 메모리 블록을 할당 해제
                // delete와 다르게 소멸자는 호출하지 않는다
                free(MallocStruct);
            }

            // 저수준의 동적할당은 사용빈도가 줄었다고 했지만,
            // 포인터는 사용하지 않는날이 없는 수준

            {
                int Value = 0;
                // Function call, 인자 복사
                // int InValue = Value;
                // Value = InValue;
                Value = CallByValue(Value);

                FParam Param = FParam();
                Param.Value[2] = 1234;

                // Call by value로 함수 호출을 한 경우
                // FParam InParam = FParam(Param);
                // FParam Temp = InParam; // 복사 생성자 호출됨(함수 리턴 되기 직전에 InParam을 임시 변수에 Backup)
                // InParam.~FParam(); // 소멸자 호출
                // Param.operator=(Temp); // 대입 연산자 호출됨
                // Temp.~FParam(); // 소멸자 호출
                // Param.~FParam(); // 소멸자 호출
                Param = CallByValue(Param);
            }
            {
                int a = 0;
                int* Pointer = &a;
                a = 999;
                //*Pointer = 1234;

                /*int* InPointer = Pointer;
                *InPointer = 1234;
                *Pointer = 1234;*/
                CallByPointer(&a);
                CallByPointer(Pointer);

                FParam Param = FParam();
                FParam* ParamPointer = &Param;

                FParam* InPointer = &Param;
                InPointer->Value[0] = 9999;
                InPointer->Value[5] = 5555;
                (*InPointer).Value[0] = 1234;
                CallByPointer(&Param);
                CallByPointer(ParamPointer);
            }
            {
                FParam Param; TestConstructor(&Param);

                FTTest TTest;
                TestConstructor(&TTest);

                int a = 200;
                int b = 400;

                TestConstructor((void*)&a);
            }
            {
                // 레퍼런스, 참조

                // 포인터와 레퍼런스의 차이

                int a = 5;
                int* Pointer = &a;  // 대상을 a로 변경
                *Pointer = 100;     // a의 값이 변경됨

                // Pointer는 가리키던 대상을 바꿀 수 있다.
                int b = 999;
                Pointer = &b;       // 대상을 b로 변경
                *Pointer = 1234;    // b의 값이 변경됨

                int* const PointerLikeReference = &a;
                // PointerLikeReference = &b; // * 오른쪽에 const가 붙어 있으면 가리키던 대상을 바꿀 수 없다
                *PointerLikeReference = 10000;
                const int* ConstPointer = &a; // * 왼쪽에 const가 붙어 있으면 가리키던 대상의 값을 바꿀 수 없다.
                //*ConstPointer = 9999;
                ConstPointer = &b;

                const int* const PointerCantChnage = &a; // 둘다 변경 불가!
                /*PointerCantChnage = &b;
                *PointerCantChnage = 1000;*/

                int& Reference = a; // 처음 초기화 시점에 반드시 대상이 와야하며, 이후 변경할 수 없다.
                Reference = b;      // 주소가 바뀌는 것이 아니라, 처음 연동한 a의 값이 b에 있는 값(1234)로 변경 된다.
                // Reference = &b;  // 이후 가리키던 주소를 변경할 수 없다.

                int TestValue = 0;
                CallByReference(TestValue);
                CallByPointer(&TestValue);

                FParam Param;
                CallByReference(Param);
            }
        }

        {
            int* Pointer = nullptr;
            FunctionWithPointer(Pointer);
            int a = 10;
            FunctionWithPointer(&a);

            if (Pointer == nullptr)
            {
                Pointer = new int{ 5 };
                FunctionWithPointer(Pointer);

                int* PointerB = Pointer;
                SAFE_DELETE(Pointer);
                FunctionWithPointer(Pointer);

                Wow hello;
                HI;
                if (Hmm(10, 20)) // 이런 메크로는 사용하지 마세요
                {

                }

                // PointerB는 댕글링 포인터
                // 이미 delete된 메모리 주소를 들고 있는 상황
                //FunctionWithPointer(PointerB);
            }

            {
                int* PointerB = new int{ 5 };
                int& ReferenceB = *PointerB;
                ReferenceB = 999;
                *PointerB = 1234;
                SAFE_DELETE(PointerB);
                FunctionWithReference(ReferenceB);
            }
        }
        {
            int a = 20, b = 10;
            Swap(a, b); // a: 10, b: 20
            Swap(&a, &b);
        }
        {
            std::array Numbers{ 1,2,3,4,5,6,7,8,9,10 };
            std::vector<int> Odds, Evens;
            SeperateOddsAndEvens(&Numbers, &Odds, &Evens);
            size_t Size = Odds.size();
            size_t Capacity = Odds.capacity();
            Odds.clear(); Evens.clear();
            SeperateOddsAndEvens(Numbers, Odds, Evens);
        }
    }
#pragma endregion

#pragma region 15. SmartPointer**
    {
        using namespace std;
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
            }
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
#pragma endregion

#pragma region 16. RVO(Return Value Optimization), NRVO(Named Return Value Optimization)
    {
        std::array Numbers{ 1,2,3,4,5,6,7,8,9,10 };
        {
            // RVO
            FOddsAndEvens OddsAndEvens = SeperateOddsAndEvens(Numbers);
        }
        {
            // NRVO
            FOddsAndEvens OddsAndEvens = SeperateOddsAndEvens2(Numbers);
        }
    }
#pragma endregion

#pragma region 17. Memory 누수(leak, 릭) 탐지
    {
        _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
        //_crtBreakAlloc = 405;
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
        using Hello2 = int;
        Hello2 cc = 100;

        using V = std::vector<int>;
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
        // [0xfff..] Text2(8Byte) = 0x100...                
        const char* Text2 = "Hello World!";
        // [0xfff..] Text3(8Byte) = 0x100...            (0x100...)"Hello World@"
        const char* Text3 = "Hello World@";
        // [0xfff..] TextStack = "Hello World@"

        // 문자열 길이가 12글자 이지만, 배열은 13으로 잡히는데,
        // 문자열의 끝인 \0 이라는 특수문자(1글자로 취급)가 생략되어 있다.
        // 그렇기 때문에 총 13자리가 필요
        const char TextStack[13] = "Hello World@";
        int Hello = 100;

        // 너무 긴 문자열이 들어오면 heap에 동적 할당
        // 초기화 시점에 문자열이 결정되고, 짧은 문자열 같은 경우 stack에
        // 올라올 수 있다.
        std::string String = "Hello World!";
        //String.append(" Wow2!");
        String += " Wow!";
        String[0] = 'W';
        String[5] = '_';
        String = "Oh hello!";
        std::cout << String << std::endl;

        /*if (Text == Text2)
        {
            std::cout << "Same\n";
        }*/
    }
    // 문자열 비교
    {
        std::string String = "Hello World!";
        std::string String2 = "Hello World@";
        //if (String != String2)
        if (String == String2)
        {
            std::cout << "Same";
        }
        else
        {
            std::cout << "not Same";
        }
    }
    // 다양한 타입을 문자열
    // 문자열을 다양한 타입으로 변환
    {
        int Value = 5000;
        float Float = 3.14f;
        std::string ValueToString = "Value: ";
        ValueToString += std::to_string(Value);
        ValueToString += " Float: " + std::to_string(Float);

        ValueToString = std::format("Value: {}, Float: {}", Value, Float);

        std::cout << ValueToString << std::endl;
    }
    // 다국어 처리
    {
        // UTF-8
        std::string MultipleLanguage = "Hello 한글 こんにちは 哈罗 صباح الخير\n";
        MultipleLanguage[6] = '갈'; // 내부적으로 다국어 표기가 1~3Byte를 차지할 수 있기 때문에
        // 이런 식으로 변경할 수 없을 수 있다.

        // UTF-16
        wchar_t WideCharacter = L'갈';
        std::wstring WString = L"Hello 한글 こんにちは 哈罗 صباح الخير\n";
        WString[6] = L'갈';
        std::wstring WString2 = TEXT("Hello 한글 こんにちは 哈罗 صباح الخير\n");

        if (WString[6] == L'갈')
        {

        }
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
}

void Function2()
{

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
