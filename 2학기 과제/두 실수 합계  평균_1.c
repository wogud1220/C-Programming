#include <stdio.h>
int hap(int a, int b,char c) { //정수형 변수 2개, 문자 1개를 받을 수 있는 hap함수 선언
	int h = 0;// 정수형 변수 h 초기화
	if (c == '+') { //입력받은 연산자가 '+' 라면
		h = a + b;	// 입력받은 정수 2개를 더해서 h에 저장
	}
	else if (c == '#') {	//입력받은 연산자가 '#' 이라면
		h = (a + b) / 2;	//입력받은 정수의 평균을 h에 저장
	}
	return h;		// 연산한 h값을 hap함수 밖으로 반환하여 main함수에 전달
}
int main(void) {		//main 함수 선언
	int num1, num2, j;	//정수형 변수 선언
	char char1;			// 연산자를 받기위한 변수 선언
	printf("두 정수를 입력하고 더할 거면 '+', 평균은 '#'를 입력하세요\n"); //문자 출력
	scanf_s("%d %d %c", &num1, &num2, &char1,1); //정수 2개와 연산자 입력 받기
	j = hap(num1, num2, char1);		//hap 함수에 2개의 정수와 연산자를 보내주고 반환 받을 값을 j에 대입
	printf("%d", j);	// j에 들어간 값 출력
	return 0;		//main 함수 종료
}