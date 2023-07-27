#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
//#pragma warning(disable:4996)

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;


typedef struct t1 {
	struct TreeNode;
}T1;
typedef struct t2 {
	struct TreeNode;
}T2;
typedef struct t3 {
	struct TreeNode;
}T3;



//====트리 높이 구하는 함수
int get_height(TreeNode* node) {
	int height = 0;
	if (node != NULL)
		height = 1 + MAX(get_height(node->left), get_height(node->right));
	return height;
}


	//최대값을 찾고 그 노드를 찾기 위해서
//======최대값 구하기
int find_max(T1* t1_root) {
	//T1*m1 = t1_root->data;
	if (t1_root != NULL) {
		int a = t1_root->data;
		a = MAX(a, find_max(t1_root->left));
		a = MAX(a, find_max(t1_root->right));
		return a;
	}
	
}
T1* find_max_ptr(T1* t1_root, int a) {
	if(t1_root!=NULL){
		if (t1_root->data == a)
			return t1_root;
			find_max_ptr(t1_root->left, a);
			find_max_ptr(t1_root->right, a);
			return t1_root;
	}
}
	

void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("[%d]", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("[%d]", root->data);
		inorder(root->right);
	}
}



void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("[%d]", root->data);

	}
}

void order_plus(TreeNode* root) {

	if (root != NULL) {
		root->data++;
		//printf("[%d]", root->data);
		order_plus(root->left);
		order_plus(root->right);
	}
	return;
}





void balance_check(TreeNode* root) {


	int left_height = 1+get_height(root->left);	//왼쪽서브트리의 높이 구하기
	int right_height = 1+get_height(root->right);	//오른쪽 서브트리읜 높이 구하기

	if (abs(left_height - right_height) >1) {	// 차이가 2이상이면, 왼 2 오 4== -2
		printf("Balanced Tree가 아닙니다.\n");
	}
	else
		printf("Balanced Tree입니다.\n");	//차이가 1이거나 같다면


	printf("트리의 높이는: %d\n", get_height(root));
	printf("왼:%d\n", left_height);
	printf("오:%d\n\n", right_height);
	return;

}



int same_tree(T1* t1_root, T2* t2_root) {


	//printf("ff%d", (!t1_root&& !t2_root)); // 0
	return ((!t1_root && !t2_root) || //둘 다 데이터가 없으면 true

		(t1_root && t2_root && (t1_root->data == t2_root->data) && 
		//노드의 데이터가 있고 데이터가 같고
		same_tree(t1_root->left, t2_root->left) &&	
		// t1의 왼쪽과 t2의 왼쪽을 재귀로 불러서 실행
		same_tree(t1_root->right, t2_root->right)));
		//왼쪽 끝까지 가면 위로 올라오면서 오른쪽으로 이동하고
		//루트노드를 만나면 오른쪽 서브트리로 이동해서 
}


T1* copy_tree(T1* t1_root) {

	if (t1_root) {
		T2* t2_root = (T2*)malloc(sizeof(T2));
		t2_root->left = copy_tree(t1_root->left);
		//왼쪽으로 가서 공간 생성하고 t1의 왼쪽이 t2의 왼쪽이 되게함
		t2_root->right = copy_tree(t1_root->right);
		//왼쪽으로 가서 공간 생성하고 t1의 오른쪽이 t2의 오른쪽이 되게함
		t2_root->data = t1_root->data;

		return t2_root;
	}

	return NULL;	
}




void main() {
	T1 n10 = { 2,NULL,NULL };
	T1 n9 = { 80,NULL,NULL };
	T1 n8 = { 9,&n9,&n10 };
	T1 n7 = { 4,NULL,NULL };
	T1 n6 = { 7,&n7,&n8 };
	T1 n5 = { 5,NULL,NULL };
	T1 n4 = { 1,NULL,NULL };
	T1 n3 = { 3,&n4,NULL };
	T1 n2 = { 15,&n3,&n5 };
	T1 n1 = { 17,&n2,&n6 };
	T1* t1_root = &n1;
	T2* t2_root;




	T3 t13 = { 100,NULL,NULL };
	T3 t12 = { 90,NULL,NULL };
	T3 t11 = { 9,&t13,NULL };
	T3 t10 = { 6,NULL,NULL };
	T3 t9 = { 70,NULL,NULL };
	T3 t8 = { 7,&t11,&t12 };
	T3 t7 = { 4,NULL,&n10 };
	T3 t6 = { 20,NULL,NULL };
	T3 t5 = { 30,NULL,NULL };
	T3 t4 = { 5,&t8,&t9 };
	T3 t3 = { 2,&t6,&t7 };
	T3 t2 = { 3,&t4,&t5 };
	T3 t1 = { 1,&t2,&t3 };
	T3* t3_root = &t1;





	int num = 0;
	printf("1: 트리의 전위, 중위, 후위 출력\n\
2: 모든 노드들의 데이터 값 ++\n3: 최대값을 갖는 포인터 반환\n\
4: 균형트리 체크\n5: 이진트리 복사하는 함수\n\
6: 두 개의 트리가 동일한지 체크\n\n-1입력시 종료\n");

	while (num != -1) {
		scanf("%d", &num);
		switch (num)
		{
		case 1:printf("전위 순회 = ");
			preorder(t1_root);
			printf("\n\n");
			printf("중위 순회 = ");
			inorder(t1_root);
			printf("\n\n");
			printf("후위 순회 ");
			postorder(t1_root);
			printf("\n\n");
			break;
		case 2:printf("1을 더한 전위 순회 = ");
			order_plus(t1_root);
			preorder(t1_root);
			printf("\n\n");
			printf("1을 더한 중위 순회 = ");
			//order_plus(t1_root);
			inorder(t1_root);
			printf("\n\n");
			printf("1을 더한 후위 순회 = ");
			//order_plus(t1_root);
			postorder(t1_root);
			printf("\n\n");
			break;
		case 3:
			printf("가장 큰 노드의 위치(값)\n");
			int c= find_max(t1_root);
			printf("가장 큰 노드의 값은: %d", c);



			//printf("가장 값이 큰 노드의 포인터 받아오기");
			//T1*p1=find_max_ptr(t1_root, c);
			//printf("포인터의 값: %d", p1->data);
			break;
		case 4:
			printf("\n==========balance Check=========\n");
			balance_check(t1_root);
			balance_check(t3_root);
			break;
		case 5:
			printf("\n==========copy tree 실행=========\n\n");
			T2* t2_root = copy_tree(t1_root);
			printf("T2 트리의 전위순회 =  ");
			preorder(t2_root);	//void 반환
			puts("");
			break;
		case 6:
			printf("같은 트리인가?\n");
			int a = same_tree(t1_root, t2_root);
			if (a == 1)printf("\nTRUE T1과 T2는 같습니다.");
			else printf("\nFALSE 두 트리는 같지 않습니다.");
			int b = same_tree(t1_root, t3_root);
			if (b == 1)printf("\nTRUE T1과 T3 트리는 같습니다.");
			else printf("\nFALSE T1과 T3 트리는 같지 않습니다.");
			break;
		default:
			break;
		}
	}//while

	printf("\nt1 트리의 높이는 = %d\n", get_height(t1_root));


	free(t2_root);
	return;
}