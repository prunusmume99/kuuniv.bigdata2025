#include "uart0.h"
#include <lcd.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>

volatile uint8_t intData;  //.볼라틸 꼭 쓰기
uint8_t cursor = 0;

int main()
{
    uart0Init();
    lcdInit();

    stdin = &INPUT;
    stdout = &OUTPUT;
   
    DDRE = 0x02; // Rx(입력), TX(출력)1, SW0 ~ 3 입력

    EICRB = 0xFF; // 4567 상승 에지에서 동작
    EIMSK = 0xF0;
    EIFR = 0xF0;

    sei(); //전역 인터럽트 허용 
            //인터럽트 사용시 switch break; 마냥 sei()로 마무리
    char cData;

    printf("Hi, I'm Atmega128");

    while (1)
    {
        // rxData = uart0Receive();
        if(intData != '0'){
            printf("\n\r Input Switch : %c", intData);
            intData = '0';
        }
        cData = fgetc(stdin);
        lcdDataWrite(cData);
        cursor++;
        if(cursor == 16)
            lcdGotoXY(0,1);
        else if (cursor == 32)
            cursor = 0;
            // lcdGotoXY(0,0);
    }
    return 0;
}


//서비스 루틴 (최대한 간단하게 적기 시간이 오레 걸리는 코드는 메인에다가 작성)
ISR(INT4_vect)
{
    cli(); // 다시 인터럽트 설정 못하게 해제
    intData = '1';
    sei();
}
ISR(INT5_vect)
{
    cli(); // 다시 인터럽트 설정 못하게 해제
    intData = '2';
    sei();
}
ISR(INT6_vect)
{
    cli(); // 다시 인터럽트 설정 못하게 해제
    intData = '3';
    sei();
}
ISR(INT7_vect)
{
    cli(); // 다시 인터럽트 설정 못하게 해제
    intData = '4';
    sei();
}