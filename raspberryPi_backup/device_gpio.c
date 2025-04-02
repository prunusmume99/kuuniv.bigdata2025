#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// physical pin
#define LED1 16
#define LED2 24
#define LED3 25
#define LED4 1

int main(void){
    int fd = open("/sys/class/gpio/export", O_WRONLY); // 리눅스의 기본적인 시스템 콜 함수
    write(fd,"16", strlen("16")); //write -> scanf? 
    close(fd);
    fd = open("/sys/class/gpio/gpio23/direction", O_WRONLY); // 리눅스의 기본적인 시스템 콜 함수
    write(fd,"out", strlen("out")); //write -> scanf? 
    close(fd);
    fd = open("/sys/class/gpio/gpio23/value", O_WRONLY);
    for(int i = 0; i < 5 ; ++i)
    {
        write(fd, "1", strlen("1"));
        sleep(1);
        write(fd, "0", strlen("0"));
        sleep(1);
    }
    close(fd);
    fd = open("/sys/class/gpio/unexport",O_WRONLY);
    write(fd, "16", strlen("16")); 
    close(fd);

    return 0;
}