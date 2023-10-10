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
    for (int i = n; i >= 2; i--)
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
            return 0;
        }
        if (arr[right] > arr[i])
        { // 오른쪽 자식이 부모보다 크다면
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
            return 0;
        }
        if (arr[right] > arr[i])
        { // 오른쪽 자식이 부모보다 크다면
            return 0;
        }
        boolean = isMaxRecur(arr, i + 1, n);
    }
    return boolean;
}
int main()
{
    int arr[] = {0, 9, 8, 7, 6, 5, 4, 3, 2};
    int arrMaxHeap[] = {0, 9, 8, 2, 6, 5, 4, 3, 7};
    int n = sizeof(arr) / sizeof(int) - 1; // -1을 제외한 요소의 개수 계산
    int num;
    int size = n;
    int isMax;
    int MaxRecur;

    while (1)
    {
        printf("1:buildMinHeap\n2:isMaxHeap\n3:queue\n");
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
            isMax = isMaxHeapFor(arrMaxHeap, size);
            if (isMax == 1)
            {
                printf("\n");
                for (int i = 1; i <= size; i++)
                {
                    printf("%d ", arrMaxHeap[i]);
                }
                printf("\n반복으로 한 최대힙은 참입니다.\n");
            }
            else if (isMax == 0)
            {
                printf("\n");
                for (int i = 1; i <= size; i++)
                {
                    printf("%d ", arrMaxHeap[i]);
                }
                printf("\n반복으로 한 최대힙은 거짓입니다.\n");
            }
            break;
        case 3: // 순환호출을 사용한 최대힙 판별
            MaxRecur = isMaxRecur(arrMaxHeap, 1, size / 2);
            if (MaxRecur)
            {
                printf("\n순환호출로 한 최대힙 판별은 참입니다.\n");
                for (int i = 1; i <= size; i++)
                {
                    printf("%d ", arrMaxHeap[i]);
                }
            }
            else
            {
                for (int i = 1; i <= size; i++)
                {
                    printf("%d ", arrMaxHeap[i]);
                }
                printf("\n순환호출로 한 최대힙 판별은 거짓입니다.\n");
            }
            break;
        default:
            break;
        }
    }

    return 0;
}
