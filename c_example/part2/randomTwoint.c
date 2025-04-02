// 두 난수( 0 ~ 100) 를 발생시켜서 비교하기 
// 10 까지의 수를 비교해서 같아질때 까지 반복하기
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int a, b, i;
    double rand1, rand2;
    while (true)
    {
        i++;
        srand((unsigned int)time(NULL)+ i); //random 셋
        rand1 = rand() / (double)RAND_MAX * 10 ;
        srand((unsigned int)time(NULL) + 10000); //random 셋
        rand2 = rand() / (double)RAND_MAX * 10 ;

        a = rand1;
        b = rand2; // ctrl + h 하면 찾기 - 바꾸기 
        printf("0~100 사이의 랜덤한 숫자: %f\n", rand1);
        printf("0~100 사이의 랜덤한 숫자: %f\n", rand2);
        printf("%d > %d : %s\n", a, b, a > b ? "ture" : "false");
        printf("%d < %d : %s\n", a, b, a < b ? "ture" : "false");
        printf("%d == %d : %s\n", a, b, a == b ? "ture" : "false");
        printf("%d != %d : %s\n", a, b, a != b ? "ture" : "false");
        if(a == b)
            break;
    }
    return 0;
}