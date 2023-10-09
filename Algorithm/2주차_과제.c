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
void digitsum(int n)
{
	int d = 0;
	for (int i = n; i > 0; i = i / 10)
	{
		d = d + (i % 10);
		printf("%d + ", i % 10);
	}
	printf("= %d\n\n", d);
	return;
}

void hanoi(int m, char a, char b, char c)
{
	if (m == 1)
		printf("<1 원판>을 %c 에서 %c로 옮겼습니다.\n", a, c);
	else
	{
		hanoi(m - 1, a, c, b);
		printf("<%d> 원판을 <%c>에서 <%c>로 옮긴다.\n", m, a, c);
		hanoi(m - 1, b, a, c);
	}
}

int hanoiCount(int m)
{
	int num = 1;
	while (--m)
	{
		num = num * 2 + 1;
	}
	return num;
}

int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int arr2[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
int arr3[30] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
				21, 22, 23, 24, 25, 26, 27, 28, 29, 30};

int size1 = sizeof(arr) / 4;
int size2 = sizeof(arr2) / 4;
int size3 = sizeof(arr3) / 4;
int cnt = 1; // 기본 1번 탐색ㄴ
int binarySearch(int find, int first, int last)
{ // 배열과 찾을 값 받음
	int mid = (first + last) / 2;

	//==========실패할 경우
	// log2 N 이므로 10일때 3, 20일때 5, 30일때 5 값은 반올림 연산
	if ((int)ceil(log2(size2)) == cnt && (arr[mid] != find) // 최대 이동회수에 도달하고 중간값에도 아니라면2
		|| (arr[last] < find) || arr[first] > find)
	{																						// 마지막보다 크거나 처음거보다 작거나
		printf("%d %d %d %d %d", last, arr[last], find, (arr[last] < find), arr[last - 2]); // 반올림연산
		printf("\n찾지 못했습니다.\n");
		return 0;
	}
	//=========성공할 경우
	if (arr[first] == find)
	{
		printf("현재 검색 범위: [%d] ~ [%d]\n찾은 위치:[%d]\n중간 위치:[%d]\n\
비교하는 값:%d\n",
			   first, last, first, mid, find);
		printf("[%d]index에서 찾음\n", first);
	}
	else if (arr[last] == find)
	{
		printf("현재 검색 범위: [%d] ~ [%d]\n찾은 위치:[%d]\n중간 위치:[%d]\n\
비교하는 값(찾은 값):%d\n\n",
			   first, last - 1, last, mid, find);
		printf("[%d]index에서 찾음\n", last);
	}
	else if (arr[mid] == find)
	{ // mid에서 값을 찾으면
		printf("현재 검색 범위: [%d] ~ [%d]\n찾은 위치:[%d]\n중간 위치:[%d]\n\
비교하는 값(찾은 값):%d\n\n",
			   first, last, mid, mid, find);
		printf("[%d]index에서 찾음\n", mid);
	}
	else if (arr[mid] > find)
	{ // 찾을 값이 작으면 mid 왼쪽 이동
		printf("%d번 탐색\n현재 검색 범위: [%d] ~ [%d]\n중간 위치의 index:[%d]\n\
		중간 위치의 값:%d\n",
			   cnt, first, last, mid, arr[mid]);
		cnt++;
		binarySearch(find, first, last / 2);
	}
	else if (arr[mid] < find)
	{
		printf("%d번 탐색\n현재 검색 범위: [%d] ~ [%d]\n중간 위치:[%d]\n\
		중간 위치의 값:%d\n",
			   cnt, first, last, mid, arr[mid]);
		cnt++;
		binarySearch(find, mid, last);
		// 찾을 값이 크면 mid 오른쪽 이동
	}
	return cnt;
}

int main()
{
	int num = 0;
	int n = 0;
	int m = 3; // 하노이 개수
	char a = 'A';
	char b = 'B';
	char c = 'C';

	int first = 0;
	int last = (sizeof(arr) / 4) - 1;
	int cnt = 0;
	int dec = 0;

	printf("1: digitsum()\n2: binarySearch()\n3: hanoi()\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("정수를 입력하세요.\n");
		scanf("%d", &n);
		digitsum(n);
		break;
	case 2:
		printf("찾을 값을 입력하세요.\n");
		scanf("%d", &dec);
		cnt = binarySearch(dec, first, last);
		if (cnt >= 1)
			printf("%d번째 탐색에서 찾음\n", cnt);
		break;
	case 3:
		hanoi(m, a, b, c);
		printf("원판이 3개일 때 총 횟수는 = %d\n", hanoiCount(m));
		printf("m=4 : %d\nm=5 : %d\nm=6 : %d\nm=7 : %d\nm=8 : %d\nm=9 : %d\n", hanoiCount(m + 1), hanoiCount(m + 2), hanoiCount(m + 3),
			   hanoiCount(m + 4), hanoiCount(m + 5), hanoiCount(m + 6));
		break;
	default:
		break;
	}

	return 0;
}