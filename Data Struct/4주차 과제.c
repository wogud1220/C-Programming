#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_TERMS 101
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


typedef struct {
    int row;
    int col;
    int value;
} element;

typedef struct SparseMatrix {
    element data[MAX_TERMS];
    int rows; // 행의 개수
    int cols; // 열의 개수
    int terms; // 항의 개수
} SparseMatrix;


SparseMatrix transpose( int a[8][10], int i, int j, SparseMatrix* matrixA) {

    int bindex = 0;
    matrixA->rows = j;    //10개의 열을 10개의 행으로 변환   10
    matrixA->cols = i;      //8개의 행을 8개의 열로 변환      8
    matrixA->terms = 0;
    for (j = 0; j < matrixA->cols; j++) {
        for (i = 0; i < matrixA->rows; i++) {
            if (a[j][i]) {          //배열에 무언가가 들어가있다면
                matrixA->terms = matrixA->terms++;      //0이 아닌 값이 들어가있는 항의개수를 셈!!
            }
        }
    }

    for (j = 0; j < matrixA->cols; j++) {   //행을 다 채울동안
        for (i = 0; i < matrixA->rows; i++) {    //열을 다 채울동안
            if (a[j][i] != 0) {         //안에 있는 값이  0이 아니라면
                matrixA->data[bindex].col = j;              //배열에 무언가가들어가있다면 그 배열의 인덱스와 값을 매트릭스A에 저장함
                matrixA->data[bindex].row = i;
                matrixA->data[bindex].value= a[j][i];
                bindex++;
            }
            
        }

    }
}


void plus_matrix(SparseMatrix* matrixA, SparseMatrix* matrixB, SparseMatrix* hap) {   //a와 b의 스파스 매트릭스 받기

    int i = 0;
    int j = 0;
    int cnt = 0;
    int hindex = 0;
    hap->cols = matrixA->cols;              //매트릭스 A에 저장된 크기를 불러옴
    hap->cols = matrixA->rows;
    for (cnt=0; cnt <matrixA->terms + matrixB->terms; cnt++) {       //a의 값 개수 + b의 값 개수 = 4+3 
        if (matrixA->data[i].col == matrixB->data[j].col) {     //행이 같고
            if (matrixA->data[i].row == matrixB->data[j].row) {     //행과 열이 둘다 같다면
                hap->data[hindex].value = matrixA->data[i].value + matrixB->data[j].value;     //합 구조체에 값과 세로, 가로열의 인덱스를 hap구조체에 저장
                hap->data[hindex].col = matrixA->data[i].col;
                hap->data[hindex].row = matrixA->data[i].row;
               
                hindex++, j++, i++;                                                         //모든 인덱스 하나씩 올리기
            }
            else if (matrixA->data[i].row > matrixB->data[j].row) {    //행은 같은데 a의 열이 더 크다면 == b열이 더 작다면
                hap->data[hindex].value = matrixB->data[j].value;
                hap->data[hindex].col = matrixB->data[j].col;
                hap->data[hindex].row = matrixB->data[j].row;
                
                hindex++, j++;
            }
            else if(matrixA->data[i].row<matrixB->data[j].row){           //행은 같은데 b의 열이 더 크다면 == a열이 더 작다면
                hap->data[hindex].value = matrixA->data[i].value;
                hap->data[hindex].col = matrixA->data[i].col;
                hap->data[hindex].row = matrixA->data[i].row;
               
                hindex++, i++;
            }
        }
        else {    //행이 서로 같지않고 
        if (matrixA->data[i].col < matrixB->data[j].col) {        //b행이 더 크다면 == a행이 더 작다면
            hap->data[hindex].value = matrixA->data[i].value;       //열 비교할 필요없이 바로 대입
            hap->data[hindex].col = matrixA->data[i].col;
            hap->data[hindex].row = matrixA->data[i].row;
           
            hindex++, i++;
        }
        else if (matrixA->data[i].col > matrixB->data[j].col) {     //a행이 더 크다면 == b행이 더 작다면
            hap->data[hindex].col = matrixB->data[j].col;       //열 비교할 필요없이 b것을 바로 대입
            hap->data[hindex].row = matrixB->data[j].row;
            hap->data[hindex].value = matrixB->data[j].value;
            
            hindex++, j++;
        }
        }//if문
        if (i == matrixA->terms) {                      //만약 매트릭스 A  인덱스에 끝에 도달했다면   
            for (j; j < matrixB->terms; j++) {          //다른 한쪽의 값을 계속해서 집어넣음
                hap->data[hindex].value = matrixB->data[j].value;       
                hap->data[hindex].col = matrixB->data[j].col;
                hap->data[hindex].row = matrixB->data[j].row;
                
                hindex++;
            }
        }
        else if (j == matrixB->terms) {                  //만약 매트릭스 B  인덱스에 끝에 도달했다면  
            for (i; i < matrixA->terms; i++) {
                hap->data[hindex].value = matrixB->data[i].value;
                hap->data[hindex].col = matrixB->data[i].col;
                hap->data[hindex].row = matrixB->data[i].row;
                
                hindex++;
            }
        }

    }//for문
    for (i = 0; i<matrixA->terms+matrixB->terms; i++) {
        if (hap->data[i].value < -800) {
            continue;
        }
        printf("\n합:%d \n", hap->data[i].value);                //값만 출력하는 반복문

    }
    printf("\n\n");
    return;

}//함수

void print_include_0(SparseMatrix* hap) {               //0을 포함하여 출력
    int i = 0;
    int j = 0;
    int hindex = 0;
    printf("\n\n");
    for (j = 0; j < 8; j++) {                                   //행렬처럼 나와야하니 2중 반복문
        for (i = 0; i < 10; i++) {                              //가로가 10개니 10번반복    0이 들어갈
                if (i == hap->data[j].row) {                    //0 4 2일때 j.row 는 4. 즉 4번째라면
                    printf(" [%d] ", hap->data[hindex].value);      //hap에서의 첫 값 출력
                    hindex++;
                    continue;
                }
                printf(" 0 ");
                //continue;
            }
        
        printf("\n");
    }
}

SparseMatrix print_plusmatrix(SparseMatrix* hap) {   //hap에 들어가있는거 출력

    int i = 0;
    int j = 0;

    for (i; i < 10; i++) {
        if (hap->data[i].col < -100)
            continue;
        printf("%d %d %d \n", hap->data[i].col, hap->data[i].row, hap->data[i].value);      //그림판에 들어간 인덱스, 값을 출력
 }
}

void print_matrix(SparseMatrix* matrixA) {              //초기 매트릭스 A, B, C에 있는 값을 출력
    int j = 0;
    int i = 0;
    for (i = 0; i < matrixA->terms; i++) {  //항의 개수만큼 반복
        printf("%d %d %d\n", matrixA->data[i].col, matrixA->data[i].row, matrixA->data[i].value);
    }
    printf("\n ");

}

int main() {
    int  a [8][10] =        { { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
                            { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
                            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                            { 0, 0, 0, 0, 0, 0, 0,-3, 0, 0 },
                            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                            { 0,-1, 0, 0, 0, 0, 0, 0, 0, 0 },
                            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };


    int b[8][10] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                     { 0, 0, 0,-1, 0, 0, 0, 0, 0, 0 },
                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                     { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                     { 0, 0, 0, 0, 0, 0, 2, 0, 0, 0 } };

    int c[8][10] = { { 0, 0, 0, 0,-2, 0, 0, 0, 0, 0 },
                     { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                     { 0, 0, 0, 0,-2, 0, 0, 0, 0, 0 },
                     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                     { 0, 0, 0, 0, 0, 0, 4, 0, 0, 0 } };

    SparseMatrix matrixA;       //배열 a를 전치로 변환한 것
    SparseMatrix matrixB;
    SparseMatrix matrixC;

    SparseMatrix hap;       //더한 값을 저장할 구조체 생성

    int num = 0;
    transpose(a, 8, 10, &matrixA);              //각각 a,b, c 변환하는 함수 불러오기
    printf("A=====================\n\n");
    print_matrix(&matrixA);
    transpose(b, 8, 10, &matrixB);
    printf("B=====================\n\n");
    print_matrix(&matrixB);
    transpose(c, 8, 10, &matrixC);
    printf("C=====================\n\n");
    print_matrix(&matrixC);

    printf("\n\nA+B: 1번 입력 \nA+C: 2번 입력\nB+C: 3번 입력\n");
    scanf("%d", &num);


    switch (num)
    {
    case 1:
        plus_matrix(&matrixA, &matrixB, &hap);      //A+B
        break;
    case 2:
        plus_matrix(&matrixA, &matrixC,&hap);       //A+C
        break;
    case 3:
        plus_matrix(&matrixB, &matrixC,&hap);       //B+C
        break;
    default:
        break;
    }
    print_plusmatrix(&hap);     //더하여 hap에 들어가있는 값이  있는 행렬만 출력
    print_include_0(&hap);      //hap에 있는 0을 포함한 행렬 출력
}