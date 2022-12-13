/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct complex_number
{
    double realnum;
    double imgnum;
}Cnum;

Cnum Sum(Cnum a, Cnum b)
{
    Cnum sum;
    sum.realnum = a.realnum + b.realnum;    //실수 부분
    sum.imgnum = a.imgnum + b.imgnum;   //허수 부분
    return sum;
}
Cnum Complex(Cnum a, Cnum b)
{
    Cnum complex;
    complex.realnum = a.realnum * b.realnum - a.imgnum * b.imgnum;
    complex.imgnum = a.realnum * b.imgnum + a.imgnum * b.realnum;
    return complex;
}

int main()
{
    Cnum n1, n2, result;
    printf("복소수1(실수, 허수): ");
    scanf("%lf%lf", &n1.realnum, &n1.imgnum);
    printf("복소수2(실수, 허수)): ");
    scanf("%lf%lf", &n2.realnum, &n2.imgnum);
    result = Sum(n1, n2);
    printf("실수: %lf 허수: %lf\n", result.realnum, result.imgnum);
    result = Complex(n1, n2);
    printf("실수: %lf 허수: %lf\n", result.realnum, result.imgnum);

    return 0;
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bok {
	double real_num;		//실수
	double bok_num;			//허수
}BOK;


BOK Sum(BOK a, BOK b) {
    BOK sum;        //합을 저장할 구조체 변수 생성
    sum.real_num = a.real_num + b.real_num;     //1번 실수 + 2번 실수
    sum.bok_num = a.bok_num + b.bok_num;        //1번 허수 + 2번 허수
    return sum;     //구조체 반환
}

BOK Gop(BOK a, BOK b) {
    BOK gop;        //곱을 저장할 구조체 변수 생성
    gop.real_num = (a.real_num * b.real_num)-(a.bok_num*b.bok_num); //(1+2i)*(2+3i)의 실수부
    gop.bok_num = (a.real_num * b.bok_num) + (a.bok_num * b.real_num); //(1+2i)*(2+3i)의 허수부
    return gop;     //구조체 반환
}



int main() {
    BOK bok1,bok2, sum, gop;
    printf("복소수 입력(실수, 허수): ");
    scanf("%lf %lf", &bok1.real_num, &bok1.bok_num);
    printf("\n복소수 입력(실수, 허수): ");
    scanf("%lf %lf", &bok2.real_num, &bok2.bok_num);
    sum = Sum(bok1, bok2);
    printf("합의 결과: 실수 %lf, 허수%lf\n", sum.real_num, sum.bok_num);
    gop = Gop(bok1, bok2);
    printf("곱의 결과: 실수 %lf, 허수%lf", gop.real_num, gop.bok_num);
}