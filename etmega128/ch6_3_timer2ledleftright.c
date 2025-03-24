// timer2 번을 써서 LED 좌우로 움직이는 코드 작성. 0.3초마다 움직이기.

#include <avr/interrupt.h>
#include <avr/io.h>

uint8_t ledData = 0x01;
volatile uint8_t timer2Cnt = 0;
ISR(TIMER2_OVF_vect);

int main(void)
{
    DDRC = 0x0F;

    TCCR2 = _BV(CS22) | _BV(CS20); // clock select 1024 prescale
    TIMSK = _BV(TOIE2);            // timer interrupt en.

    sei();
    uint8_t direction = 0;
    while (1)
    {
        if (timer2Cnt == 30)
        {
            if (ledData > 0x04)
                direction = 0;
            if (ledData == 1)
            {
                direction = 1;
                ledData = 1;
            }
            if (direction)
                ledData <<= 1;
            else
                ledData >>= 1;
            timer2Cnt = 0;
        }
        PORTC = ledData;
    }
}

ISR(TIMER2_OVF_vect)
{
    cli();
    TCNT2 = 112; // 113, 114 .... 255 .. 144-> 0.0025 초
    timer2Cnt++;
    sei();
}