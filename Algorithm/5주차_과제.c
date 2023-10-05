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
int partition1(int arr[], int p, int r) // 1이랑 9받음
// 맨 오른쪽 값이 pivot
{
    int temp;
    int x = arr[r];                  // pivot값 들어감
    int i = p - 1;                   // i는 시작한칸전 가르킴
    for (int j = p; j <= r - 1; j++) // 마지막 요소까지 비교
    {
        if (arr[j] <= x) // pivot이 더 크면
        {
            ++i; // i는 pivot보다 작은 값의 영역
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        for (int a = 0; a < 10; a++)
        {
            printf("%d ", arr[a]);
        }
        printf("\n");
    }

    /*마지막에 i의 다음값과 pivot바꿔줌
    pivot을 기준으로 나눈걸 보여주기위해*/
    temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;
    return i + 1;
}
void quickSort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = partition1(arr, p, r); // 시작,끝 보내줌
        // pivot값의 index 리턴받아옴
        quickSort(arr, p, q - 1);
        // pivot보다 작은 범위 정렬
        quickSort(arr, q + 1, r);
        // pivot보다 큰 범위 정렬
    }

    return;
}

int partition2(int arr[], int p, int r) // 1이랑 9받음
// 맨 오른쪽 값이 pivot
{
    int temp;
    int x = arr[p];              // 첫번재 인덱스에 pivot
    int i = p - 1;               // i는 시작한칸전 가르킴
    for (int j = p; j <= r; j++) // 마지막 요소까지 비교
    {
        if (arr[j] <= x) // pivot이 더 크면
        {
            ++i; // i는 pivot보다 작은 값의 영역
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        for (int a = 0; a < 10; a++)
        {
            printf("%d ", arr[a]);
        }
        printf("\n");
    }

    /*마지막에 i의 다음값과 pivot바꿔줌
    pivot을 기준으로 나눈걸 보여주기위해*/
    temp = arr[i]; // 다음 값이 아니라 i끝값과 바꿔줌
    arr[i] = arr[p];
    arr[p] = temp;
    return i;
}
void quickSort2(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = partition2(arr, p, r); // 시작,끝 보내줌
        // pivot값의 index 리턴받아옴
        quickSort2(arr, p, q - 1);
        // pivot보다 작은 범위 정렬
        quickSort2(arr, q + 1, r);
        // pivot보다 큰 범위 정렬
    }

    return;
}
void swap(int arr[], int left, int right)
{
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;

    return;
}
int partition3(int arr[], int left, int right)
{
    int pivotValue = arr[left];
    int leftMark = left + 1, rightMark = right;
    while (leftMark <= rightMark)
    {
        while (arr[leftMark] <= pivotValue)
        {
            leftMark++;
        }
        while (arr[rightMark] > pivotValue)
        {
            rightMark--;
        }
        if (leftMark <= rightMark)
        {
            swap(arr, arr[leftMark], arr[rightMark]);
        }
    }
    swap(arr, arr[left], arr[rightMark]);
    return rightMark;
}

void quickSort3(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = partition3(arr, p, r); // 시작,끝 보내줌
        // pivot값의 index 리턴받아옴
        quickSort3(arr, p, q - 1);
        // pivot보다 작은 범위 정렬
        quickSort3(arr, q + 1, r);
        // pivot보다 큰 범위 정렬
    }

    return;
}
int main()
{
    int arr[10] = {31, 8, 48, 73, 11, 3, 20, 29, 65, 15};
    int num = 0;
    int r = 9;
    int p = 0;
    printf("번호 입력: ");
    scanf("%d", &num);
    switch (num)
    {
    case 1:

        quickSort(arr, p, r);
        printf("\n\n분할1의 최종결과\n");
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", arr[i]);
        }
        break;
    case 2:
        quickSort2(arr, p, r);
        printf("\n\n분할2의 최종결과\n");
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", arr[i]);
        }
        break;
    case 3:
        quickSort3(arr, p, r);
        printf("\n\n분할3의 최종결과\n");
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", arr[i]);
        }
        break;
    default:
        break;
    }

    return 0;
}