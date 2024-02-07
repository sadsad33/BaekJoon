// 4811 ¾Ë¾à
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
long long dp[31][31];
int main(void) {

	for (int h = 0; h <= 30; h++) {
		for (int w = 0; w <= 30; w++) {
			if (h > w) continue;
			if (h == 0) dp[w][h] = 1;
			else dp[w][h] = dp[w - 1][h] + dp[w][h - 1];
		}
	}

	while (1) {
		int input; scanf("%d", &input);
		if (!input) break;
		printf("%lld\n", dp[input][input]);
	}
	return 0;
}