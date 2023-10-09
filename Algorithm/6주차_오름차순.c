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
    int largest = k;

    if (left <= n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right <= n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != k)
    {
        int temp = arr[k];
        arr[k] = arr[largest];
        arr[largest] = temp;
        heapify(arr, largest, n);
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
    int arr[] = {-1, 5, 3, 4, 1, 6, 10};      // -1을 0번째 요소로 사용하지 않음
    int n = sizeof(arr) / sizeof(arr[0]) - 1; // -1을 제외한 요소의 개수 계산

    heapSort(arr, n);

    printf("오름차순 정렬 결과: ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
