#include <arpa/inet.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <wait.h>

void error_handling(char *message);
void read_childproc(int sig);

#define BUF_SIZE 30

int main(int argc, char *argv[])
{
    int serv_sock, clnt_sock;
    int str_len;
    pid_t pid;
    char buf[BUF_SIZE];

    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_addr_size;

    if (argc != 2)
    {
        printf("사용법: %s <port>\n", argv[0]);
        exit(1);
    }

    // 시그널 설정 (자식 종료 감지)
    struct sigaction act;
    act.sa_handler = read_childproc;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGCHLD, &act, 0);

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1)
        error_handling("socket() 만들기 실패");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    int option = 1;
    setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("바인드 에러!!!");

    if (listen(serv_sock, 5) == -1)
        error_handling("리슨 에러");

    while (1)
    {
        clnt_addr_size = sizeof(clnt_addr);
        clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
        if (clnt_sock == -1)
            continue;
        else
            printf("Connected client : %s\n", inet_ntoa(clnt_addr.sin_addr));

        pid = fork();
        if (pid == -1)
        {
            close(clnt_sock);
            continue;
        }

        if (pid == 0) // 자식 프로세스
        {
            close(serv_sock);
            while ((str_len = read(clnt_sock, buf, BUF_SIZE)) != 0)
            {
                write(clnt_sock, buf, str_len);
                buf[str_len] = '\0'; // 문자열 종료 처리
                printf("클라이언트로부터 받은 메시지: %s", buf);
            }
            close(clnt_sock);
            printf("client 연결 종료... %s\n", inet_ntoa(clnt_addr.sin_addr));
            return 0;
        }
        else // 부모 프로세스
        {
            close(clnt_sock);
        }
    }

    close(serv_sock);
    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

void read_childproc(int sig)
{
    int status;
    pid_t id = waitpid(-1, &status, WNOHANG);
    if (WIFEXITED(status))
    {
        printf("프로세스 제거 id: %d\n", id);
        printf("자식이 보낸 번호: %d\n", WEXITSTATUS(status));
    }
}
