#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main()
{
    pid_t pid = fork();
    int status;

    if (pid == 0) // 자식1
    {
        return 3;
    }
    else
    {
        pid = fork();

        if (pid == 0) // 자식2
        {
            exit(7);
        }
        else // 부모
        {
            printf("자식 프로세스 ID: %d \n", pid);
            wait(&status);
            if (WIFEXITED(status))
                printf("자식1 이 보낸 메세지: %d \n", WEXITSTATUS(status));
            wait(&status);
            if (WIFEXITED(status))
                printf("자식2 이 보낸 메세지: %d \n", WEXITSTATUS(status));
            sleep(30);
        }
    }
    return 0;
}