#include <stdio.h>

int main(void)
{
    for(int i = 2; i <= 9; ++i) //단수 2단 ~9단 i
    {
        printf("---------%d단 입니다.--------\n\n", i);
        for(int j = 2; j <= 9; ++j) // 2부터 9까지 j
        {
            printf("%d X %d = %d\n", i, j, i * j);
        }
    }

    return 0;
}