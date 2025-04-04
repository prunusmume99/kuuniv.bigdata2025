#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <softTone.h>
#include <softPwm.h>

// MPU6050 설정
#define GYRO_ADDR 0x68
#define MPU6050_PWR_MGMT_1 0x6B
#define GYRO_CONFIG 0x1B
#define ACCEL_CONFIG 0x1C
#define GYRO_XOUT_H 0x43

// 피에조 및 LED 핀 (BCM 기준)
#define BUZZER_PIN 12
#define LED1 23
#define LED2 24
#define LED3 25
#define LED4 1

int doReMi[8] = {523, 587, 659, 698, 783, 880, 987, 1046};

// 절댓값 비교를 위한 함수
int is_over_threshold(float value, float threshold)
{
    return (value > threshold || value < -threshold);
}

// 자이로 움직임 감지 함수
int is_movement_detected(int fd, float threshold)
{
    int16_t gx = (wiringPiI2CReadReg8(fd, GYRO_XOUT_H) << 8) | wiringPiI2CReadReg8(fd, GYRO_XOUT_H + 1);
    int16_t gy = (wiringPiI2CReadReg8(fd, GYRO_XOUT_H + 2) << 8) | wiringPiI2CReadReg8(fd, GYRO_XOUT_H + 3);
    int16_t gz = (wiringPiI2CReadReg8(fd, GYRO_XOUT_H + 4) << 8) | wiringPiI2CReadReg8(fd, GYRO_XOUT_H + 5);

    float x = gx / 131.0;
    float y = gy / 131.0;
    float z = gz / 131.0;

    return is_over_threshold(x, threshold) || is_over_threshold(y, threshold) || is_over_threshold(z, threshold);
}

// 피에조 + LED 2초간 작동
void activate_alarm()
{
    // LED 모두 켜기
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);

    // 피에조 알람음 (2초 동안 짧게 반복)
    for (int i = 0; i < 8; ++i)  // 8번 × 250ms = 2초
    {
        softToneWrite(BUZZER_PIN, 1000); // 알람음 (1000Hz)
        delay(100); // 0.1초 울림
        softToneWrite(BUZZER_PIN, 0);    // 끔
        delay(150); // 0.15초 대기 (삐- 삐- 삐- 느낌)
    }

    // 종료: 소리 끄기 + LED 끄기
    softToneWrite(BUZZER_PIN, 0);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
}
int main(void)
{
    wiringPiSetupGpio();

    // MPU6050 초기화
    int gyro_fd = wiringPiI2CSetup(GYRO_ADDR);
    delay(100);
    wiringPiI2CWriteReg8(gyro_fd, MPU6050_PWR_MGMT_1, 0x00);
    wiringPiI2CWriteReg8(gyro_fd, GYRO_CONFIG, 0x00);
    wiringPiI2CWriteReg8(gyro_fd, ACCEL_CONFIG, 0x00);
    delay(100);

    // 피에조 및 LED 초기화
    pinMode(BUZZER_PIN, OUTPUT);
    softToneCreate(BUZZER_PIN);

    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);

    printf("자이로 센서 감지 대기 중...\n");

    while (1)
    {
        if (is_movement_detected(gyro_fd, 50.0)) // 움직임 기준값: 50 °/s
        {
            printf("움직임 감지! 알람 작동\n");
            activate_alarm();
            delay(1000); // 다음 감지 전 1초 대기
        }
        delay(200); // 감지 주기
    }

    return 0;
}
