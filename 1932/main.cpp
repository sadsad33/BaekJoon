// 1932 정수 삼각형
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
			if (!j) dp[i][j] = dp[i - 1][j] + arr[i][j]; // 깊이 k의 0번 인덱스는 이전 층의 0번 인덱스를 선택했을 경우만 선택 가능
			else if (j == i) dp[i][j] = dp[i - 1][j - 1] + arr[i][j]; // 깊이 k의 마지막 인덱스는 이전층의 마지막 인덱스를 선택했을 경우만 선택 가능
			else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j]; // 나머지 인덱스들 고려
		}
	}

	int maxValue = -INT_MAX;
	for (int i = 0; i < n; i++) {
		if (dp[n - 1][i] > maxValue) maxValue = dp[n - 1][i];
	}
	printf("%d", maxValue);
}