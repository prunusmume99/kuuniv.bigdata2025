#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define PIPE1 "/tmp/pipe1" // 서버 -> 클라이언트
#define PIPE2 "/tmp/pipe2" // 클라이언트 -> 서버

int main()
{
    int fd1, fd2;
    char buffer[BUFFER_SIZE];

    printf("클라이언트 실행");

    fd1 = open(PIPE1, O_RDONLY);
    if (fd1 == -1)
    {
        perror("open pipe1");
        exit(EXIT_FAILURE);
    }
    printf("테스트4:\n");
    getchar();
    read(fd1, buffer, BUFFER_SIZE); // 대기
    printf("클라이언트에서 받은 메세지: %s\n", buffer);
    close(fd1);

    fd2 = open(PIPE2, O_WRONLY);
    if (fd2 == -1)
    {
        perror("open pipe2");
        exit(EXIT_FAILURE);
    }
    printf("테스트3:\n");
    char *message = "Hello from Client!";
    write(fd2, message, strlen(message) + 1);
    printf("서버로 보낸 메세지: %s\n", message);
    close(fd2);

    unlink(PIPE1);
    unlink(PIPE2);

    return 0;
}