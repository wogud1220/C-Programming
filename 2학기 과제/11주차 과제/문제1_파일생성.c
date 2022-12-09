#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)

{
	char str[30];
	FILE* fp = fopen("mystory.txt", "wt");
	fputs("#이름 : 홍길동\n", fp);

	fputs("#주민번호 : 020301 - 4012345\n", fp);

	fputs("#전화번호 : 010-1111-1111\n", fp);
	fputs("#즐겨먹튼 음식: 짬뽕, 탕수육\n", fp);
	fputs("#취미: 축구", fp);
	fclose(fp);
	fp=fopen("mystory.txt", "rt");
	//fseek(fp, SEEK_SET, 0);
	while (fgets(str, sizeof(str), fp) != NULL) {       //fp파일에서 str[30]자만큼의 크기를 str에 저장하여서 읽어옴
		fputs(str, stdout);         //표준 출력(모니터)으로 str출력함
	}


	fclose(fp);

	return 0;

}