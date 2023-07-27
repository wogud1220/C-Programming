#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
//#pragma warning(disable:4996)

//1. 여러개 삽입
//2. 탐색을해본다
//3. 중위 순회로 오름차순 정렬해보기
//4. 노드 삭제 해보기		1. 단말		2. 노드 1개		 3. 노드 2개 일 때
//5. 높이 + 개수		넣은 순서에 따라 달라짐
//6. 

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
}TreeNode;

//========중위 순회, 오름차순으로 정렬하게됨
void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}


TreeNode* search_node(TreeNode* root, int key) {
	while (root != NULL) {
		if (key == root->key) {
			printf("[%d]는 높이가 %d 인 곳에 있습니다.", root->key, get_height(root));
			return root;
		}
		else if (key < root->key)
			root = root->left;
		else
			root = root->right;
	}
	printf("[%d]는 트리에 없습니다.\n", key);
	return NULL;	//탐색 실패시 null 반환
} `


TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}


TreeNode* insert_node(TreeNode* node, int key) {
	//트리 공백시 새 노드 입력 함수 불러옴
	if (node == NULL) return new_node(key);	//처음 입력시, 키 값이 없을시

	if (key < node->key)	//키 값을 작으면 왼쪽 노드를 주고 순환호출
		node->left = insert_node(node->left, key);
	else if (key > node->key)// 오른쪽 노드 순환호출
		node->right = insert_node(node->right, key);

	return node;	
}

//=======왼쪽 서브트리에서 제일 큰값을 갖는 노드 반환
TreeNode* max_value_node(TreeNode* node) {
	TreeNode* current = node;

	while (current->right != NULL)	//오른쪽 노드가 없을 때까지
		current = current->right;	//오른쪽으로 계속 이동
	return current;				// 자신의(current) 오른쪽 노드가 null이라면 current 노드 반환
}



TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL) return root;	//루트 노드가 비어있으면 
	
	if (key < root->key)		//삭제할 값이 루트보다 작으면
		root->left = delete_node(root->left, key);	//왼쪽으로 이동
	else if(key>root->key)		//삭제할 값이 루트보다 크면
		root->right = delete_node(root->right, key);	//오른쪽으로 이동

	else {	//루트가 키값을 만나면
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		TreeNode* temp = max_value_node(root->left);	//왼쪽 서브트리 줌

		root->key = temp->key;	//
		root->left = delete_node(root->left, temp->key);	//
	}
	return root;
}


int get_height(TreeNode* node) {
	int height = 0;
	if (node != NULL)
		height = 1 + MAX(get_height(node->left), get_height(node->right));
	return height;
}


void main() {
	TreeNode* root = NULL;
	TreeNode* current = root;
	int i = 0;
	int delete_num = 0;
	int main_key = 0;
	int num = 0;
	int find_key = 0;
	while (num!=-1) {
		printf("1. 삽입\n2. 중위순회하여 결과 확인\n3. 현재 높이 계산\n4. 특정 키값 탐색	\n5. 특정 노드 삭제\
	-1 입력 시 종료\n");
		scanf("%d", &num);
		switch (num)
		{case 1:
			printf("삽입할 key 값을 입력하세요\n");
			scanf("%d", &main_key);
			if (i == 0) {
				root = insert_node(root, main_key);	//처음에만 실행하여 루트노드 위치를 받아옴
				i++;
			}
			else
				root= insert_node(root, main_key);	
		break;

		case 2: 
			printf("현재의 이진탐색트리를 중위순회하여 결과 확인\n");
			inorder(root);
			puts("\n");
			break;

		case 3:
			printf("\n현재 트리의 높이는 [%d] 입니다\n", get_height(root));
			break;
		case 4:
			
			printf("찾을 키 값을 입력하세요.\n");
			scanf("%d", &find_key);
			current = search_node(root, find_key);//25
			break;
		case 5:
			printf("삭제할 key 값을 입력하세요.\n");
			scanf("%d", &delete_num);
			root=delete_node(root, delete_num);	//어차피 루트 반환함
			printf("[%d]를 삭제하였습니다.\n", delete_num);
			break;

		default:
			break;
		}
		
	}
	
	
	

}