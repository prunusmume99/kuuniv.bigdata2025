#include <limits.h>
#include <stdio.h>

void printHello();

int main(void)
{
    printHello(); 
    printf("char_bit : %d\n", CHAR_BIT);
    printf("char_max : %d\n", CHAR_MAX);
    printf("INT_MIN : %d \t INT_MAX : %d", INT_MIN, INT_MAX);
    printf("LONG_MIN : %ld \t LONG_MAX : %ld", LONG_MIN, LONG_MAX);
    printf("INT_MAX + 1 : %d\n", INT_MAX + 1);
    return 0;
}

void printHello() 
{
    printf("hello, world\n");
}
