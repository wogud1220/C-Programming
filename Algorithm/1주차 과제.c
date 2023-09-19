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
	for (int i = n; i > 10; i % 10) {
		n = n + i % 10;
	}
	printf("%d", n);
	return;
}

int fac(char* str, int i) {


	if (*(str + i) == ' ') {//공백이면 cnt 없이 순환

		fac(str, i + 1);
	}
	else if (*(str + i) != NULL) {	//무언가가 있다면 cnt증가 시키고 순환

		cnt++;
		fac(str, i + 1);
	}
	else if (*(str + i) == NULL)	//비어있으면 종료
		return cnt;


}
int noname(int a[], int p, int r) {
	//	p부터 r까지
	int x = a[r];	//끝을 x로 옮김
	int i = p - 1;	//i는 p 전부터
	int temp;

	for (int j = p; j < r - 1; j++) {
		if (a[j] <= x) {	//기준값보다 작으면
			temp = a[++i];	//교환
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[i + 1];
	a[i + 1] = a[r];
	a[r] = temp;

	return i + 1;	//2번째에 있는 값이 바뀌었다.

}

int main() {
	int num = 0;


	
	while (1) {
		printf("1: digitsum()\n2: 문자열 입력\n3: 의사 코드\n");
		scanf("%d", &num);
		digitsum(n);
		switch (num)
		{
		case 1:

			scanf("%d", &n);	//n은 숫자, b는 진수
			continue;
		case 2:
			printf("문자열 입력:");

			scanf(" %[^\n]s", strp);
			printf("\n공백을 제외한 크기는 %d", fac(strp, 0));
			printf("\n");
			continue;
		case 3:
			scanf("%d %d", &p, &r);
			for (int i = 0; i < 10; i++)
				printf("%d ", a[i]);
			printf("\n");
			int sam = noname(a, p, r);
			for (int i = 0; i < 10; i++)
				printf("%d ", a[i]);
			printf("\n%d", sam);
			printf("\n");
			continue;
		default:
			break;
		}
	}


	return 0;



}