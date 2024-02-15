// 2579 계단 오르기
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int arr[301], dp[301];
int main(void) {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i];
	}

	printf("%d", dp[n]);
	return 0;
}