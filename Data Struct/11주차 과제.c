#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
//#pragma warning(disable:4996)

//============	노드의 구조체
typedef struct DListNode {	
	int data;	//재생시간
	char name[100];//영화 제목
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;


//==========	초기화 함수
DListNode *init(DListNode* phead) {
	phead->llink = phead;	//자기 자신을 가르키도록
	phead->rlink = phead;
	return phead;
}

//===========	모든 노드 출력하는 함수
void print_dlist(DListNode* phead) {	//realhead 받아옴
	DListNode* p = phead;
	while(1) {
		printf("영화제목: %s	", p->name);
		printf("런타임: %d\n", p->data);
		p=p->rlink;
		if (p == phead)break;	//한바퀴 돌아서 다시 오면 종료
	}
	printf("\n");
}


//==============	특정 노드를 찾는 함수
DListNode* dsearch(DListNode* head,char movieName[]) {
	DListNode* p = head;
	int i = 1;
	
	while (1) {
		if (!strcmp(p->name, movieName)) {	//이름과 같으면 몇번째 노드인지 출력 후
			printf("%s는 %d번째 노드에 있습니다.\n", movieName, i);
			return p;	//그 노드를 현재 노드로 반환
		}
		else {		//아니라면 다음노드로 이동해서 비교 
			p = p->rlink;
			i++;
		}
	}
}

//======노드의 헤드를 생성할때 처음 1번만 사용하는 함수
DListNode* first_insert(DListNode* head, char movieName[], int data) {

	strcpy(head->name, movieName);
	head->data = data;
	return head;
}


//==========삽입 함수, 오름차순X 넣은 순서대로O
DListNode* dinsert(DListNode* head, char movieName[], int data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	DListNode* tail = head;
	while (1) {
		if (tail->rlink == head) break;	//tail이 끝 찾아가기
		else tail = tail->rlink;
	}
	strcpy(newnode->name, movieName);
	newnode->data = data;

	newnode->llink = tail;//새로운 노드의 llink와 tail의  rlink를 이어서 이중으로 연결
	newnode->rlink = head;//새로운 노드와 기존의 head를 연결하여 원형 연결
	head->llink = newnode;
	tail->rlink = newnode;

	return head;

}


//==============삭제 함수
DListNode * ddelete(DListNode* head, char movieName[]) {
	if (!strcmp(movieName, head->name) && head->rlink == head) {	//하나밖에 없을 때
		free(head);
		return;
	}
	DListNode *p = head;
	while (1) {
		if (!strcmp(head->name, movieName)) {	//헤드를 삭제할 때
			DListNode* temp = head;		//head의 복사본 생성
			head->llink->rlink = head->rlink;	//head가 가지고 있던 주소 옮겨줌
			head->rlink->llink = head->llink;
			printf("%s가 삭제되었습니다.", head->name);
			head = head->rlink;		//head를 다음 칸으로 옮겨줌
			free(temp);//복사본 free
			break;
		}

		else if (!strcmp(movieName, p->name)) {	//헤드가 아닌 뒤에 것들을 삭제할 때
			p->llink->rlink = p->rlink;		//똑같이 삭제하려는 노드가 가지고있는 주소들 이동시킴
			p->rlink->llink = p->llink;
			printf("%s가 삭제되었습니다.\n", p->name);
			free(p);
			break;
		}//if문
		else
			p = p->rlink;	//못찾았다면 다음 노드로 이동
	}
	return head;	//처음 노드 리턴함
}


//========	입력한 제목부터 한바퀴 재생하는 함수

DListNode* play(DListNode* head, char movieName[]) {
	DListNode* p = head;
	DListNode* start_point;		//시작하는 지점 지정
	int storedata = 0;		//런타임이 줄어들면 다음 실행시 0으로 되어서 복구하기위한 변수
	int i = 0;

	while (1) {
		if (!strcmp(p->name, movieName)) {		//재생할 제목을 찾으면
			storedata = p->data;		//런타임 기록
		storeskip:						//런타임 중복 기록을 막기위해서 
			start_point = p;			//시작하는 노드 기록
			printf("재생 중인 영화: %s	남은시간: %d ...\n", p->name, p->data);
			p->data--;
			Sleep(1000);			//1초씩 줄어듦
			if (p->data ==  -1) {	//런타임 끝나면 while문 탈출
				p->data = storedata;//런타임 복구, 안하면 다음 재생때 0으로 되어서 재생이 안됨
				p = p->rlink;
				break;
			}//p->data if문
		}//strcmp if문
		else {
			printf("다음 노드로 이동합니다.\n");
			p = p->rlink;
			continue;
		}
		goto storeskip;//런타임 중복 기록을 막기위해서 
	}//while문 break 이후

	//rlink로 한칸 오른쪽옴
	// 
	// 
	//두번째 노드부터~ 한바퀴 돌 때까지
	while (1) {
		storedata = p->data;
	storeskip2:	
		printf("재생 중인 영화: %s	남은 시간:%d\n", p->name, p->data);
		p->data--;
		Sleep(1000);
		if (p->data==-1 && p->rlink == start_point) {	//start_point를만나면 == 한바퀴 다 돌면
			p->data = storedata;
			break;
		}
		else if (p->data == -1 || p->data==-2) {	//런타임이 -1이 된다면
			p->data = storedata;
			p = p->rlink;			//다음 노드로 이동하여 계속 재생함
			continue;
		}
		goto storeskip2;		//런타임 중복 기록을 막기 위해서
	}

	
	return start_point;		//시작 노드를 반환함
}


//=========	맨 앞의 영화 하나 재생
DListNode* playFirst(DListNode* realhead) {	
	int storedata = realhead->data;		////런타임 기록
	while (1) {
		printf("재생 중인 영화 처음 노드의 영화: %s		남은 시간:%d\n", realhead->name, realhead->data);
		realhead->data--;
		Sleep(1000);
		if (realhead->data == 0) {
			realhead->data = storedata;	//런타임 기록
			break;
		}
	}
	return realhead;		//맨앞의 노드를 반환하여 현재 위치로 저장

}


//=======	맨 뒤의 영화 하나 재생
DListNode* playLast(DListNode* tail) {	
	int storedata = tail->data; //런타임 기록
	while (1) {
		printf("재생 중인 마지막 노드의 영화: %s	남은 시간:%d\n", tail->name, tail->data);
		tail->data--;
		Sleep(1000);
		if (tail->data == 0) {		//런타임 0되면 탈출
			tail->data = storedata;
			break;
		}
	}//while문

	return tail;		//맨 뒤의 노드를 반환하여 현재 위치로 저장
}

//======현재 노드를 받아서 다음 노드를 재생하는 함수
DListNode* playNext(DListNode* head) {
	int storedata = head->rlink->data; //런타임 기록
	while (1) {
		printf("재생 중인 영화: %s	남은시간: %d ...\n", head->rlink->name, head->rlink->data);
		head->rlink->data--;
		Sleep(1000);
		if (head->rlink->data == 0) {
			head->rlink->data = storedata;
			return head->rlink;		//받아온 노드의 다음 노드를 리턴하여 현재위치로 저장함
		}
	}
	
}


//=========	현재 노드를 받아서 이전 노드를 재생하는 함수
DListNode* playBefore(DListNode* head) {
	int storedata = head->llink->data;	//런타임 기록
	while (1) {
		printf("재생 중인 영화: %s	남은시간: %d ...\n", head->llink->name, head->llink->data);
		head->llink->data--;
		Sleep(1000);
		if (head->llink->data == 0) {
			head->llink->data = storedata;
			return head->llink;		//받아온 노드의 이전 노드를 리턴하여 현재위치로 저장함
		}
	}
}



int main() {
	char movieName[100];	//영화제목
	int movieTime;
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	head=init(head);
	DListNode* realhead = head;
	int num = 0;
	int number = 0;
	while (1) {

		printf("하고 싶은 메뉴를 선택하세요.\n1. 삽입\n2. 삭제\n3. 검색\n4. 출력 \n5. 재생(P)\n6. 다음 노드로 이동하여 재생(>)\n\
7. 이전 노드로 이동하여 재생(<)\n8. 맨 앞의 영화로 이동하여 재생\n9. 맨 뒤의 영화로 이동하여 재생\n");
		scanf("%d", &num);
		number++;		
		if (num == 1) {
			if (number == 1) {	//처음 시작할때
				printf("영화 제목을 입력하세요.\n");
				scanf("%s", movieName);
				printf("영화 재생 시간을 입력하세요.\n");
				scanf("%d", &movieTime);
				realhead=first_insert(realhead, movieName, movieTime);
			}
			else {		//이후로 추가할때
				printf("영화 제목을 입력하세요.\n");
				scanf("%s", movieName);
				printf("영화 재생 시간을 입력하세요.\n");
				scanf("%d", &movieTime);
				realhead=dinsert(realhead, movieName, movieTime);
			}
		}
		else if (num == 2) {
			printf("삭제할 영화 제목을 입력하세요.\n");
			scanf("%s", movieName);
			realhead=ddelete(realhead, movieName);
		}
		else if (num == 3) {
			printf("찾을 영화 제목을 입력하세요.\n");
			scanf("%s", movieName);
			head=dsearch(realhead, movieName);
		}
		else if (num == 4) {
			printf("모든 리스트를 출력하겠습니다.\n");
			print_dlist(realhead);
		}
		else if (num == 5) {
			printf("시작할 영화 제목부터 입력해주세요.\n");
			scanf("%s", movieName);
			head = play(realhead, movieName);	//start_point 받아옴, 여기서 시작
		}
		else if (num == 6) {
			head = playNext(head);	//현재 가르키고 있는 노드주고 다음 칸 받아옴
		}
		else if (num == 7) {
			head = playBefore(head);	//현재 위치 주고 이전 칸 받아옴
		}
		else if (num == 8) {
			head = playFirst(realhead);	//처음 노드 리턴 받아고 현재위치를 처음으로 이동
		}
		else if (num== 9) {
			head = playLast(realhead->llink);	//마지막 노드 리턴 받고 마지막 노드를 현재위치로 바꿈
			
		}

		
	}//while문


}//main문