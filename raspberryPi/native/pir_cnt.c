// cc helloRaspberry.c -lwiringPi

#include <stdio.h>
#include <wiringPi.h>

// gpio pin
#define PIR_PIN 7
#define LED1_PIN 23

int flag = 0;
int main(void)
{
    wiringPiSetupGpio(); // BCM 기준 gpio 핀번호

    pinMode(LED1_PIN, OUTPUT);
    pinMode(PIR_PIN, INPUT);

    while (1)
    {
        if (digitalRead(PIR_PIN) == HIGH)
        {
            printf("PIR 감지\n");
        }
        delay(100);
    }
    return 0;
}