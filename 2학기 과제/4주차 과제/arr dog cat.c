#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	char animal2[4][10] = { "dog","cat","horse","elephant" };


	int i;
	int cnt;
	cnt = sizeof(animal2) / 10; //sizeof(animal[0]) 1칸은 10의 크기를 가지고 있음
	for (i = 0; i < cnt; i++) {
		printf("%s\n", animal2[i]);
	}
}
//2.
	/*char animal[4][10] = {
	{'c','a','t'},
	{'d','o','g'},
	{'h','o','r','s','e'},
	{'e','l','e','p','h','a','n','t'}
	};

	int i;
	int cnt;
	cnt = sizeof(animal) / 10; //sizeof(animal[0]) 1칸은 10의 크기를 가지고 있음
	for (i = 0; i < cnt; i++) {
		printf("%s\n", animal[i]);
	}
}*/
