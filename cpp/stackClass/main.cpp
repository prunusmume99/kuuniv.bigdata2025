#include <iostream>
#include "stack.h"

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.print();  // [ 10 20 30 ]
    std::cout << "Top: " << s.top() << std::endl;

    Stack s2 = s;  // 복사 생성자
    s2.pop();
    s2.print();  // [ 10 20 ]

    Stack s3;
    s3 = s;  // 복사 대입 연산자
    s3.print();  // [ 10 20 30 ]

    s.clear();
    std::cout << "s cleared, size: " << s.size() << std::endl;
    s.print();  // [ ]

    return 0;
}
