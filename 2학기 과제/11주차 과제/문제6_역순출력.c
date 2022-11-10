#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)

{

	FILE* fp = fopen("text.txt", "wt");

	char str[3][100];
	int i = 0;
	int a = 0;
	for (i = 0; i < 3; i++) {
		printf("문자를 입력\n");
		gets(str[i]);
		fputs(str[i], fp);
		fputs("\n", fp);
	}

	fclose(fp);

	FILE* fp2 = fopen("text.txt", "rt");
	while (fgets(str, sizeof(str), fp2) != NULL) {
		printf("%d   %s", i + 1, str[i]);
		i++;
	}
	while (i > 0) {
		i--;
		printf("%d   %s", i + 1, str[i]);
	}
	fclose(fp2);
	return 0;

}