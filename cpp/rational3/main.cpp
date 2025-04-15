#include <iostream>
#include "rational.h"

int main() {
    Rational r1;                  // 기본 생성자
    Rational r2 = 3;              // 정수 생성자 (3/1)
    Rational r3(6, 8);            // 자동 약분 → (3/4)

    r1 = r3;

    if (r1 == r3) {
        std::cout << "r1과 r3는 같은 유리수" << std::endl;
    } else {
        std::cout << "r1과 r3는 다른 유리수" << std::endl;
    }

    std::cout << "r1: " << r1 << std::endl;
    std::cout << "r2: " << r2 << std::endl;
    std::cout << "r3: " << r3 << std::endl;

    return 0;
}
