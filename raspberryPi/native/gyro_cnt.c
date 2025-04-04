#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define GYRO_ADDR 0x68

// 자이로 센서 레지스트리 MPU6050
#define MPU6050_PWR_MGMT_1 0x6B
#define GYRO_CONFIG 0x1B
#define ACCEL_CONFIG 0x1C
#define ACCEL_XOUT_H 0x3B
#define GYRO_XOUT_H 0x43

int main(void)
{
    // MPU 6050 I2C file descriptor
    int gyro_fd = wiringPiI2CSetup(GYRO_ADDR);
    delay(100);

    // initiation MPU 6050
    wiringPiI2CWriteReg8(gyro_fd, MPU6050_PWR_MGMT_1, 0x00); // 슬립 모드 해제
    wiringPiI2CWriteReg8(gyro_fd, GYRO_CONFIG, 0x00);        // 자이로 범위 250 도/s
    wiringPiI2CWriteReg8(gyro_fd, ACCEL_CONFIG, 0x00);       // 가속도 범위 +-2g
    delay(100);

    const int samples = 100;

    int32_t accel_x_offset = 0, accel_y_offset = 0, accel_z_offset = 0;
    int32_t gyro_x_offset = 0, gyro_y_offset = 0, gyro_z_offset = 0;
    for (int i = 0; i < samples; i++)
    {
        int16_t ax = (wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H) << 8) | wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 1);
        int16_t ay = (wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 2) << 8) | wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 3);
        int16_t az = (wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 4) << 8) | wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 5);
        int16_t gx = (wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H) << 8) | wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 1);
        int16_t gy = (wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 2) << 8) | wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 3);
        int16_t gz = (wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 4) << 8) | wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 5);
        accel_x_offset += ax;
        accel_y_offset += ay;
        accel_z_offset += az;
        gyro_x_offset += gx;
        gyro_y_offset += gy;
        gyro_z_offset += gz;
        delay(10);
    }
    accel_x_offset /= 100 * 16384.0;
    accel_y_offset /= 100 * 16384.0;
    accel_z_offset /= 100 * 16384.0;
    gyro_x_offset /= 100 * 131.0;
    gyro_y_offset /= 100 * 131.0;
    gyro_z_offset /= 100 * 131.0;

    while (1)
    {
        int16_t ax = (wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H) << 8) | wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 1);
        int16_t ay = (wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 2) << 8) | wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 3);
        int16_t az = (wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 4) << 8) | wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 5);
        int16_t gx = (wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H) << 8) | wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 1);
        int16_t gy = (wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 2) << 8) | wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 3);
        int16_t gz = (wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 4) << 8) | wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 5);

        printf("ax : %f\n", (float)ax / 16384.0 - accel_x_offset);
        printf("ay : %f\n", (float)ay / 16384.0 - accel_y_offset);
        printf("az : %f\n", (float)az / 16384.0 - accel_z_offset);
        printf("gx : %f\n", (float)gx / 131.0 - gyro_x_offset);
        printf("gy : %f\n", (float)gy / 131.0 - gyro_y_offset);
        printf("gz : %f\n", (float)gz / 131.0 - gyro_z_offset);
        // printf("ax : %f\n", (float)ax / 16384.0);
        // printf("ay : %f\n", (float)ay / 16384.0);
        // printf("az : %f\n", (float)az / 16384.0);
        // printf("gx : %f\n", (float)gx / 131.0);
        // printf("gy : %f\n", (float)gy / 131.0);
        // printf("gz : %f\n", (float)gz / 131.0);
        delay(100);
    }

    return 0;
}