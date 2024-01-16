#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int sizeRow, sizeCol, rectNum;
int arr[101][101], visit[101][101];
void DFS(int y, int x, int* width) {
	int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, -1, 0, 1 };
	for (int i = 0; i < 4; i++) {
		int nextY = y + dy[i], nextX = x + dx[i];
		if (nextY < 0 || nextY >= sizeRow || nextX < 0 || nextX >= sizeCol) continue;
		if (arr[nextY][nextX] || visit[nextY][nextX]) continue;
		visit[nextY][nextX] = 1;
		*width += 1;
		DFS(nextY, nextX, width);
	}
}
int main(void) {
	scanf("%d%d%d", &sizeRow, &sizeCol, &rectNum);

	for (int i = 0; i < rectNum; i++) {
		int leftBotX, leftBotY, rightTopX, rightTopY; scanf("%d%d%d%d", &leftBotX, &leftBotY, &rightTopX, &rightTopY);
		for (int y = leftBotY; y < rightTopY; y++) {
			for (int x = leftBotX; x < rightTopX; x++) {
				arr[y][x] = 1;
			}
		}
	}
	int areaCnt = 0;
	vector<int> v;
	for (int i = 0; i < sizeRow; i++) {
		for (int j = 0; j < sizeCol; j++) {
			if (!arr[i][j] && !visit[i][j]) {
				int width = 0;
				visit[i][j] = 1;
				DFS(i, j, &width);
				width += 1;
				areaCnt++;
				if (width) v.push_back(width);
			}
		}
	}

	sort(v.begin(), v.end());
	printf("%d\n", areaCnt);
	for (int i = 0; i < v.size(); i++)
		printf("%d ", v[i]);
	return 0;
}