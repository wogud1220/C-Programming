#include <stdio.h>
int main() {
	char str1[20] = "computerprogramming";
	int i = 0;
	for (i = 0; i < 20; i++) {
		if (str1[i] == 'e') {
			printf("배열로 찾은 e는 %d번째에 있습니다.", i+1);
			break;
		}
		
	}

}

/*#include <stdio.h>
int main() {

	char* p = "computerprogramming";
	int i = 0;
	for (i = 0; i < 20; i++) {
		if (*(p+i) == 'e') {
			printf("포인터로 찾은 e는 %d번째에 있습니다.\n", i + 1);
			break;
		}
	}
}*/