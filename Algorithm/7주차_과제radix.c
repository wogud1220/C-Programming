#include <stdio.h>

// 가장 큰 숫자를 찾는 함수
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// 기수 정렬을 위한 counting sort 함수
void countingSort(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};

    // 현재 자릿수를 기준으로 빈도수 계산
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    // count 배열 업데이트
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // 결과 배열에 정렬된 숫자 배치
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // 결과 배열을 복사
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

// 기수 정렬 함수
void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp);
    }
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("정렬 전 배열: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    radixSort(arr, n);

    printf("정렬 후 배열: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
