// #include <stdio.h>
// #include "queue.h"

// int main(void) {
//     Queue q1, q2;

//     initQueue(&q1);
//     initQueue(&q2);

//     enqueue(&q1, 100);
//     enqueue(&q1, 200);
//     enqueue(&q1, 300);

//     printf("q1 1st dequeue() : %d\n", dequeue(&q1));
//     printf("q1 2nd dequeue() : %d\n", dequeue(&q1));
//     printf("q1 3rd dequeue() : %d\n", dequeue(&q1));

//     enqueue(&q2, 700);
//     enqueue(&q2, 800);
//     enqueue(&q2, 900);

//     printf("q2 1st dequeue() : %d\n", dequeue(&q2));
//     printf("q2 2nd dequeue() : %d\n", dequeue(&q2));
//     printf("q2 3rd dequeue() : %d\n", dequeue(&q2));

//     return 0;
// }

#include <stdio.h>
#include "queue.h"
 
int main(void)
{
    Queue q1, q2;
    q1.front = q1.rear = 0;
    q2.front = q2.rear = 0;
    //초기화

    initQueue(&q1);
    initQueue(&q2);
    
    push(&q1, 100);
    push(&q1, 200);
    push(&q1, 300);
    
    printf("q1 1st pop() : %d \n", pop(&q1));
    printf("q1 2nd pop() : %d \n", pop(&q1));
    printf("q1 3rd pop() : %d \n", pop(&q1));
    
    // pop(&q1);
    
    push(&q2, 700);
    push(&q2, 800);
    push(&q2, 900);
    
    printf("q2 1st pop() : %d \n", pop(&q2));
    printf("q2 2nd pop() : %d \n", pop(&q2));
    printf("q2 3rd pop() : %d \n", pop(&q2));
    
    
    return 0;
}

