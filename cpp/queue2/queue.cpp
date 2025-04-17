#include "queue.h"
#include <iostream>
#include <cassert>

const int Queue::QUEUE_SIZE;

Queue::Queue(int size)
    : pArr_(new int[size]), size_(size), front_(0), rear_(0), count_(0)
{
    assert(pArr_);
}

Queue::~Queue() {
    delete[] pArr_;
}

int Queue::size() const {
    return size_;
}

int Queue::remain() const {
    return size_ - count_;
}

bool Queue::isEmpty() const {
    return count_ == 0;
}

bool Queue::isFull() const {
    return count_ == size_;
}

void Queue::push(int data) {
    assert(!isFull());
    pArr_[rear_] = data;
    rear_ = (rear_ + 1) % size_;
    ++count_;
}

int Queue::pop() {
    assert(!isEmpty());
    int data = pArr_[front_];
    front_ = (front_ + 1) % size_;
    --count_;
    return data;
}
