#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// 전역 변수
volatile uint8_t interrupt_count = 0;  // Timer0 오버플로우 발생 횟수
volatile uint8_t running = 1;            // 1: 자동 증가, 0: 정지(멈춤)

// 7세그먼트 디스플레이에 표시할 숫자 패턴 (1~9)
// 배열의 인덱스 0은 숫자 1, 인덱스 8은 숫자 9를 나타냄
uint8_t numbers[] = {0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67};

volatile uint8_t count = 0;  // 현재 표시할 숫자의 배열 인덱스 (0~8)

// Timer0 오버플로우 인터럽트 서비스 루틴
ISR(TIMER0_OVF_vect)
{
    interrupt_count++;  
}

// INT5 인터럽트 서비스 루틴 (스위치 누름)
// 토글 스위치 역할: running 상태를 반전시킴
ISR(INT5_vect)
{
    running = !running;
    _delay_ms(50);  // 간단한 디바운스 (실제 응용에서는 ISR내 딜레이는 지양)
}

int main(void)
{
    // PORTA를 출력으로 설정 (7세그먼트 디스플레이 연결)
    DDRA = 0xFF;
    PORTA = numbers[count];

    // Timer0 설정: 프리스케일러 1024 사용
    TCCR0 = (1 << CS02) | (1 << CS01) | (1 << CS00);
    // Timer0 오버플로우 인터럽트 활성화
    TIMSK = (1 << TOIE0);

    // INT5 외부 인터럽트 설정 (PINE의 해당 핀에 연결된 스위치)
    // INT5를 하강 에지 트리거로 설정: ISC51=1, ISC50=0
    EICRB |= (1 << ISC51);
    EICRB &= ~(1 << ISC50);
    // INT5 인터럽트 활성화
    EIMSK |= (1 << INT5);

    sei();  // 전역 인터럽트 활성화

    while (1)
    {
        // running 상태일 때, Timer0 오버플로우가 약 100ms(6번 오버플로우)마다 count 증가
        if (running && (interrupt_count >= 6))
        {
            interrupt_count = 0;
            count++;
            if (count > 8)  // 0~8: 1~9를 표현, 9 이상이면 다시 0으로 순환
                count = 0;
        }
        // 7세그먼트 디스플레이에 현재 숫자 출력
        PORTA = numbers[count];
    }

    return 0;
}
