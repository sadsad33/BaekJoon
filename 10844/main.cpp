#include <iostream>
#include <vector>
using namespace std;

// dp[n][m] : n번째 자리의 수가 m일 경우 최대 계단수의 개수
int dp[101][10];
int main(void) {
	int n; scanf("%d", &n);

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j + 1] % 1000000000;
			else if (j == 9) dp[i][j] = dp[i - 1][j - 1] % 1000000000;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}

	int ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans = (ans + dp[n][i]) % 1000000000;
	}
	printf("%d", ans);
	return 0;
}