// 11053 가장 긴 증가하는 부분 수열
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
int arr[1010];
int main(void) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int dp[1010], ans = -INT_MAX;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
	printf("%d", ans);
	return 0;
}