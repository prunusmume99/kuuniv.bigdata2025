#ifndef STACK_H
#define STACK_H

class Stack{
private:
    int *pArr;
    int size;
    int tos;

public:
    //void initStack(int size); // Constructor
    //void cleanupStack();      // destructor
    Stack(int size);            // 생성자
    ~Stack();                  //소멸자

    void push(int data);
    int pop();

};

 #endif 

 