#include "stack.h"
#include <cassert>

const int Stack::STACK_SIZE = 100;

Stack::Stack(int size)
    : arr_(size), tos_(0)
{
    // Array 객체는 생성자에서 size로 생성됨
}

Stack::~Stack() {
    // arr_는 자동 소멸 (Array의 소멸자 호출됨)
}

int Stack::size() const {
    return arr_.size();  // Array 클래스에 정의된 size() 사용
}

int Stack::remain() const {
    return arr_.size() - tos_;
}

bool Stack::isEmpty() const {
    return tos_ == 0;
}

bool Stack::isFull() const {
    return tos_ == arr_.size();
}

void Stack::push(int data) {
    assert(!isFull());
    arr_[tos_++] = data;  // Array의 operator[] 사용
}

int Stack::pop() {
    assert(!isEmpty());
    return arr_[--tos_];
}
