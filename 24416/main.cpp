// 24416 피보나치수 1
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int n, fibCnt = 0, fibonacciCnt = 0;
int dp[41];
int fib(int n) {
	if (n == 1 || n == 2) {
		fibCnt++;
		return 1;
	}
	else return fib(n - 1) + fib(n - 2);
}

int fibonacci(int n) {
	dp[1] = 1, dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		fibonacciCnt++;
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int main(void) {
	scanf("%d", &n);
	fib(n); fibonacci(n);
	printf("%d %d", fibCnt, fibonacciCnt);
	return 0;
}