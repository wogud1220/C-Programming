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

int partition2(int arr[], int p, int r)
{
    int temp;
    int x = arr[p]; // 첫 번째 요소를 pivot으로 선택
    int i = p - 1;

    for (int j = p; j <= r; j++)
    {
        if (arr[j] <= x)
        {
            ++i;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[p];
    arr[p] = temp;

    return i + 1;
}

void quicksort2(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = partition2(arr, p, r);
        quicksort2(arr, p, q - 1);
        quicksort2(arr, q + 1, r);
    }
}

int main()
{
    int arr[] = {31, 8, 48, 73, 11, 3, 20, 29, 65, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort2(arr, 0, 9);

    printf("quicksort2 결과:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
