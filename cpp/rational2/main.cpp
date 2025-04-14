#include <iostream>
#include "rational.h"

int main()
{
    Rational r1;
    Rational r2 = 3;                 // Rational(3) = 3/1
    Rational r3(6, 8);               // 약분되면 3/4

    r1 = r3;                         // 대입 연산자 사용

    if (r1 == r3) {                  // 비교 연산자 사용
        std::cout << "r1과 r3는 같은 유리수" << std::endl;
    } else {
        std::cout << "r1과 r3는 다른 유리수" << std::endl;
    }

    std::cout << "r1: (" << r1.numerator() << "/" << r1.denominator() << ")" << std::endl;
    std::cout << "r2: (" << r2.numerator() << "/" << r2.denominator() << ")" << std::endl;
    std::cout << "r3: (" << r3.numerator() << "/" << r3.denominator() << ")" << std::endl;

    return 0;
}
