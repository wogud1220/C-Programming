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
// AVL 트리 노드 정의
/*
typedef struct hash
{
    int key;
    int step;
} HASH;
void initHash(HASH hash)
{
    hash.key = 0;
    hash.step = 0;
}*/

typedef struct AVLNode
{
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
} AVLNode;

typedef struct TreeNode
{
    int key;
    struct TreeNode *left, *right;
} TreeNode;

void inorder(AVLNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("[%d] ", root->key);
        inorder(root->right);
    }
}
// 트리의 높이를 반환
int get_height(AVLNode *node)
{
    int height = 0;
    if (node != NULL)
        height = 1 + MAX(get_height(node->left), get_height(node->right));
    return height;
}
int get_height_tree(TreeNode *node)
{
    int height = 0;
    if (node != NULL)
        height = 1 + MAX(get_height(node->left), get_height(node->right));
    return height;
}
// 노드의 균형인수를 반환 : 왼쪽 서브트리 높이 - 오른쪽 서브트리 높이
int get_balance(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return get_height(node->left) - get_height(node->right);
}

// key  값을 갖는 노드를 동적으로 생성하고 반환하는 함수
AVLNode *create_node(int key)
{
    AVLNode *node = (AVLNode *)malloc(sizeof(AVLNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// 오른쪽으로 회전시키는 함수
AVLNode *rotate_right(AVLNode *parent)
{
    AVLNode *child = parent->left;
    parent->left = child->right;
    child->right = parent;
    return child; // 새로운 루트를 반환
}

// 왼쪽으로 회전시키는 함수
AVLNode *rotate_left(AVLNode *parent)
{
    AVLNode *child = parent->right;
    parent->right = child->left;
    child->left = parent;
    return child; // 새로운 루트 반환
}
// AVL 트리에 새로운 노드 추가 함수
// 새로운 루트를 반환한다.
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

AVLNode *insert(AVLNode *node, int key)
{
    // 이진 탐색 트리의 노드 추가 수행
    if (node == NULL)
        return (create_node(key));
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // 동일한 키는 허용되지 않음
        return node;
    // 노드들의 균형인수 재계산

    int balance = get_balance(node);
    // LL 타입 처리
    if (balance > 1 && key < node->left->key)
        return rotate_right(node);
    // RR 타입 처리
    if (balance < -1 && key > node->right->key)
        return rotate_left(node);

    // LR 타입 처리
    if (balance > 1 && key > node->left->key)
    {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    // RL 타입 처리

    if (balance < -1 && key < node->right->key)
    {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }
    return node;
}
AVLNode *deleteNode(AVLNode *node, int key)
{
    if (node == NULL)
        return node;
    if (key < node->key)
        node->left = deleteNode(node->left, key);
    else if (key > node->key)
        node->right = deleteNode(node->right, key);
    else
    {
        if (node->left == NULL || node->right == NULL)
        {
            AVLNode *temp = node->left ? node->left : node->right;
            if (temp == NULL)
            {
                temp = node;
                node = NULL;
            }
            else
                *node = *temp;
            free(temp);
        }
        else
        {
            AVLNode *temp = node->right;
            while (temp->left != NULL)
                temp = temp->left;
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }
    }

    if (node == NULL)
        return node;
    int balance = get_height(node->left) - get_height(node->right);

    if (balance > 1 && key < node->left->key)
        return rotate_right(node);

    if (balance < -1 && key > node->right->key)
        return rotate_left(node);
    if (balance > 1 && key > node->left->key)
    {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }
    if (balance < -1 && key < node->right->key)
    {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node;
}

int main()
{
    int hashTable[13] = {0};
    int hashNum = 0;
    int i, a, sum;
    AVLNode *AVLroot = NULL;
    TreeNode *root = NULL;
    int probNum;
    int num = 1;
    printf("1: hash Table\n2: hash Table (I Square)\n5:AVL Tree\n");
    scanf("%d", &probNum);
    switch (probNum)
    {
    case 1:
        printf("input hashKey\n");
        for (int s = 0; s < 8; s++)
        {
            scanf("%d", &hashNum);
            i = hashNum % 13;

            if (hashTable[i] == NULL)
            {
                hashTable[i] = hashNum;
            }
            else
            { // 안 비어있으면
                while (hashTable[i] != NULL)
                {
                    i++;
                    if (i >= 13)
                        i = 0;
                }
                hashTable[i] = hashNum;
            }
        }

        for (int i = 0; i < 13; i++)
        {
            printf("%d: %d \n", i, hashTable[i]);
        }
        break;
    case 2: /*
             printf("input hashKey\n");
         for (int s = 0; s < 2; s++)
         {
             scanf("%d", &hashNum);
             i = hashNum % 13;

             if (hashTable[i] == NULL)
             {
                 hashTable[i] = hashNum;
             }
             else
             { // 안 비어있으면
                 printf("asdf");
                 a = 1;
                 sum = 0;

                 while (hashTable[i] != NULL)
                 {
                     a = pow(a, 2);
                     sum += a;
                     a++;
                 }
                 hashTable[sum + i] = hashNum;
             }
         }
         for (int i = 0; i < 13; i++)
         {
             printf("%d: %d \n", i, hashTable[i]);
         }*/
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        printf("input key\n");
        while (1)
        {
            scanf("%d", &num);
            if (num == 0)
                break;
            AVLroot = insert(AVLroot, num);
            root = insert_node(root, num);
        }
        printf("AVL Tree = ");
        inorder(AVLroot);
        printf("\nAVL height= %d\n", get_height(AVLroot));
        printf("\nBST = ");
        inorder(root);
        printf("\nBST height = %d\n", get_height_tree(root));
        printf("삭제할 번호를 입력하세요.\n");
        scanf("%d", &num);
        deleteNode(AVLroot, num);
        printf("삭제한 AVL Tree = ");
        inorder(AVLroot);
        printf("\nAVL height= %d\n", get_height(AVLroot));
        break;
    default:
        break;
    }
    return 0;
}
