#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "queue.h"


void initQueue(Queue *pq, int size, int eleSize) {
    pq->pArr = malloc(eleSize * size);
    assert(pq->pArr);

    pq->size = size;
    pq->eleSize = eleSize;
    pq->front = 0;
    pq->rear = 0;
    pq->count = 0;
}

void cleanupQueue(Queue *pq) {
    free(pq->pArr);
}

void push(Queue *pq, const void *pData) {
    assert(pq->count != pq->size);
    memcpy((unsigned char *)pq->pArr + (pq->rear * pq->eleSize), pData, pq->eleSize);

    pq->rear++;
    pq->count++;
}

void pop(Queue *pq, void *pData) {
    assert(pq->count != 0);
    memcpy(pData, (unsigned char *)pq->pArr + (pq->front * pq->eleSize), pq->eleSize);

    pq->front++;
    pq->count--;
}