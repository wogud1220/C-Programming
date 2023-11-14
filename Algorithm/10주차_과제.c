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
TreeNode *insert_node_notTree(TreeNode *node, int key)
{
    if (node == NULL)
        return new_node(key); // 처음 입력시, 키 값이 없을시

    if (key > node->key) // 키 값을 작으면 왼쪽 노드를 주고 순환호출
        node->left = insert_node_notTree(node->left, key);
    else if (key < node->key) // 오른쪽 노드 순환호출
        node->right = insert_node_notTree(node->right, key);

    return node;
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
TreeNode *min_value_node(TreeNode *node)
{
    TreeNode *current = node;
    if (current == NULL)
        return NULL;
    while (current->left != NULL) // 오른쪽 노드가 없을 때까지
        current = current->left;  // 오른쪽으로 계속 이동
    return current;               // 자신의(current) 오른쪽 노드가 null이라면 current 노드 반환
}
TreeNode *min_value_node_recur(TreeNode *node)
{
    TreeNode *current = node;
    if (current == NULL)
        return NULL;
    if (current->left == NULL)
        return current;
    else
        return min_value_node_recur(current->left);
}
TreeNode *delete_node(TreeNode *root, int key)
{
    if (root == NULL)
        return root; // 루트 노드가 비어있으면

    if (key < root->key)                             // 삭제할 값이 루트보다 작으면
        root->left = delete_node(root->left, key);   // 왼쪽으로 이동
    else if (key > root->key)                        // 삭제할 값이 루트보다 크면
        root->right = delete_node(root->right, key); // 오른쪽으로 이동

    else
    { // 루트가 키값을 만나면
        if (root->left == NULL)
        {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        TreeNode *temp = min_value_node(root->right); // 왼쪽 서브트리 줌
        // 오른쪽 서브트리에서 가장 작은 값
        root->key = temp->key;                             //
        root->right = delete_node(root->right, temp->key); //
    }
    return root;
}
TreeNode *max_value_node_recur(TreeNode *node)
{
    TreeNode *current = node;
    if (current == NULL)
        return NULL;
    if (current->right == NULL)
        return current;
    else
        return max_value_node_recur(current->right);
}
int get_height(TreeNode *node, int length)
{
    int height = 0;
    if (node != NULL)
        height = length + get_height(node->left, length + 1) + get_height(node->right, length + 1);
    return height;
}

int get_node_count(TreeNode *node)
{
    int count = 0;
    if (node != NULL)
        count = 1 + get_node_count(node->left) + get_node_count(node->right);
    return count;
}

int hasPathSum(TreeNode *node, int sum)
{
    if (node == NULL)
        return 0;
    sum -= node->key;
    // 리프노드에 도달하고값이 같으면
    if (sum == 0 && node->left == NULL && node->right == NULL)
    {
        /*for (int i = 0; i < visitPath; i++)
        {
            printf("%d ->", visited[i]);    //경로 저장
        }*/
        return 1;
    }

    return hasPathSum(node->left, sum) || hasPathSum(node->right, sum);
}

int main()
{
    TreeNode *notTree = NULL;
    TreeNode *curNotTree = notTree;
    TreeNode *root = NULL;
    TreeNode *cur = root;
    int num = 1;
    int IPL = 0;
    int hap = 0;
    int visited[100];
    int probNum = 0;
    double count = 0;
    int item = 0;
    printf("12개의 숫자 입력 0입력시 종료\n");
    while (num != 0)
    {
        scanf("%d", &num);
        if (num == 0)
            break;
        cur = search_node_iterative(root, num); // 먼저 탐색후 null이면 집어넣기
        if (cur == NULL)
        {
            root = insert_node(root, num);
            notTree = insert_node_notTree(notTree, num);
        } // 탐색 실패시 삽입
        else
            printf("중복된 값이라서 삽입 안 함\n");
    }
    while (1)
    {
        printf("\n1: Delete Node\n2: IPL\n3: avgSearch\n4: inorder\n5: isBSTrecursive\n6: hasPathSum\n");
        scanf("%d", &probNum);

        switch (probNum)
        {
        case 1:
            printf("\n삭제할 값을 입력하세요: ");
            scanf("%d", &item);
            if (NULL == search_node_recursive(root, item))
            {
                printf("그 값은 트리에 없습니다.\n");
            }
            else
            {
                root = delete_node(root, item);
                // notTree = delete_node(notTree, item);
                printf("%d를 삭제했습니다.\n", item);
            }
            break;
        case 2:
            // 각 노드의 깊이
            IPL = get_height(root, 1);
            printf("\nIPL= %d\n", IPL);
            printf("get node count= %d\n", get_node_count(root));

            break;
        case 3:
            // 평균 검색 성능
            count = get_node_count(root);
            printf("평균 검색 성능: %lf\n", IPL / count);
            break;
        case 4:
            printf("\n이진검색트리의 중위순회:\n");
            inorder(root);
            printf("\n\n이진 검색트리가 아닌 트리의 중위순회\n");
            inorder(notTree);
            break;
        case 5:
            printf("======이진탐색트리의 트리=======\n");
            cur = min_value_node_recur(root->right);
            if (cur == NULL)
                printf("\n오른쪽 노드가 없습니다.\n");
            else
            {
                printf("\n오른쪽 서브트리의 최소값: %d\n", cur->key);
                printf("루트인 %d가 오른쪽 서브트리인 %d보다 작으니 이진탐색트리가 맞음.\n", root->key, cur->key);
            }
            cur = max_value_node_recur(root->left);
            if (cur == NULL)
                printf("왼쪽 노드가 없습니다.\n");
            else
            {
                printf("왼쪽 서브트리의 최대값: %d\n", cur->key);
                printf("루트인 %d가 왼쪽 서브트리인 %d보다 크니 이진탐색트리가 맞음.\n", root->key, cur->key);
            }
            printf("=======이진탐색트리가 아닌 트리=========\n");
            curNotTree = min_value_node_recur(notTree->right);
            if (curNotTree == NULL)
                printf("\n오른쪽 노드가 없습니다.\n");
            else
            {
                printf("\n오른쪽 서브트리의 최소값: %d\n", curNotTree->key);
                printf("루트인 %d가 오른쪽 서브트리의 최소값인 %d보다 크니 이진탐색트리가 아님.\n", notTree->key, curNotTree->key);
            }
            curNotTree = max_value_node_recur(notTree->left);
            if (curNotTree == NULL)
                printf("왼쪽 노드가 없습니다.\n");
            else
            {
                printf("왼쪽 서브트리의 최대값: %d\n", curNotTree->key);
                printf("루트인 %d가 왼쪽 서브트리인 %d보다 작으니 이진탐색트리가 아님.\n", notTree->key, curNotTree->key);
            }
            break;
        case 6:
            printf("합을 입력하세요.\n");
            scanf("%d", &hap);
            if (1 == hasPathSum(root, hap))
            {
                printf("경로가 있습니다.\n");
            }
            else
                printf("경로가 없습니다.\n");
        default:
            break;
        }
    }
    return 0;
}
