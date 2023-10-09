#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
#include <ctype.h>
// #include <windows.h>
// #pragma warning(disable:4996)

// 우선순위 큐 구조체
struct PriorityQueue
{
    int heap[MAX_SIZE];
    int size;
};

// 우선순위 큐 초기화
void initPriorityQueue(struct PriorityQueue *pq)
{
    pq->size = 0;
}

// 요소를 우선순위 큐에 삽입
void enqueue(struct PriorityQueue *pq, int value)
{
    if (pq->size >= MAX_SIZE)
    {
        printf("우선순위 큐가 가득 찼습니다.\n");
        return;
    }

    // 우선순위 큐에 요소 추가
    pq->size++;
    int index = pq->size;

    while (index > 1 && value < pq->heap[index / 2])
    {
        pq->heap[index] = pq->heap[index / 2];
        index /= 2;
    }

    pq->heap[index] = value;
}

// 우선순위 큐에서 최소값을 제거하고 반환
int dequeue(struct PriorityQueue *pq)
{
    if (pq->size == 0)
    {
        printf("우선순위 큐가 비어 있습니다.\n");
        return -1; // 오류를 나타내는 값을 반환
    }

    int minValue = pq->heap[1];
    int lastValue = pq->heap[pq->size];
    pq->size--;

    int index = 1;
    int child = 2;

    while (child <= pq->size)
    {
        // 자식 중 더 작은 값을 선택
        if (child < pq->size && pq->heap[child + 1] < pq->heap[child])
        {
            child++;
        }

        // 자식이 더 크다면 반복 종료
        if (lastValue <= pq->heap[child])
        {
            break;
        }

        // 부모와 자식 교환
        pq->heap[index] = pq->heap[child];
        index = child;
        child *= 2;
    }

    pq->heap[index] = lastValue;
    return minValue;
}

int main()
{
    struct PriorityQueue pq;
    initPriorityQueue(&pq);

    // 요소를 우선순위 큐에 추가
    enqueue(&pq, 5);
    enqueue(&pq, 3);
    enqueue(&pq, 7);
    enqueue(&pq, 2);
    enqueue(&pq, 8);

    // 우선순위 큐에서 최소값을 제거하고 출력
    printf("최소값: %d\n", dequeue(&pq));
    printf("최소값: %d\n", dequeue(&pq));
    printf("최소값: %d\n", dequeue(&pq));
    printf("최소값: %d\n", dequeue(&pq));

    return 0;
}
