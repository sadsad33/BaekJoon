// 1904 동적계획법
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int dp[1000010];
int main(void) {
	int n; scanf("%d", &n);
	dp[1] = 1, dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 15746;
	}

	printf("%d", dp[n]);
	return 0;
}