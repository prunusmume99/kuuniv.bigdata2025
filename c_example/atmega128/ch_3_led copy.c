#include <avr/io.h>
#include <util/delay.h>

int main()
{
      DDRC = 0x0F;
      PORTC = 0x08;

      unsigned char led_data = 0x08;
      char direction = -1; 

      while(1)
      {
        _delay_ms(500);
        if(direction == -1) 
        {
            led_data >>= 1; 
            if(led_data == 0x01) 
            direction = 1;
        }
        else 
        {
            led_data <<= 1; 
            if(led_data == 0x08) 
            direction = -1;
        }
        PORTC = led_data;
      }   
    return 0;
}
