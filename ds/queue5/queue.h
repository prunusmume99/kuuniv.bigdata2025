#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct queue {
    void *pArr;      // 큐 내부 저장소 (동적 할당)
    int eleSize;     // 저장할 요소의 크기 (바이트 단위)
    int size;        // 큐에 할당된 최대 요소 개수
    int front;       // 큐의 앞쪽(삭제될 위치) 인덱스
    int rear;        // 큐의 뒤쪽(삽입될 위치) 인덱스
    int count;       // 현재 큐에 저장된 요소 개수
} Queue;

void initQueue(Queue *pq, int size, int eleSize);
void cleanupQueue(Queue *pq);

void push(Queue *pq, const void *pData);
void pop(Queue *pq, void *pData);

#endif
