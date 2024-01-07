#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;

int n, m;
int maze[100][100], visit[100][100];
int main(void) {
	scanf("%d%d", &n, &m);
	char temp[100];
	for (int i = 0; i < n; i++) {
		scanf("%s", temp);
		for (int j = 0; j < m; j++) {
			maze[i][j] = (int)temp[j] - 48;
		}
	}

	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,-1,0,1 };

	queue<pair<int, int>>q;
	visit[0][0] = 1;
	q.push(make_pair(0, 0));

	while (!q.empty()) {
		pair<int, int>pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = pos.first + dy[i];
			int nextX = pos.second + dx[i];

			if (visit[nextY][nextX]) continue;
			if (!maze[nextY][nextX] || nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) continue; 
			visit[nextY][nextX] = visit[pos.first][pos.second] + 1; 
			q.push(make_pair(nextY, nextX));
		}
	}

	printf("%d", visit[n - 1][m - 1]);
	return 0;
}