
#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a)>(b))?(a):(b))
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 10
#define MAX_QUEUE_SIZE 100

int m = 1;		//남자의 수
int w = 1;		//여자의 수 
// ===== 원형큐 코드 시작 ======

typedef int element;

typedef struct { // 큐 타입

	element  data[MAX_QUEUE_SIZE];

	int  front, rear;

} QueueType;


// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 초기화 함수
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}


// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}


// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형큐 출력 함수
void queue_print(QueueType* q, QueueType* woman, int num)	//남녀의 큐, 짝홀 받아옴
{

	if (num == 0) {	//남자라면

		if (!is_empty(q) && !is_empty(woman)) {//양쪽의 큐가 비어있지 않고 

			if (q->front == woman->front) {	//큐의 첫 front부분이 같다면
				printf("남자%d 입장 - ", m);
				printf("여자 %d / 남자 %d 매칭\n", woman->front+1, q->front+1);//여자의 첫번째와 남자의 첫번째를 이어줌
				dequeue(q);	//맨 아래에 있는 값 서로 매칭시켰으니 내보냄
				dequeue(woman);
			}
		}
		else
			printf("남자%d 입장 - 대기\n", m);	//한쪽의 큐가 비어있으면 매칭할수없으니 대기
	}
	else if (num == 1) {	//여자라면
		if (!is_empty(q) && !is_empty(woman)) {

			if (q->front == woman->front) {
				printf("여자%d 입장 - ", w);
				printf("여자 %d / 남자 %d 매칭\n", woman->front + 1, q->front + 1);
				dequeue(q);
				dequeue(woman);
			}
		}
		else
			printf("여자%d 입장 - 대기\n", w);
	}




	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);

			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");

}



// 삽입 함수


void enqueue(QueueType* q, element item)

{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;

}



// 삭제 함수

element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");

	q->front = (q->front + 1) % MAX_QUEUE_SIZE;

	return q->data[q->front];

}


element peek(QueueType* q)

{

	if (is_empty(q))

		error("큐가 공백상태입니다");

	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];

}

// ===== 원형큐 코드 끝 ======



int main() {

	QueueType man;	//남자와 여자의 두개의 원형 큐 생성
	QueueType woman;
	init_queue(&man);
	init_queue(&woman);
	srand(time(NULL));

	for (int i = 0; i < 100; i++) {

		int random = rand();
		if (random % 2 == 1) {	//홀수니깐 여자라면
			enqueue(&woman, w);	//여자의 큐에 여자의 인원 추가함
			queue_print(&man, &woman, random % 2);	//남녀의 큐 모두 전해주고 짝,홀수 전달
			w++;
		}
		else {	//짝수라면 남자라면
			enqueue(&man, m);
			queue_print(&man, &woman, random % 2);
			m++;
		}

	}


}






//=================은행 창구 문제===============

/*
#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a)>(b))?(a):(b))
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 10
#define MAX_QUEUE_SIZE 100


// ===== 원형큐 코드 시작 ======
	typedef struct { // 요소 타입

		int id;

		int arrival_time;

		int service_time;

	} element; // 교체!

	typedef struct { // 큐 타입

		element  data[MAX_QUEUE_SIZE];

		int  front, rear;

	} QueueType;



	// 오류 함수

	void error(char* message)

	{

		fprintf(stderr, "%s\n", message);

		exit(1);

	}

	//초기화

	void init_queue(QueueType * q)

	{

		q->front = q->rear = 0;

	}



	// 공백 상태 검출 함수

	int is_empty(QueueType * q)

	{

		return (q->front == q->rear);


	}



	// 포화 상태 검출 함수

	int is_full(QueueType * q)

	{

		return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);

	}



	// 원형큐 출력 함수

	void queue_print(QueueType * q)

	{

		printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);

		if (!is_empty(q)) {

			int i = q->front;

			do {

				i = (i + 1) % (MAX_QUEUE_SIZE);

				printf("%d | ", q->data[i]);

				if (i == q->rear)

					break;

			} while (i != q->front);

		}

		printf("\n");

	}



	// 삽입 함수

	void enqueue(QueueType * q, element item)
	{
		if (is_full(q))
			error("큐가 포화상태입니다");
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
	}

	//삭제 함수
	element dequeue(QueueType * q)
	{
		if (is_empty(q))
		{
			error("공백상태입니다.\n");
		}
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
	}

	element peek(QueueType * q)
	{

		if (is_empty(q))

			error("큐가 공백상태입니다");

		return q->data[(q->front + 1) % MAX_QUEUE_SIZE];

	}

	// ===== 원형큐 코드 끝 ======



	int main(void)

	{

		int minutes = 60;		//1시간동안

		int total_wait = 0;

		int total_customers = 0;

		int service_time = 0;
		int b_service_time = 0;

		int service_customer;
		int b_service_customer;

		QueueType queue;

		init_queue(&queue); srand(time(NULL));

		for (int clock = 0; clock < minutes; clock++) {

			printf("현재시각=%d\n", clock);


			if ((rand() % 10) < 3) {

				element customer;

				customer.id = total_customers++;	//고객의 수

				customer.arrival_time = clock;	//고객의 도착 시간

				customer.service_time = rand() % 3 + 1;		//고객의 업무처리시간

				enqueue(&queue, customer);//큐에 고객의 멤버 전달 (id,arrival,service_time)

				printf("고객 %d이 %d분에 들어옵니다. 업무처리시간= %d분\n",

					customer.id, customer.arrival_time, customer.service_time);

			}

			if (service_time > 0) {		//A창구에서 뭔가 진행중이라면

				printf("A창구에서 고객 %d 업무처리중입니다. \n", service_customer);	//누가 진행중인지 표시

				service_time--;	//시간 단축

			}
			
			else if (!is_empty(&queue)) {	//새로운 고객이 있다면

				element customer = dequeue(&queue);

				service_customer = customer.id;	//고객 번호

				service_time = customer.service_time;	//고객의 업무처리시간 전달

				printf("A창구에서 고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n",
					
					customer.id, clock, clock - customer.arrival_time);

				total_wait += clock - customer.arrival_time;



			}
			if (b_service_time > 0) {	//B창구에서 업무가 진행중이라면
				printf("B창구에서 고객 %d 업무처리중입니다. \n", b_service_customer);
				b_service_time--;	//clock이 올라갔으니
			}
			else if (!is_empty(&queue)) {
				element customer = dequeue(&queue);

				b_service_customer = customer.id;

				b_service_time = customer.service_time;

				printf("B창구에서 고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n",

					customer.id, clock, clock - customer.arrival_time);

				total_wait += clock - customer.arrival_time;
			}
		}

		printf("전체 대기 시간=%d분 \n", total_wait);

		return 0;

	}
	*/








	//===========================미로 문제==========================

/*
	#define _CRT_SECURE_NO_WARNINGS
	#define MAX(a,b) (((a)>(b))?(a):(b))
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <math.h>
	#define MAX_STACK_SIZE 100
	#define MAZE_SIZE 10




	typedef struct { // 교체!
		short r;
		short c;
	} element;

	typedef struct {
		element data[MAX_STACK_SIZE];
		int top;
	} StackType;

	// 스택 초기화 함수
	void init_stack(StackType* s)
	{
		s->top = -1;
	}

	// 공백 상태 검출 함수
	int is_empty(StackType* s)
	{
		return (s->top == -1);
	}

	// 포화 상태 검출 함수
	int is_full(StackType* s)
	{
		return (s->top == (MAX_STACK_SIZE - 1));
	}

	// 삽입함수
	void push(StackType* s, element item)

	{
		if (is_full(s)) {
			fprintf(stderr, "스택 포화 에러\n");
			return;
		}
		else s->data[++(s->top)] = item;
	}

	// 삭제함수
	element pop(StackType* s)
	{
		if (is_empty(s)) {
			fprintf(stderr, "스택 공백 에러\n");
			exit(1);
		}
		else return s->data[(s->top)--];
	}

	// 피크함수
	element peek(StackType* s)

	{
		if (is_empty(s)) {
			fprintf(stderr, "스택 공백 에러\n");
			exit(1);
		}
		else return s->data[s->top];
	}

	// ===== 스택 코드의 끝 =====

	element here = { 1,0 }, entry = { 1,0 };	//미로 출발 위치

	char maze[MAZE_SIZE][MAZE_SIZE] = {		//미로 생성

	{ '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},

	{ 'e', '0', '0', '0', '1', '1', '1', '1', '1', '1'},

	{ '1', '1', '0', '1', '1', '1', '1', '1', '1', '1' },

	{ '1', '1', '0', '0', '1', '1', '1', '1', '1', '1' },

	{ '1', '1', '1', '0', '0', '0', '0', '0', '0', '1' },

	{ '1', '1', '1', '1', '1', '1', '1', '1', '0', '1' },

	{ '1', '1', '1', '1', '1', '1', '1', '1', '0', '1'},

	{ '1', '1', '1', '1', '1', '1', '1', '0', '0', '1'},

	{ '1', '1', '1', '1', '1', '1', '1', '0', '1', '1'},

	{ '1', '1', '1', '1', '1', '1', '1', '0', '0', 'x'},


	};

	// 위치를 스택에 삽입
	void push_loc(StackType* s, int row, int col,int num)		//1,3 전달받음
	{
		element up;
		
			if (num == 1) {
				
				up.r = row +1;		//지나온길 저장함
				up.c = col-1;
				printf("지나온 길:[%d %d]\n", up.r, up.c);		
	

		}
		if (row >= 10 || row < 0 || col < 0 || col >= 10) return;		//바깥으로 벗어날때 배제
		if (maze[row][col] != '1' && maze[row][col] != '.') {		// 0이라면
			element tmp;	
			tmp.r = row;		
			tmp.c = col;		
			push(s, tmp);	
			
				printf("갈 수 있는 모든 미로 경로 : [% d, % d] \n", tmp.r, tmp.c);			//갈수있는곳 모두 표기
				return;
		}

	}

	// 미로를 화면에 출력한다.

	void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])

	{
		int c = 0;
		int r = 0;
		printf("\n");
		
		for (int r = 0; r < MAZE_SIZE; r++) {
			
			for ( c = 0; c < MAZE_SIZE; c++) {

				printf("%c", maze[r][c]);
			}
			printf("\n");
			
		}
		
	}


	int main(void)

	{
		
		StackType s;
		
		init_stack(&s);
		int r, c;
		int up, down, left, right;
		here = entry;			//{1,0}으로 같음ㄹ
		while (maze[here.r][here.c] != 'x') {	//출구가 아닐동안
			r = here.r;		//인덱스 주소 입력		먼저 1,0 들어옴
			c = here.c;
			maze[r][c] = '.';	//온 길 .으로 입력
			maze_print(maze);	//.으로 찍고 미로 출력
			
				
					push_loc(&s, r - 1, c,1);
					
					//한 칸 위로
				
					push_loc(&s, r + 1, c,2);
					
				//한 칸 아래
				
					push_loc(&s, r, c - 1,3);
					
				//한 칸 왼쪽
				
					push_loc(&s, r, c + 1,4);
					
				//한 칸 오른쪽 갔는데 길이 없음
			

			if (is_empty(&s)) {
				printf("실패\n");
				return;
			}
			else {
				here = pop(&s);	//푸시한 주소 뽑아내서 현재 주소에 저장
				printf("갈 경로: [%d  %d]\n", here.r,here.c);

			}
		}
		printf("성공\n");

		return 0;

	}*/