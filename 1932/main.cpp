// 1932 Á¤¼ö »ï°¢Çü
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int arr[510][510], dp[510][510];
int main(void) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	dp[0][0] = arr[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (!j) dp[i][j] = dp[i - 1][j] + arr[i][j];
			else if (j == i) dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
			else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
		}
	}

	int maxValue = -INT_MAX;
	for (int i = 0; i < n; i++) {
		if (dp[n - 1][i] > maxValue) maxValue = dp[n - 1][i];
	}
	printf("%d", maxValue);
}