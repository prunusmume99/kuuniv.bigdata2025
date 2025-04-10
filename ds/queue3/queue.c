// #include <stdio.h>
// #include <stdlib.h>
// #include "queue.h"


// void initQueue(Queue *q)
// {
//     q->front = 0;
//     q->rear = 0;
// }

// void enqueue(Queue *q, int data) {
//     if (q->rear == QUEUESIZE) {
//         fprintf(stderr, "queue is full.\n");
//         exit(1);
//     }
//     q->array[q->rear] = data;
//     ++q->rear;
// }

// int dequeue(Queue *q) {
//     if (q->front == q->rear) {
//         fprintf(stderr, "queue is empty.\n");
//         exit(2);
//     }
//     int data = q->array[q->front];
//     ++q->front;
//     return data;
// }

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void initQueue(Queue *pq)
{
    pq->front = 0;
    pq->rear = 0;
}

void push(Queue *pq, int data)
{
    if(pq->rear == QUEUESIZE) {
        fprintf(stderr, "queue is full.\n");
        exit(1);
    }
    pq->array[pq->rear] = data;
    ++pq->rear;
}


int pop(Queue *pq)
{
    if(pq->rear == pq->front) {
        fprintf(stderr, "queue is empty.\n");
        exit(2);
    }

    int i = pq->front;

    ++pq->front;
    
    return pq->array[i];
    
}