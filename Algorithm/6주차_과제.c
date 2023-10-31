#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MAX_SIZE 1000001
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
void heapify(int arr[], int k, int n)
{
    int left = 2 * k;
    int right = 2 * k + 1;
    int bigger, temp;

    if (right <= n)
    {
        if (arr[left] < arr[right])
        { // 오른쪽이 더크면
            bigger = right;
        }
        else
        {
            bigger = left;
        }
    }
    else if (left <= n)
    { // 자식이 왼쪽만 있는 경우
        bigger = left;
    }

    else
    {
        return;
    }
    if (arr[bigger] > arr[k])
    {
        int temp = arr[k];
        arr[k] = arr[bigger];
        arr[bigger] = temp;
        printf("    root = %d\n", arr[1]);
        printf("heapTree ");
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", arr[i]);
        }
        heapify(arr, bigger, n);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(arr, i, n);
    }
}

void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i = n; i >= 1; i--)
    {
        int temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        heapify(arr, 1, i - 1);
    }
}

int isMaxHeapFor(int arr[], int n)
{
    int i = 1;

    for (int i = 1; i <= n / 2; i++)
    {
        int left = i * 2;
        int right = (i * 2) + 1;
        if (arr[left] > arr[i])
        { // 왼쪽 자식이 부모보다 크다면
            printf("왼쪽자식인 %d가 부모노드인 %d보다 큽니다.\n", arr[left], arr[i]);
            return 0;
        }
        if (arr[right] > arr[i])
        { // 오른쪽 자식이 부모보다 크다면
            printf("오른쪽자식인 %d가 부모노드인 %d보다 큽니다.\n", arr[right], arr[i]);
            return 0;
        }
    }
    return 1;
}
int isMaxRecur(int arr[], int i, int n)
{ // n은 4받아옴, i 는 1받아옴
    int boolean;
    int left = i * 2;
    int right = (i * 2) + 1;
    if (i == n) // 종료 조건
        return 1;
    else
    {
        if (arr[left] > arr[i])
        { // 왼쪽 자식이 부모보다 크다면
            printf("왼쪽자식인 %d가 부모노드인 %d보다 큽니다.\n", arr[left], arr[i]);
            return 0;
        }
        if (arr[right] > arr[i])
        { // 오른쪽 자식이 부모보다 크다면
            printf("오른쪽자식인 %d가 부모노드인 %d보다 큽니다.\n", arr[right], arr[i]);
            return 0;
        }
        boolean = isMaxRecur(arr, i + 1, n);
    }
    return boolean;
}
typedef struct heapQueue
{
    int front;
    int data[100];
    int size;
} heapQueue;

void initQueue(heapQueue *heapQueue, int n, int arr[])
{
    for (int i = 1; i < n; i++)
    {
        heapQueue->data[i] = arr[i];
    } // 먼저 최대힙을 만족하는 배열을 큐에 넣어줌
    heapQueue->front = 1;
    heapQueue->size = n;
}

int deleteQueue(heapQueue *heapQueue)
{
    int maxValue = heapQueue->data[1]; // 루트 빼오기
    int lastValue = heapQueue->data[heapQueue->size];
    heapQueue->size--;

    int index = 1;
    int child = 2;

    while (child <= heapQueue->size)
    {
        // 좌,우 자식 중 큰 자식 선택하기
        if (heapQueue->data[child + 1] > heapQueue->data[child])
        {
            child++;
        }

        // 자식이 더 작으면 ㄱ반복 끝내고 루트 리턴하기
        if (lastValue >= heapQueue->data[child])
        {
            break;
        }
        // 자식이 전체 사이즈보다 작은동안에는
        //  부모와 자식 교환
        heapQueue->data[index] = heapQueue->data[child];
        index = child;
        child *= 2;
    }

    heapQueue->data[index] = lastValue;
    return maxValue;
}
void insertQueue(heapQueue *heapQueue, int item)
{
    // 우선순위 큐에 값 추가
    heapQueue->size++;
    int index = heapQueue->size;
    if (index > 100)
    { // 큐 최대 데이터 개수가 100개임
        printf("용량 초과");
        return;
    }

    while (item > heapQueue->data[index / 2])
    { // 새로 들어온 값이 부모노드보다 크다면
        heapQueue->data[index] = heapQueue->data[index / 2];
        index /= 2;
        if (index == 1) // 루트 넣을때 오류남 더이상 올라가지안ㄷ로골
            break;
    }

    heapQueue->data[index] = item;
}
int main()
{
    int arr[] = {0, 9, 7, 5, 3, 1};
    int arrMaxHeap[] = {0, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(int) - 1; // -1을 제외한 요소의 개수 계산
    int num = 1;
    int size = n;

    int sizeIsMax = (sizeof(arrMaxHeap) / 4) - 1;
    int isMax;
    int MaxRecur;
    heapQueue heapQueue;
    int item = 0;
    int deleteItem;
    initQueue(&heapQueue, sizeIsMax, arrMaxHeap);
    while (num != 0)
    {
        printf("\n0:Exit\n1:buildMinHeap\n2:isMaxHeapFor\n3:isMaxHeapRecur\n4:insertQueue\n5:deleteQueue");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            printf("오름차순 정렬 전: ");
            for (int i = 1; i <= size; i++)
            {
                printf("%d ", arr[i]);
            }
            heapSort(arr, size);
            printf("\n오름차순 정렬 후:\n");
            for (int i = 1; i <= size; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 2: // 반복문을 사용한 최대힙 판별;
            isMax = isMaxHeapFor(arrMaxHeap, sizeIsMax);
            if (isMax == 1)
            {
                printf("\n");
                for (int i = 1; i <= sizeIsMax; i++)
                {
                    printf("%d ", arrMaxHeap[i]);
                }
                printf("\n반복으로 한 최대힙은 참입니다.\n");
            }
            else if (isMax == 0)
            {
                printf("\n");
                for (int i = 1; i <= sizeIsMax; i++)
                {
                    printf("%d ", arrMaxHeap[i]);
                }
                printf("\n반복으로 한 최대힙은 거짓입니다.\n");
            }
            break;
        case 3: // 순환호출을 사용한 최대힙 판별
            MaxRecur = isMaxRecur(arrMaxHeap, 1, sizeIsMax / 2);
            if (MaxRecur)
            {
                printf("\n순환호출로 한 최대힙 판별은 참입니다.\n");
                for (int i = 1; i <= sizeIsMax; i++)
                {
                    printf("%d ", arrMaxHeap[i]);
                }
            }
            else
            {
                for (int i = 1; i <= sizeIsMax; i++)
                {
                    printf("%d ", arrMaxHeap[i]);
                }
                printf("\n순환호출로 한 최대힙 판별은 거짓입니다.\n");
            }
            break;
        case 4: // 우선 순위 큐 구현
                // 수선한 배열 큐에 넣기
            printf("\n넣을 값을 입력하세요.");
            scanf("%d", &item);
            insertQueue(&heapQueue, item);
            for (int i = 1; i <= heapQueue.size; i++)
            {
                printf("%d ", heapQueue.data[i]);
                arrMaxHeap[i] = heapQueue.data[i];
            }

            break;
        case 5:
            deleteItem = deleteQueue(&heapQueue);
            printf("root= %d\n", deleteItem);
            for (int i = 1; i <= heapQueue.size; i++)
            {
                printf("%d ", heapQueue.data[i]);
                arrMaxHeap[i] = heapQueue.data[i];
            }
            break;
        default:
            break;
        }
    }

    return 0;
}
