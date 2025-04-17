#ifndef STACK_H
#define STACK_H

class Stack {
private:
    static const int STACK_SIZE = 100;
    int* pArr_;
    int size_;
    int tos_;

    Stack(const Stack&);
    Stack& operator=(const Stack&);

public:
    explicit Stack(int size = STACK_SIZE);
    ~Stack();

    int size() const;
    int remain() const;

    bool isEmpty() const;
    bool isFull() const;

    void push(int data);
    int pop();
};

#endif
