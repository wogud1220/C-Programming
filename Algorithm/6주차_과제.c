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
    int right = (2 * k) + 1;
    int smaller, temp;
    if (right <= n) // k의 자식 노드가 2개라면
    {
        if (arr[left] < arr[right])
        { // 오른쪽 노드가 더 클 경우, 왼쪽이 더 작은 값
            smaller = left;
        }
        else // 왼쪽이 더 클경우
        {
            smaller = right;
        }
    }
    else if (left <= n)
    { // 왼쪽 자식만 있는 경우
        smaller = arr[left];
    }
    else
        return;
    if (arr[smaller] < arr[k])
    {
        temp = arr[k];
        arr[k] = arr[smaller];
        arr[smaller] = temp;
        heapify(arr, smaller, n);
    }
}
void buildHeap(int arr[], int n)
{                                    // arr을 힙으로 만듦
    for (int i = n / 2; i >= 0; i--) // int i=n/2-1 ??
    {
        heapify(arr, i, n);
        /*for (int j = 1; j <= n; j++)
        {
            printf("%d ", arr[j]);
        }
        printf("힙 한번돔\n");*/
    }
    return;
}
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    int temp;
    for (int i = n; i >= 0; i--)
    {
        temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        heapify(arr, 1, i - 1);
    }
    return;
}
int main()
{
    int arr[10];
    int j = 1;
    int i = 10;
    while (j <= 10)
    {
        arr[j] = i;
        i--;
        j++;
    }
    // 배열에 10,9,8,7~~ 들어감
    int size = sizeof(arr) / sizeof(int);
    printf("정렬 전: ");
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    heapSort(arr, size);

    printf("정렬 후:\n");
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", arr[i]);
    }
}