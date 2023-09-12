#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_SIZE 1000001
#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
#include <ctype.h>
//#include <windows.h>
//#pragma warning(disable:4996)
void digitsum(int n) {
	int d = 0;
	for (int i = n; i >0; i=i / 10) {
		 d= d + (i % 10);
		 printf("%d + ", i%10);
	}
	printf("= %d\n\n", d);
	return;
}



void hanoi(int m, char a, char b, char c) {
	if (m == 1)
		printf("<1 원판>을 %c 에서 %c로 옮겼습니다.\n",a,c);
	else {
		hanoi(m - 1, a, c, b);
		printf("<%d> 원판을 <%c>에서 <%c>로 옮긴다.\n",m, a, c);
		hanoi(m - 1, b,a,c);
	}
}



int hanoiCount(int m) {
	int num = 1;
	while (--m) {
		num = num * 2 + 1;
	}
	return num;
}



int cnt = 1;

void binarySearch(int arr[],int find,int first,int last) {	//배열과 찾을 값 받음
	int mid = (first + last) / 2;
	float size = last + 1;


	//==========실패할 경우
	if ((int)log2(size)==cnt && (arr[mid] != find) || arr[last] < find ||
		arr[first]>find) {
		//최대 이동회수에 도달하고 중간값에도 아니라면
		//정렬된 값보다 크다면	
		//정렬된 값보다 작으면
		printf("\n%d번 탐색에도 찾지 못했습니다.\n", cnt);
		return;
	}
	if (arr[first] == find) {
		printf("현재 검색 범위: [%d] ~ [%d]\n찾은 위치:[%d]\n중간 위치:[%d]\n\
비교하는 값:%d", first, last, first, mid, find);
		printf("%d번째에 찾음\n", cnt);
	}
	else if (arr[last] == find) {
		printf("현재 검색 범위: [%d] ~ [%d]\n찾은 위치:[%d]\n중간 위치:[%d]\n\
비교하는 값(찾은 값):%d\n\n", first, last, last, mid, find);
		printf("%d번째에 찾음\n", cnt);
	}
	else if (arr[mid] == find) {	//mid에서 값을 찾으면
		printf("현재 검색 범위: [%d] ~ [%d]\n찾은 위치:[%d]\n중간 위치:[%d]\n\
비교하는 값(찾은 값):%d\n\n", first, last, mid, mid, find);
		printf("%d번째에 찾음\n", cnt);
	}
	else if (arr[mid] > find) {	//찾을 값이 작으면 mid 왼쪽 이동
		cnt++;
		printf("현재 검색 범위: [%d] ~ [%d]\n중간 위치의 값:[%d]\n찾는 값:%d\n", first, last, mid, find);
		binarySearch(arr, find, first, last / 2);
	}
	else if (arr[mid] < find) {
		cnt++;
		printf("현재 검색 범위: [%d] ~ [%d]\n중간 위치:[%d]\n비교하는 값:%d\n", first, last, mid, find);
		binarySearch(arr, find, mid, last);
		//찾을 값이 크면 mid 오른쪽 이동
	}



	
	
	
}

int main() {
	int num = 0;
	int n = 0;
	int m = 5;	//하노이 개수
	char a = 'A';
	char b = 'B';
	char c = 'C';
	int arr[10] = { 1,3,4,5,6,7,8,9,10,11};
	int first = 0;
	int last = 9;
	int dec = 0;
	while (1) {
		printf("1: digitsum()\n2: binarySearch()\n3: hanoi()\n");
		scanf("%d", &num);

		switch (num)
		{
		case 1:
			printf("정수를 입력하세요.\n");
			scanf("%d", &n);
			digitsum(n);
			continue;
		case 2:
			printf("찾을 값을 입력하세요.\n");
			scanf("%d", &dec);
			binarySearch(arr,dec,first,last);
			continue;
		case 3:
			hanoi(m, a, b, c);
			printf("총 횟수는 = %d\n",hanoiCount(m));
			continue;
		default:
			break;
		}
	}








	return 0;



}