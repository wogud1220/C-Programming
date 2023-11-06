#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the AVL tree
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

// Function to get the height of a node
int height(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

// Function to calculate the balance factor of a node
int getBalanceFactor(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// Function to update the height of a node
void updateHeight(Node *node)
{
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to rotate a subtree rooted with node to the right
Node *rightRotate(Node *node)
{
    Node *newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;

    updateHeight(node);
    updateHeight(newRoot);

    return newRoot;
}

// Function to rotate a subtree rooted with node to the left
Node *leftRotate(Node *node)
{
    Node *newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;

    updateHeight(node);
    updateHeight(newRoot);

    return newRoot;
}

// Function to insert a new node into the AVL tree
Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        // Duplicate data is not allowed in AVL trees
        return root;
    }

    // Update the height of the current node
    updateHeight(root);

    // Get the balance factor to check for imbalance
    int balance = getBalanceFactor(root);

    // Perform rotations to balance the tree
    if (balance > 1)
    {
        if (data < root->left->data)
        {
            // Left-Left case
            return rightRotate(root);
        }
        else
        {
            // Left-Right case
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    if (balance < -1)
    {
        if (data > root->right->data)
        {
            // Right-Right case
            return leftRotate(root);
        }
        else
        {
            // Right-Left case
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

// Function to print the AVL tree in-order
void inOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to free the memory of the AVL tree
void freeAVLTree(Node *root)
{
    if (root != NULL)
    {
        freeAVLTree(root->left);
        freeAVLTree(root->right);
        free(root);
    }
}

int main()
{
    Node *root = NULL;
    int choice, data;

    while (1)
    {
        printf("1. 노드 추가\n");
        printf("2. AVL 트리 출력\n");
        printf("3. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("추가할 데이터 입력: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("AVL 트리 (중위 순회): ");
            inOrderTraversal(root);
            printf("\n");
            break;
        case 3:
            // 프로그램 종료 시 메모리 해제
            freeAVLTree(root);
            exit(0);
        default:
            printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    }

    return 0;
}
