#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char buf1[100];
	char buf2[100];
	char buf3[200];
	FILE* fp1 = fopen("file1.txt", "wt");
	FILE* fp2 = fopen("file2.txt", "wt");

	printf("문장입력: ");
	gets(buf1);
	fputs(buf1, fp1);
	printf("문장입력: ");
	gets(buf2);
	fputs(buf2, fp2);
	fclose(fp1);
	fclose(fp2);

	if (fp1 == NULL || fp2 == NULL) {
		printf("오류");
		return -1;
	}
	fopen(fp1,"rt");
	fgets(buf1, sizeof(buf1), fp1);
	fopen(fp2,"rt");
	fgets(buf2, sizeof(buf2), fp2);
	FILE* fp3 = fopen("file3.txt", "wt");
	fputs(buf1, fp3);
	fputs("\n", fp3);
	fputs(buf2, fp3);


	fclose(fp1);
	fclose(fp2);
	fclose(fp3);


	return 0;




}