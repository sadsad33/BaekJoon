//1912 동적계획법
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int n, arr[100010], dp[100010];
int main(void) {
	scanf("%d", &n);
	int maxValue = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	dp[0] = arr[0];
	maxValue = dp[0];
	for (int i = 1; i < n; i++) {
		if (dp[i - 1] + arr[i] <= arr[i])
			dp[i] = arr[i];
		else
			dp[i] = dp[i - 1] + arr[i];
		maxValue = max(maxValue, dp[i]);
	}

	printf("%d", maxValue);
	return 0;
}