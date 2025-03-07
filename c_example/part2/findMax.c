// 10개의 랜덤한 0~100 배열을 만들고 가장 높은 값을 프린트 하세요.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int randomNumber[10];
    int max;

    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; ++i)
    {
        randomNumber[i] = rand() % 101;
        printf("%d , ", randomNumber[i]);
    }
    printf("\n");
    max = randomNumber[0];
    for (int i = 0; i < 10; ++i)
    {
        if (max < randomNumber[i])
            max = randomNumber[i];
    }
    printf("max : %d\n", max);
    return 0;
}