#include <stdio.h>

int main(void)
{
    char ch;
    char str[100];

    printf("문자를 입력하세요: ");
    ch = getc(stdin);
    printf("입력한 문자는 %c 입니다.", ch);
    ch = getchar();

    ch = getchar();
    printf("입력한 문자는 %c입니다.", ch);
    scanf("%s", str);
    printf("입력한 문자열은 %s입니다.", str);
    // 버퍼의 개행 문자가 있다.
    getchar();
    return 0;
}