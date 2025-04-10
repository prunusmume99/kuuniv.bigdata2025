#include <stdio.h>
#include "queue.h"

int main(void) {
    Queue q1, q2;
    
    initQueue(&q1, 10, sizeof(int));
    initQueue(&q2, 100, sizeof(double));

    int i;
    i = 100; push(&q1, &i);
    i = 200; push(&q1, &i);
    i = 300; push(&q1, &i);

    int re;
    pop(&q1, &re); printf("q1 1st pop() : %d\n", re);
    pop(&q1, &re); printf("q1 2nd pop() : %d\n", re);
    pop(&q1, &re); printf("q1 3rd pop() : %d\n", re);

    double d;
    d = 1.1; push(&q2, &d);
    d = 2.2; push(&q2, &d);
    d = 3.3; push(&q2, &d);

    double re2;
    pop(&q2, &re2); printf("q2 1st pop() : %f\n", re2);
    pop(&q2, &re2); printf("q2 2nd pop() : %f\n", re2);
    pop(&q2, &re2); printf("q2 3rd pop() : %f\n", re2);

    cleanupQueue(&q1);
    cleanupQueue(&q2);
    return 0;
}
