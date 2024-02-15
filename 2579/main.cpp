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

	// 연속된 세개의 계단을 모두 밟을수는 없다
	// n 번째 계단을 검사할때 (n-2 번째까지의 최대값)과 (n-3 번째까지의 최대값 + n-1번째 계단의 값)을 비교하여 더 큰쪽에 현재 계단의 값을 더해주면 세개의 계단을 연속으로 밟는일이 없다.
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i];
	}

	printf("%d", dp[n]);
	return 0;
}