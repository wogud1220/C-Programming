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

void binarySearch(int arr1[], int arr1Size)
{
    int first = 0;
    int end = arr1Size;
    int find = arr1[first];
    int cnt = 0;
    int i = 0;
    while (1)
    {
        if (find == 10)
            break;
        int mid = (end + first) / 2;
        printf("%d번째 탐색 결과\n현재 검색 범위:[%d] ~ [%d]\n\
중간 값의 인덱스:[%d]\n",
               cnt + 1, first, end, mid);
        if (find == arr1[first])
        {
            printf("%d찾기   [%d]번째에서 찾음, %d번의 범위 탐색\n\n", find, first, cnt + 1);
            find++;
            // 나머지 first,end,mid돋 초기화해야됨
            first = 0;
            cnt = 0;
            end = arr1Size;

            continue;
        }
        else if (find == arr1[end])
        {
            printf("%d찾기  [%d]번째에서 찾음, %d번의 범위 탐색\n\n", find, end, cnt + 1);
            find++;
            first = 0;
            cnt = 0;
            end = arr1Size;
            continue;
        }
        else if (find == arr1[mid])
        {
            printf("%d찾기  [%d]번째에서 찾음, %d번의 범위 탐색\n\n", find, mid, cnt + 1);
            find++;
            first = 0;
            cnt = 0;
            end = arr1Size;
            continue;
        }
        else // 못 찾았고;
        {
            if (find < arr1[mid]) // 찾을 값이 중간값보다 작다면;
            {
                end = mid;
                cnt++;
            }
            else if (find > arr1[mid]) // 찾을 값이 중간갑ㅂㅅㅂ다 크다면;
            {
                first = mid;
                cnt++;
            }
        }
    }
}

int main()
{
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr1Size = sizeof(arr1) / 4 - 1;
    binarySearch(arr1, arr1Size);
    return 0;
}