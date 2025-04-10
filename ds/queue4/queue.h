#ifndef QUEUE_H
#define QUEUE_H
//#define QUEUESIZE 100

typedef struct queue {
    //int array[QUEUESIZE];
    int *pArr;
    int front;   // 큐의 첫 번째 요소(삭제할 위치)
    int rear;    // 큐의 마지막 요소(추가할 위치)
    int size;
} Queue;

void initQueue(Queue *pq, int size);

void push(Queue *pq, int data);
int pop(Queue *pq);

#endif
