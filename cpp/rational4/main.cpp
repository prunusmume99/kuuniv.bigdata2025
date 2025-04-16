#include <iostream>
#include "rational.h"
int main()
{
    Rational r1;
    Rational r2(3, 1);
    Rational r3(3, 4);
    Rational r4 = r3;
    r1 = r3;

    std::cout << "r2 : " << r2 << std::endl;
    std::cout << "r3 : " << r3 << std::endl;

    r1 = r2 + r3;
    std::cout << "r2 + r3 = " << r1 << std::endl;

    r1 = r2 - r3;
    std::cout << "r2 - r3 = " << r1 << std::endl;

    r1 = r2;
    r1 += r3;
    std::cout << "r2 += r3 -> r1 = " << r1 << std::endl;

    std::cout << "r2 : " << r2 << std::endl;
    std::cout << "r3 : " << r3 << std::endl;
    std::cout << "r4 : " << r4 << std::endl;

    return 0;
}
