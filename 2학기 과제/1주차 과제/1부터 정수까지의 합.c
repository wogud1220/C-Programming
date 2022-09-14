#include <stdio.h>
int main(void) {
	int num1, i, sum = 0;	//정수형 변수 선언
	printf("정수를 입력하세요\n");	//문자 출력
	scanf_s("%d", & num1);	//입력받은 정수 num1에 저장
	for (i = 0; i <= num1; i++) {	//  입력받은 숫자까지의 합을 계산하는 반복문 선언
		if (i % 5 == 0) {		// 5의 배수는 제외하는 조건1 선언
			continue;		//5의 배수라면 다시 for문의 조건 검사식으로 이동
		}
		else if (sum >= 1000) {		//입력받은 정수까지의 합이 1000 이상이면 
			break;					//for문 탈출
		}
		sum += i;				// 입력받은 정수까지의 합 저장
	}
	printf("%d", sum);			//입력받은 정수까지의 합 출력

	return 0;				//main함수 종료
}