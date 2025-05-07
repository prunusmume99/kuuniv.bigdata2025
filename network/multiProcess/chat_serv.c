#include <arpa/inet.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 100
#define MAX_CLIENT 20

typedef struct
{
    int sockfd;
    struct sockaddr_in addr;
    int clnt_socks_index;
} ClientInfo;

void error_handling(char *message);
void *handle_clnt(void *arg);
void broadcast_msg(char *msg, int len, int sender_fd);

int clnt_cnt = 0;
int clnt_socks[MAX_CLIENT];
pthread_mutex_t mtx;
ClientInfo clients[MAX_CLIENT] = {0};

int main(int argc, char *argv[])
{
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_addr_size;
    pthread_t t_id;

    if (argc != 2)
    {
        printf("사용법: %s <port>\n", argv[0]);
        exit(1);
    }

    pthread_mutex_init(&mtx, NULL);
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1)
        error_handling("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    int option = 1;
    setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));
    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("bind() error");
    if (listen(serv_sock, 5) == -1)
        error_handling("listen() error");

    printf("Chat Server Started...\n");
    while (1)
    {
        clnt_addr_size = sizeof(clnt_addr);
        clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
        if (clnt_sock == -1)
            continue;

        pthread_mutex_lock(&mtx);
        if (clnt_cnt < MAX_CLIENT)
        {
            clients[clnt_cnt].sockfd = clnt_sock;
            clients[clnt_cnt].addr = clnt_addr;
            clients[clnt_cnt].clnt_socks_index = clnt_cnt;
            clnt_socks[clnt_cnt++] = clnt_sock;
            pthread_mutex_unlock(&mtx);

            pthread_create(&t_id, NULL, handle_clnt, (void *)&clnt_sock);
            pthread_detach(t_id);
            printf("New client connected! IP: %s, Total clients: %d\n", 
                   inet_ntoa(clnt_addr.sin_addr), clnt_cnt);
        }
        else
        {
            pthread_mutex_unlock(&mtx);
            close(clnt_sock);
            printf("Maximum client limit reached\n");
        }
    }

    close(serv_sock);
    pthread_mutex_destroy(&mtx);
    return 0;
}

void *handle_clnt(void *arg)
{
    int str_len;
    char buf[BUF_SIZE];
    int clnt_sock = *(int *)arg;
    int cl_index = -1;

    // Find client index
    pthread_mutex_lock(&mtx);
    for (int i = 0; i < clnt_cnt; i++)
    {
        if (clnt_socks[i] == clnt_sock)
        {
            cl_index = i;
            break;
        }
    }
    pthread_mutex_unlock(&mtx);

    while ((str_len = read(clnt_sock, buf, BUF_SIZE)) != 0)
    {
        if (str_len == -1)
            break;

        buf[str_len] = '\0';
        printf("Message from %s: %s", inet_ntoa(clients[cl_index].addr.sin_addr), buf);
        broadcast_msg(buf, str_len, clnt_sock);
    }

    // Client disconnected
    pthread_mutex_lock(&mtx);
    if (cl_index != -1)
    {
        printf("Client disconnected! IP: %s\n", inet_ntoa(clients[cl_index].addr.sin_addr));
        
        // Move last client to this position
        if (cl_index != clnt_cnt - 1)
        {
            clnt_socks[cl_index] = clnt_socks[clnt_cnt - 1];
            clients[cl_index] = clients[clnt_cnt - 1];
            clients[cl_index].clnt_socks_index = cl_index;
        }
        clnt_cnt--;
    }
    pthread_mutex_unlock(&mtx);

    close(clnt_sock);
    return NULL;
}

void broadcast_msg(char *msg, int len, int sender_fd)
{
    pthread_mutex_lock(&mtx);
    for (int i = 0; i < clnt_cnt; i++)
    {
        if (clnt_socks[i] != sender_fd)
        {
            write(clnt_socks[i], msg, len);
        }
    }
    pthread_mutex_unlock(&mtx);
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}