#include "queue.h"
#include <iostream>
#include <cassert>

Queue::Queue(int size) : front(0), rear(0), size(size) {
    pArr = new int[size];
    assert(pArr);  // 메모리 할당 확인
}

Queue::~Queue() {
    delete[] pArr;
}

void Queue::push(int data) {
    if (rear >= size) {
        std::cout << "Queue is full!" << std::endl;
        return;
    }
    pArr[rear++] = data;
}

int Queue::pop() {
    if (isEmpty()) {
        std::cout << "Queue is empty!" << std::endl;
        return -1;
    }
    return pArr[front++];
}

bool Queue::isEmpty() const {
    return front == rear;
}
