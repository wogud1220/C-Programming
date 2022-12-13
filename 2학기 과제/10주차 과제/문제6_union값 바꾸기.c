#include <stdio.h>
union grade {
   int score;  // 점수
double gpa; // 평점평균
};


int main(void) {
    union grade g1 = { 95 }; // 공용체 변수의 선언과 초기화
    printf("%d\n", g1.score);// score를 출력하시오
    g1.gpa = 4.3;// gpa에 4.3을 대입하시오
    printf("%lf\n", g1.gpa);// gpa를 출력하시오
    printf("%d\n", g1.score);// score를 출력하시오
    return 0;
}

/*#include <stdio.h>

typedef union student {
	int age;
	double age2;
}STUDENT;

int main() {

	STUDENT student;

	student.age2 = 20;      //더 큰 값에 20 선언
	student.age = 10;       //작은 값에 10 선언
	student.age2 = 20;      //다시 큰 값에 20 선언

    //큰 게 작은값을 덮어씀

	printf("%d", student.age);  //이상한값 
	printf("\n%lf\n", student.age2);    //20 
	printf("%d", student.age);  //이상한값


}*/