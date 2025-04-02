// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <wiringPi.h>
// #include <wiringPiI2C.h>

// #define RGB_SERVO_I2C_ADDR 0x5e
// #define PCA9685_LED_ON_L 0x06
// #define PCA9685_PRESCALE 0xFE
// #define PCA9685_MODE1 0x00

// void i2C_init(int fd, int freq);

// int main(void)
// {
//     int rgb_servo_fd = wiringPiI2CSetup(RGB_SERVO_I2C_ADDR);
//     i2C_init(rgb_servo_fd, 0x79); // 50 hz
//     // 프리스케일 값 = (오실레이터 주파수 / (4096 * 원하는 주파수)) - 1
//     // 25000000 / (4096 * (0x79 + 1))=50.028817
//     srand(time(NULL)); // random 셋

//     wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L, 0);     // 빨간색
//     wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 4, 0); // 녹색
//     wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 8, 0); // 파란색

//     // 빨간색
//     wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 2, 4095);
//     delay(100);
//     wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 2, 0);
//     delay(100);

//     // 녹색
//     wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 6, 4095);
//     delay(100);
//     wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 6, 0);
//     delay(100);

//     // 파란색
//     wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 10, 4095);
//     delay(100);
//     wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 10, 0);
//     delay(100);

//     // 점점 밝아지는 코드
//     for (int i; i < 4096; ++i)
//     {
//         wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 2, i);
//         wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 6, 4096 - i);
//         wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 10, (i * 2) % 4046);
//         delay(1);
//     }
//     // 랜덤한 색깔
//     for (int i; i < 100; ++i)
//     {
//         wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 2, rand() % 4096);
//         wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 6, rand() % 4096);
//         wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 10, rand() % 4096);
//         delay(100);
//     };
//     return 0;
// }

// void i2C_init(int fd, int freq)
// {
//     wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0x01);    // 리셋
//     delay(10);                                        // 리셋 후 대기
//     wiringPiI2CWriteReg8(fd, PCA9685_PRESCALE, freq); // 주파수 설정
//     wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0xA1);
// }


// led 숙제 코드

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define RGB_SERVO_I2C_ADDR 0x5e     // 모듈의 I2C 주소
#define PCA9685_LED_ON_L 0x06       // 각 채널 PWM의 시작 주소
#define PCA9685_PRESCALE 0xFE       // PWM 주파수 조정용 레지스터
#define PCA9685_MODE1 0x00          // 제어 모드 레지스터

// 스위치 정의 (SW1 = RED, SW2 = GREEN, SW3 = BLUE)
#define SW1 4
#define SW2 17
#define SW3 27

void i2C_init(int fd, int freq);
void setColor(int fd, int r, int g, int b);

int main(void)
{
    int rgb_servo_fd = wiringPiI2CSetup(RGB_SERVO_I2C_ADDR);
    i2C_init(rgb_servo_fd, 0x79); // 50 Hz

    wiringPiSetupGpio(); // BCM 핀번호 기준
    pinMode(SW1, INPUT);
    pinMode(SW2, INPUT);
    pinMode(SW3, INPUT);

    pullUpDnControl(SW1, PUD_DOWN);
    pullUpDnControl(SW2, PUD_DOWN);
    pullUpDnControl(SW3, PUD_DOWN);

    while (1)
    {
        int brightness = 0;

        if (digitalRead(SW1)) // RED  스위치가 눌리면 내부에서 밝기를 점점 증가시키는 while 루프 실행
        {
            while (digitalRead(SW1) && brightness < 4095)
            {
                setColor(rgb_servo_fd, brightness, 0, 0);
                brightness += 40; // 누르고 있는 동안 밝기 점점 증가(+40)
                delay(50);
            } 
        }
        else if (digitalRead(SW2)) // GREEN
        {
            while (digitalRead(SW2) && brightness < 4095)
            {
                setColor(rgb_servo_fd, 0, brightness, 0);
                brightness += 40;
                delay(50);
            }
        }
        else if (digitalRead(SW3)) // BLUE
        {
            while (digitalRead(SW3) && brightness < 4095)
            {
                setColor(rgb_servo_fd, 0, 0, brightness);
                brightness += 40;
                delay(50);
            }
        }
        else
        {
            setColor(rgb_servo_fd, 0, 0, 0); // 손을 떼면 루프 탈출하고 다음에 들어오는 조건은 모두 false라 setcolor(0,0,0) 꺼짐
        }

        delay(10); // loop 안정화
    }

    return 0;
}

void i2C_init(int fd, int freq) 
{
    wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0x00);     // 모듈 리셋
    delay(10);
    wiringPiI2CWriteReg8(fd, PCA9685_PRESCALE, freq);  // PWM 주파수 설정 /프리스케일 설정
    wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0xA1);     // auto increment + enable
}

void setColor(int fd, int r, int g, int b)
{
    wiringPiI2CWriteReg16(fd, PCA9685_LED_ON_L + 2, r);   // RED
    wiringPiI2CWriteReg16(fd, PCA9685_LED_ON_L + 6, g);   // GREEN
    wiringPiI2CWriteReg16(fd, PCA9685_LED_ON_L + 10, b);  // BLUE
}
