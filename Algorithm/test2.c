#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MAX_SIZE 100
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

int main()
{
    // int arr[] = {26, 5, 77, 1, 61, 11, 59, 15, 48, 19};
    int arr[10];
    for (int i = 1; i <= 10; i++) // 11~1까지 역순으로 집어넣음
    {
        arr[i] = 11 - i;
    }

    int temp[10];
    int p = 0;
    int r = sizeof(arr) / 4; // 10;
    int i = p;
    int q = (p + r) / 2;
    int a = 0;
    int j = q + 1;
    int t = 1;
    while (a < r / 2)
    {
        if (arr[i] < arr[i + 1]) // 오른쪽이 더 크면 왼쪽 넣고 오른쪽 넣기
        {
            temp[t++] = arr[i++]; // 5저장
            temp[t++] = arr[i++]; // 5다음인 26저장
        }
        else // 왼쪽이 더 크면 오른쪽 넣고 왼쪽 넣기
        {
            temp[t++] = arr[i + 1];
            i++;
            temp[t++] = arr[i++];
        }
        i = i + 1; // i=2가 됐음

    } // 2개씩 묵음 끝남
    i = 1;
    a = 0;
    while (a < r / 2 / 2)
    {
        if (arr[i] < arr[i + 1]) // 오른쪽이 더 크면 왼쪽 넣고 오른쪽 넣기
        {
            temp[t++] = arr[i++]; // 5저장
            temp[t++] = arr[i++]; // 5다음인 26저장
        }
        else // 왼쪽이 더 크면 오른쪽 넣고 왼쪽 넣기
        {
            temp[t++] = arr[i + 1];
            i++;
            temp[t++] = arr[i++];
        }
    }
    while (j <= r) // 왼쪽 정렬 다 끝나고 오른쪽이 남을 경우
    {
        temp[t++] = arr[j++];
    }

    //    return 0;
}