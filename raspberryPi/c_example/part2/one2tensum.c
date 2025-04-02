// 100 + 101 + .... + 10000
// 10100 * (10000 - 100) / 2


#include <stdio.h>

int main(void)
{
    int sum = 0;

    for(int i = 0; i < 9901; i++)
    {
        sum += i;
    }
    printf("100부터 10000까지 더한 숫자는 %d 입니다.\n", sum);
    return 0;
}