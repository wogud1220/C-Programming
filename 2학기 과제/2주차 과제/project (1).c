/*#include <stdio.h>
int main() {
	int i = 0;	//i ����
	double arrd[4] = { 12.4, 23.1, 15.7, 31.2 };	//arrd��� �迭�� 4���� �Ǽ� ����
	double* pb = arrd;	//������ pb�� arrd �ּҾȿ� �ִ� ���� ã�ư�
	for (i = 0; i < 4; i++) {	//4�� �ݺ�
		printf("%lf\n", pb[i]);	// pb�� arrd��� �迭�� ã�ư� ������� �Ǽ� ���
	}
	return  0;

}*/





/*#include <stdio.h>
int main() {

	char* p = "banana";	//������ ���ڿ� �ٳ��� ����
	int i;
	for (i = 0; i < 6; i++) {	//6�� �ݺ�
		printf("%s\n", (p + i));	//���ڿ� ���, ������ p�� ���� ������ 1�� �ڷ� �и鼭
	}
	return 0;	//�Լ� ����
}*/





/*#include <stdio.h>
int main() {
	char str1[20] = "computerprogramming";
	int i = 0;
	for (i = 0; i < 20; i++) {
		if (str1[i] == 'e') {
			printf("�迭�� ã�� e�� %d��°�� �ֽ��ϴ�.", i+1);
		}

	}

}*/

/*#include <stdio.h>
int main() {

	char* p = "computerprogramming";
	int i = 0;
	for (i = 0; i < 20; i++) {
		if (*(p + i) == 'e') {
			printf("�����ͷ� ã�� e�� %d��°�� �ֽ��ϴ�.\n", i + 1);
		}
	}
}*/