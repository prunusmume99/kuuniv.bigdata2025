#include <cstdio>
#include <cstdlib>
#include "stack.h"
#include <cassert>

Stack::Stack(int size)
{
    //this->pArr =(int *)malloc(sizeof(int) * size);
    this->pArr = new int[size];
    assert(this->pArr); //예외처리할때 사용한다. 조건식이 참이면 계속 실행, 조건식이 거짓이면 프로그램 중단
   
    this->size = size;
    this->tos = 0;
}

Stack::~Stack()
{
   // free(this->pArr);
   delete [] this->pArr;
}

void Stack::push(int data)
{
    assert(this->tos != this->size);
    this->pArr[this->tos] = data;
    ++this->tos;
}
int Stack::pop()
{
    assert(this->tos != 0);
    --this->tos;
    return this->pArr[this->tos];

}