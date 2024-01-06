#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
int n, m;
int city[50][50], visit[50][50];
int minDistance, houseNum, chickenNum, chickenCur;
map<pair<int, int>, int> pos[50]; // 모든 집의 좌표로부터 도달할 수 있는 치킨 집들의 좌표(key)와 거리(value)를 저장
vector<pair<int, int>> v;
void Sum() {
	int total = 0;
	for (int i = 0; i < houseNum; i++) {
		int min = 1 << 30;
		for (unsigned long int j = 0; j < v.size(); j++) {
			int temp = pos[i].at(v[j]);
			if (temp < min) min = temp;
		}
		total += min;
	}
	if (total < minDistance)minDistance = total;
}

void Select() {
	if (v.size() == (unsigned long int)m) {
		Sum();
		return;
	}

	// 치킨 집의 좌표들 중 m개를 선택
	for (const auto& iter : pos[0]) {
		if (visit[iter.first.first][iter.first.second]) continue;
		visit[iter.first.first][iter.first.second] = 1;
		v.push_back(make_pair(iter.first.first, iter.first.second));
		Select();
		v.pop_back();
		visit[iter.first.first][iter.first.second] = 0;
	}
}

void Move(int y, int x, int* curDistance, int index) {
	if (city[y][x] == 2) {
		chickenCur++;
		pair<int, int>coord = make_pair(y, x);
		if (pos[index][coord])
			pos[index][coord] = pos[index][coord] > *curDistance ? *curDistance : pos[index][coord];
		else
			pos[index][coord] = *curDistance;
		if (chickenCur == chickenNum)
			return;
	}

	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, -1, 0, 1 };

	for (int i = 0; i < 4; i++) {
		int nextY = y + dy[i], nextX = x + dx[i];
		if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) continue;
		if (visit[nextY][nextX]) continue;
		visit[nextY][nextX] = 1;
		*curDistance += 1;
		Move(nextY, nextX, curDistance, index);
		*curDistance -= 1;
		visit[nextY][nextX] = 0;
	}
}

int main(void) {
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &city[i][j]);
			if (city[i][j] == 2) chickenNum++;
		}
	}

	int index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (city[i][j] == 1) {
				visit[i][j] = 1;
				int curDistance = 0;
				Move(i, j, &curDistance, index);
				visit[i][j] = 0;
				index++;
			}
		}
	}
	houseNum = index;
	for (int i = 0; i < n; i++)
		memset(visit[i], 0, sizeof(int) * n);

	minDistance = 1 << 30;
	Select();
	printf("%d", minDistance);
	return 0;
}