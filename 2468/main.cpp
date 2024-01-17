// 2468 안전영역
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <limits.h>

int n;
int heights[101][101], visit[101][101];
void DFS(int y, int x, int rain, int* cnt) {
	if (heights[y][x] <= rain) {
		return;
	}

	int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, -1 , 0, 1 };
	for (int i = 0; i < 4; i++) {
		int nextY = y + dy[i], nextX = x + dx[i];
		if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) continue;
		if (visit[nextY][nextX] == rain) continue;
		visit[nextY][nextX] = rain;
		DFS(nextY, nextX, rain, cnt);
	}
}
int main(void) {
	scanf("%d", &n);

	int maxHeight = -INT_MAX;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &heights[i][j]);
			maxHeight = maxHeight < heights[i][j] ? heights[i][j] : maxHeight;
			visit[i][j] = 101;
		}
	}

	int rain = 1, maxArea = 1;
	while (rain < maxHeight) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == rain || heights[i][j] <= rain) continue;
				visit[i][j] = rain;
				DFS(i, j, rain, &cnt);
				cnt++;
			}
		}
		rain++;
		maxArea = maxArea < cnt ? cnt : maxArea;
	}
	printf("%d", maxArea);
	return 0;
}