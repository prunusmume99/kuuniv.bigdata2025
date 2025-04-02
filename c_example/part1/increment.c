#include <stdio.h>

int main(void)
{
    int a, b;
    // 'a' 라는 가비지 값, 임의의 ? 
    a = 5;
    b = ++a;
    printf("a : %d\t b: %d", a, b);

    a = 5;
    b = a++;
    printf("a : %d\t b: %d", a, b);

    return 0;
}
