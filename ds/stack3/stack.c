
// Stack
// {
//     int array[100];
//     int tos;
// };

// void push(Stack *s, int data)
// {
//     // stack[tos] = data;
//     // ++tos;
//     s.array[s.tos] = data;
//     ++s.tos;
// }

// int pop(Stack *s)
// {
//     // --tos;
//     // return stack[tos];
//     --s.tos;
//     return s.array[s.tos];
// }

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void initStack(Stack *ps)
{
    ps->tos = 0;
}


// push 함수 정의
void push(Stack *ps, int data) {
    //s.array[s.tos] = data;
    // //++s.tos;
    // (*ps).array[(*ps).tos] = data;
    // ++(*ps).tos;

    // full ???
    if(ps->tos ==STACKSIZE){
        fprintf(stdout, "stack is full.\n");
        exit(1);
    }

    ps->array[ps->tos] = data;
    ++ps->tos;
}

// pop 함수 정의
int pop(Stack *ps) {
    //++s. tos;
    // //return s.array[s.tos]
    // --(*ps).tos;
    // return (*ps).array[(*ps).tos];

    // empty ???
    if(ps->tos == 0){
        fprintf(stdout, "stack is empty.\n");
        exit(2);
    }

    --ps->tos;
    return ps->array[ps->tos];
}
