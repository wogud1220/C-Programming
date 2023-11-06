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

typedef struct TreeNode
{
    int key;
    struct TreeNode *left, *right;
} TreeNode;

void inorder(TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("[%d]", root->key);
        inorder(root->right);
    }
}

TreeNode *new_node(int item)
{
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode *insert_node(TreeNode *node, int key)
{
    // 트리 공백시 새 노드 입력 함수 불러옴
    if (node == NULL)
        return new_node(key); // 처음 입력시, 키 값이 없을시

    if (key < node->key) // 키 값을 작으면 왼쪽 노드를 주고 순환호출
        node->left = insert_node(node->left, key);
    else if (key > node->key) // 오른쪽 노드 순환호출
        node->right = insert_node(node->right, key);

    return node;
}

TreeNode *search_node_recursive(TreeNode *root, int key)
{
    if (root != NULL)
    {
        if (root->key == key)
            return root;
        else if (root->key > key)
            root = search_node_recursive(root->left, key);
        else if (root->key < key)
            root = search_node_recursive(root->right, key);
    }
    if (root == NULL)
        return NULL;
    return root; // 찾은 곳 반환
}

TreeNode *search_node_iterative(TreeNode *root, int key)
{
    while (root != NULL)
    {
        if (key == root->key)
        {
            // printf("[%d] 찾음", key);
            return root;
        }
        else if (key < root->key)
            root = root->left;
        else
            root = root->right;
    }
    // printf("[%d]는 트리에 없습니다.\n", key);
    return NULL; // 탐색 실패시 null 반환
}

TreeNode *max_value_node(TreeNode *node)
{
    TreeNode *current = node;

    while (current->right != NULL) // 오른쪽 노드가 없을 때까지
        current = current->right;  // 오른쪽으로 계속 이동
    return current;                // 자신의(current) 오른쪽 노드가 null이라면 current 노드 반환
}
TreeNode *min_value_node(TreeNode *node)
{
    TreeNode *current = node;

    while (current->left != NULL) // 오른쪽 노드가 없을 때까지
        current = current->left;  // 오른쪽으로 계속 이동
    return current;               // 자신의(current) 오른쪽 노드가 null이라면 current 노드 반환
}

int main()
{
    TreeNode *root = NULL;
    TreeNode *cur = root;
    int num;
    int probNum = 0;
    int item = 0;
    printf("12개의 숫자 입력\n");
    while (num != 0)
    {
        scanf("%d", &num);
        if (num == 0)
            break;
        cur = search_node_iterative(root, num); // 먼저 탐색후 null이면 집어넣기
        if (cur == NULL)
        {
            root = insert_node(root, num);
        } // 탐색 실패시 삽입
        else
            printf("중복된 값이라서 삽입 안 함");
    }
    while (1)
    {
        printf("\n1: Search Recursive\n2: Search Iterative\n3: inorder\n4: FindMax\n5: FindMin\n");
        scanf("%d", &probNum);

        switch (probNum)
        {
        case 1:
            printf("찾을 값을 입력하세요\n");
            scanf("%d", &item);
            cur = search_node_recursive(root, item);
            if (cur == NULL)
                printf("[%d]를 찾지 못함.\n", item);
            else
                printf("[%d]를 찾았습니다.\n", cur->key);
            break;
        case 2:
            printf("찾을 값을 입력하세요\n");
            scanf("%d", &item);
            cur = search_node_iterative(root, item);
            if (cur == NULL)
                printf("[%d]를 찾지 못함.\n", item);
            else
                printf("[%d]를 찾았습니다.\n", cur->key);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            cur = max_value_node(root);
            printf("가장 큰 값은 [%d]입니다.\n", cur->key);
            break;
        case 5:
            cur = min_value_node(root);
            printf("가장 작은 값은 [%d]입니다.\n", cur->key);
            break;
        default:
            break;
        }
    }
    return 0;
}
