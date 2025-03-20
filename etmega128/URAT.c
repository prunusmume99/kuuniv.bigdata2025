#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

volatile uint8_t txFlag = 0;
volatile char txData = 0;

uint8_t getch(void)
{
    uint8_t data;
    while ((UCSR0A & 0x80) == 0) // 문자 버퍼에 있으면 내려가기.
        ;
    data = UDR0;
    UCSR0A |= 0x80;
    return data;
}

int main()
{
    uint8_t numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67};
    uint8_t rxData;
   

    UCSR0A = 0x00;
    UCSR0B = 0x18; // 0b00011000 Rx, Tx enable
    UCSR0C = 0x16;

    UBRR0H = 0x00;
    UBRR0L = 0x07;

    while (1)
    {
        rxData = getch();
        if ((rxData >= 0x30) && (rxData <= 0x39))
    {
        PORTA = numbers[rxData - 0x30];
    }
    }
    return 0;
}
