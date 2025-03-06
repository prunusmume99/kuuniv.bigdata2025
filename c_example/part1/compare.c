//정수를 두 숫자를 받아서 크기 관계 0과 1로 프린트 하기
//시험 문제 ( 결과 값은 0 또는 1 true or false)
#include <stdio.h>

int main(void)
{
    int a, b;
    int greater;
    printf ("두 정수를 입력하세요 : ");
    scanf("%d %d", &a, &b);

    greater = a > b;
    printf("greater의 값은 %d 이다." , greater);

    return 0;
}