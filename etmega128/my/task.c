#include <avr/io.h>
#include <avr/interrupt.h>

// 타이머 인터럽트 누적 횟수를 저장하는 변수 (volatile: ISR과 메인 루프에서 모두 사용됨)
volatile uint8_t timer2Count = 0;
// LED 업데이트를 요청하는 플래그 (ISR에서 설정, 메인 루프에서 처리)
volatile uint8_t updateLedFlag = 0;

int main(void)
{
    // PORTC 하위 4비트를 출력으로 설정 (LED가 연결되어 있다고 가정)
    DDRC = 0x0F;
    
    // LED 초기 패턴 (예: 0x01은 첫 번째 LED 켜짐)
    uint8_t led_data = 0x01;
    // 이동 방향: 1이면 왼쪽(비트 왼쪽 시프트), 0이면 오른쪽(비트 오른쪽 시프트)
    uint8_t direction = 1;
    
    // Timer2 설정: CTC 모드, 분주비 1024 사용
    // - WGM21: CTC 모드 활성화
    // - CS22와 CS20: 분주비 1024 선택
    TCCR2 = (1 << WGM21) | (1 << CS22) | (1 << CS20);
    
    // OCR2 값 설정: (146+1) tick * 1.024ms ≒ 150.5ms 간격 (F_CPU = 1MHz 가정)
    OCR2 = 146;
    
    // Timer2 비교일치 인터럽트 활성화
    TIMSK |= (1 << OCIE2);
    
    // 전역 인터럽트 활성화
    sei();
    
    while (1)
    {
        // updateLedFlag가 설정되면 LED 업데이트 수행
        if (updateLedFlag)
        {
            updateLedFlag = 0;      // 플래그 초기화
            PORTC = led_data;       // 현재 led_data를 PORTC에 출력하여 LED 갱신
            
            // LED가 오른쪽 끝(0x08)일 경우, 이동 방향을 오른쪽(0)으로 전환
            if (led_data == 0x08)
                direction = 0;
            // LED가 왼쪽 끝(0x01)일 경우, 이동 방향을 왼쪽(1)으로 전환
            else if (led_data == 0x01)
                direction = 1;
            
            // 설정된 방향에 따라 LED 데이터 시프트
            if (direction)
                led_data <<= 1;  // 왼쪽으로 시프트 (예: 0x01 → 0x02 → 0x04 → 0x08)
            else
                led_data >>= 1;  // 오른쪽으로 시프트 (예: 0x08 → 0x04 → 0x02 → 0x01)
        }
    }
    
    return 0;
}

// Timer2 비교일치 인터럽트 서비스 루틴
// 약 150.5ms마다 호출되며, 2회 누적 시 약 0.3초마다 updateLedFlag를 설정
ISR(TIMER2_COMP_vect)
{
    timer2Count++;  // 인터럽트 발생 횟수 증가
    if (timer2Count >= 2)
    {
        timer2Count = 0;   // 카운트 초기화
        updateLedFlag = 1; // 메인 루프에 LED 업데이트 요청
    }
}
