#include <avr/io.h>
#include <util/delay.h>

// 과제 
// led 가 0.5초 마다 좌우로 움직이게 하세요
// 1000 -> 0100 -> 0010 -> 0001 -> 0010 -> 0100 -> 1000 이렇게
int main()
{
      DDRC = 0x0F;
      PORTC = 0x08;

      unsigned char led_data = 0x08; // 1000 (PC3 LED 켜짐)
      char direction = -1; // 방향 (-1: 오른쪽 >> , 1: 왼쪽 <<)

      while(1)
      {
        _delay_ms(500);
        if(direction == -1) //오른쪽 이동
        {
            led_data >>= 1; // 한 칸 오른쪽 이동 (1000 -> 0100 -> 0010 -> 0001)
            if(led_data == 0x01) // 맨 오른쪽 (pc0)에 도달하면 방향 변경
            direction = 1;
        }
        else // 왼쪽 이동
        {
            led_data <<= 1; // 한 칸 왼쪽 이동 ( 0001 -> 0010 -> 0100 -> 1000)
            if(led_data == 0x08) // 맨 왼쪽(pc3)에 도달하면 방향 변경
            direction = -1;
        }
        PORTC = led_data;
      }   
    return 0;
}
