#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee {
	char name[20];
	char per_num[20];
	int money;
}EMPLOYEE;





int main() {
	EMPLOYEE employee[3];       //배열을 선언해서 구조체가 3개인 것과 비슷.
	int i = 0;
	for (i = 0; i < 3; i++) {
		printf("종업원 이름: ");
		scanf("%s", employee[i].name);
		printf("\n주민번호: ");
		scanf("%s", employee[i].per_num);
		printf("\n급여 정보:");
		scanf("%d", &employee[i].money);
		puts("");
	}

	for (i = 0; i < 3; i++) {
		printf("종업원 이름: %s\n", employee[i].name);
		printf("주민번호: %s\n", employee[i].per_num);
		printf("급여 정보: %d\n", employee[i].money);
		puts("");
	}
	
	return 0;


}