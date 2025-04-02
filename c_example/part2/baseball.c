// 숫자 3개를 만드시오 [랜덤]  (서로 다른 숫자 0-9)
// 숫자 3개를 입력 받으시오
// 위치가 다르지만 숫자가 같으면  ball + 1
// 모든 데이터의 위치와 숫자가 동일하면 성공
// 시도 횟수를 출력하는 프로그램을 만드세요.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main()
{
    int question[3];
    int answer[3];
    srand(time(NULL));

    question[0] = rand() % 10 ;

    do{
    question[1] = rand() % 10 ;
    } while (question[0] == question[1]);


    do{
        question[2] = rand() % 10 ;
    } while (question[0] == question[2] || question[1] == question[2]);
    printf("%d %d %d\n", question[0], question[1], question[2]);

    int count = 0;

    while(true){
        printf("숫자 세개를 입력해 주세요. : ");
        for (int i = 0; i < 3; ++i){
            scanf("%d", &answer[i]);
        }

        //비교
        int strike = 0;
        int ball = 0;

        //스트라이크 & 볼 판별
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                if(question[i] == answer[j]){
                    if(i == j)
                        ++strike;
                    else
                        ++ball;
                }
            }
        }
        printf("strike: %d \t Ball: %d\n", strike, ball);
        ++count;
        
        if(strike == 3)
            break;

    }
    printf("축하합니다. 당신의 시도 횟수는 %d 입니다.", count);
    return 0;
}