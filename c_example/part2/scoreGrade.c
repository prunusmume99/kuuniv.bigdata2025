// A - F 까지 점수를 받아서 출력
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    char grades[] = {'F','F','F','F','F','F','D','C','B','A','\0'};
    int score;
    char grade = 'F';
    while(true)
    {
        printf("점수를 넣으세요 : ");
        scanf( "%d", &score);
        grade = 'F';

        if (score > 0 && score <=100){
            grade = grades [score / 10];
        }
        printf("점수는 : %d --- %c\n", score, grade);
    }
    return 0;
}