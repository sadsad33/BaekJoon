#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

// �� �� ��ǥ���� �� ġŲ�� ��ǥ������ �Ÿ��� ��Ʈ��ŷ�ϸ� ���� �ʿ�� ����...
int n, m;
vector<pair<int, int>>house, chicken;
vector<vector<int>>positions; // ������ m���� ġŲ�� ������ ������ ����

// ġŲ���� m���� �����Ѵ�.
// ���� ������ ������� ������ ������ ������ �ȵ�
// ������ ���� �ε������� �Ѱܹ������ν� �湮ó���� ���� �ʾƵ� ���� ������ �ɷ����� �ִ�.
void Select(int index, vector<int> v) {
	if (v.size() == m) {
		// m�� ������ �Ϸ��ϸ� �ش� ������ ���
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
	for (const auto& coordinates : positions) { // ġŲ�� ��ǥ ������ �ϳ��� ����
		totalDistance = 0;
		for (int i = 0; i < house.size(); i++) { // ��� ������ ��ǥ�� ��ȸ
			int minDistance = 1 << 30;
			for (int j = 0; j < coordinates.size(); j++) { // ������ ġŲ�� ��ǥ ������ ��ȸ�ϸ� �� ������ �ּ� �Ÿ��� ���Ѵ�
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