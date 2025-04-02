#include <stdio.h>

int main(void)
{
    int a, b;
    printf("Input a, b: ");
    scanf("%d %d", &a, &b);

    printf("PLUS %d + %d = %d\n", a, b, a + b);
    printf("MINUS %d - %d = %d\n", a, b, a - b);
    printf("MULTIPLY %d * %d = %d\n", a, b, a * b);
    printf("DIVISION %d / %d = %d\n", a, b, a / b);
    printf("나머지 %d 나머지 %d = %d\n", a, b, a % b);  

    return 0;
}
