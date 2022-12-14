#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct book {
	char name[10];
	char phone[20];
	struct book* next;
}BOOK;


int main() {
	BOOK* head;
	BOOK* temp;
	BOOK* sick;
	BOOK* out;
	BOOK* tail;
	temp = head = NULL;
	char in_name[10];
	int cnt = 0;

	while (1) {
		printf("이름을 입력하세요: ");
		scanf("%s", in_name);


		if (!strcmp(in_name, "q")) {
			printf("종료하겠습니다.");
			break;
		}

		else if (cnt == 0) {
			head = malloc(sizeof(BOOK));
			temp = head;
		}
		else {
			temp->next = malloc(sizeof(BOOK));
			temp = temp->next;
		}

		strcpy(temp->name, in_name);

		printf("전화번호를 입력하세요");
		scanf("%s", temp->phone);

		temp->next = NULL;
		cnt++;

	}


	temp = head;
	while (1) {
		if (temp->next != NULL) {
			printf("\n%s는 %s에게 연락을 해야 합니다.%s의 연락처는 %s입니다.\n", temp->name, temp->next->name, temp->next->name, temp->next->phone);
			temp = temp->next;
		}
		else if (temp->next == NULL) {
			printf("%s가 마지막으로 연락을 받았습니다. 모든 구성원들에게 연락을했습니다.\n", temp->name);
			break;
		}
	}

	temp = head;
	//그냥 사람 찾기
	printf("찾을 구성원의 이름을 입력하세요: ");
	scanf("%s", in_name);

	while (1) {
		if (!strcmp(temp->name, in_name)) {
			printf("%s는 %s에게 연락해야 합니다. %s의 전화번호는 %s입니다.\n", temp->name, temp->next->name, temp->next->name, temp->next->phone);
			break;
		}
		else
			temp = temp->next;
	}


	//아픈 사람 찾기
	temp = head;
	sick = head;
	printf("아픈 사람을 입력하세요: ");
	scanf("%s", in_name);

	printf("\n");

	while (1) {
		if (!strcmp(temp->name, in_name)) {
			printf("%s는 %s에게 연락해야 합니다. %s의 전화번호는 %s입니다.\n\n", sick->name, sick->next->next->name, sick->next->next->name, sick->next->next->phone);
			break;
		}
		else {
			sick = temp;
			temp = temp->next;
		}
	}

	//탈퇴한 사람 찾기
	temp = head;
	out = head;
	
	printf("탈퇴한 사람을 입력하세요: ");
	scanf("%s", in_name);
	while (1) {
        out ->next = malloc(sizeof(BOOK));
		if (!strcmp(out->name, in_name)) {
			printf("%s님이 탈퇴했습니다. 앞으로는 %s가 %s에게 연락해야합니다.\n", out->name, temp->name, out->next->name);
			temp->next = out->next;
			free(out);
			break;
		}
		else {
			temp = out;
			out = out->next;
		}
	}

	temp = head;



	printf("\n연락처 출력 아프고, 탈퇴한 사람 제외하고\n");
	while (temp != NULL) {
		if (!strcmp(sick->name, temp->name)) {
			temp = temp->next;
			continue;
		}
		//else if(!strcmp(temp->name, ))
		else {
			printf("%s의 연락처는 %s입니다.\n", temp->name, temp->phone);
			temp = temp->next;
		}
	}



}