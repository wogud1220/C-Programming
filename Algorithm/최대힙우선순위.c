#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// 우선순위 큐 구조체
struct PriorityQueue
{
    int heap[MAX_SIZE];
    int size;
} PriorityQueue;

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

    while (index > 1 && value > pq->heap[index / 2])
    {
        pq->heap[index] = pq->heap[index / 2];
        index /= 2;
    }

    pq->heap[index] = value;
}

// 우선순위 큐에서 최대값을 제거하고 반환
int dequeue(PriorityQueue *pq)
{
    if (pq->size == 0)
    {
        printf("우선순위 큐가 비어 있습니다.\n");
        return -1; // 오류를 나타내는 값을 반환
    }

    int maxValue = pq->heap[1];
    int lastValue = pq->heap[pq->size];
    pq->size--;

    int index = 1;
    int child = 2;

    while (child <= pq->size)
    {
        // 자식 중 더 큰 값을 선택
        if (child < pq->size && pq->heap[child + 1] > pq->heap[child])
        {
            child++;
        }

        // 자식이 더 작다면 반복 종료
        if (lastValue >= pq->heap[child])
        {
            break;
        }

        // 부모와 자식 교환
        pq->heap[index] = pq->heap[child];
        index = child;
        child *= 2;
    }

    pq->heap[index] = lastValue;
    return maxValue;
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

    // 우선순위 큐에서 최대값을 제거하고 출력
    printf("최대값: %d\n", dequeue(&pq));
    printf("최대값: %d\n", dequeue(&pq));
    printf("최대값: %d\n", dequeue(&pq));
    printf("최대값: %d\n", dequeue(&pq));

    return 0;
}
