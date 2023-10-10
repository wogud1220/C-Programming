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

int main()
{
    int arr[] = {0, 9, 8, 7, 6, 5, 4, 3, 2};
    int n = sizeof(arr) / sizeof(int) - 1; // -1을 제외한 요소의 개수 계산
    int num = 0;
    int size = n;
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
        break;

    default:
        break;
    }

    return 0;
}
