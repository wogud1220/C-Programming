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

void insertionSort(int *arr)
{
    // 최선의 비교 횟수:n번, 최악의 비교 횟수:n(n-1)/2
    int i, j, temp;
    int total = 0;

    printf("삽입 정렬 수행\n");
    for (i = 1; i < 8; i++)
    {
        int cnt = 1; // 안 옮겨도 카운트해줘야함;
        temp = arr[i];
        int exchange = 0;                             // 비교할 뒤의 숫자를 복사시킴
        for (j = i - 1; j >= 0 && arr[j] > temp; j--) // 옮길때
        {                                             // temp가 더 큰 값일 때까지
            arr[j + 1] = arr[j];                      // 한칸뒤로 이동시킴
            cnt++;                                    // 옮기면 카운트해주고
            exchange++;                               // 교환 횟수 증가
            if (arr[j - 1] == 0)
            // 기본적으로 1번 카운트해줘서 벽을 만나면 비교한게 아닌 걸로해서 감소시킴
            {
                cnt--;
            }
        }

        arr[j + 1] = temp; //
        printf("%d단계: ", i);
        for (int a = 0; a < 8; a++)
        {
            printf("%d ", arr[a]);
        }
        total += cnt;
        printf(" %d번의 비교\n%d번의 교환\n[%d]번 index까지 정렬 완료.\n\n", cnt, exchange, i);
    }
    printf("총 비교 횟수는: %d번 입니다.a", total);
}
void merge(int arr[], int p, int q, int r)
{
    int temp[100];
    int i = p;
    int j = q + 1;
    int t = 0;
    int a = 0;

    while (i <= q && j <= r) // 정렬이 안끝난 상태에서
    {
        if (arr[i] <= arr[j]) // 오른쪽 반이 더 크면
        {
            temp[t++] = arr[i++]; // 왼쪽이 더 작으니 왼쪽걸 집어넣기
        }
        else
        {
            temp[t++] = arr[j++];
        }
    }
    while (i <= q) // 오른쪽 정렬 다 끝나고 왼쪽이 남을 경우
    {
        temp[t++] = arr[i++];
    }

    while (j <= r) // 왼쪽 정렬 다 끝나고 오른쪽이 남을 경우
    {
        temp[t++] = arr[j++];
    }

    i = p;
    t = 0;
    while (i <= r) // 결과 저장
    {
        arr[i++] = temp[t++];
        printf("[%d] ", temp[t - 1]); // 병합된 범위 출력
    }
    printf("정렬됨\n");

    for (int i = 0; i < 8; i++)
    {
        printf("[%d] ", arr[i]);
    }

    printf("\n");
    return;
}
void mergeSort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
    return;
}

int main()
{
    int arr[] = {1, 4, 5, 2, 16, 8, 31, 22};
    int p = 0;
    int r = 7;
    printf("1:insertionSort\n2:mergeSort\n");
    int num;
    scanf("%d", &num);
    switch (num)
    {
    case 1:
        insertionSort(arr);
        // n-1번 비교, n에 비례하는 복잡도
        // 최악: n(n-1)/2  n^2에 비례
        break;
    case 2:
        printf("<<<<<<<병합 정렬 수행>>>>>>>\n");
        mergeSort(arr, p, r);
        break;
    case 3:

        break;
    default:
        break;
    }

    return 0;
}