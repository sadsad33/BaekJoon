//9461 파도반 수열
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

long long dp[110];
int main(void) {
	int t; scanf("%d", &t);
	dp[0] = 0, dp[1] = 1, dp[2] = 1, dp[3] = 1, dp[4] = 2;
	for (int i = 5; i <= 100; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	while (t--) {
		int input; scanf("%d", &input);
		printf("%lld\n", dp[input]);
	}
	return 0;
}