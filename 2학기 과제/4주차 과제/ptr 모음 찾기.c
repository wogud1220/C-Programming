#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void mo(char *ptr1, char *ptr2, int* num1, int* num2) {
	int cnt1 = 0;
	int cnt2 = 0;
	int i = 0;

		for (i = 0; i < sizeof(ptr1) / sizeof(char); i++) {
			if (*(ptr1+i) == 'a')
				cnt1++;
			else if (*(ptr1 + i) == 'e')
				cnt1++;
			else if (*(ptr1 + i) == 'i')
				cnt1++;
			else if (*(ptr1 + i)== 'o')
				cnt1++;
			else if (*(ptr1 + i) == 'u')
				cnt1++;
		}
		for (i = 0; i < sizeof(ptr2) / sizeof(char); i++) {
			if (*(ptr2+i) == 'a')
				cnt2++;
			else if (*(ptr2 + i) == 'e')
				cnt2++;
			else if (*(ptr2 + i) == 'i')
				cnt2++;
			else if (*(ptr2 + i) == 'o')
				cnt2++;
			else if (*(ptr2 + i) == 'u')
				cnt2++;
		}
	*num1 = cnt1;
	*num2 = cnt2;
	return 0;
}
void  main() {
	char word1[50];
	char word2[50];
	int num1, num2;
	char* ptr1 = word1;
	char* ptr2 = word2;
	printf("단어를 2개 입력하세요\n");
	scanf("%s",word1);
	scanf("%s",word2);
	mo(ptr1, ptr2, &num1, &num2);
	printf("word1의 모음의 수는 %d개입니다.\n", num1);
	printf("word2의 모음의 수는 %d개입니다.", num2);
}