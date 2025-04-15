#include <iostream>
#include "empty.h"

int main()
{
    Empty e1;      // 기본 생성자 호출  
    Empty e2 = e1; // 복사 생성자 호출

    e1 = e2;

    Empty *p1 = &e1;    //e1.operator&()    &연산
    
    const Empty *p2 = &e3;  // const 
    
    return 0;   // 소멸자 호출

}