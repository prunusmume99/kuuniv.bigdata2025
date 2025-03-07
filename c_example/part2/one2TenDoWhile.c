#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int i = 0;
    do
    {
        printf("%d 번 출력입니다.\n", i + 1); 
        ++i;
    }   while (i < 10) ;
    return 0;
}