#include <avr/delay.h>
#include <avr/io.h>

int main(void)
{
    DDRD = _BV(PD4) | _BV(PD5); // 출력 설정
    DDRB = _BV(PB5) ;

    while (1)
    {
        PORTD = _BV(PD4); // M1 정회전 (스위치 올릴 때)set 
        PORTB = _BV(PB5); // M1 회전
        _delay_ms(500);

        PORTD &= ~_BV(PD4); // 0bXXX1XXXX -> & (0b 11101111) (스위치 내릴 때) unset
        PORTD |= _BV(PD5); // M1 정회전
        PORTB |= _BV(PB5); // M1 회전 
        _delay_ms(500);
    }
    return 0;
}