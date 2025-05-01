#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/select.h>

#define BUF_SIZE 30
void error_handling(char *message);

int main(int argc, char *argv[])
{
    int sock;
    int str_len;
    char buf[BUF_SIZE];
    struct sockaddr_in brd_addr;
    fd_set reads, temps;
    struct timeval timeout;
    int result;

    if (argc != 3)
    {
        printf("사용법: %s <BROAD IP> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_DGRAM, 0); // UDP 설정
    if (sock == -1)
        error_handling("socker() 만들기 실패");

    memset(&brd_addr, 0, sizeof(brd_addr));
    brd_addr.sin_family = AF_INET;
    brd_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    brd_addr.sin_port = htons(atoi(argv[2])); // Broadcast port

    if (bind(sock, (struct sockaddr *)&brd_addr, sizeof(brd_addr)) == -1)
        error_handling("bind 에러!!!");

    FD_ZERO(&reads);
    FD_SET(sock, &reads);

    printf("Broadcast 메시지 수신 대기 중...\n");
    while (1)
    {
        temps = reads;
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;

        result = select(sock + 1, &temps, 0, 0, &timeout);
        if (result == -1)
        {
            puts("select 에러!!");
            break;
        }
        else if (result == 0)
        {
            puts("Time out!!");
            continue;
        }

        if (FD_ISSET(sock, &temps))
        {
            str_len = recvfrom(sock, buf, BUF_SIZE - 1, 0, NULL, 0);
            if (str_len < 0)
                break;
            buf[str_len] = 0;
            fputs(buf, stdout);
        }
    }

    close(sock);
    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}