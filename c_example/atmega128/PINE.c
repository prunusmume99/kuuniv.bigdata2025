#include "lcd.h"
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

int main()
{
    lcdInit();
    lcdClear();
    char lcdBuffer[17];

    unsigned char switch_flag = 0;
    DDRE = 0x00;  // PE4~PE7을 입력으로 설정
    PORTE = 0xF0; // 상위 4비트(PE4~PE7) 풀업 설정
    DDRC = 0x0F;  // PC0~PC3을 출력으로 설정 (LED 제어)

    while (1)
    {
        switch_flag = PINE & 0xF0; // 상위 4비트(PINE4~PINE7) 읽기
        switch_flag >>= 4; // 하위 4비트로 이동 (0~15 범위)

        PORTC = switch_flag; // LED에 출력

        // LCD에 표시 (ASCII 문자 범위가 아닐 경우, "." 출력)
        snprintf(lcdBuffer, sizeof(lcdBuffer), "SW: 0x%02X, %c", switch_flag, 
                 (switch_flag >= 0x20 && switch_flag <= 0x7E) ? switch_flag : '.');

        lcdGotoXY(0, 0);
        lcdPrint(lcdBuffer);

        _delay_ms(200); // LCD 깜빡임 방지 (200ms 딜레이)
    }

    return 0;
}
