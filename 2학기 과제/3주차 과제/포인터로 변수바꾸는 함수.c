#include <stdio.h>
//포인터를 사용하지 않은 swap
/*void swap(int x, int y) {		//swap 함수에 main 함수에서의 x, y값 받아오기
	int temp;		//	x,y의 순서를 바꿔줌
	temp = x;
	x = y;
	y = temp;				
}
int main(void) {	//main 함수 선언
	int x = 5, y = 20;	//x와 y에 값 저장
	swap(x, y);		//swap 함수 호출
	printf("%d %d", x, y);	//바뀐 x, y값 출력
	return 0;		//main 함수 종료
}*/


//포인터를 사용한 swap

/*void swap(int* x, int* y) {//포인터형 변수 x,y를 매개변수로 받는 swap함수 생성
	int temp = *x;		//x에 있는 값을 temp로 이동
	*x = *y;			//y에 있는 값을 x로 이동
	*y = temp;			//y에 있는 값을 temp로 이동
    return 0;
}

int main(void) {		//main함수 선언
	int x, y;			//정수형 변수 x, y 선언
	x = 10, y = 30;		//x에 10, y에 30 저장
	printf("변경 전 x값과 y값 %d %d\n", x, y);	//swap전 x값과 y값 출력
	swap(&x, &y);		//x와 y값의 주소를 swap함수의 매개변수로 이동
	printf("변경 후 x값과 y값 %d %d\n", x, y);	// 변경 후 x값과 y값 출력
}*/