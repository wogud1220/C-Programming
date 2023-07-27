#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//#pragma warning(disable:4996)



typedef struct listnode {
	char name[100];
	char genre;
	int year;
	struct listnode* link;
}LISTNODE;

//--- 헤드를 바꾸는 insert 함수
LISTNODE* insert_first(LISTNODE* head, char main_name[], char main_genre, int main_year) {
	LISTNODE* p = (LISTNODE*)malloc(sizeof(LISTNODE));
	strcpy(p->name, main_name);
	p->genre = main_genre;
	p->year = main_year;
	p->link = head;		//avengers
	head = p;
	return head;
}
//--- 중간, 마지막에 집어넣는 insert 함수
LISTNODE* insert(LISTNODE* head, LISTNODE* pre, char main_name[], char main_genre, int main_year) {
	LISTNODE* p = (LISTNODE*)malloc(sizeof(LISTNODE*));
	int j = 0;
	strcpy(p->name, main_name);
	p->genre = main_genre;
	p->year = main_year;


	//---몇 번에 들어가야하는지 반복 함수 추가
	while (1) {	//--- 새로운 연결리스트 p가 어디에 들어가야하는 지 확인하는 반복문
		if (strcmp(p->name, pre->name) > 0 && pre->link == NULL) {	//pre보단 크고 pre다음이 널이라면 , 맨 마지막 값일 때
			p->link = pre->link;			//harrypotter의 다음이 널이니->notebook
			pre->link = p;
			break;
		}
		else if (strcmp(p->name, pre->name) > 0 && strcmp(p->name, pre->link->name) < 0) {	//pre보단 크고 pre의 다음값보단 작으면 , 중간값일때
			p->link = pre->link;
			pre->link = p;			//captain
			break;
		}
		else if (strcmp(p->name, pre->name) > 0 && pre->link != NULL) {	//pre보다 크고 다음값이 널이 아니면 , 더 뒤로 가야할 때
			pre = pre->link;			//aven harry notebook
			continue;
		}

	}
	return head;
}

LISTNODE* delete(LISTNODE* head, char delete_name[]) {
	LISTNODE* p = head;
	if (head == NULL) {		//연결리스트가 비어있으면
		printf("연결리스트가 비어있습니다.");
		return head;
	}
	if (!strcmp(delete_name, p->name)) { //첫 노드를 삭제
		head = head->link;
		free(p);
		return head;
	}
	LISTNODE* temp;
	for (p = head; p != NULL; p = p->link) {

		if (!strcmp(delete_name, p->link->name)) {	//a위치에서 b를 보고
			if (p->link->link == NULL) {
				free(p->link);	//맨 뒤에 거 삭제할 때
				return head;
			}
			else {
				temp = p->link;
				p->link = p->link->link;	//a랑 c연결하고
				free(temp);
			}			//b 해제
			return head;
		}
	}

	return head;
}



//--- 출력 함수
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

//--- 노드의 길이 반환 함수
int get_length(LISTNODE* head) {
	int length = 0;
	for (LISTNODE* p = head; p != NULL; p = p->link) {
		length++;
	}
	printf("들어있는 노드의 개수는 %d\n", length);
	return length;
}



//--- 영화를 찾는 함수
void find_movie(LISTNODE* head) {
	LISTNODE* p = head;
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

LISTNODE* find_latest(LISTNODE* head) {		//최근에 개봉된 영화 출력 함수
	LISTNODE* p;
	LISTNODE* bigg;
	int year = 0;

	/*int big = 0;

	for ( p = head; p != NULL; p = p->link) {
		big=MAX(year, p->year);		//가장 년도가 큰 값 찾기
	}

	for (p = head; p != NULL; p = p->link) {
		if (p->year == big) return p;	//년도가 가장 큰 노드 찾아서반환
	}*/

	bigg = p = head;
	for (p = head; p->link != NULL; p = p->link) {
		if (p->year > p->link->year) {
			bigg = p;
		}
		else
			bigg = p->link;
	}
	return bigg;

}

void find_genre(LISTNODE* head, char find_genre) {	//원하는 장르 찾는 함수

	for (LISTNODE* p = head; p != NULL; p = p->link) {
		if (find_genre == p->genre) {
			printf("제목: %s	", p->name);
			printf("장르: %c\n", p->genre);
		}
	}
	printf("\n\n\n");
	return;

}


int hap(LISTNODE* head) {
	if (head != NULL) {
		return head->year + hap(head->link);
	}
	else 
		return 0;
}

int  num = 0;	//노드의 개수를 전역 변수로 설정
void get_length_recur(LISTNODE* head) {
	if ((head->link) == NULL) {
		num = num + 1;
		printf("총 노드의 개수는: %d\n", num);
		//return num 해주던가
	}
	else {
		num = num + 1;
		get_length_recur(head->link);

	}

}

int get_length(LISTNODE *head){
	int length=0;
	if(head!=NULL){
		length=1+get_length(head->link);
	}
	return length;
}



void print_recursive(LISTNODE* head) {

	if ((head->link) == NULL) {
		printf("마지막 영화의 제목: %s\n", head->name);
	}
	else {
		printf("제목: %s\n", head->name);
		print_recursive(head->link);

	}

}

void print_reverse(LISTNODE* head) {	//역순으로 출력하는 함수

	if ((head->link) != NULL) {
		print_reverse(head->link);

		printf("제목: %s\n", head->name);
		//free(head);
	}
	else { // 마지막 영화면
		printf("제목: %s\n", head->name);
		//free(head);
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
	char delete_name[100];
	//---한 번은 무조건 실행
	printf("q를 누르면 종료합니다.\n");
	printf("영화 제목을 입력하세요\n");
	scanf("%s", main_name);
	if (!strcmp(main_name, "q")) {
		display(head);
		get_length(head);
		find_movie(head);
	}

first:		//--- 장르를 잘못입력하면 다시 돌아옴
	printf("장르를 입력하세요. 장르는 A, C, F, R만 입력 받습니다.\n");
	scanf(" %c", &main_genre);
	if (main_genre != 'A' && main_genre != 'C' && main_genre != 'F' && main_genre != 'R') {		//--- 장르를 잘못입력하면 다시 돌아옴
		printf("장르가 잘못 되었습니다. 다시 입력해주세요.\n");
		goto first;

	}
	printf("개봉년도를 입력하세요.\n");
	scanf("%d", &main_year);
	head = insert_first(head, main_name, main_genre, main_year);	//첫번째 값은 무조건 헤드에 저장
	pre = head;
	while (1) {
		int list_length = get_length(head);		//노드의 개수 실시간 반환
		printf("q를 누르면 종료합니다.\n");
		printf("영화 제목을 입력하세요\n");
		scanf("%s", main_name);
		if (!strcmp(main_name, "q")) break;
	second:
		printf("장르를 입력하세요. 장르는 A, C, F, R만 입력 받습니다.\n");
		scanf(" %c", &main_genre);

		if (main_genre != 'A' && main_genre != 'C' && main_genre != 'F' && main_genre != 'R') {	//--- 장르를 잘못입력하면 다시 돌아옴
			printf("장르가 잘못 되었습니다. 다시 입력해주세요.");
			goto second;
		}
		printf("개봉년도를 입력하세요.\n");
		scanf("%d", &main_year);
		pre = head;

		if (strcmp(main_name, head->name) < 0) {	//헤드보다 작다면 헤드로 값 이동
			head = insert_first(head, main_name, main_genre, main_year);	//---들어온 값을 헤드로 바꿔줌
			pre = head;

		}
		else if (strcmp(main_name, pre->name) > 0) {	//헤드,프리보다 크다면
			insert(head, pre, main_name, main_genre, main_year);		//중간인지, 끝인지 확인하는 함수로 보냄

		}

	}

	printf("삭제할 영화를 입력하세요.\n");
	scanf("%s", delete_name);
	head = delete(head, delete_name);

	LISTNODE* late = find_latest(head);		//가장 최신 영화의 노드를 받아옴
	printf("==============================\n");
	printf("가장 최근에 개봉된 영화는\n");
	printf("제목: %s\n", late->name);
	printf("장르: %c\n", late->genre);
	printf("개봉년도: %d\n", late->year);

	char find_genre1;
	printf("==============================\n");		//찾고 싶은 장르의 영화를 모두 출력
	printf("찾을 장르를 입력하세요.\n");
	scanf(" %c", &find_genre1);
	find_genre(head, find_genre1);





	printf("================================\n들어있는 모든 영화는\n");
	printf("recursive로 출력된 결과는 \n");
	print_recursive(head);	//재귀로 출력하는 함수
	printf("=========================\n");
	printf("역순으로 출력된 결과는\n");
	print_reverse(head);	//역순으로 출력하는 함수
	printf("재귀로 노드의 개수를 호출한 결과:	");
	get_length_recur(head);	//재귀로 노드의 개수를 호출
	printf("년도의 합은 %d", hap(head));

	//display(head); 반복문으로 노드의 내용 차례대로 출력하는 함수

	//get_length(head);	//반복문으로 노드의 개수를 반환
	find_movie(head);
}
