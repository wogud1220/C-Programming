#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef union mem {
	char mem1;
	int mem2;
	double mem3;
}MEM;

typedef enum e_mem {
	CHAR = 1, INT, DOUBLE
}E_NUM;
 
int main() {
	MEM member;
	member.mem3 = 1.72;
	member.mem2 = 10;
	member.mem1 = 'a';
	E_NUM dufrj;
	puts("");
	printf("저장할 자료형: 1은 문자열 2는 정수 3은 실수\n");
	scanf("%d", &dufrj);
	
	/*switch (dufrj) {
	case 1:
		scanf("%s", member.mem1);
		break;
	case 2:
		scanf("%d", &member.mem2);
		break;
	case 3:
		scanf("%lf", &member.mem3);
		break;
	}*/

	switch (dufrj) {    //size 맞추어서 하기
    
	case CHAR:
		printf("%c", member.mem1);
		break;
	case INT:
		printf("%d",member.mem2);
		break;
	case DOUBLE:
		printf("%lf", member.mem3);
		break;
	}
	return 0;

}