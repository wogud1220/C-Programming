#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SQUARE(X)   X*X						//장점: 실행 속도 빠름, 자료형에 따라 별도 함수 필요없음
#define SQUARE_1(X)	(X)*(X)					//단점: 정의하기 까다로움, 디버깅하기 쉽지 않음.
#define SQUARE_2(X) (X*X)						//작은 크기의 함수, 호출의 빈도가 높은 함수만 사용하기.
#define ADD 3									//ADD는 3으로 정의 되어있다.
#define MIN 0
#define STR(A,B)	#A "의 직업은 " #B"입니다."		//문자열을 치환할때는 앞에 # 붙이기
#define STNUM(X, Y, Z)	(X*100000+Y*1000+Z)			//숫자 치환		(XYZ)로 하면 안됨  그런데 이렇게 하면 더러워지니깐
#define STNUM_REAL(X, Y, Z)		X ## Y ## Z		//매크로 몸체에서 ##은 서로 이어주는 역할.

int main() {
	printf("%d\n", SQUARE(2));	// 정상적으로 4 출력.

	printf("%d\n", SQUARE_1(3 + 2));	//25 출력

	printf("%d\n",120/SQUARE(2));	//30이 나와야하는데 120 출력	== 120/2*2가 실행됨

	printf("%d\n\n", 120 / SQUARE_2(2));	//괄호를 한번 더 해서 정상적인 값 나옴.  == 120/(2*2)가 실행됨

	#ifdef ADD
		printf("ADD가 정의되었습니다.\n");
	#endif // ADD


#if ADD ==1
	printf("ADD가 1입니다.\n");
#elif ADD==2 
	printf("ADD가 2입니다.\n");
#elif ADD==3
	printf("ADD가 3입니다.\n");
#else
	printf("ADD가 1,2,3 다 아닙니다.\n");

#endif // ADD 1

	printf("%s\n",STR(이동춘, 나무꾼));		//문자열을 치환할때는 앞에 # 붙이기




	printf("가짜 학번: %d\n", STNUM(10, 65, 175));		//11행
	printf("가짜 학번: %d\n", STNUM(10, 65, 075));		//11행
	printf("진짜 학번: %d\n", STNUM_REAL(10, 65, 075));


	return 0;


}