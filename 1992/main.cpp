#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int n;
char arr[65][65];
int totalDivideCnt, divideCnt;
void DFS(int y, int x, int size) {
	if (size != n && totalDivideCnt < divideCnt) {
		totalDivideCnt = divideCnt;
		printf("(");
	}

	int one = 0, zero = 0;

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (arr[i][j] == '1') one = 1;
			if (arr[i][j] == '0') zero = 1;
		}
	}

	// 현재 범위를 1혹은 0으로 압축할수 없다면 분할
	if (one && zero) {
		divideCnt += 1;
		DFS(y, x, size / 2);
		DFS(y, x + size / 2, size / 2);
		DFS(y + size / 2, x, size / 2);
		DFS(y + size / 2, x + size / 2, size / 2);
		printf(")");
	}
	else if (one) printf("1");
	else printf("0");
}

int main(void) {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i]);
	}

	int size = n;
	DFS(0, 0, n);
}