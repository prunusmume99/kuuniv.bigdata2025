#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 1024
void error_handling(char *message);

int main(int argc, char *argv[])
{
    int sock;

    struct sockaddr_in serv_addr;

    if (argc != 3)
    {
        printf("사용법: %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0); // TCP 설정
    if (sock == -1)
        error_handling("socket() 열기 실패!!");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]); // 서버 IP
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("connect() 연결 실패!!!");
    else
        puts("Connected............");

    char message[BUF_SIZE];
    int str_len, recv_len, recv_cnt;

    while (1)
    {
        fputs("메세지를 넣으세요(Q 나가기): ", stdout);
        fgets(message, BUF_SIZE, stdin);

        if (!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
            break;

        str_len = write(sock, message, strlen(message));

        recv_len = 0;  // ✅ 여기로 옮겨야 정상 작동
        while (recv_len < str_len)
        {
            recv_cnt = read(sock, message + recv_len, BUF_SIZE - 1);
            if (recv_cnt == -1)
            {
                fputs("read() 에러!!!", stderr);
                break;
            }
            recv_len += recv_cnt;
        }

        message[recv_len] = '\0';  // ✅ 정확한 수신 길이 기준으로 종료
        printf("서버에서 온 메세지: %s", message);
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
