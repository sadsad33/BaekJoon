// 11722 ���� �� �����ϴ� �κ� ����
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int arr[1010];
int main(void) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int dp[1010] = { 0 }, maxLength = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		maxLength = max(maxLength, dp[i]);
	}

	printf("%d", maxLength);
	return 0;
}