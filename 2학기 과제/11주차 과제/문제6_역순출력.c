#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>



int main(void) {

	FILE* fp;
	char buf[100];
	char list[10][100];
	int i = 0;
	int line = 0;
	fp = fopen("text.txt", "w+");

	if (fp == NULL) {
		puts("파일오픈 실패!");
		return -1;
	}
	printf("몇 줄을 입력하실건가요\n");
	scanf("%d", &line);
	getchar();
	for (i = 0; i < line; i++) {
		printf("%d번째 문장 입력 :", i + 1);
		gets(list[i]);
		fputs(list[i], fp);
		fputs("\n", fp);
	}

	i = 0;

	fseek(fp, 0, SEEK_SET);

	while (fgets(list[i], sizeof(list[i]), fp) != NULL) {
		printf("%d: %s", i + 1, list[i]);

		i++;

	}
	//puts("");

	while (i > 0) {

		i--;

		printf("%d: %s", i + 1, list[i]);

	}



	return 0;

}

