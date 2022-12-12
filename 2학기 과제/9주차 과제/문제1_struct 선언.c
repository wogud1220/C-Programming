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
	EMPLOYEE employee;      //구조체 변수 선언

	printf("종업원 이름: ");
	scanf("%s", employee.name);
	printf("\n주민번호: ");
	scanf("%s", employee.per_num);
	printf("\n급여 정보:");
	scanf("%d", &employee.money);       //  &꼭 넣기!!

	printf("종업원 이름: %s\n", employee.name);
	printf("주민번호: %s\n", employee.per_num);
	printf("급여 정보: %d\n", employee.money);
	
	return 0;


}