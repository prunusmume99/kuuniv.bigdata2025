// 점수를 출력하는 코드  A - F
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int score;
    if (argc < 2) 
    {
        printf("인자를 하나 넣어서 실행하세요.\n");
        return 0;
    }
    score = atoi(argv[1]);

    if (score >= 90)
    {
        printf("score : %d === A\n", score);
    }
    else if(score >=80)
    {
        printf("score : %d === B\n", score);
    }
    else if(score >=70)
    {
        printf("score : %d === C\n", score);
    }
    else if(score >=60)
    {
        printf("score : %d === D\n", score);
    }
    else if(score >=50)
    {
        printf("score : %d === E\n", score);
    }
    else 
    {
        printf("score : %d === F\n", score);
    }
    return 0;
}