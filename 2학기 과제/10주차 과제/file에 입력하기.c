#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {


	FILE* fp = fopen("simple.txt", "wt");

	fputc('A', fp);
	fputs("B\n", fp);
	fputs("My name is", fp);
	fclose(fp);
	return 0;

}