#include "stack.h"
#include <iostream>
#include <cassert>

Stack::Stack(int initCapacity)
    : data_(new int[initCapacity])
    , capacity_(initCapacity)
    , top_(-1)
{
    assert(data_);
}

Stack::Stack(const Stack& rhs)
    : data_(new int[rhs.capacity_])
    , capacity_(rhs.capacity_)
    , top_(rhs.top_)
{
    assert(data_);
    for (int i = 0; i <= top_; ++i)
        data_[i] = rhs.data_[i];
}

Stack& Stack::operator=(const Stack& rhs) {
    if (this != &rhs) {
        delete[] data_;
        capacity_ = rhs.capacity_;
        top_ = rhs.top_;
        data_ = new int[capacity_];
        assert(data_);
        for (int i = 0; i <= top_; ++i)
            data_[i] = rhs.data_[i];
    }
    return *this;
}

Stack::~Stack() {
    delete[] data_;
}

void Stack::resize() {
    int newCapacity = capacity_ * 2;
    int* newData = new int[newCapacity];
    assert(newData);
    for (int i = 0; i <= top_; ++i)
        newData[i] = data_[i];
    delete[] data_;
    data_ = newData;
    capacity_ = newCapacity;
}

void Stack::push(int value) {
    if (top_ + 1 >= capacity_)
        resize();
    data_[++top_] = value;
}

void Stack::pop() {
    if (!isEmpty())
        --top_;
}

int Stack::top() const {
    assert(!isEmpty());
    return data_[top_];
}

int Stack::size() const {
    return top_ + 1;
}

bool Stack::isEmpty() const {
    return top_ == -1;
}

void Stack::clear() {
    top_ = -1;
}

void Stack::print() const {
    std::cout << "[ ";
    for (int i = 0; i <= top_; ++i)
        std::cout << data_[i] << " ";
    std::cout << "]" << std::endl;
}
