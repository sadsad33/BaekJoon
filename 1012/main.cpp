#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int n, m, k;
int map[50][50], visit[50][50];
void DFS(int y, int x) {
	if (!map[y][x]) return;

	int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0 ,-1, 0, 1 };
	for (int i = 0; i < 4; i++) {
		int nextY = y + dy[i], nextX = x + dx[i];
		if (visit[nextY][nextX]) continue;
		if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) continue;
		visit[nextY][nextX] = 1;
		DFS(nextY, nextX);
	}
}

int main(void) {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < n; i++) {
			memset(map[i], 0, sizeof(int) * m);
			memset(visit[i], 0, sizeof(int) * m);
		}
		while (k--) {
			int row, col; scanf("%d%d", &row, &col);
			map[row][col] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] && !visit[i][j]) {
					visit[i][j] = 1;
					DFS(i, j);
					cnt++;
				}
			}
		}

		printf("%d\n", cnt);
	}
	return 0;
}