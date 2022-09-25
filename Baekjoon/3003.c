#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int king, queen, rook, shop, knight, pone;
	int k, q, r, s, n, p;
	k = 1, q = 1, r = 2, s = 2, n = 2, p = 8;
	scanf("%d %d %d %d %d %d",&king, &queen,&rook,&shop, &knight,&pone);
	printf("%d %d %d %d %d %d", k - king, q - queen, r - rook, s - shop, n - knight, p - pone);

}