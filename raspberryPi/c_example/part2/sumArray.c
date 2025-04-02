// 배열을 int로 만들어서 랜덤 (0~ 100) 합을 구해서 프린트 하기

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int randomNumder[10];
    int sum = 0;
    srand(time(NULL));
    for(int i = 0 ; i < 10; ++i)
    {
        randomNumder[i] = rand( ) % 100 ;
    }
    for (int i = 0 ; i < 10; ++i)
    {
        sum += randomNumder[i];
        printf("%d", randomNumder[i]);
    }
    printf("\n 10개 배열의 총합은 %d이다.\n", sum);
    return 0;
}