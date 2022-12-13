#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


typedef enum season {
	spring = 1, summer, fall, winter

}SEASON;


int main() {
	SEASON ss;
	char* ptr = 0;
	printf("숫자 입력해주세요 1,2,3,4\n");
	scanf("%d", &ss);
	switch (ss) {
	case spring:
		ptr = "inline";
		break;
	case summer:
		ptr = "swimming";
		break;
	case fall:
		ptr = "trip";
		break;
	case winter:
		ptr = "skiing";
		break;
	}
	printf("나의 레저 할동 : %s", ptr);
}