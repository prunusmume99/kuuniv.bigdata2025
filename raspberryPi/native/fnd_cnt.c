// 스위치를 오래 누르면 (0 ~ 1)초 -> (0 ~ 4095) 높은 값으로 변화할 수 있게 만들기
// 스위치를 누르고 떼면 -> FND에 숫자 출력 (0 ~ 1)초 -> (00 ~ 99) ||| ms  -> 10ms 단위
#include <stdint.h>
#include <stdio.h>
#include <wiringPi.h>

#define DATA_PIN 0
#define LATCH_PIN 5
#define CLOCK_PIN 6

uint8_t numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67};

void bit_74HC595_shift16(uint8_t digit1, uint8_t digit2);

int main(void)
{
    wiringPiSetupGpio();
    pinMode(DATA_PIN, OUTPUT);
    pinMode(LATCH_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);

    digitalWrite(DATA_PIN, LOW);
    digitalWrite(LATCH_PIN, LOW);
    digitalWrite(CLOCK_PIN, LOW);

    printf("테스트 FND 숫자 테스트\n");
    for (int i = 0; i < 10; ++i)
    {
        bit_74HC595_shift16(numbers[i % 10], numbers[0]);
        delay(300);
    }
    for (int i = 0; i < 10; ++i)
    {
        bit_74HC595_shift16(numbers[0], numbers[i % 10]);
        delay(300);
    }
    printf("FND 끄기\n");
    bit_74HC595_shift16(0x00, 0x00);
}

void bit_74HC595_shift16(uint8_t digit1, uint8_t digit2)
{
    uint16_t data = (digit1 << 8) | (digit2 << 0);

    for (int i = 15; i >= 0; i--)
    {
        digitalWrite(LATCH_PIN, LOW);
        digitalWrite(CLOCK_PIN, LOW);
        digitalWrite(DATA_PIN, (data >> i) & 1);
        // xxxxxxxx0 or xxxxxxxx1 & 0000000001
        digitalWrite(LATCH_PIN, HIGH);
        digitalWrite(CLOCK_PIN, HIGH);
        delayMicroseconds(10);
    }
    digitalWrite(LATCH_PIN, LOW);
    delayMicroseconds(10);
    digitalWrite(LATCH_PIN, HIGH);
}


// #include <stdint.h>
// #include <stdio.h>
// #include <wiringPi.h>


// #define DATA_PIN 0
// #define LATCH_PIN 5
// #define CLOCK_PIN 6

// uint8_t numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67};

// void bit_74HC595_shift16(uint8_t digit1, uint8_t digit2);

// int main(void)
// {
//     wiringPiSetupGpio();
//     pinMode(DATA_PIN, OUTPUT);
//     pinMode(LATCH_PIN, OUTPUT);
//     pinMode(CLOCK_PIN, OUTPUT);

//     digitalWrite(DATA_PIN, LOW);
//     digitalWrite(LATCH_PIN, LOW);
//     digitalWrite(CLOCK_PIN, LOW);

//     printf("FND 숫자 테스트\n");
//     for (int i = 0; i < 10; ++i)
//     {
//         bit_74HC595_shift16(numbers[i % 10], numbers[0]);
//         delay(300);
//     }
//     for (int i = 0; i < 10; ++i)
//     {
//         bit_74HC595_shift16(numbers[0], numbers[i % 10]);
//         delay(300);
//     }
//     printf("FND 끄기\n");
//     bit_74HC595_shift16(0x00, 0x00);
// }

// void bit_74HC595_shift16(uint8_t digit1, uint8_t digit2)
// {
//     uint16_t data = (digit1 << 8) | (digit2 << 0);

//     for (int i = 15; i >= 0; i--)
//     {
//         digitalWrite(LATCH_PIN, LOW);
//         digitalWrite(CLOCK_PIN, LOW);
//         digitalWrite(DATA_PIN, (data >> i) & 1);
//         // xxxxxxxx0 or xxxxxxxx1 & 0000000001
//         digitalWrite(LATCH_PIN, HIGH);
//         digitalWrite(CLOCK_PIN, HIGH);
//         delayMicroseconds(10);
//     }
//     digitalWrite(LATCH_PIN, LOW);
//     delayMicroseconds(10);
//     digitalWrite(LATCH_PIN, HIGH);
// }