/*답안 확인했습니다.

함수 작성이 2개가 있었고, 둘 다 필요한 데이터를 매개변수로 넘겨주고, 반환값을 받아서 활용하는 거였는데 매개변수나 리턴값 없이 구현을 해서 감점이 좀 있습니다.
그리고 int check(void) 라고 정의를 했을 때 int가 의미하는 것은 return값(반환값)으로 정수를 받겠다는 의미이므로, 'return 정수'를 해줘야 합니다.
제가 의도한 것은 놀이기구를 탈 수 있을 때는 return 1; 탈 수 없을 때는 return 0;을 해서 
if (check(height, age)) {
    printf("탑승 가능");
}
이런 거였는데... 놀이기구 운행 순서도요...1->3->2->5->4번 놀이기구 순서로 타면 된다...이런 식의 답을 찾는데
함수 nol에 매개변수로 arr을 넘겨주게끔 하라는 의도였어요.

전역변수는 110, 8 이것을 전역변수로 선언해놓고 입력받는 height, age와 비교하라는 의미였고요 (실제로 구현하면 이건 const int limit_height = 110 이런 식으로 상수로 선언되겠지만...)

전역변수선언(-3), check()에 매개변수넘기기(-3), check()에서 리턴값받기(-3), ===> -7
놀이기구운행시간배열을 매개변수로 넘기기(-3), 타는순서 리턴(-3) ===> -6
이렇게 감점했습니다.
그래도 전체성적 3등이네요. 한 학기 동안 고생 많았습니다.




2020년 7월 6일 (월) 오후 5:59, 윤재형 <jack001220@naver.com>님이 작성:
혹시 몰라서 코드도 따로 보내겠습니다.

 
*/
 

#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

int old;

int height;

int main(void)

{

	printf("나이와 키를 입력하세요"); // 나이와 키 입력하세요 출력

	scanf_s("나이:%d  키:%d", &old, &height);//나이와 키 입력받아서 저장

	check(); //나이와 키를 검사하는 함수 불러옴

	nol();  //nol(놀이기구의 시간을 입력) 함수 불러옴

}

int check(void)

{

	scanf_s("%d %d", &old, &height);// 나이와 키 입력받음

	if (old > 7 && height > 109)//나이 8이상 키 110이상 만족한다면

		printf("탑승 가능\n");// 탑승 가능 출력

	else

		printf("탑승 불가능\n");// 탑승 불가능 출력

	return;

}

int nol(void) {

	printf("놀이기구 동작 시간(분)을 입력하세요");//놀이기구 동작 분 입력하기

	int arr[5];						//5개 놀이기구의 시간 배열 저장

	int i;

	int temp, j;

	for (i = 0; i < 5; i++) {		// 배열에 들어가는 반복문

		scanf_s("%d", &arr[i]);		//5개의 배열에 들어가는 수 입력

	}

	printf("%d분\n", arr[0]);	// 배열에 저장된 놀이기구의 1~5가지의 시간 저장

	printf("%d분\n", arr[1]);

	printf("%d분\n", arr[2]);

	printf("%d분\n", arr[3]);

	printf("%d분\n", arr[4]);

 

	for (i = 0; i < 5 - 1; i++) // 무작위로 입력된 시간 크기에 따라 정렬하는 반복문

	{

		for (j = 0; j < 5 - 1 - i; j++)

		{

			if (arr[j] > arr[j + 1])

			{

				temp = arr[j];

				arr[j] = arr[j + 1];

				arr[j + 1] = temp;

			}

		}

	}

	printf("시간에 따른 놀이기구를 먼저 타야하는 순서 : \n");

	int a = 1;

	for (int i = 0; i < 5; i++)

	{

		printf("%d번째: %d분에 운행하는 놀이기구\n ", a, arr[i]);// 무작위로 입력된 시간 오름차순으로 정렬

		a++;

	}

	return;

}

 

 



--
이애리 010-2741-3501