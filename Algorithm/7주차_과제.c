#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0
#define BUCKETS 10
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
#include <ctype.h>

typedef struct List
{
	int data;
	struct List *next;

} LIST;

LIST *new_node(struct List *node, int item)
{
	struct List *temp = (LIST *)malloc(sizeof(LIST));
	temp->data = item;
	temp->next = NULL;
	return temp;
}
typedef struct QUEUE
{
	int data[MAX_SIZE];
	int front, rear;
} QUEUE;
void initQueue(QUEUE *q)
{
	q->front = 0;
	q->rear = 0;
}

void enqueue(QUEUE *q, int item)
{
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->data[q->rear] = item;
}
int dequeue(QUEUE *q)
{
	q->front = (q->front + 1) % MAX_SIZE;
	return q->data[q->front];
}
int isEmpty(QUEUE *q)
{
	return (q->front == q->rear); // 같으면 빈거임
}
void radixSort(int arr[], int n)
{
	QUEUE QUEUE[BUCKETS];
	int i = 1;
	int factor = 1;
	for (int b = 0; b < BUCKETS; b++)
		initQueue(&QUEUE[b]);
	for (int d = 0; d < 4; d++)
	{
		for (i = 0; i < n; i++)
		{ ////버켓을 만들어서 나머지를 기준으로 1이면 1버켓에 넣어줌
			enqueue(&QUEUE[(arr[i] / factor) % 10], arr[i]);
		}
		for (int b = i = 0; b < BUCKETS; b++)
			while (!isEmpty(&QUEUE[b]))
				arr[i++] = dequeue(&QUEUE[b]); // 하나 꺼내고 배열에 하나씩 다시 저장
		factor *= 10;						   // 두번째 숫자부터는 100,1000, 이후 4번 반복하기
	}
}

int main()
{
	QUEUE queue;
	int arr3[10] = {1230, 724, 812, 1122, 120, 415, 1010, 410, 331, 808};

	int arr[4] = {5, 7, 24, 56};
	int arr2[5] = {19, 45, 61, 79, 82};
	LIST *head = (LIST *)malloc(sizeof(1));
	LIST *cur = head;
	LIST *pre = head;

	LIST *head2 = (LIST *)malloc(sizeof(1)); // 리스트 2의 포인터 생성
	LIST *cur2 = head2;
	LIST *pre2 = head2;
	int num = 0;
	printf("1: List\n2: RadixSort\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		for (int i = 0; i < 4; i++)
		{
			cur = new_node(head, arr[i]);
			pre->next = cur;
			pre = cur;
		} // 각각의 리스트에 배열에 있는 값 집어넣어서 리스트끼리 잇기
		for (int i = 0; i < 5; i++)
		{
			cur2 = new_node(head2, arr2[i]);
			pre2->next = cur2;
			pre2 = cur2;
		}
		head = head->next; // 포인터 위치 재조정
		cur = pre = head;
		head2 = head2->next;
		cur2 = pre2 = head2;

		while (cur != NULL && cur2 != NULL)
		{
			if (cur->data < cur2->data)
			{ // 2 리스트의 값이 더 크면
				pre = cur;
				cur = cur->next; // 1리스트 하나씩 증가해서
				continue;
			}
			pre->next = cur2; // 위 조건 만족 안 하면 전 단계의 포인터를 2리스트로 이어줌

			if (cur2->data < cur->data) // 1리스트 값이 더 크면
			{
				pre2 = cur2;
				cur2 = cur2->next;
			}
			pre2->next = cur; // 1로 이어줌
		}

		if (cur == NULL)
		{ // 1리스트가 끝에 도달하면
			pre->next = cur2;
		}
		if (cur2 == NULL) // 2리스트가 끝에 도달하면
		{
			pre2->next = cur;
		}

		for (int i = 0; i < 9; i++)
		{
			printf("%d ", head->data);
			head = head->next;
		}
		break;
	case 2:
		radixSort(arr3, 10);
		for (int i = 0; i < 10; i++)
			printf("%d ", arr3[i]);

	default:
		break;
	}

	return 0;
}