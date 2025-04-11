#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
    int* pArr;
    int front;
    int rear;
    int size;

public:
    Queue(int size);       // 생성자
    ~Queue();              // 소멸자

    void push(int data);   // 데이터 삽입
    int pop();             // 데이터 제거
    bool isEmpty() const;  // 큐가 비어있는지 확인
};

#endif
