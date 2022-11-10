#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


long asdf(FILE* fp) {
	int fpos = ftell(fp);
	return fpos;
}

int main(void)

{

	FILE* fp = fopen("mystory.txt", "rt");

	char str[200];


	while (fgets(str, sizeof(str), fp) != NULL) {
		puts(str);
	}
	

	printf("파일크기는:%d", asdf(fp));
	rewind(fp);

	fclose(fp);

	return 0;

}