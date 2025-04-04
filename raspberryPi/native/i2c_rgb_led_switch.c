// // 스위치 1,2,3 을 이용해서
// // 1-> R 색 변화
// // 2-> G 색 변화
// // 3-> B 색 변화
// // 스위치를 오래 누르면(0 ~ 1 초)-> (0~4095) 높은 값으로 변화 할 수 있게 만들기

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <wiringPi.h>
// #include <wiringPiI2C.h>

// #define RGB_SERVO_I2C_ADDR 0x5e
// #define PCA9685_LED_ON_L 0x06
// #define PCA9685_PRESCALE 0xFE
// #define PCA9685_MODE1 0x00

// #define SW1 4
// #define SW2 17
// #define SW3 27
// #define SW4 22

// void SW_ISR1R(void);
// void SW_ISR2R(void);
// void SW_ISR3R(void);
// void SW_ISR1F(void);
// void SW_ISR2F(void);
// void SW_ISR3F(void);
// void i2C_init(int fd, int freq);

// int r_value, g_value, b_value;
// int r_start_time, g_start_time, b_start_time;
// int r_pushed, g_pushed, b_pushed;

// int main(void)
// {
//     int rgb_servo_fd = wiringPiI2CSetup(RGB_SERVO_I2C_ADDR);
//     i2C_init(rgb_servo_fd, 0x79); // 50 hz

//     wiringPiISR(SW1, INT_EDGE_BOTH, SW_ISR1R);
//     wiringPiISR(SW2, INT_EDGE_BOTH, SW_ISR2R);
//     wiringPiISR(SW3, INT_EDGE_BOTH, SW_ISR3R);

//     pinMode(SW1, INPUT);
//     pinMode(SW2, INPUT);
//     pinMode(SW3, INPUT);
//     pinMode(SW4, INPUT);

//     while (1)
//     {
//         wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 2, r_value);
//         wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 6, g_value);
//         wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 10, b_value);
//     }

//     return 0;
// }

// void i2C_init(int fd, int freq)
// {
//     wiringPiSetupGpio();
//     wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0x01);    // 리셋
//     delay(10);                                        // 리셋 후 대기
//     wiringPiI2CWriteReg8(fd, PCA9685_PRESCALE, freq); // 주파수 설정
//     wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0xA1);

//     wiringPiI2CWriteReg16(fd, PCA9685_LED_ON_L, 0);     // 빨간색
//     wiringPiI2CWriteReg16(fd, PCA9685_LED_ON_L + 4, 0); // 녹색
//     wiringPiI2CWriteReg16(fd, PCA9685_LED_ON_L + 8, 0); // 파란색
// }

// void SW_ISR1R(void)
// {
//     if (!r_pushed)
//     {
//         r_start_time = millis();
//         r_pushed = 1;
//     }
//     else
//     {
//         unsigned int press_time = millis() - r_start_time;
//         r_value = (press_time * 4095 / 1000);
//         if (r_value >= 4096)
//             r_value = 4095;
//         printf("R: %d\n", r_value);
//         r_pushed = 0;
//     }
// }

// void SW_ISR2R(void)
// {
//     if (!g_pushed)
//     {
//         g_start_time = millis();
//         g_pushed = 1;
//     }
//     else
//     {
//         unsigned int press_time = millis() - g_start_time;
//         g_value = (press_time * 4095 / 1000);
//         if (g_value >= 4096)
//             g_value = 4095;
//         printf("G: %d\n", g_value);
//         g_pushed = 0;
//     }
// }

// void SW_ISR3R(void)
// {
//     if (!b_pushed)
//     {
//         b_start_time = millis();
//         b_pushed = 1;
//     }
//     else
//     {
//         unsigned int press_time = millis() - b_start_time;
//         b_value = (press_time * 4095 / 1000);
//         if (b_value >= 4096)
//             b_value = 4095;
//         printf("B: %d\n", b_value);
//         b_pushed = 0;
//     }
// }

// led 숙제 코드 (gpt 활용)

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <wiringPi.h>
// #include <wiringPiI2C.h>

// #define RGB_SERVO_I2C_ADDR 0x5e     // 모듈의 I2C 주소
// #define PCA9685_LED_ON_L 0x06       // 각 채널 PWM의 시작 주소
// #define PCA9685_PRESCALE 0xFE       // PWM 주파수 조정용 레지스터
// #define PCA9685_MODE1 0x00          // 제어 모드 레지스터

// // 스위치 정의 (SW1 = RED, SW2 = GREEN, SW3 = BLUE)
// #define SW1 4
// #define SW2 17
// #define SW3 27

// void i2C_init(int fd, int freq);
// void setColor(int fd, int r, int g, int b);

// int main(void)
// {
//     int rgb_servo_fd = wiringPiI2CSetup(RGB_SERVO_I2C_ADDR);
//     i2C_init(rgb_servo_fd, 0x79); // 50 Hz

//     wiringPiSetupGpio(); // BCM 핀번호 기준
//     pinMode(SW1, INPUT);
//     pinMode(SW2, INPUT);
//     pinMode(SW3, INPUT);

//     pullUpDnControl(SW1, PUD_DOWN);
//     pullUpDnControl(SW2, PUD_DOWN);
//     pullUpDnControl(SW3, PUD_DOWN);

//     while (1)
//     {
//         int brightness = 0;

//         if (digitalRead(SW1)) // RED  스위치가 눌리면 내부에서 밝기를 점점 증가시키는 while 루프 실행
//         {
//             while (digitalRead(SW1) && brightness < 4095)
//             {
//                 setColor(rgb_servo_fd, brightness, 0, 0);
//                 brightness += 40; // 누르고 있는 동안 밝기 점점 증가(+40)
//                 delay(50);
//             } 
//         }
//         else if (digitalRead(SW2)) // GREEN
//         {
//             while (digitalRead(SW2) && brightness < 4095)
//             {
//                 setColor(rgb_servo_fd, 0, brightness, 0);
//                 brightness += 40;
//                 delay(50);
//             }
//         }
//         else if (digitalRead(SW3)) // BLUE
//         {
//             while (digitalRead(SW3) && brightness < 4095)
//             {
//                 setColor(rgb_servo_fd, 0, 0, brightness);
//                 brightness += 40;
//                 delay(50);
//             }
//         }
//         else
//         {
//             setColor(rgb_servo_fd, 0, 0, 0); // 손을 떼면 루프 탈출하고 다음에 들어오는 조건은 모두 false라 setcolor(0,0,0) 꺼짐
//         }

//         delay(10); // loop 안정화
//     }

//     return 0;
// }

// void i2C_init(int fd, int freq) 
// {
//     wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0x00);     // 모듈 리셋
//     delay(10);
//     wiringPiI2CWriteReg8(fd, PCA9685_PRESCALE, freq);  // PWM 주파수 설정 /프리스케일 설정
//     wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0xA1);     // auto increment + enable
// }

// void setColor(int fd, int r, int g, int b)
// {
//     wiringPiI2CWriteReg16(fd, PCA9685_LED_ON_L + 2, r);   // RED
//     wiringPiI2CWriteReg16(fd, PCA9685_LED_ON_L + 6, g);   // GREEN
//     wiringPiI2CWriteReg16(fd, PCA9685_LED_ON_L + 10, b);  // BLUE
// }


// 스위치 1,2,3 을 이용해서
// 1-> R 색 변화
// 2-> G 색 변화
// 3-> B 색 변화
// 스위치를 오래 누르면(0 ~ 1 초)-> (0~4095) 높은 값으로 변화 할 수 있게 만들기

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define RGB_SERVO_I2C_ADDR 0x5e
#define PCA9685_LED_ON_L 0x06
#define PCA9685_PRESCALE 0xFE
#define PCA9685_MODE1 0x00

#define SW1 4
#define SW2 17
#define SW3 27
#define SW4 22

void SW_ISR1R(void);
void SW_ISR2R(void);
void SW_ISR3R(void);
void SW_ISR1F(void);
void SW_ISR2F(void);
void SW_ISR3F(void);
void i2C_init(int fd, int freq);

int r_value, g_value, b_value;
int r_start_time, g_start_time, b_start_time;
int r_pushed, g_pushed, b_pushed;

int main(void)
{
    int rgb_servo_fd = wiringPiI2CSetup(RGB_SERVO_I2C_ADDR);
    i2C_init(rgb_servo_fd, 0x79); // 50 hz

    wiringPiISR(SW1, INT_EDGE_BOTH, SW_ISR1R);
    wiringPiISR(SW2, INT_EDGE_BOTH, SW_ISR2R);
    wiringPiISR(SW3, INT_EDGE_BOTH, SW_ISR3R);

    pinMode(SW1, INPUT);
    pinMode(SW2, INPUT);
    pinMode(SW3, INPUT);
    pinMode(SW4, INPUT);

    while (1)
    {
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 2, r_value);
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 6, g_value);
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 10, b_value);
    }

    return 0;
}

void i2C_init(int fd, int freq)
{
    wiringPiSetupGpio();
    wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0x10);    // 리셋
    delay(10);                                        // 리셋 후 대기
    wiringPiI2CWriteReg8(fd, PCA9685_PRESCALE, freq); // 주파수 설정
    wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0xA1);

    wiringPiI2CWriteReg16(fd, PCA9685_LED_ON_L, 0);     // 빨간색
    wiringPiI2CWriteReg16(fd, PCA9685_LED_ON_L + 4, 0); // 녹색
    wiringPiI2CWriteReg16(fd, PCA9685_LED_ON_L + 8, 0); // 파란색
}

void SW_ISR1R(void)
{
    if (!r_pushed)
    {
        r_start_time = millis();
        r_pushed = 1;
    }
    else
    {
        unsigned int press_time = millis() - r_start_time;
        r_value = (press_time * 4095 / 1000);
        if (r_value >= 4096)
            r_value = 4095;
        printf("R: %d\n", r_value);
        r_pushed = 0;
    }
}

void SW_ISR2R(void)
{
    if (!g_pushed)
    {
        g_start_time = millis();
        g_pushed = 1;
    }
    else
    {
        unsigned int press_time = millis() - g_start_time;
        g_value = (press_time * 4095 / 1000);
        if (g_value >= 4096)
            g_value = 4095;
        printf("G: %d\n", g_value);
        g_pushed = 0;
    }
}

void SW_ISR3R(void)
{
    if (!b_pushed)
    {
        b_start_time = millis();
        b_pushed = 1;
    }
    
    else
    {
        unsigned int press_time = millis() - b_start_time;
        b_value = (press_time * 4095 / 1000);
        if (b_value >= 4096)
            b_value = 4095;
        printf("B: %d\n", b_value);
        b_pushed = 0;
    }
}