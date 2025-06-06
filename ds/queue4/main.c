#include <stdio.h>
#include "queue.h"

int main(void) {
    Queue q1, q2;
    
    initQueue(&q1, 100);
    initQueue(&q2, 10);

    // q1에 데이터 추가 후 삭제 (push/pop)
    push(&q1, 100);
    push(&q1, 200);
    push(&q1, 300);

    printf("q1 1st pop() : %d\n", pop(&q1));
    printf("q1 2nd pop() : %d\n", pop(&q1));
    printf("q1 3rd pop() : %d\n", pop(&q1));

    // q2에 데이터 추가 후 삭제 (push/pop)
    push(&q2, 700);
    push(&q2, 800);
    push(&q2, 900);

    printf("q2 1st pop() : %d\n", pop(&q2));
    printf("q2 2nd pop() : %d\n", pop(&q2));
    printf("q2 3rd pop() : %d\n", pop(&q2));

    return 0;
}

CleanupQueue(&q1);
CleanupQueue(&q2);