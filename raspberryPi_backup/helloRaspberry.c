#include <stdio.h>
#include <wiringPi.h>

#define LED1 23
#define LED2 24
#define LED3 25
#define LED4 1
//gpio pin 번호 설정


int main(void){
    wiringPiSetupGpio(); // BCM 기준 gpio 핀번호
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);  // wiring 함수 DDR 이랑 같음

    while(1){
        digitalWrite(LED1,  LOW); 
        digitalWrite(LED2, LOW) ;
        digitalWrite(LED3, LOW) ;
        digitalWrite(LED4, LOW); // PORT 랑 같음
    }

    printf("안녕하세요!\n");
    return 0;
}