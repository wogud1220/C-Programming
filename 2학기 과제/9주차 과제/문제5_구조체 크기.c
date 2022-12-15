#include <stdio.h>
typedef struct stdent {

	int num;

	double gpa;

	char hi;
}STUDENT;

int main() {

	STUDENT student;
	printf("%d\n", &student.num);
	printf("%d\n", &student.gpa);
	printf("%d\n", &student.hi);

	printf("%d", sizeof(STUDENT));

	/*num 은 4바이트
	gpa 는 8바이트
	hi는 1바이트이지만
	패딩이 일어남
	num=ㅁㅁㅁㅁ
 doubel=ㅁㅁㅁㅁㅁㅁㅁㅁ
 char=  ㅁ
	
	위의 빈 공간을 패딩으로 채워줘야함.
	num에 4바이트 넣고 char에 7바이트 넣어야함 그래서 24바이트가 나옴
	
	순서를 오름차순으로 다르게 한다면 메모리 용량을 줄일 수 있음
	char,int, double 순

	char=ㅁ			num과 같게하려고 3바이트필요함
	num =ㅁㅁㅁㅁ	위의 char와 num을 합하면 8바이트됨 doub과 크기가 같게됨
	doub=ㅁㅁㅁㅁㅁㅁㅁㅁ

	이건 16바이트가 나옴


	char 1;			ㅁ		쇼츠와 맞추기 위해서 1바이트가 더 필요함 총 2바이트
	short 2;		ㅁㅁ	위의 캐릭터와 더하면 4바이트가 되어 int랑 맞음
	int 4;			ㅁㅁㅁㅁ
	int 4;			ㅁㅁㅁㅁ
	이건 2+2+4+4 하면됨 	12바이트

	메모리 절약을 위해선 변수 선언 순서도 중요함.
	*/
}