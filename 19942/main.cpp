#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int n, minCost;
vector<int> records, visit;
int arr[15][5], quota[4];
void DFS(int startIndex, int cost) {
	int succeed = 0, recordIndex = 0, prefixSum[4] = { 0, 0, 0, 0 };
	for (const auto& iter : visit) {
		prefixSum[0] += arr[iter][0];
		prefixSum[1] += arr[iter][1];
		prefixSum[2] += arr[iter][2];
		prefixSum[3] += arr[iter][3];
		recordIndex |= 1 << iter;
	}

	if (prefixSum[0] >= quota[0] && prefixSum[1] >= quota[1] && prefixSum[2] >= quota[2] && prefixSum[3] >= quota[3]) succeed = 1;
	if (succeed && cost < minCost) { // 백트래킹을 할때, 인덱스를 앞에서 부터 검사하므로 값이 더 작은데 인덱스도 더 작은 경우가 이미 앞에 존재할 수 없음
		minCost = min(minCost, cost);
		records.push_back(recordIndex);
		return;
	}

	for (int i = startIndex; i < n; i++) {
		visit.push_back(i);
		DFS(i + 1, cost + arr[i][4]);
		visit.pop_back();
	}
}
int main(void) {
	minCost = INT_MAX;
	scanf("%d", &n);
	for (int i = 0; i < 4; i++) {
		scanf("%d", &quota[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	DFS(0, 0);
	if (minCost != INT_MAX) {
		printf("%d\n", minCost);
		for (int i = 0; i < n; i++) {
			if (records.back() & 1 << i) printf("%d ", i + 1);
		}
	}
	else printf("-1\n");
	return 0;
}