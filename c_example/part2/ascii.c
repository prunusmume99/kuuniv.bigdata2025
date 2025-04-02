// 1~127 아스키 코드를 출력하세요.
// ==> printf("%c", ch);
// 이중 for 문으로 만드세요.
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 
// 8 줄 출력

#include <stdio.h>

int main(void)
{
    char ch;
    for(int j = 0; j <= 7;  ++j)
    {
        printf("\n");
        for(int i = 0; i <= 15; ++i)
        {
            ch = i + 16 * j;
            printf("%d : %c ", ch, ch);
        }
    }
    return 0 ;
}