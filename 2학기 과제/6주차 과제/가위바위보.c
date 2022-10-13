#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // rand()함수를 포함하는 라이브러리
#include <time.h>   // time()함수를 포함하는 라이브러리

int main(void) {
	srand(time(NULL)); // 매번 다른 난수가 발생하도록 하기 위해서 사용
	int random = 0;
	char user[5];
	char computer[5];
	int win = 0, lose = 0, draw = 0;
	for (int i = 0; i < 10; i++) {
		random = rand() % 3;          // 가위, 바위, 보를 위한 3개의 난수 생성
		printf("가위, 바위, 보 중에서 하나를 입력하세요\n\n"); // 가위는 0, 바위는 1, 보는 2
		gets(user); // 또는 scanf("%s", user)
		switch (random) {
		case 0: strcpy(computer, "가위");
			break;
		case 1: strcpy(computer, "바위");
			break;
		case 2: strcpy(computer, "보");
			break;
		}
		printf("\n당신은 %s, 컴퓨터는 %s 선택하였습니다. \t", user, computer);
		if (!strcmp(user, "가위")) {			//사용자가 가위일 때
			if (!strcmp(computer, "가위")) {
				printf("비겼습니다.\n\n");
				printf("%d승 %d무\n\n", win, ++draw);
			}
			else if (!strcmp(computer, "바위")) {
				printf("당신이 졌습니다.\n\n");
				printf("게임의 결과 : %d승 %d무\n\n", win, draw);
				return 0;
			}
			else if (!strcmp(computer, "보")) {
				printf("당신이 이겼습니다.\n\n");
				printf("%d승 %d무\n\n", ++win, draw);
			}
		}
		if (!strcmp(user, "바위")) {		//사용자가 바위일 때
			if (!strcmp(computer, "가위")) {
				printf("당신이 이겼습니다.\n\n");
				printf("%d승 %d무\n\n", ++win, draw);
			}
			else if (!strcmp(computer, "바위")) {
				printf("비겼습니다.\n\n");
				printf("%d승 %d무\n\n", win, ++draw);
			}
			else if (!strcmp(computer, "보")) {
				printf("당신이 졌습니다.\n\n");
				printf("게임의 결과 : %d승 %d무\n\n", win, draw);
				return 0;
			}
		}
		if (!strcmp(user, "보")) {		//사용자가 보일 때
			if (!strcmp(computer, "가위")) {
				printf("게임의 결과 : 당신이 졌습니다.\n\n");
				printf("%d승 %d무\n\n", win, draw);
				return 0;
			}
			else if (!strcmp(computer, "바위")) {
				printf("당신이 이겼습니다.\n\n");
				printf("%d승 %d무\n\n", ++win, draw);
			}
			else if (!strcmp(computer, "보")) {
				printf("비겼습니다.\n\n");
				printf("%d승 %d무\n\n", win, ++draw);
			}
		}
	}
}
