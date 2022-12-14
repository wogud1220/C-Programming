#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int arrlen = 5;
	int idx = 0;
	int i;
	int* arr = (int*)malloc(sizeof(int) * arrlen);

	while (1) {
		printf("정수 입력: ");
		scanf("%d", &arr[idx]);			//배열이니깐 붙여야됨.
		if (arr[idx] == -1) {
			break;
		}
		if (arrlen == idx + 1) {		//배열의 확장 검사
			arrlen += 3;
			arr = (int*)realloc(arr,sizeof(int) * arrlen);

		}
		idx++;
	}
	for (i = 0; i < idx; i++) {
		printf("%d ", arr[i]);
	}
	free(arr);
	return 0;
}





#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int i = 0;
	int arrlen = 5;
	int num;
	int *numarr = (int*)malloc(sizeof(int) * arrlen);
	while (1) {
		

	
		if (i == arrlen) {
			arrlen += arrlen + 3;
			numarr = (int*)realloc(numarr, sizeof(int) * arrlen);
		}

        
		printf("숫자 입력: -1은 종료");
		scanf("%d", &num);
		if (num == -1) {
			return 0;
		}
		numarr[i] = num;
		i++;
	}

	free(numarr);

}