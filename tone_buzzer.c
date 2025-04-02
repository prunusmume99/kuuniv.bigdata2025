#include <softPwm.h>
#include <softTone.h>
#include <stdio.h>
#include <wiringPi.h>

#define BUZZER_PIN 12

int doReMi[8] = {523, 587, 659, 698, 783, 880, 987, 1046};

int main(void)
{
    wiringPiSetupGpio(); // BCM 기준 gpio 핀번호
    pinMode(BUZZER_PIN, OUTPUT);
    // set PWM
    softToneCreate(BUZZER_PIN);
    while (1)
    {
        for (int i = 0; i < 8; ++i)
        {
            softToneWrite(BUZZER_PIN, doReMi[i]);
            delay(1000);
        }
    }
    return 0;
}