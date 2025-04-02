#include <stdio.h>

int main(void)
{
    int num;
    char *string;
    //printf("숫자를 넣으시오: ");
    scanf("%d", &num);

    if (num >0)
    {
        string = "양수";
    }
    else if (num < 0)
    {
        string = "음수";
    }
    else{
        string = "영";
    }

    printf("%d 이 숫자는 %s 입니다.\n", num, string);
    return 0;
}