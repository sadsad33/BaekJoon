#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <limits.h>
#include <cstring>
#include <queue>
using namespace std;
int visit[51][51];
int main(void) {
	char map[51][51];
	int sizeRow, sizeCol; scanf("%d%d", &sizeRow, &sizeCol);

	for (int i = 0; i < sizeRow; i++) {
		scanf("%s", &map[i]);
		memset(visit[i], -1, sizeof(int) * sizeCol);
	}

	int maxDistance = -INT_MAX;
	int dy[4] = { -1,0,1,0 }, dx[4] = { 0,-1,0,1 };
	for (int row = 0; row < sizeRow; row++) {
		for (int col = 0; col < sizeCol; col++) {
			if (map[row][col] == 'L') {
				visit[row][col] = 0;
				queue<pair<int, int>>q;
				q.push(make_pair(row, col));

				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					maxDistance = max(maxDistance, visit[y][x]);
					q.pop();

					for (int i = 0; i < 4; i++) {
						int nextY = y + dy[i], nextX = x + dx[i];
						if (nextY < 0 || nextY >= sizeRow || nextX < 0 || nextX >= sizeCol) continue;
						if (map[nextY][nextX] == 'W') continue;
						if (visit[nextY][nextX] >= 0) continue;
						visit[nextY][nextX] = visit[y][x] + 1;
						q.push(make_pair(nextY, nextX));
					}
				}
			}
			for (int i = 0; i < sizeRow; i++) // 이게 되네
				memset(visit[i], -1, sizeof(int) * sizeCol);
		}


	}
	printf("%d", maxDistance);
	return 0;
}