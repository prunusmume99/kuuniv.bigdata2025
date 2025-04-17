#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int* data_;
    int  capacity_;
    int  top_;  // top 인덱스

    void resize();  // 내부 배열 가득 찼을 경우 크기 늘리는 함수

public:
    Stack(int initCapacity = 10);         // 생성자
    Stack(const Stack& rhs);              // 복사 생성자
    Stack& operator=(const Stack& rhs);   // 복사 대입 연산자
    ~Stack();                             // 소멸자

    void push(int value);
    void pop();
    int  top() const;

    int  size() const;
    bool isEmpty() const;

    void clear();
    void print() const;
};

#endif
