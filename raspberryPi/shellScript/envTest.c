
#include <stdio.h>
#include <stdlib.h>

int main(void){
    printf("name : %s\n", getenv("name"));
    printf("age : %s\n", getenv("age"));
    return 0;
}