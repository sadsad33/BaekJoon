#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int n;
int visit[15];
int board[15][15];

int Check(int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] && abs(row- i) == abs(col - j )) return 0;
		}
	}
	return 1;
}

void Select(int row, int col, int* cnt) {
	if (row == n) {
		(*cnt)++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visit[i]) continue;
		if (!Check(row, i)) continue;
		visit[i] = 1;
		board[row][i] = 1;
		Select(row + 1, i, cnt);
		visit[i] = 0;
		board[row][i] = 0;
	}
}

int main(void) {
	scanf("%d", &n);

	int cnt = 0;
	Select(0, 0, &cnt);

	printf("%d", cnt);
	return 0;
}