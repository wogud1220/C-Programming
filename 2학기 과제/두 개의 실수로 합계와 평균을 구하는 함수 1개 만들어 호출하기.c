#include <stdio.h>
void add(int num1, int num2, int *sum, int *avg) {	//main 함수에서 입력받은 정수 2개와 
	*sum = num1 + num2;		// main함수에서 매개변수로 넘겨준 num1,num2를 더하여 포인터 변수 sum에 값을 저장
	*avg = (num1 + num2) / 2;//main함수에서 매개변수로 넘겨준 것들을 이용하여 평균을 계산하고 avg에 값을 저장
}
int main(void) {	// main함수 선언
	int num1, num2, sum, avg;	//정수형 변수 선언
	scanf_s("%d %d", &num1, &num2);	//입력받은 정수를 num1과 num2의 주소에 저장
	add(num1, num2, &sum, &avg);	//4개의 인자들을 add함수로 전달하며 add함수 호출
	printf("합계:%d\n평균:%d\n", sum, avg);	//sum과 avg의 값 출력
}
