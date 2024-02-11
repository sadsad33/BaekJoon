// 1149 동적 계획법
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int costs[1010][3], dp[1010][3];
int main(void) {
	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &costs[i][0], &costs[i][1], &costs[i][2]);
	}

	dp[0][0] = costs[0][0];
	dp[0][1] = costs[0][1];
	dp[0][2] = costs[0][2];

	for (int i = 1; i < n; i++) {
		dp[i][0] = costs[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] += costs[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] += costs[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}

	printf("%d", min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])));
	return 0;
}