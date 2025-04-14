#include <iostream>
#include "rational.h"

int main()
{
    Rational r1(2, 4);    // 2/4 → 약분되어 1/2
    Rational r2(3);       // 3 → 3/1
    Rational r3;          // 기본 생성자 → 0/1

    r3.numerator(4);
    r3.denominator(6);   // 4/6 → 약분되어 2/3

    std::cout << "r1 : " << r1.numerator() << "/" << r1.denominator() << std::endl;
    std::cout << "r2 : " << r2.numerator() << "/" << r2.denominator() << std::endl;
    std::cout << "r3 : " << r3.numerator() << "/" << r3.denominator() << std::endl;

    return 0;
}
