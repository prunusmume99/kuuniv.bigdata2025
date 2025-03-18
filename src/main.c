#include <avr/io.h>
#include <util/delay.h>

int main()
{
    while(1)
    {
    PORTC = 0x00;       // 0b00000000
    _delay_ms(1000);    // 1초 대기
    PORTC = 0x0F;       // 0b00001111
    _delay_ms(1000);    // 1초 대기
    }
    return 0;
}