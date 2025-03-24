#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRC = 0x00;
    DDRB |= _BV(PB4); //OC0 핀 PB4 출력 설정

    TCCR0 = _BV(WGM00) | _BV(WGM01) | _BV(COM01) | _BV(CS01); // clock select 1024 prescale
    // fast PWM, compare -> clear
    //1600000 Hz /8 -> 2MHz / 255 -> 7845Hz (Duty Cycle)
    // 0.00012 s -> 0.1ms | 0.02ms on 0.08ms off  (normal) 

    uint8_t brightness = 0;
    int8_t delta = 1;

    while (1)
    {
        OCR0 = brightness; // 0~ 255 -> 이 숫자로 compare가 일어남
        _delay_ms(10);
        brightness += delta;
        if (brightness == 0 || brightness == 255)
        {
            delta = -delta;
        }
    }
    return 0;
}