#include <stdio.h>
int main() {
	char str1[20] = "computerprogramming";
	int i = 0;
	for (i = 0; i < 20; i++) {
		if (str1[i] == 'e') {
			printf("�迭�� ã�� e�� %d��°�� �ֽ��ϴ�.", i+1);
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
			printf("�����ͷ� ã�� e�� %d��°�� �ֽ��ϴ�.\n", i + 1);
			break;
		}
	}
}*/