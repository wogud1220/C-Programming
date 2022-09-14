/*#include <stdio.h>
int main() {
	int i = 0;	//i 선언
	double arrd[4] = { 12.4, 23.1, 15.7, 31.2 };	//arrd라는 배열에 4개의 실수 저장
	double* pb = arrd;	//포인터 pb가 arrd 주소안에 있는 값을 찾아감
	for (i = 0; i < 4; i++) {	//4번 반복
		printf("%lf\n", pb[i]);	// pb가 arrd라는 배열을 찾아가 순서대로 실수 출력
	}
	return  0;

}*/





/*#include <stdio.h>
int main() {

	char* p = "banana";	//포인터 문자열 바나나 선언
	int i;
	for (i = 0; i < 6; i++) {	//6번 반복
		printf("%s\n", (p + i));	//문자열 출력, 포인터 p의 시작 지점을 1씩 뒤로 밀면서
	}
	return 0;	//함수 종료
}*/





/*#include <stdio.h>
int main() {
	char str1[20] = "computerprogramming";
	int i = 0;
	for (i = 0; i < 20; i++) {
		if (str1[i] == 'e') {
			printf("배열로 찾은 e는 %d번째에 있습니다.", i+1);
		}

	}

}*/

/*#include <stdio.h>
int main() {

	char* p = "computerprogramming";
	int i = 0;
	for (i = 0; i < 20; i++) {
		if (*(p + i) == 'e') {
			printf("포인터로 찾은 e는 %d번째에 있습니다.\n", i + 1);
		}
	}
}*/