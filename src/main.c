#include "SHT2x.h"
#include "TWI_driver.h"
#include "at25160.h"
#include "uart0.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

volatile uint8_t Read_flag = 1, TX_flag = 0;
uint16_t timer0Cnt = 0;
uint16_t temperatureC, humidityRH;

int main(void)
{
    nt16 tempRaw, humiRaw;

    SPI_Init();
    Init_TWI();
    SHT2x_Init();
    uart0Init();

    DDRE = 0x02;
    EICRB = 0x03; // INT4 상승 에지
    EIMSK = 0x10; // INT4 허용
    TCCR0 = 0x07; // Timer0 프리스케일러 1024
    TCNT0 = 112;  // 0.01초 인터럽트
    TIMSK = 0x01; // Timer0 오버플로우 허용

    sei();
    stdout = &OUTPUT;

    while (1)
    {
        if (Read_flag)
        {
            SHT2x_MeasureHM(TEMP, &tempRaw);
            temperatureC = (uint16_t)(SHT2x_CalcTemperatureC(tempRaw.u16) * 10);
            SHT2x_MeasureHM(HUMIDITY, &humiRaw);
            humidityRH = (uint16_t)(SHT2x_CalcRH(humiRaw.u16) * 10);
            at25160_Write_Arry(0x0100, (uint8_t *)&temperatureC, 2);
            at25160_Write_Arry(0x0200, (uint8_t *)&humidityRH, 2);
            Read_flag = 0;
        }
        if (TX_flag)
        {
            at25160_Read_Arry(0x0100, (uint8_t *)&temperatureC, 2);
            at25160_Read_Arry(0x0200, (uint8_t *)&humidityRH, 2);
            uart0PrintString("\n\rTemp: ");
            printf("%u.%u[C], Humi: %u.%u[%%]",
                   temperatureC / 10, temperatureC % 10,
                   humidityRH / 10, humidityRH % 10);
            TX_flag = 0;
        }
    }
}

ISR(TIMER0_OVF_vect)
{
    timer0Cnt++;
    if (timer0Cnt >= 500) // 5초
    {
        timer0Cnt = 0;
        Read_flag = 1;
    }
    TCNT0 = 112;
}

ISR(INT4_vect)
{
    TX_flag = 1;
}