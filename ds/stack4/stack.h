
// #ifndef STACK_H
// #define STACK_H
// #define STACKSIZE 100

// // 구조체 정의
// typedef struct stack {    // 기존 자료형 새 이름
//     int array[STACKSIZE];
//     int tos;
// } Stack;

// void initStack(Stack *ps);

// // 함수 원형 선언 (포인터로 수정해야 원본에 반영됨)
// void push(Stack *ps, int data);
// int pop(Stack *ps);

// #endif


#ifndef STACK_H
#define STACK_H
//#define STACKSIZE 100

typedef struct stack{
    //int array[STACKSIZE];
    int *pArr;
    int size;
    int tos;
}Stack;

void initStack(Stack *ps,int size);
void cleanupStack(Stack *ps);

void push(Stack *ps,int data);
int pop(Stack *ps);

 #endif 

 