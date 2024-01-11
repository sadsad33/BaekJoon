#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <cstring>
#include <limits.h>
using namespace std;
int damage1[6] = { 9,9,3,3,1,1 };
int damage2[6] = { 3,1,9,1,9,3 };
int damage3[6] = { 1,3,1,9,3,9 };
int dp[61][61][61];
int main(void) {
	int n; scanf("%d", &n);
	int arr[3];
	memset(arr, 0, sizeof(int) * 3);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int minCnt = INT_MAX;
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(arr[0], arr[1], arr[2]));
	while (!q.empty()) {
		int first = get<0>(q.front());
		int second = get<1>(q.front());
		int third = get<2>(q.front());
		if (first < 1 && second < 1 && third < 1) minCnt = min(minCnt, dp[first][second][third]);
		q.pop();
		
		for (int i = 0; i < 6; i++) {
			int newFirst = max(0, first - damage1[i]);
			int newSecond = max(0, second - damage2[i]);
			int newThird = max(0, third - damage3[i]);
			if (dp[newFirst][newSecond][newThird] && dp[newFirst][newSecond][newThird] <= dp[first][second][third] + 1) continue;
			dp[newFirst][newSecond][newThird] = dp[first][second][third] + 1;
			q.push(make_tuple(newFirst, newSecond, newThird));
		}
	}

	printf("%d", minCnt);
	return 0;
}