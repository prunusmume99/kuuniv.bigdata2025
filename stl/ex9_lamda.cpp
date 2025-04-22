#include <iostream>
#include <vector>
using namespace std;

class Adder
{
public:
    int offset;
    Adder(int o) : offset(o) {};                            // 생성자 정의
    int operator()(int x) const { return x + offset; }      // 함수형 객체
};

int main()
{
    double pi = 3.1415926535;
    auto calc = [&pi](int r) -> double
    // 람다식 참조 캡처 [&pi] 사용 (원본 사용, 수정 가능)
    // 반환타입 double
    {
        pi = 30;                        // pi 값을 직접 수정
        return pi * r * r;             // 원의 면적 계산 공식
    };
    cout << "면적은 " << calc(3) << endl;
    cout << "Pi 의 값은 : " << pi << endl;

    int sum = 0;

    auto calc2 = [&sum](int x, int y)
    // 람다식 참조 캡처 [&sum] 사용 (외부 sum 변수에 결과 저장)
    { sum = x + y; };
    calc2(2, 3);
    cout << "합은 : " << sum << endl;

    auto calc3 = [&](int x, int y)
    // 람다식 참조 캡처 [&] 사용 (sum, pi 모두 참조 사용)
    { sum = x + y + pi; };  // double(pi) + int → int로 자동 형변환 (주의)
    calc3(2, 3);
    cout << "합은 : " << sum << endl;

    // vector<int> test;
    // test();   // ❌ 함수 아님, 주석처리

    Adder addObject(4);                  // offset = 4
    cout << addObject(10) << endl;       // 10 + 4 = 14

    return 0;
}
