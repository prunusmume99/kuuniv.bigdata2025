#include <avr/io.h>
#include <util/delay.h>

int main()
{
    DDRC = 0x0F;
    unsigned char led_data;
    led_data = 0x01;
    int direction = 1;
    while (1)
    {
        while (1)
        {
            PORTC = led_data;
            if (led_data > 0x04)
                direction = 0;
            if (led_data == 1)
            {
                direction = 1;
                led_data = 1;
            }

            if (direction)
                led_data <<= 1;
            else
                led_data >>= 1;
            _delay_ms(500);
        }
    }
    return 0;
}