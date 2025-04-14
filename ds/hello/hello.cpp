#include <iostream>

int main()
{
    std::cout << "Hello, World!" << std::endl;

    //std::cout << "Hello, World!" (C++에서는 이렇게 쓰면 컴파일러가 자동으로 아래 2줄로 바꿔줌.)
    operator<<(std::cout, "Hello, World!");// 연산자식을 전역함수 형태의 함수호출식으로 바꾼 것!
    // std:: cout.operator<<("Hello, World!"); // 연산자식을 멤버함수 형태의 함수호출식으로 바꾼 것! (가능한 이유: cout도 ostring타입의 객체임) //주소값 출력
    
    //std::cout << std::endl; // endl은 전역함수로 정의되어 있음. (C++에서는 endl을 전역함수로 정의해줌.)
    // operator<<(std::cout, std::endl); // 연산자식을 전역함수 형태의 함수호출식으로 바꾼 것! 이 부분 지금 주석처리해야 컴파일 에러 제거
    std::cout.operator<<(std::endl); // 연산자식을 멤버함수 형태의 함수호출식으로 바꾼 것! (가능한 이유: cout도 ostring타입의 객체임)

    operator<<(std::cout, "Hello, World!").operator<<(std::endl); // operator<<(std::cout, "Hello, World!") 얘의 리턴값이 cout이므로 계속해서 한 번 더 멤버함수를 쓸 수 있음.
    return 0;
}

// 12번, 9번 주석처리함. c++컴파일러가 연산자식을 함수초출식으로 바꿔서 예들 들면 7번 라인은 8번 라인으로, 11번 라인은 13번 라인으로 바꿔서 호출할 수 있음. 5번 라인을 15번 라인처럼 바꿀 수도 있음.