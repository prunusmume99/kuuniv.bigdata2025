#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
    static const int QUEUE_SIZE = 100;
    int* pArr_;
    int size_;
    int front_;
    int rear_;
    int count_;

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
