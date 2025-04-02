// 짝수 홀수 구별하기 짝수이면 1 홀수이면 0
#include <stdio.h>

int main(void)
{
    int num;
    printf("숫자를 넣으세요 : ");
    scanf("%d", &num);

    int isOdd;
    //isOdd = num % 2;
    isOdd = (num % 2 == 1);

    printf("num: %d \t isOdd : %d\n", num, isOdd);

    return 0;
}