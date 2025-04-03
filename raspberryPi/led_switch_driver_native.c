// cc -o led_switch_driver_native led_switch_driver_native.c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int fd;
    char buf[4] = {0};

    // 드라이버 열기
    fd = open("/dev/led_switch_driver", O_RDWR);
    if (fd < 0)
    {
        printf("led_switch_driver open failed\n");
        return -1;
    }

    for (int i = 0; i < 20; ++i) // 20번 반복 (필요에 따라 조정 가능)
    {
        // 스위치 상태 읽기
        if (read(fd, buf, sizeof(buf)) < 0)
        {
            perror("read error");
            close(fd);
            return -1;
        }

        printf("SW -> sw1: %d, sw2: %d, sw3: %d, sw4: %d\n", buf[0], buf[1], buf[2], buf[3]);

        // 읽은 값을 그대로 LED에 쓰기
        if (write(fd, buf, sizeof(buf)) < 0)
        {
            perror("write error");
            close(fd);
            return -1;
        }

        sleep(1); // 1초 대기
    }

    close(fd);
    return 0;
}