#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(void) {
	int n, k; scanf("%d%d", &n, &k);
	int arr[100001];

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int dp[100001];
	dp[0] = arr[0];
	
	for (int i = 1; i < n; i++) {
		dp[i] = dp[i - 1] + arr[i];
	}
	
	int max = dp[k - 1];
	for (int i = k; i < n; i++) {
		if (dp[i] - dp[i - k] >= max) max = dp[i] - dp[i - k];
	}

	printf("%d", max);
	return 0;
}