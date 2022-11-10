#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)

{

	FILE* fp = fopen("mystory.txt", "rt");

	char str[100];

	while (fgets(str, sizeof(str), fp) != NULL) {
		puts(str);
	}


	fclose(fp);

	return 0;

}

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)

{
	int fpos;

	FILE* fp = fopen("mystory.txt", "rt");

	char str[100];


	while (fgets(str, sizeof(str), fp) != NULL) {
		puts(str);
	}
	
	/*fpos = ftell(fp);
	if (fpos == NULL) {
		printf("끝입ㄴ니ㅏㄷ.");
	}*/

	fclose(fp);

	return 0;

}