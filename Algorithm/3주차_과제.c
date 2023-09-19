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
    int arr[8] = {69, 10, 30, 2, 16, 8, 31, 22};
    int arrSize = sizeof(arr) / 4;
    int temp;
    int i = 0;
    int final = 0;
    int cnt = 0;

    int minIdx;
    for (int j = 0; j < sizeof(arr) / 4 - 1; j++) // n-1번
    {
        int min = arr[j];

        for (i = j; i < sizeof(arr) / 4 - 1; i++)
        {
            if (min > arr[i + 1]) // 더 작은거 발견하면 idx,min갱신;
            {
                min = arr[i + 1];
                minIdx = i + 1;
                cnt++; // 교환 횟수 증가;

                temp = arr[j]; // 첫번째값이랑 교환하고
                arr[j] = min;
                arr[minIdx] = temp;
            }
        }
        for (int a = 0; a < sizeof(arr) / 4; a++)
        {
            printf("[%d] ", arr[a]);
        }
        printf("  %d단계 %d번의 비교 ,%d번의 교환 이루어짐\n", j + 1, --arrSize, cnt);

        cnt = 0;
    }
    return;
}

void bubbleSort()
{
    int arr[8] = {69, 10, 30, 2, 16, 8, 31, 22};
    int maxIdx, temp;
    int arrSize = sizeof(arr) / 4;
    for (int j = 0; j < arrSize - 1; j++)
    {
        int cnt = 0;
        int max = arr[0];
        maxIdx = 0;
        printf("%d단계>>\n", j + 1);

        for (int i = 0; i < (sizeof(arr) / 4) - 1 - j; i++)
        {
            // 맥스값 한번씩 이동시키기;

            if (max > arr[i + 1]) // 맥스가 더 큰 값이면 오른쪽거랑 교환
            {
                temp = arr[i + 1];        // 3->temp;
                arr[i + 1] = arr[maxIdx]; // 31->[1]
                arr[maxIdx] = temp;       // 위치 교환 후;
                maxIdx++;                 // 증가;
                cnt++;                    // 교환 횟수 표시;2
            }

            else // 더 큰게 아니면 맥스값 이동시키기;
            {
                maxIdx++;
                max = arr[i + 1];
            }

            for (int a = 0; a < sizeof(arr) / 4; a++)
            {
                printf("[%d] ", arr[a]);
            }

            printf("  %d\n", i + 1);

        } // for(i)

        printf("%d번의 교환이 이루어졌습니다.\n", cnt);

        if (cnt == 1)
        {
            printf("제자리 교환");
            break;
        }
    } // for(j);
    return;
}
void binarySearch(int arr1[], int arr1Size)
{
    int first = 0;
    int end = arr1Size;
    int find = arr1[first];
    int cnt = 0;
    int i = 0;
    while (1)
    {
        if (find == arr1[arr1Size])
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
int visit[100];                // 출력 했는지
int listOrigin[3] = {4, 5, 6}; // 진짜 배열
int list[MAX_SIZE];            // 출력할 값을 넣을 배열
void fac(int n)
{
    if (n == sizeof(listOrigin) / 4) // 종료
    {
        for (int i = 1; i <= sizeof(listOrigin) / 4; i++)
            printf("%d ", list[i]); // 리스트에 있는 값 사이즈만큼 출력
        printf("\n");
        return;
    }

    for (int i = 1; i <= sizeof(listOrigin) / 4; i++)
    {
        if (visit[i] == 1) // 방문 했으면 넘어가기
            continue;
        list[n + 1] = listOrigin[i - 1]; // 리스트 배열에 origin에 있는 값 집어넣기, i가 1부터 시작하니[0]번 인덱스 넣으려고

        visit[i] = 1; // 갖다 썼으니 1저장==방문했다

        // 후다 돌고난 뒤에 초기화
        fac(n + 1);   // 다음번째 숫자 재귀
        visit[i] = 0; // 재귀가 끝나고 0으로 초기화 해야됨
    }
}
int main()
{
    int problemNum;
    // binarySearch에 사용
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int arr1Size = sizeof(arr1) / 4 - 1;
    int arr2Size = sizeof(arr2) / 4 - 1;
    //
    printf("1:select Sort()\n2:binarySearch()\n3:Bubble Sort()\n4:permutation()\n");
    scanf("%d", &problemNum);
    switch (problemNum)
    {
    case 1:
        selectsort();
        break;
    case 2: // 1~20까의 탐색 기록, 인덱스 출력
        binarySearch(arr2, arr2Size);
        break;
    case 3:
        bubbleSort();
        break;
    case 4:
        fac(0);
        break;
    default:
        break;
    }

    return 0;
}