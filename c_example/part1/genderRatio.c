#include <stdio.h>

int main(void)
{
    int man, woman;
    double sum, manRate, womanRate;

    // 입력 받는 코드
    printf("Input man, woman : ");
    scanf("%d %d", &man, &woman);

    // 연산 하는 코드
    //타입 캐스팅 sum = (double)man + (double)woman;
    sum = man + woman;
    manRate = man * 100.0 / sum; //남자 비율
    womanRate = woman * 100.0 / sum; //여자 비율

    printf("남자의 수는 %d명이고 여자의 수는 %d명이다. \n", man, woman);
    printf("총 수는 %.0f명\n", sum);
    printf("남자의 비율은 %.2f%%\n", manRate);
    printf("여자의 비율은 %.2f%%\n", womanRate);

    return 0;
}