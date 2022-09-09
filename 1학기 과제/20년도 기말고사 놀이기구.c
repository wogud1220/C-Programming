#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int old;
int height;
int main(void)
{
	printf("나이와 키를 입력하세요"); // 나이와 키 입력하세요 출력
	scanf_s("나이:%d  키:%d", &old, &height);//나이와 키 입력받아서 저장
	check(); //나이와 키를 검사하는 함수 불러옴
	nol();  //nol(놀이기구의 시간을 입력) 함수 불러옴
}
int check(void)
{
	scanf_s("%d %d", &old, &height);// 나이와 키 입력받음
	if (old > 7 && height > 109)//나이 8이상 키 110이상 만족한다면
		printf("탑승 가능\n");// 탑승 가능 출력
	else
		printf("탑승 불가능\n");// 탑승 불가능 출력
	return;
}
int nol(void) {
	printf("놀이기구 동작 시간(분)을 입력하세요");//놀이기구 동작 분 입력하기
	int arr[5];						//5개 놀이기구의 시간 배열 저장
	int i;
	int temp, j;
	for (i = 0; i < 5; i++) {		// 배열에 들어가는 반복문
		scanf_s("%d", &arr[i]);		//5개의 배열에 들어가는 수 입력
	}
	printf("%d분\n", arr[0]);	// 배열에 저장된 놀이기구의 1~5가지의 시간 저장
	printf("%d분\n", arr[1]);
	printf("%d분\n", arr[2]);
	printf("%d분\n", arr[3]);
	printf("%d분\n", arr[4]);

	for (i = 0; i < 5 - 1; i++) // 무작위로 입력된 시간 크기에 따라 정렬하는 반복문
	{
		for (j = 0; j < 5 - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	printf("시간에 따른 놀이기구를 먼저 타야하는 순서 : \n");
	int a = 1;
	for (int i = 0; i < 5; i++)
	{
		printf("%d번째: %d분에 운행하는 놀이기구\n ", a, arr[i]);// 무작위로 입력된 시간 오름차순으로 정렬
		a++;
	}
	return;
}


