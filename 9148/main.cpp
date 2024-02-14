// 9184 신나는 함수 실행
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int dp[51][51][51];
int W(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1; // 기저
	if (a > 20 || b > 20 || c > 20) return W(20, 20, 20);

	// 해당 값이 존재하면 바로 반환
	if (dp[a][b][c]) return dp[a][b][c];

	// 기록하기
	if (a < b && b < c) return dp[a][b][c] = W(a, b, c - 1) + W(a, b - 1, c - 1) - W(a, b - 1, c);
	else return dp[a][b][c] = W(a - 1, b, c) + W(a - 1, b - 1, c) + W(a - 1, b, c - 1) - W(a - 1, b - 1, c - 1);
}
int main(void) {
	int a, b, c;
	while (1) {
		scanf("%d%d%d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1) break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, W(a, b, c));
	}
}