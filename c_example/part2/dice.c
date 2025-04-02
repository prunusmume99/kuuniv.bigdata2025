//  난수를 이용하여 1-6까지의 숫자를 만들기
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    int dice[30];
    srand(time(NULL));
    for(int i = 0 ; i < 30; ++i)
    {
        dice [1] = rand() % 6 + 1;
        printf("%d\n", dice[i]);
        printf("%p", &dice[i]);
    }
    printf("\n");
    // 각 배열을 변경 - 10을 곱하기
    for (int i = 1 ; i < 30; ++i)
    {
        dice[i] *= 10;
        printf("%d", dice[i]);
        printf("%p", &dice[i]);
    }
    printf("\n");
    return 0;
}