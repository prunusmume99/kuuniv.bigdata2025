#include <iostream>
#include "complex.h"

int main()
{
    Complex c1;                 // 기본 생성자
    Complex c2 = 3.0;           // Complwx c2(3.0) 변환 생성자
    Complex c3(3.0, 4.0);       // 전형적인 생성자들 
    // 생성자 하나만 만들었지만 위에 세개가 다 동작함
    Complex c4 = c3;            // Complex c4(c3) 복사 생성자 인자 타입 cosnt t타입 레퍼런스

    c1 = c3;                    // 컴파일러가 전역함수 또는 멤버함수 형태로 바꿔줌
    // c1.operator = (c3)         멤버함수  
    // operator = (c1, c3)        전역함수
    //c1 = c2 = c3;                // daisy-chain
    c4 = c2 + c3;              //c2.operator+(c3) or operator+(c2, c3)
    c4 = c2 - c3;

    if(c1 == c3) {

        std::cout << "c1 and c3 are equal" << std::endl;
    } else {
        std::cout << "c1 and c3 are not equal" << std::endl;
    }

    //std::cout << c1;    // (3.0, 4.0i)   std::cout.operator<<(c1) <- 멤버함수 형태는 X or operator<<(std::cout, c1) 0
    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    std::cout << c3 << std::endl;
    std::cout << c4 << std::endl;



    return 0;
}