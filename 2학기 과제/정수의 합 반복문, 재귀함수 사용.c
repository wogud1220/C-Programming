#include <stdio.h>
/*int main(void) {			//main함수 선언
	int i, num1;			//int형 변수 선언
	int sum = 0;
	printf("정수를 입력하세요\n");	//문자 출력
	scanf_s("%d", &num1);		//정수를 입력받아 num1공간에 저장
	for (i = 0; i <= num1; i++) {	//1부터 입력받은 정수까지 구하는 조건 선언
		sum+=i;		//sum에 0부터 입력한 정수 값 저장
	}
	printf("%d", sum);	//sum값 출력
	return 0;	//main함수 종료
}*/
int hap(int num1) {	//num1을 매개변수로 받은 hap함수 생성
	if (num1==0){	//받은 num1값이 0이라면
		return 0; // 0 반환 하기, hap함수 종료
	}
	else { //위의 조건에 만족하지 않는다면
		return num1 + hap(num1 - 1); //num1값을 반환하고 (num1-1)의 값을 hap함수로 다시 호출
	}
}
int main(void) {	//main 함수 선언
	int num1 = 0;	//정수형 변수 선언
	printf("정수를 입력하세요");	//문자 출력
	scanf_s("%d", &num1);		//입력받은 정수 num1에 저장
	hap(num1);	//hap함수에 num1을 전달
	printf("%d", hap(num1));	//hap 함수의 return 값 출력
	return 0; //main 함수 종료



}