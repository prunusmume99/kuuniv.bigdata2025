#ifndef QUEUE_H
#define QUEUE_H

#include "array.h"

class Queue {
private:
    static const int QUEUE_SIZE;
    Array arr_;    // 내부 배열 객체 (has-a)
    int front_;    // 데이터 꺼낼 위치
    int rear_;     // 데이터 넣을 위치
    int count_;    // 현재 요소 개수

    Queue(const Queue&);
    Queue& operator=(const Queue&);

public:
    explicit Queue(int size = QUEUE_SIZE);
    ~Queue();

    int size() const;
    int remain() const;

    bool isEmpty() const;
    bool isFull() const;

    void push(int data);
    int pop();
};

#endif
