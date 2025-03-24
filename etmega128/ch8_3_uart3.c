#include "lcd.h"
#include "uart0.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

volatile uint8_t intData = '0';
uint8_t cursor = 0;

int main()
{
    uart0Init();
    lcdInit();

    stdin = &INPUT;
    stdout = &OUTPUT;

    DDRE = 0x02; // Rx(입력), TX(출력)1, SW0~3 입력

    EICRB = 0xFF; // 4567 상승 엣지에서 동작 289p.
    EIMSK = 0xF0; // 4567 허용
    EIFR = 0xF0;  // 4567 클리어

    sei(); // 전역 인터럽트 허용
    char cData;
    char buffer[32];
    uint8_t count;

    printf("Hi, I'm Atmega128");
    lcdGotoXY(0, 0);
    while (1)
    {
        if (intData != '0')
        {
            printf("\n\r Input Switch : %c", intData);
            intData = '0';
        }
        while (UCSR0A & (1 << RXC0))
        {
            // TODO : 4 개 문자 이상 못 받아 오는 문제 버퍼 문제 해결.
            // scanf("%s", buffer);
            // lcdPrint(buffer);
            count++;
            cData = fgetc(stdin);
            lcdDataWrite(cData);
            lcdDataWrite('0' + count);
            cursor++;
            cursor++;
            if (cursor == 16)
                lcdGotoXY(0, 1);
            else if (cursor >= 32)
            {
                cursor = 0;
                lcdGotoXY(0, 0);
            }
        }
    }
    return 0;
}

ISR(INT4_vect)
{
    cli();
    intData = '1';
    sei();
}

ISR(INT5_vect)
{
    cli();
    intData = '2';
    sei();
}

ISR(INT6_vect)
{
    cli();
    intData = '3';
    sei();
}

ISR(INT7_vect)
{
    cli();
    intData = '4';
    sei();
}