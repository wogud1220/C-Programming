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
// #include <windows.h>g
// #pragma warning(disable:4996)
void heapify(int arr[], int k, int n) // 수선 함수
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
        else // 왼쪽이 더 클경우, 오른쪽이 더 작은 값
        {
            smaller = right;
        }
    }
    else if (left <= n)
    { // 왼쪽 자식만 있는 경우
        smaller = left;
    }
    else // 리프노드면 교환할 필요가 없음
        return;
    if (arr[smaller] < arr[k])
    {
        temp = arr[k];
        arr[k] = arr[smaller];
        arr[smaller] = temp;
        printf("    root = %d\n", arr[1]);
        printf("heapTree ");
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", arr[i]);
        }
        heapify(arr, smaller, n);
    }
}
void buildHeap(int arr[], int n)
{ // arr을 힙으로 만듦
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(arr, i, n);
    }
    return;
}
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    int temp;
    for (int i = n; i >= 2; i--)
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
    int arr[] = {0, 3, 6, 4, 8, 9, 7};
    int size = sizeof(arr) / sizeof(int) - 1;
    int num = 0;
    printf("1:buildMinHeap\n2:isMaxHeap\n3:queue\n");
    scanf("%d", &num);
    switch (num)
    {
    case 1:
        printf("정렬 전: ");
        for (int i = 1; i <= size; i++)
        {
            printf("%d ", arr[i]);
        }
        heapSort(arr, size);
        printf("\n정렬 후:\n");
        for (int i = 1; i <= size; i++)
        {
            printf("%d ", arr[i]);
        }
        break;

    default:
        break;
    }
}