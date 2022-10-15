#define _CRT_SECURE_NO_WARNINGS    
#include <stdio.h>

int main() {
	char name[20];
	char name2[20];
	int i;
	printf("이름과 나이를 입력하세요 ex) 홍길동 20\n");
	gets(name);
	gets(name2);
	puts("");
	puts(name);
	puts(name2);

	if (!strcmp(name, name2))
		puts("서로 이름, 나이가 같다");
	else
		puts("서로 이름, 나이가 다르다");
}