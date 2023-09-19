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
int visit[100];                // 출력 했는지
int listOrigin[3] = {4, 5, 6}; // 출력 배열
int list[MAX_SIZE];

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
        list[n + 1] = listOrigin[i - 1]; // 리스트 배열에 i집어넣기 i는 순차적으로 증가

        visit[i] = 1; // 갖다 썼으니 1저장==방문했다

        // 후다 돌고난 뒤에 초기화
        fac(n + 1);   // 다음번째 숫자 재귀
        visit[i] = 0; // 재귀가 끝나고 0으로 초기화 해야됨
    }
}
int main()
{
    printf("hi\n");
    fac(0);
    return 0;
}
