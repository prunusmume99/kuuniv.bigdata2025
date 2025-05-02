#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define THREAD_NUM 5
#define LOOP_COUNT 1000000

void *thread_main(void *arg);  // 쓰레드 함수
long long num = 0;
pthread_mutex_t mtx;  // 뮤텍스

int main()
{
    pthread_t t_id[THREAD_NUM];
    void *thr_ret[THREAD_NUM];

    pthread_mutex_init(&mtx, NULL);  // ✅ 뮤텍스 초기화

    // 쓰레드 생성
    for (int i = 0; i < THREAD_NUM; ++i)
        pthread_create(&t_id[i], NULL, thread_main, NULL);

    // 쓰레드 종료 대기 및 결과 수신
    for (int i = 0; i < THREAD_NUM; ++i)
    {
        pthread_join(t_id[i], &thr_ret[i]);
        printf("쓰레드에서 받아온 메세지: %s", (char *)thr_ret[i]);
        free(thr_ret[i]);  // ✅ 동적 메모리 해제
    }

    pthread_mutex_destroy(&mtx);  // ✅ 뮤텍스 해제

    printf("쓰레드 끝 메인 시작!! \n");
    for (int i = 0; i < 3; i++)
    {
        sleep(1);
        puts("running main()");
    }

    printf("최종 num 값: %lld\n", num);  // ✅ 예상값: 5,000,000
    return 0;
}

void *thread_main(void *arg)
{
    char *msg = (char *)malloc(50);
    strcpy(msg, "Hello, I'm from thread--- \n");

    for (int i = 0; i < LOOP_COUNT; i++)
    {
        pthread_mutex_lock(&mtx);
        num += 1;
        pthread_mutex_unlock(&mtx);
    }

    return (void *)msg;
}
