// 숫자를 입력 받아서 양수, 제로, 음수를 출력하는 프로그램
// if else 구문으로 만드세요.
// printf 는 한 번만 쓰세요.

#include <stdio.h>

int main(void)
{
    int num;
    printf("숫자를 입력하세요. : ") ;
    scanf("%d", &num);

    char *result;

    if(num > 0)
        result = "양수";
    else if(num == 0)
        result = "제로";
    else
        result = "음수";

    printf("%s입니다.\n", (num > 0) ? "양수" : (num == 0) ? "제로" : "음수");

    return 0;
}