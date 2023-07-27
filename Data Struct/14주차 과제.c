#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
//#pragma warning(disable:4996)


typedef struct {
    char    word[10000];
    int     count;
} element;


typedef struct TreeNode {
    element key;
    struct TreeNode* left, * right;
} TreeNode;


int compare(element e1, element e2)
{
    return strcmp(e1.word, e2.word);
}

static int ko = 0;


/// 성공적으로 읽었으면 TRUE, 그렇지 않으면(파일 끝) FALSE 리턴
int getword(FILE* fd, char* word)
{
    char    ch;
    int    i;

    do {
        ch = getc(fd);
        if (ch == EOF)
            return 0;
    } while (!isalpha(ch)); /// 첫번째 알파벳 문자가 나올때까지 읽는다. 알파벳이면 탈출
    i = 0;
    do {    /// 단어 1개를 읽는다.
        ch = tolower(ch);   /// 소문자로 변환
        word[i++] = ch;
        ch = getc(fd);
    } while (isalpha(ch));  /// 알파벳 문자이면 계속 읽는다.
    word[i] = '\0';
    return 1;
}


TreeNode* update_BST(TreeNode** root, element key)
{
    TreeNode* p, * q;
    TreeNode* newnode;
    p = *root;
    q = NULL;
    while (p != NULL)   //노드가 빌 때까지 이동 시킴
    {
        if (compare(key, p->key) == 0) { //같으면 count++
            p->key.count++;
            ko++;
            return p;
        }
        q = p;
        if (compare(key, p->key) < 0) { //작으면 왼쪽으로 크면 오른쪽으로 포인터 이동
            p = p->left;
        }
        else
            p = p->right;
    }

    newnode = (TreeNode*)malloc(sizeof(TreeNode));  //동적 생성
    newnode->key = key;     
    newnode->left = newnode->right = NULL;

    //p위치 받아옴, 없는 값일때 생성하는 것
    if (q != NULL) {
        if (compare(key, q->key) < 0) {  //새로운 값이 들어온다면, 루트보다 작은 알파벳이라면
            q->left = newnode;
            newnode->key.count = 1;
            ko++;
        }
        else {
            q->right = newnode;
            newnode->key.count = 1;//새로운 값이 들어온다면, 큰 알파벳이라면
            ko++;
        }
    }
    else {
        *root = newnode;
        newnode->key.count = 1;   //null이라면
        ko++;
    }
};


void inorder(TreeNode* t, FILE* fp_in, FILE* fp_out)  ///노드의 단어와 count를 출력해줍니다.
{
    if (t)
    {
        inorder(t->left, fp_in, fp_out); 
        fputs(t->key.word, fp_out);
        fprintf(fp_out, " %d개\n", t->key.count);
        printf("%s %d개\n", t->key.word, t->key.count); //값을 출력해줍니다.
        inorder(t->right, fp_in, fp_out);
    }
   
}

/// 노드 개수 세기
int get_node_count(TreeNode* node)
{
    int count = 0;
    if (node != NULL)
        count = 1 + get_node_count(node->left) + get_node_count(node->right); 
    return count;
}

TreeNode* search(TreeNode* node, int item) {
    if (node->key.count == item) return node;
    search(node->left,item);
    search(node->right,item);
}





int find_max(TreeNode* node) {
    //T1*m1 = t1_root->data;
    if (node != NULL) {
        int a= node->key.count;
        a = MAX(a, find_max(node->left));
        a = MAX(a, find_max(node->right));
        return a;
    }

}

/// 트리 높이 계산
int get_height(TreeNode* node)
{
    int height = 0;
    if (node != NULL) 
        height = 1 + max(get_height(node->left), get_height(node->right)); 
    return height;  
}


int main()
{
    element     e;
    TreeNode* root = NULL;
    char        w[10000];   // 읽어들인 단어
    int         flag;               //파이 ㄹ끝 확인

    FILE* fp_in;
    fp_in = fopen("bst_in.txt", "r");

    FILE* fp_out;
    fp_out = fopen("bst_out.txt", "w+");


    do {
        flag = getword(fp_in, w);
        if (flag == 0)      //단어가 있다면
            break;
        strcpy(e.word, w);   ///strcpy를 사용하여 e.word에 w값을 넣었습니다.
        if (!strcmp(e.word, "break") || !strcmp(e.word, "case") ||
            !strcmp(e.word, "do") || !strcmp(e.word, "else") ||
            !strcmp(e.word, "for") || !strcmp(e.word, "if") ||
            !strcmp(e.word, "int") || !strcmp(e.word, "return") ||
            !strcmp(e.word, "switch") || !strcmp(e.word, "while"))
            update_BST(&root, e);  ///root의 주소 값을 넣고 e를 받아갑니다.

    } while (1);


    inorder(root, fp_in, fp_out);///프린트 함수

    printf("\n노드 개수 = %d\n", get_node_count(root));
    printf("트리 높이 = %d\n\n", get_height(root));
    int maxpoint = find_max(root);  //최대값 couㅜㅅ 저장

    TreeNode* max=search(root, maxpoint); //반환값은 포인터임

    printf("최대 빈도 단어 = %s", max->key.word);
    printf("   %d번 나옴\n", maxpoint);
    fclose(fp_in);
    fclose(fp_out);

}
