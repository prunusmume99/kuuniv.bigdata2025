#include <stdio.h>

int main(void){
    int var_a, var_b;
    int *pVar;

    var_a = 100;
    pVar = &var_b; // 포인터는 변수와 연결을 해야 한다.

    *pVar = 200;

    printf("var_a : %d, &var_a: %p\n", var_a, &var_a);
    printf("*pVar : %d, pVar : %p\n", *pVar, pVar);
    printf("var_b : %d, &var_b: %p\n", var_b, &var_b);

    return 0;
}