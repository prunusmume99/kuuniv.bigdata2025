#include <stdio.h>

int main(void){
    int var_a;
    int *pVar_a;
    int **ppVar_a;

    var_a = 100;
    pVar_a = &var_a;
    ppVar_a = &pVar_a;

   **ppVar_a = 200;
   printf("a : %d\n, &var_a: %p\n", var_a, &var_a);
   printf("pVar_a: %p\n, *pVar_a: %d\n", pVar_a, *pVar_a);
   printf("ppVar_a: %p\n, *ppVar_a : %p\n, **ppVar_a: %d\n", ppVar_a, *ppVar_a, **ppVar_a);

    return 0;
}