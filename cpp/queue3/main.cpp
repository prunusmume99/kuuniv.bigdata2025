#include <iostream>
#include "queue.h"

int main() {
    Queue q1(10);
    Queue q2;

    q1.push(100);
    q1.push(200);
    q1.push(300);

    while (!q1.isEmpty()) {
        std::cout << q1.pop() << std::endl;
    }

    std::cout << "q1 capacity : " << q1.size() << std::endl;
    std::cout << "q1 remain   : " << q1.remain() << std::endl;

    return 0;
}
