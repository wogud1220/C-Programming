#include <stdio.h>
int main() {

	char* p = "banana";	//������ ���ڿ� �ٳ��� ����
	int i;
	for (i = 0; i < 6; i++) {	//6�� �ݺ�
		printf("%s\n", (p+i));	//���ڿ� ���, ������ p�� ���� ������ 1�� �ڷ� �и鼭
	}
	return 0;	//�Լ� ����
}