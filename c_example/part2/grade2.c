// 점수를 출력하는 코드 A-F
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

    switch (score / 10)
    {
    case 10:
        printf("축하합니다. 100점이예요\n");
    case 9:
        printf("score : %d === A\n", score);
        break;
    case 8:
        printf("score : %d === B\n", score);
        break;
    case 7:
        printf("score : %d === C\n", score);
        break;
    case 6:
        printf("score : %d === D\n", score);
        break;
    default:
        printf("score : %d === F\n", score);
        break;
    }
    return 0;
}