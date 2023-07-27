#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)



typedef struct listnode {
	char name[100];
	char genre;
	int year;
	struct listnode* link;
}LISTNODE;


LISTNODE* insert_first(LISTNODE* head, char main_name[], char main_genre, int main_year) {
	LISTNODE* p = (LISTNODE*)malloc(sizeof(LISTNODE));
	strcpy(p->name, main_name);
	p->genre = main_genre;
	p->year = main_year;
	p->link = head;
	head = p;
	return head;
}

LISTNODE* insert(LISTNODE* head, LISTNODE* pre, char main_name[], char main_genre, int main_year) {
	LISTNODE* p = (LISTNODE*)malloc(sizeof(LISTNODE*));
	int j = 0;
	strcpy(p->name, main_name);
	p->genre = main_genre;
	p->year = main_year;
	//---몇 번에 들어가야하는지 반복 함수 추가
	while(1) {
		if (strcmp(p->name, pre->name) > 0 && pre->link==NULL) {	//pre보단 크고 pre다음이 널이라면
			p->link = pre->link;
			pre->link = p;
			break;
		}
		else if (strcmp(p->name, pre->name) > 0 && strcmp(p->name, pre->link->name) < 0) {	//pre보단 크고 pre의 다음값보단 작으면
			p->link = pre->link;
			pre->link = p;
			break;
		}
		else if(strcmp(p->name,pre->name)>0 && pre->link!=NULL){	//pre보다 크고 다음값이 널이 아니면
			pre = pre->link;
			continue;
		}

	}
	return head;
}
void display(LISTNODE* head) {
	int num = 1;

	for (LISTNODE* p = head; p != NULL; p = p->link) {
		printf("%d번째 영화제목: %s	", num, p->name);
		printf("%d번째 영화 장르: %c	", num, p->genre);
		printf("%d번째 영화 개봉년도: %d", num, p->year);
		printf("\n");
		num++;
	}
}

int get_length(LISTNODE* head) {
	int length = 0;
	for (LISTNODE* p = head; p != NULL; p = p->link) {
		length++;
	}
	printf("들어있는 노드의 개수는 %d\n", length);
	return length;
}


void find_movie(LISTNODE* p) {
	char find[100];
	int f = 1;
	printf("찾을 영화 제목을 입력하세요.\n");
	scanf("%s", find);
	while (1) {
		if (!strcmp(find, p->name)) {	//찾았다면
			printf("%s는 %d번째 노드에 있습니다.", p->name, f);
			break;
		}
		else {					 //못찾았다면
			p = p->link;
			f++;
		}
	}
	return;
}



int main() {

	LISTNODE* head = (LISTNODE*)malloc(sizeof(LISTNODE*));
	LISTNODE* pre;
	head = pre = NULL;
	char main_name[100];
	char main_genre;
	int main_year = 0;
	//---한 번은 무조건 실행
	printf("q를 누르면 종료합니다.\n");
	printf("영화 제목을 입력하세요\n");
	scanf("%s", main_name);
	if (!strcmp(main_name, "q")) {
		display(head);
		get_length(head);
		find_movie(head);
	}
	first:
	printf("장르를 입력하세요. 장르는 A, C, F, R만 입력 받습니다.\n");
	scanf(" %c", &main_genre);
	if (main_genre != 'A' && main_genre != 'C' && main_genre != 'F' && main_genre != 'R') {
		printf("장르가 잘못 되었습니다. 다시 입력해주세요.\n");
		goto first;

	}
	printf("개봉년도를 입력하세요.\n");
	scanf("%d", &main_year);
	head = insert_first(head, main_name, main_genre, main_year);
	pre = head;
	while (1) {
		int list_length = get_length(head);
		printf("q를 누르면 종료합니다.\n");
		printf("영화 제목을 입력하세요\n");
		scanf("%s", main_name);
		if (!strcmp(main_name, "q")) break;
		second:
		printf("장르를 입력하세요. 장르는 A, C, F, R만 입력 받습니다.\n");
		scanf(" %c", &main_genre);

		if (main_genre != 'A' && main_genre != 'C' && main_genre != 'F' && main_genre != 'R') {
			printf("장르가 잘못 되었습니다. 다시 입력해주세요.");
			goto second;
		}
		printf("개봉년도를 입력하세요.\n");
		scanf("%d", &main_year);
		pre = head;
		if (strcmp(main_name, head->name) < 0) {	//헤드보다 작다면 헤드로 값 이동
			head = insert_first(head, main_name, main_genre, main_year);
			pre = head;

		}
		else if (strcmp(main_name, pre->name) > 0) {	//헤드,프리보다 크다면
			insert(head, pre, main_name, main_genre, main_year);

		}
		

	}

	display(head);
	get_length(head);
	find_movie(head);
}
