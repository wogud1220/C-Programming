#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>




typedef struct polynomial{ // 다항식 구조체 타입 선언

	int degree; // 다항식의 차수

	float coef[MAX_DEGREE]; // 다항식의 계수

}POLYNOMIAL;

void print_poly(POLYNOMIAL p) {		//문제 3번		결과 다항식을 매개변수로 받음
	int i = 0;
	for (i = p.degree; i > 0;i--) {		//최고차항부터 시작하여서 0보다 클 동안 하나씩줄어들음.
		if (p.coef[p.degree - i] == 0)		// 예를들어 최고차항이 5면 5-5니깐 0번째 인덱스의 계수가 0이라면 printf를 안 하고 조건검사식으로 이동
			continue;
		else {
			printf("%3.1fx^%d  ", p.coef[p.degree - i], i);	//0이 아니라면 n번째 인덱스의 계수, x의 지수 표현.
			printf("+ ");			//+는 마지막에 안 나오게하기
		}
	}
	if (p.coef[p.degree - i] == 0) {
		return;
	}
	printf("%3.1fx^%d", p.coef[p.degree], i);		//마지막은 x의 0승인데 반복문에서 0보다 클 동안이라 했으므로 따로 표현
}



POLYNOMIAL poly_gop(POLYNOMIAL A, POLYNOMIAL B) {	//1번 곱셈을계산하는 함수

	POLYNOMIAL C; // 결과 다항식

	int Apos = 0, Bpos = 0, Cpos = 0; // 배열 인덱스 변수

	int degree_a = A.degree;		//넘겨받은 구조체 A 다항식 1의 최고차수

	int degree_b = B.degree;		//넘겨받은 구조체 B 다항식 2의 최고차수

	C.degree = MAX(A.degree, B.degree); // 결과 다항식 차수. 누가 더 큰지

	while (Apos <= A.degree && Bpos <= B.degree) {	// 다항식 1,2의 최고차항이 0보다 크거나 같고 == 최고차항이 있으면

		if (degree_a > degree_b) {  // A항 > B항

			C.coef[Cpos++] = A.coef[Apos++];	//0번째를 결과에 대입하고 다음 인덱스를 계산하기위해서 플러스

			degree_a--;	//3제곱이였으면 2제곱으로 낮춤.

		}

		else if (degree_a == degree_b) {  // A항 == B항

			C.coef[Cpos++] = A.coef[Apos++] * B.coef[Bpos++]; //지수가 같으면 둘이 곱함

			degree_a--; degree_b--;		//3제곱이였으면 2제곱으로 낮춤.


		}

		else { // B항 > A항

			C.coef[Cpos++] = B.coef[Bpos++];

			degree_b--;
		}


	}

	return C;		//A구조체의 다항식1과 B구조체의 다항식 2를 계산하여서 결과다항식을 구조체 C에 집어넣음.

}

int poly_eval(int x,POLYNOMIAL c) {

	printf("x의 값은 : %d입니다.\n--------------------------------\n\n", x);			//x값 표기
	int i = 0;
	float d = 0;
	int c_arr = c.degree;			//c.degree라는 본래의 차수도 필요하기 때문에 똑같은 수가 들어가있는 변수 또 생성
	float sum = 0;
	
	for ( i = c.degree; i > 0; i--) {
		if (c.coef[c.degree - i] == 0) {		//계수가 n번째 인덱스가 0이라면, 처음:5-5, 계수가 0이라면 표현을 안하니깐 printf문 사용 Xa
			c_arr--;							//지수를 하나씩 내려주고, 다시 위로 올라감
			continue;
		}
		else {
			printf("%f ", c.coef[c.degree - i] * pow(x, c_arr));		//결과 값은 계수 * x의 지수승이니 검사식을 작성해줌.
			printf("+ ");
																//계산이 끝나면 다음 차수를 계산하기위해 지수를 하나 내려줌
			sum = sum + (c.coef[c.degree - i] * pow(x, c_arr));
			c_arr--;
		}
	}
	if (c.coef[c.degree - i] != 0) {
		printf("%f\n\n\n", c.coef[c.degree] * pow(x, c_arr));
	}		//마찬가지로 0보다 클때니깐 0일때의 계산 써줌
	sum+= (c.coef[c.degree - i] * pow(x, c_arr));

	printf("\n완료된 값은: %f", sum);
}





POLYNOMIAL input_poly_1() {		//반환값은 다항식1이 전부 들어있는 구조체
	
	POLYNOMIAL a;
	int i = 0;
	printf("첫번째 다항식에서 최고차항을 입력해주세요.\n");
	scanf("%d", &a.degree);
	printf("다항식을 입력해주세요.\n");
	for (i = 0; i < a.degree + 1; i++) {
		scanf("%f", &a.coef[i]);
	}
	return a;

}
POLYNOMIAL input_poly_2() {		//반환값은 다항식2가 전부 들어있는 구조체
	POLYNOMIAL b;
	int i = 0;
	printf("두번째 다항식에서 최고차항을 입력해주세요.\n");
	scanf("%d", &b.degree);
	printf("다항식을 입력해주세요.\n");
	for (i = 0; i < b.degree + 1; i++) {
		scanf("%f", &b.coef[i]);
	}
	return b;
}

int main(void) {		//2번 문제

	POLYNOMIAL c;			//다항식을 저장할 구조체 
	int x;					//x의 값 선언
	c = poly_gop(input_poly_2(), input_poly_1());		//곱하는 함수에 다항식 입력함수를 인자로 넣어줌, c에 결과 다항식이 들어가있음.
	print_poly(c);			//다항식 출력하는 함수
	printf("\n---------------------------------------------");
	printf("\n\nx의 값을 입력하세요.\n");
	scanf("%d", &x);
	poly_eval(x,c);		//x의 값과 결과 다항식 구조체인 C를 넘겨줌
	return 0;
}