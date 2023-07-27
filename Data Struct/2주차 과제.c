#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


typedef struct man {		//사람 구조체 생성
	char name[10];
	char sex;
	int age;

}MAN;

int pro_2() {

	MAN man[10];

	int i = 0;
	int cnt = 0;


	printf("10명의 정보를 입력하세요\n");


	for (i = 0; i < 5; i++) {		//구조체에 5명의 정보를 입력함
		printf("이름: ");
		scanf("%s", man[i].name);
		printf("\n성별(M/F): "); scanf(" %c", &man[i].sex);	
		printf("\n나이: "); scanf("%d", &man[i].age);
	}

	for (i = 0; i < 10; i++) {		//나이가 20이상 여성
		if (man[i].age >= 20 && man[i].sex == 'F') {
			printf("%d번째 사람은 20세 이상 여자입닌다.\n", i + 1);
			cnt++;
		}
		else if (man[i].age >= 20 && man[i].sex == 'M') {	//20세 이상 남성
			printf("%d번째 사람은 20세 이상 남자입니다.\n", i + 1);
			cnt++;
		}
	}
	printf("20세 이상 남녀의 수는 %d 명입니다.\n", cnt);	//총합
	return 0;
}





int pro_1() {

	printf("대문자, 소문자, 숫자, 특수문자가 모두 포함되게 입력하세요\n");
	
	char str[30];
	int i = 0;
	int num = 0;
	int small = 0;
	int big = 0;
	int special = 0;			//변수 4개에 0을 대입함.
	scanf("%s", str);

	for (i = 0; i < strlen(str); i++) {
		if (str[i] >= 48 && str[i] <= 57) {		//숫자라면 num변수에 1넣음
			num = num + 1;
			continue;
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {	//소문자라면 small변수에 1넣고
			small=small+1;
			continue;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {	//대문자라면 big변수에 1넣음
			big=big+1;
			continue;
		}
		else if (str[i] == '!' || '?' || '*' || '#' || '$') {	//특수문자라면 special 변수에 1넣음
			special=special+1;
			continue;
		}
	}								//하나라도 있으면 1이 더해져서 0이 안나오지만
	if (num == 0)					//변수의 값이 0이라면 위의 if문 충족 X
		printf("숫자가 없습니다.\n");
	else if (small == 0)
		printf("소문자가 없습니다.\n");
	else if (big == 0)
		printf("대문자가 없습니다.\n");
	else if (special == 0)
		printf("특수문자가 없습니다.\n");


	if (strlen(str) <= 10)		//글자 길이 계산
		printf("10자 이상이 아닙니다.\n");
	else
		printf("10자 이상입니다.");
	return 0;

}



int max_num(int n, int arr[]) {		//배열의 개수, 배열 매개변수
	if (n == 1)				//배열의 개수가 1개라면 그 값 리턴.
		return arr[0];
	else
		return max(arr[n - 1], max_num(n - 1, arr));		
		//끝에서 하나를 뺀 값과 다시 이 배열을 함수로 불러들여 순환하도록 만듦.
		//불러온 함수는 또 그 배열에서 하나를 빼고 또 불러들여 순환
		//이런 식으로 둘이 비교하여 최대값을 찾고 리턴함.
	}

int Pro_3() {
	int i = 0;
	int n = 5;
	int arr[5] = { 1,2,3,4,5 };			//미리 배열 선언
	/*for (i = 0; i<5; i++)
	scanf("%d", &arr[i]);*/
	printf("\n가장 큰 값은: %d", max_num(n, arr));	//개수, 배열 인자로
}

int binary_search(int arr[],int find, int size) {	//배열, 값, 사이즈를 받음

	int first, mid, end;	//처음,중간,끝 인덱스 변수 생성
	first = 0;
	end = size - 1;

	while (first <= end) {		//

		printf("처음 인덱스 [%d]  끝 인덱스 [%d]\n", arr[first], arr[end]);
		mid = (first + end) / 2;	//중간 인덱스 설정, 절반으로

		if (find == arr[mid])
			return mid;			//찾을값이 중간에 있어서 찾았다면 리턴

		else if (find > arr[mid])
			first = mid + 1;		//찾을값이 더 크다면 첫번째 인덱스를 중간보다 크게

		else if (find < arr[mid])		//찾을값이 중간보다 작다면 끝 인덱스를 중간바로 옆으로 이동
			end = mid - 1;
	}
}


int pro_4() {

	int i, find = 0;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };	//배열 선언
	printf("찾을 값을 입력해주세요");
	scanf("%d", &find);		//찾을 값 입력

	int size_arr = sizeof(arr) / 4;		//배열의 사이즈 계산
	//printf("%d", size_arr);
	printf("찾은 값은 %d번째 인덱스에 있습니다.",binary_search(arr,find,size_arr));
	//인자로 배열, 찾을 값, 배열의 크기넣고 함수를 불러옴
}




int main() {

	int problem_num = 0;
	printf("\n풀 문제 번호를 입력하세요:\n1: 알파벳 포함 문제\n2: 20세 이상 수 구하기\n3: 정수배열에서 최대값\n\
4: 이진검색\n");
	scanf("%d", &problem_num);

	switch (problem_num)
	{
	case 1:
		pro_1();
		main();
	case 2:
		pro_2();
		int main();
	case 3:
		Pro_3();
		main();
	case 4:
		pro_4();
		main();
	default:
		break;
	}
	return 0;
}

