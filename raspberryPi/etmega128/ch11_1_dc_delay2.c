#include <avr/delay.h>
#include <avr/io.h>

int main(void)
{
    DDRD = _BV(PD4) | _BV(PD5); // 출력 설정
    DDRB = _BV(PB5) ;
    
    TCCR1A = _BV(COM1A1) | _BV(WGM11);
    TCCR1B = _BV(CS11) | _BV(WGM12) |_BV(WGM13); //CS 분주비, WGM 웨이브
    // fast pwm 분주비 8 -> 16MHz/ 8 = 2MHz

    ICR1 = 800; // 2MHz : 1초 == 800Hz : x초 ... 2500Hz
    OCR1A = 560; // 800 카운트 하는데 560번 까지 -> 5V 70%

    while (1)
    {
        PORTD = _BV(PD4); // M1 정회전 (스위치 올릴 때) set 
        PORTB = _BV(PB5); // M1 회전
        _delay_ms(500);

        PORTD &= ~_BV(PD4); // 0bXXX1XXXX -> & (0b 11101111) (스위치 내릴 때) unset
        PORTD |= _BV(PD5); // M1 정회전 - 속도 영향 ?
        PORTB |= _BV(PB5); // M1 회전 enable
        _delay_ms(500);
    }
    return 0;
}