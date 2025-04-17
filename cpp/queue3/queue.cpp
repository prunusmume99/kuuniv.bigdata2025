#include "queue.h"
#include <cassert>

const int Queue::QUEUE_SIZE = 100;

Queue::Queue(int size)
    : arr_(size), front_(0), rear_(0), count_(0)
{
    // Array 클래스가 생성자에서 자동 생성됨
}

Queue::~Queue() {
    // arr_는 자동 소멸 (Array의 소멸자 호출)
}

int Queue::size() const {
    return arr_.size();
}

int Queue::remain() const {
    return arr_.size() - count_;
}

bool Queue::isEmpty() const {
    return count_ == 0;
}

bool Queue::isFull() const {
    return count_ == arr_.size();
}

void Queue::push(int data) {
    assert(!isFull());
    arr_[rear_] = data;
    rear_ = (rear_ + 1) % arr_.size();  // 원형처럼 처리
    ++count_;
}

int Queue::pop() {
    assert(!isEmpty());
    int data = arr_[front_];
    front_ = (front_ + 1) % arr_.size();  // 원형처럼 처리
    --count_;
    return data;
}
