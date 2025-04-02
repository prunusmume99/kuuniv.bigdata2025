// 이 프로그램의 목적은 n의 제곱을 만들어서 2의 62제곱을 프린트하시오.

#include <stdio.h>
long long power(long long base, int exponent) ;
void power2(int base, int exponent, long long *result);

int main(void)
{
    long long result = power(2, 62);
    printf("2 power of 62 = %lld\n", result);
    long long result2 = 1;
    power2(2, 62, &result2);
    printf("2 power of 62 = %lld\n", result2);
    return 0;
}

long long power(long long base, int exponent)
{
    long long result = 1;
    for(int i = 0; i < exponent; i++)
        result *= base;
    return result;
}

void power2(int base, int exponent, long long *result)
{
    for(int i = 0; i < exponent; i++)
        *result *= base;
}