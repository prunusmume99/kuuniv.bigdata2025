#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int i = 0;
    while(true)
    {
        printf("%d 번 출력입니다.\n", i + 1); 
        if(i == 10)
            break ;
        ++i ;
    }
    return 0;
}