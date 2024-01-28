// 14002 - LIS 4
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int arr[1010];
int main(void) {
	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int dp[1010] = { 0 }, trace[1010] = { 0 }, endIndex = 0, maxLength = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		trace[i] = i;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
					trace[i] = j;
					if (dp[i] > maxLength) {
						endIndex = i;
						maxLength = dp[i];
					}
				}
			}
		}
	}

	int ans[1010] = { 0 }, index = endIndex, i = 0;
	while (true) {
		ans[i++] = arr[index];
		if (index == trace[index]) break;
		index = trace[index];
	}

	printf("%d\n", i);
	for (int j = i - 1; j >= 0; j--) {
		printf("%d ", ans[j]);
	}
	return 0;
}