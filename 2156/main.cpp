#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int arr[10010], dp[10010];
int main(void) {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	// 연속한 3개의 인덱스의 값을 선택할 수는 없다.
	// 계단 문제와 다르게 몇칸이든 건너뛸 수 있다.
	// 따라서 특정 인덱스 값의 경우 선택하지 않고 건너 뛴채로 기존의 최대값을 유지하는 것이 더 이득인 경우가 존재한다.
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	int maxValue = dp[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 1], max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]));
		if (dp[i] > maxValue) maxValue = dp[i];
	}

	printf("%d\n", maxValue);
	return 0;
}