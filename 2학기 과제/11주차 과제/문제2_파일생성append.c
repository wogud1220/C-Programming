#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)

{

	FILE* fp = fopen("mystory.txt", "at");




	fputs("#즐겨먹는 음식 : 피자, 파스타\n", fp);

	fputs("#취미 : 축구\n", fp);



	fclose(fp);

	return 0;

}