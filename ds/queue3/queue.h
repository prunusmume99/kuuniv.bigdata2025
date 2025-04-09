// #ifndef QUEUE_H
// #define QUEUE_H

// #include <stdlib.h>

// #define QUEUESIZE 100  

// typedef struct {
//     int array[QUEUESIZE];  // 큐 데이터 저장 배열
//     int front;             // dequeue할 위치 (큐의 앞)
//     int rear;              // enqueue할 위치 (큐의 뒤)
// } Queue;

// void initQueue(Queue *q);

// void enqueue(Queue *q, int data);

// int dequeue(Queue *q);

// #endif

// #pragma once                  // at visual studio 

#ifndef QUEUE_H
#define QUEUE_H

#define QUEUESIZE 100

typedef struct queue{
    int array[QUEUESIZE];
    int rear;
    int front;
} Queue;                                // struct stack -> Stack

void initQueue(Queue *pq);
void push(Queue *pq, int data);         // func. declaration
int pop(Queue *pq);


#endif