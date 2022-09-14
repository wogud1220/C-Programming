#include <stdio.h>
int main() {

	char* p = "banana";	//포인터 문자열 바나나 선언
	int i;
	for (i = 0; i < 6; i++) {	//6번 반복
		printf("%s\n", (p+i));	//문자열 출력, 포인터 p의 시작 지점을 1씩 뒤로 밀면서
	}
	return 0;	//함수 종료
}