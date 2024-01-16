//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <limits.h>
//#include <cstring>
//#include <queue>
//using namespace std;
//int main(void) {
//	int visit[51][51] = { 0 };
//	char map[51][51];
//	int sizeRow, sizeCol; scanf("%d%d", &sizeRow, &sizeCol);
//
//	for (int i = 0; i < sizeRow; i++) {
//		scanf("%s", &map[i]);
//		memset(visit[i], -1, sizeof(int) * sizeCol);
//	}
//
//	int maxDistance = -INT_MAX;
//	int dy[4] = { -1,0,1,0 }, dx[4] = { 0,-1,0,1 };
//	for (int row = 0; row < sizeRow; row++) {
//		for (int col = 0; col < sizeCol; col++) {
//			if (map[row][col] == 'L') {
//				queue<pair<int, int>>q;
//				visit[row][col] = 0;
//				q.push(make_pair(row, col));
//
//				while (!q.empty()) {
//					int y = q.front().first;
//					int x = q.front().second;
//					q.pop();
//					maxDistance = max(maxDistance, visit[y][x]);
//					for (int i = 0; i < 4; i++) {
//						int nextY = y + dy[i], nextX = x + dx[i];
//						if (!visit[nextY][nextX]) continue;
//						if (visit[nextY][nextX] >= 0 && visit[nextY][nextX] <= visit[y][x] + 1) continue;
//						if (nextY < 0 || nextY >= sizeRow || nextX < 0 || nextX >= sizeCol) continue;
//						if (map[nextY][nextX] == 'W') continue;
//						visit[nextY][nextX] = visit[y][x] + 1;
//						q.push(make_pair(nextY, nextX));
//					}
//				}
//				visit[row][col] = -1;
//			}
//		}
//	}
//	printf("%d", maxDistance);
//	return 0;
//}