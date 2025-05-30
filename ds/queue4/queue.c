#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

void initQueue(Queue *pq, int size) {
    pq->pArr = malloc(sizeof(int)* size);
    //pq->pArr  != NULL
    assert(pq->pArr );


    pq->size = size;
    pq->front = 0;
    pq->rear = 0;
}

void cleanupQueue(Queue *qp)
{
    free(qp->pArr);
}

void push(Queue *pq, int data) {
    if (pq->rear == pq->size){
        fprintf(stderr,"queue is full\n");
        exit(1);    
    }
    
    pq->pArr[pq->rear] = data;
    ++pq->rear;
}

int pop(Queue *pq) {
    if(pq->rear == pq->front) {
        fprintf(stderr, "queue is empty.\n");
        exit(2);
    }

    int i = pq->front;

    ++pq->front;
    
    return pq->pArr[i];
}
