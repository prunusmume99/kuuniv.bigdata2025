#include <stdio.h>
#include <unistd.h>

int main(){
    pid_t pid = fork();

    if(pid==0)// 자식
    {
        puts("안녕, 나는 자식 프로세스야");
    } else  //부모 
    {
        printf("Child Process ID: %d \n", pid);
        sleep(30);
    }

    if(pid==0)
        puts("End 자식 프로세스 \n");
    else
        puts("End 부모 프로세스 \n");
    return 0;
}