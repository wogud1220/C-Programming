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

void swap(int *arr, int x, int y);
void complex_arrange(int *arr, int size);

int main()
{
    int arr[] = {69, 10, 32, 44, 56, 13};
    int size = sizeof(arr) / sizeof(int);
    /* 배열 출력 */
    printf("\n 정렬 전 : ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    /* 정렬 */
    complex_arrange(arr, size);

    /* 배열 출력 */
    printf("\n 정렬 후 : ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}

void complex_arrange(int *arr, int size)
{

    // 2개짜리, 4개짜리, 8개짜리...
    int i = 2;
    while (1)
    {
        // 전체범위(j-i) ~ (j-1), 대상범위(j-i/2)~(j-1) -> 삽입정렬 수행
        for (int j = 0; j <= size; j += i)
        {
            /* 삽입정렬을 수행할 대상 */
            for (int w = j - i / 2; w < j && w > 0; w++)
            {
                /* arr[w]를 arr[j-i]까지 삽입정렬 수행 */
                int k = w;
                while (k > 0 && k > j - i && arr[k] < arr[k - 1])
                {
                    swap(arr, k, k - 1);
                    k--;
                }
            }
        }

        /* 남은 숫자 처리하고 반복문 탈출 */
        if (i * 2 > size)
        {
            for (int i; i < size; ++i)
            {
                int k = i;
                while (k > 0 && arr[k] < arr[k - 1])
                {
                    swap(arr, k, k - 1);
                    k--;
                }
            }
            break;
        }
        i *= 2;
    }
}

void swap(int *arr, int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}