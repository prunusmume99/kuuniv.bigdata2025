// 1과 9 사이의 숫자인지 확인해서 맞으면 1 틀리면 0을 프린트 하기 (숙제)

#include <stdio.h>

int main(void)
{

    //변수 선언
    //숫자 선언

    int num;
    printf ("1에서 9 사이의 값을 입력하세요 :" );
    scanf("%d", &num);

    printf("1 <= %d <= 9 : %d\n" , num ,  1 <= num && num <= 9);

    return 0;
}