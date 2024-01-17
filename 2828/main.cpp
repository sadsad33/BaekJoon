// 2828 사과 담기 게임
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
int n, m, appleNum, totalMoveCnt;
int targetX;
int main(void) {
	scanf("%d%d\n%d", &n, &m, &appleNum);
	int currentXLeft = 0, currentXRight = m - 1;
	while (appleNum--) {
		int x; scanf("%d", &x);
		targetX = x - 1;
		if (targetX >= currentXLeft && targetX <= currentXRight) continue;
		if (abs(targetX - currentXLeft) < abs(targetX - currentXRight)) {
			totalMoveCnt += abs(targetX - currentXLeft);
			currentXRight -= abs(targetX - currentXLeft);
			currentXLeft = targetX;
		}
		else {
			totalMoveCnt += abs(targetX - currentXRight);
			currentXLeft += abs(targetX - currentXRight);
			currentXRight = targetX;
		}
	}

	printf("%d", totalMoveCnt);
	return 0;
}