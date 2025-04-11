// #include <stdio.h>
// #include <stdlib.h>
// #include "stack.h"

// void initStack(Stack *ps)
// {
//     ps->tos = 0;
// }

// void push(Stack *ps, int data) {
//     if(ps->tos ==STACKSIZE){
//         fprintf(stdout, "stack is full.\n");
//         exit(1);
//     }

//     ps->array[ps->tos] = data;
//     ++ps->tos;
// }

// int pop(Stack *ps) {
 
//     if(ps->tos == 0){
//         fprintf(stdout, "stack is empty.\n");
//         exit(2);
//     }

//     --ps->tos;
//     return ps->array[ps->tos];
// }


#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "assert.h"

void initStack(Stack *ps,int size)
{
    ps->pArr = malloc(sizeof(int) * size);
    assert(ps->pArr/*!= NULL*/); //예외처리할때 사용한다., 조건식이 참이면 계속 실행, 조건식이 거짓이면 프로그램 중단
   
    ps->size = size;
    ps->tos = 0;
}

void cleanupStack(Stack *ps)
{
    free(ps->pArr);
}

void push(Stack *ps,int data)
{

    //if (ps->tos == STACKSIZE)
    // if (ps->tos == ps->size)
    // {
    //     fprintf(stderr,"stack is full.\n");
    //     exit(1);
    // }

    assert(ps->tos != ps->size);

    // (*ps).array[(*ps).tos]=data; 
    //  *(ps->pArr+ps->tos)=data;
   ps->pArr[ps->tos] = data;
   ++ps->tos;
}
int pop(Stack *ps)
{
    // if (ps->tos == 0)
    // {
    //     fprintf(stderr,"stack is empty.\n");
    //     exit(2);
    // }

    assert(ps->tos != 0);
    --ps->tos;
    //return (*ps).array[(*ps).tos];
    return ps->pArr[ps->tos];

}