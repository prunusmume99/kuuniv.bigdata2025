#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct queue {
    void *pArr;      // 큐 내부 저장소 (동적 메모리 할당)
    int eleSize;     // 저장할 요소의 크기 (바이트 단위)
    int size;        // 큐에 할당된 최대 요소 개수 (용량)
    int front;       // 삭제(pop)할 위치 (큐의 앞쪽 인덱스)
    int rear;        // 삽입(push)할 위치 (큐의 뒷쪽 인덱스)
    int count;       // 현재 큐에 저장된 요소의 개수
} Queue;

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
    pq->rear = (pq->rear + 1) % pq->size;  
    pq->count++;
}

void pop(Queue *pq, void *pData) {
    assert(pq->count != 0);  
    memcpy(pData, (unsigned char *)pq->pArr + (pq->front * pq->eleSize), pq->eleSize);

    memset((unsigned char *)pq->pArr + (pq->front * pq->eleSize), 0, pq->eleSize);
    pq->front = (pq->front + 1) % pq->size;  
    pq->count--;
}

int main(void) {
    Queue q1, q2;
    
    initQueue(&q1, 10, sizeof(int));
    initQueue(&q2, 100, sizeof(double));

    int i;
    i = 100; push(&q1, &i);
    i = 200; push(&q1, &i);
    i = 300; push(&q1, &i);

    int r;
    pop(&q1, &r); printf("q1 1st pop() : %d\n", r);
    pop(&q1, &r); printf("q1 2nd pop() : %d\n", r);
    pop(&q1, &r); printf("q1 3rd pop() : %d\n", r);

    double d;
    d = 1.1; push(&q2, &d);
    d = 2.2; push(&q2, &d);
    d = 3.3; push(&q2, &d);

    double r2;
    pop(&q2, &r2); printf("q2 1st pop() : %f\n", r2);
    pop(&q2, &r2); printf("q2 2nd pop() : %f\n", r2);
    pop(&q2, &r2); printf("q2 3rd pop() : %f\n", r2);

    cleanupQueue(&q1);
    cleanupQueue(&q2);
    return 0;
}
