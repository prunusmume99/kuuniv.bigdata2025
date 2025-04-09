#ifndef STACK_H
#define STACK_H

typedef struct stack {      // 기존 자료형 새 이름
    void *pArr;
    int eleSize;            // 동적 배열의 시작 주소를 저장(스택 내부 저장소)
    int size;               // 스택에 할당된 배열의 크기
    int tos;                // Top of Stack (스택의 현재 요소 개수 또는 마지막 요소의 인덱스)
} Stack;

void initStack(Stack *ps, int size, int eleSize);
void cleanupStack(Stack *ps);

void push(Stack *ps, const void * pData);
void pop(Stack *ps, void *pData); 
// 포인터가 가리키는 대상을 read only면 const
// 안붙어 있으면 포인터가 가리키는 대상의 값이 바뀐다는 것을 알수 있음 . 포인터 사용이유 1번


#endif
