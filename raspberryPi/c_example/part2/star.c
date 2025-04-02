// 별표를 5줄 하나씩 늘어나는 모양을 출력하세요.
// *
// **
// ***
// ****
// *****
// 별표를 피라미드 모양으로 출력하세요.
//    *
//   ***
//  *****
// *******

#include <stdio.h>

int main(void)
{
    for(int i = 1; i <=5; ++i)
    {
            for(int j = 0 ; j < i; ++j) 
            {
                printf("*");
            }
            printf("\n") ;
    }
    for(int i = 1; i <=5; ++i)
    {
            for(int j = 1 ; j <=6 - i; ++j) 
            {
                printf(" ");
            }
            for(int j = 1 ; j <= 2 * i - 1; ++j) 
            {
                printf("*");
            }
            printf("\n") ;
    }
    
    return 0;
}

