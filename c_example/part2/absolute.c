#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    //숫자입력
    int num;
    int state;
    printf("숫자를 입력하세요 : ");
    scanf("%d", &num);
    //절댓값 자리
    if( num < 0)
    {
        state = false;
    }
    else
    {
        state = true;
    }
    num = state ? num : -num;
    //숫자출력
    printf("주어진 숫자의 절대값은 %d 이다.\n",num);
    return 0 ;

}