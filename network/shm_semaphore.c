// ps aux    // 현재 시스템의 프로세스 상태를 보는 명령어 (참고용 주석)

#include <fcntl.h>      // 파일 제어 관련 (O_CREAT, O_RDWR)
#include <semaphore.h>  // 세마포어 관련 함수 (sem_open, sem_wait, sem_post, sem_close, sem_unlink)
#include <stdio.h>      // 입출력 함수 (printf, perror)
#include <stdlib.h>     // exit(), malloc(), free() 등
#include <string.h>     // 문자열 함수 (strcpy)
#include <sys/mman.h>   // 메모리 매핑 함수 (mmap, munmap)
#include <unistd.h>     // fork(), close(), ftruncate()
#include <wait.h>       // wait() 함수

#define SHM_NAME "/myshm"    // 공유 메모리 객체 이름
#define SEM_NAME "/mysem"    // 세마포어 객체 이름
#define SHM_SIZE 128         // 공유 메모리 크기 (128 바이트)

int main()
{
    // 공유 메모리 객체 생성 또는 열기 (읽기/쓰기 모드, 없으면 생성)
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);

    // 공유 메모리 크기를 128바이트로 설정
    ftruncate(shm_fd, SHM_SIZE);

    // 공유 메모리 객체를 프로세스 주소 공간에 매핑
    char *shm = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    // 세마포어 생성 또는 열기 (초기값 1, 즉 락이 풀린 상태)
    sem_t *sem = sem_open(SEM_NAME, O_CREAT, 0666, 1);

    // 프로세스 복제 (자식 프로세스 생성)
    pid_t pid = fork();

    if (pid == 0) // 자식 프로세스
    {
        sem_wait(sem); // 세마포어 락 획득 (다른 프로세스가 쓰고 있으면 대기)

        printf("자식\n");   // 자식 프로세스 출력
        printf("Child read: %s\n", shm); // 공유 메모리에서 읽은 내용 출력

        sem_post(sem); // 세마포어 락 해제

        munmap(shm, SHM_SIZE); // 공유 메모리 매핑 해제
        sem_close(sem);        // 세마포어 닫기
        exit(0);               // 자식 프로세스 정상 종료
    }
    else // 부모 프로세스
    {
        sem_wait(sem); // 세마포어 락 획득

        printf("부모\n");   // 부모 프로세스 출력
        strcpy(shm, "Hello from Parent!"); // 공유 메모리에 문자열 복사
        printf("Parent wrote: %s\n", shm); // 쓴 내용 출력

        sem_post(sem); // 세마포어 락 해제

        wait(NULL); // 자식 프로세스 종료까지 대기 (Zombie 프로세스 방지)

        munmap(shm, SHM_SIZE); // 공유 메모리 매핑 해제
        close(shm_fd);         // 공유 메모리 파일 디스크립터 닫기
        shm_unlink(SHM_NAME);  // 공유 메모리 객체 시스템에서 삭제

        sem_close(sem);        // 세마포어 닫기
        sem_unlink(SEM_NAME);  // 세마포어 시스템에서 삭제
    }

    return 0; // 메인 함수 종료
}
