#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
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
void selectsort()
{
    int arr[8] = {16, 4, 9, 20, 30, 5, 33, 13};
    //          {2, 8,}
    int arrSize = sizeof(arr) / 4;
    int temp;
    int first = 0;
    int i = 0;
    int cnt = 0;
    int minIdx;
    for (int j = 0; j < (sizeof(arr) / 4) - 1; j++) // n-1번
    {
        int min = arr[j];
        for (i = j; i < sizeof(arr) / 4; i++)
        {
            if (min > arr[i + 1])
            {
                min = arr[i + 1];
                minIdx = i + 1;
                cnt++;
            }
        }
        temp = arr[j];
        arr[minIdx] = temp;
        arr[j] = min;
        for (int a = 0; a < sizeof(arr) / 4; a++)
        {
            printf("[%d] ", arr[a]);
        }
        printf("  %d단계 %d번의 비교 ,%d번의 교환 이루어짐\n", j + 1, --arrSize, cnt);
        cnt = 0;
    }
}
void bubbleSort()
{
}
int main()
{
    int problemNum;
    printf("1:select Sort\n2:Bubble Sort\n");
    scanf("%d", &problemNum);
    switch (problemNum)
    {
    case 1:
        selectsort();
        break;
    case 2:
        bubbleSort();
    default:
        break;
    }

    return 0;
}