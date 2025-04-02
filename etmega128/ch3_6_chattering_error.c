#include <avr/io.h>

int main()
{
    unsigned char switchFlag = 0;
    DDRC = 0x0F;
    PORTE = 0x01; // 풀업 설정

    while (1)
    {
        if (PINE & _BV(PE0))
        {
            switchFlag = PINE;
        }
        if (!(switchFlag & _BV(PE0)))
            PORTC ^= 0x01; // 1 번 비트 반전
    }

    return 0;
}