#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

// 각 집 좌표에서 각 치킨집 좌표까지의 거리를 백트래킹하며 구할 필요는 없다...
int n, m;
vector<pair<int, int>>house, chicken;
vector<vector<int>>positions; // 가능한 m개의 치킨집 조합을 저장할 벡터

// 치킨집중 m개를 선택한다.
// 뽑힌 순서와 관계없이 동일한 조합을 뽑으면 안됨
// 이전에 뽑은 인덱스값을 넘겨받음으로써 방문처리를 하지 않아도 동일 조합을 걸러낼수 있다.
void Select(int index, vector<int> v) {
	if (v.size() == m) {
		// m개 선택을 완료하면 해당 수열을 기록
		positions.push_back(v);
		return;
	}

	for (int i = index + 1; i < chicken.size(); i++) {
		v.push_back(i);
		Select(i, v);
		v.pop_back();
	}
}
int main(void) {
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num; scanf("%d", &num);
			if (num == 1) house.push_back(make_pair(i, j));
			else if (num == 2) chicken.push_back(make_pair(i, j));
		}
	}

	vector<int> v;
	Select(-1, v);


	int totalDistance = 0, totalMinDistance = 1 << 30;
	for (const auto& coordinates : positions) { // 치킨집 좌표 조합중 하나를 꺼냄
		totalDistance = 0;
		for (int i = 0; i < house.size(); i++) { // 모든 집들의 좌표를 순회
			int minDistance = 1 << 30;
			for (int j = 0; j < coordinates.size(); j++) { // 꺼내온 치킨집 좌표 조합을 순회하며 각 집과의 최소 거리를 구한다
				int distance = abs(chicken[coordinates[j]].first - house[i].first) + abs(chicken[coordinates[j]].second - house[i].second);
				minDistance = minDistance > distance ? distance : minDistance;
			}
			totalDistance += minDistance;
		}
		totalMinDistance = totalMinDistance > totalDistance ? totalDistance : totalMinDistance;
	}

	printf("%d", totalMinDistance);
	return 0;
}