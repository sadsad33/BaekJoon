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

	// ������ 3���� �ε����� ���� ������ ���� ����.
	// ��� ������ �ٸ��� ��ĭ�̵� �ǳʶ� �� �ִ�.
	// ���� Ư�� �ε��� ���� ��� �������� �ʰ� �ǳ� ��ä�� ������ �ִ밪�� �����ϴ� ���� �� �̵��� ��찡 �����Ѵ�.
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