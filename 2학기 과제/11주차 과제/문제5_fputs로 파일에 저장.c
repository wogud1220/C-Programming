#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)

{

	FILE* fp = fopen("text.txt", "wt");

	char str[100];

	printf("문자를 입력\n");
	gets(str);
	puts(str);
	fputs(str, fp);
	fputs("\n", fp);
	printf("문자를 입력2\n");
	gets(str);

	puts(str);
	fputs(str, fp);
	fclose(fp);

	return 0;

}