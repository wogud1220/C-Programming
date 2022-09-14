#include <stdio.h>					
float high(float i) {		// 실수i를 입력받아 실수를 반환하는 함수 생성
	float result;		//실수형 변수 result 생성
	result = (float)i / 100;	// 입력 받은 키를 m단위로 변환
	return result;				// result값을 main 함수로 반환
}
int main(void) {				//main 함수 선언
	int i;						//정수형 변수 i선언
	float c;					//실수형 변수 c 선언
	printf("키를 입력하세요.\n"); //문자 출력
	scanf_s("%d", &i);			//키를 입력받아 i에 저장
	c = high((float)i);			//high 함수 호출
	printf("%.2lfm입니다.", c);	//c출력 출력
	return 0;					//함수 종료
}