// 1463 1로 만들기
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int dp[1000010];
int main(void) {
	int n; scanf("%d", &n);

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i < 1000001; i++) {
		dp[i] = dp[i - 1] + 1;
		if (!(i % 3)) dp[i] = min(dp[i / 3] + 1, dp[i]);
		if (!(i % 2)) dp[i] = min(dp[i / 2] + 1, dp[i]);
	}

	printf("%d", dp[n]);
	return 0;
}