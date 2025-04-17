#ifndef STACK_H
#define STACK_H

#include "array.h"

class Stack {
private:
    static const int STACK_SIZE;
    Array arr_;   // has-a 관계: 배열을 직접 멤버로 가짐
    int tos_;     // top of stack

    Stack(const Stack&);
    Stack& operator=(const Stack&);

public:
    explicit Stack(int size = STACK_SIZE);
    ~Stack();

    int size() const;     // 전체 배열 크기
    int remain() const;   // 남은 공간 크기

    bool isEmpty() const;
    bool isFull() const;

    void push(int data);
    int pop();
};

#endif
