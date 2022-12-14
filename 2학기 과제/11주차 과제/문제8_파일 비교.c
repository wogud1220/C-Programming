#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char buf1[100];
	char buf2[100];

	FILE* fp = fopen("file1.txt", "rt");
	FILE* fp2 = fopen("file2.txt", "rt");

	
	fgets(buf1, 100, fp);
	fgets(buf2, 100, fp2);

	if (!strcmp(buf1, buf2)) {
		printf("같은 파일입니다.");
	}
	else
		printf("다른 파일입니다.");


	fclose(fp);
	fclose(fp2);
}