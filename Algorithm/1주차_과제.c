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
<<<<<<< HEAD:Algorithm/1주차 과제.c
	// #include <windows.h>
	// #pragma warning(disable:4996)
	void
	digitsum(int n)
{
	for (int i = n; i > 10; i % 10)
	{
		n = n + i % 10;
	}
	printf("%d", n);
	return;
}

int fac(char *str, int i)
{

	if (*(str + i) == ' ')
	{ // 공백이면 cnt 없이 순환

		fac(str, i + 1);
	}
	else if (*(str + i) != NULL)
	{ // 무언가가 있다면 cnt증가 시키고 순환
=======
		// #include <windows.h>
		// #pragma warning(disable:4996)

		void two(int n, int b)
		{
			if (n > 1)
				two(n / b, b);
			printf("%d", n % b);
		}

		void six(int n, int b)
		{

			if (n > 1)
				six(n / b, b);
			if (n % b > 10)
				printf("%c", 'A' + (n % b) - 10);
			else
				printf("%d", n % b);
		}

		int cnt = 0;

		int fac(char *str, int i)
		{

			if (*(str + i) == ' ')
			{ // 공백이면 cnt 없이 순환

				fac(str, i + 1);
			}
			else if (*(str + i) != NULL)
			{ // 무언가가 있다면 cnt증가 시키고 순환
>>>>>>> c4fd3acce0ad53857332ceffc6252d2b38e4d85c:Algorithm/1주차_과제.c

				cnt++;
				fac(str, i + 1);
			}
			else if (*(str + i) == NULL) // 비어있으면 종료
				return cnt;
		}
		int noname(int a[], int p, int r)
		{
			//	p부터 r까지
			int x = a[r];  // 끝을 x로 옮김
			int i = p - 1; // i는 p 전부터
			int temp;

<<<<<<< HEAD:Algorithm/1주차 과제.c
			for (int j = p; j < r - 1; j++)
			{
				if (a[j] <= x)
				{				   // 기준값보다 작으면
					temp = a[++i]; // 교환
=======
			for (int j = p; j < r - 1; j++)
			{
				if (a[j] <= x)
				{
					temp = a[++i];
>>>>>>> c4fd3acce0ad53857332ceffc6252d2b38e4d85c:Algorithm/1주차_과제.c
					a[i] = a[j];
					a[j] = temp;
				}
			}
			temp = a[i + 1];
			a[i + 1] = a[r];
			a[r] = temp;

<<<<<<< HEAD:Algorithm/1주차 과제.c
			return i + 1; // 2번째에 있는 값이 바뀌었다.

=======
			return i + 1;
>>>>>>> c4fd3acce0ad53857332ceffc6252d2b38e4d85c:Algorithm/1주차_과제.c
		}

		int main()
		{
			int num = 0;
			int n = 0;
			int b = 0;
			char str[100];
			char *strp = str;
			int a[10] = {2, 20, 4, 18, 6, 16, 14};
			int r = 0;
			int p = 0;
			while (1)
			{
				printf("1: 진수 변환\n2: 문자열 입력\n3: 의사 코드\n");
				scanf("%d", &num);
				digitsum(n);
				switch (num)
				{
				case 1:

					scanf("%d %d", &n, &b); // n은 숫자, b는 진수
					if (b <= 10)
						two(n, b);
					else
						six(n, b);
					printf("(%d)", b);
					printf("\n");
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
<<<<<<< HEAD:Algorithm/1주차 과제.c



=======
>>>>>>> c4fd3acce0ad53857332ceffc6252d2b38e4d85c:Algorithm/1주차_과제.c
		}