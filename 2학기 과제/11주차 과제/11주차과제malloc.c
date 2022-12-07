#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define SLEN 30
#define SLINE 5

int main() {
	char** sentence = (char**)(sizeof(char*) * SLINE);
	int i;

	for (i = 0; i < SLINE; i++) {
		sentence[i] = (char*)malloc(sizeof(char) * SLEN);
		memset(sentence[i], 0, sizeof(char) * SLEN);

		printf("문장을 입력하세요 >>");
		fgets(sentence[i], SLEN, stdin);
		sentence[i][strlen(sentence[i]) - 1] = 0;
		
	}
	for (i = 0; i < SLINE; i++) {
		printf("%2d %s\n", i, sentence[i]);
	}
	for (i = SLINE-1; i>=0; i--) {
		printf("%2d %s\n", i, sentence[i]);
	}

	for (i = 0; i < SLINE; i++) {
		free(sentence[i]);
	}
	free(sentence);
	return 0;
}