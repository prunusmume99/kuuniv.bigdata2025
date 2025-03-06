#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    int year ;
    while (true)
    {
        printf("년도를 넣으세요. : ");
        scanf("%d", &year);
       // if(year % 4 == 0)
        //{
       //     printf("%d 년도는 윤년입니다.\n", year) ;
       // } 
       // else 
       // {
        printf("%d 년도는 %s입니다.\n", year, year % 4 ? "평년" : "윤년");
        if (!year)
            break;
    }
}