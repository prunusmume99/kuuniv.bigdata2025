#include <stdio.h>
#include <string.h>

int main(void){
    int a = 100;
    int b ;

    //b = 0;
    memset(&b, 0, sizeof(int));
    printf("a : %d\tb: %d\n", a, b);

    //b = a;
    memcpy(&b, &a, sizeof(int));
    printf("a: %d\tb: %d\n", a, b);

    //int isEqual = (a == b);
    // int isEqual;
    // if (memcmp(&a, &b, sizeof(int)) == 0)
    //     isEqual = 1;
    // else
    //     isEqual = 0;

    //int isEqual = (memcmp(&a, &b, sizeof(int)) == 0) ? 1 : 0;
    int isEqual = !memcmp(&a, &b, sizeof(int));
    printf("a == b : %d\n", isEqual);

    return 0;
}