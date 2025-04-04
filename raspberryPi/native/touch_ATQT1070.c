
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define TOUCH_ADDR 0x1b   
#define TOUCH_READ_REG 0x03

void i2C_init(int fd, int freq);

int main(void)
{
    //wiringPiSertipGpio();
    int touch_fd = wiringPiI2CSetup(TOUCH_ADDR);

    while (1)
    {
        int touch_value = wiringPiI2CReadReg8(touch_fd, TOUCH_READ_REG);
        printf("touch : %d\n", touch_value);
        delay(100);
    }
       return 0;
}