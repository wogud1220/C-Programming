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