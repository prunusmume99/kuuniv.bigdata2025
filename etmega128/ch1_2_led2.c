#include <avr/io.h>
#include <util/delay.h>

int main()
{
    DDRC = 0x03; // 0011 0,1 울 출력 모드로 한다.
    while (1)
    {
        PORTC = 0x0F; // 1111 0, 1, 2, 3 번을 1(ON)->5V 출력시킴.
        _delay_ms(500);

        PORTC = 0x00; // 0000 0, 1, 2, 3 번을 0(ㅒㄹㄹ)-> 0V 출력시킴.
        _delay_ms(500);
    }
    return 0;
}