// 2729-보석상자
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int jewels[300010];
int main(void) {
	int n, m, maxNum = 0; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &jewels[i]);
		maxNum = max(maxNum, jewels[i]);
	}

	int minValue = INT_MAX, left = 1, right = maxNum;
	while (left <= right) {
		int mid = (left + right) / 2, cnt = 0;
		for (int i = 0; i < m; i++) {
			cnt += jewels[i] / mid;
			if (jewels[i] % mid) cnt++;
		}

		if (cnt <= n) {
			minValue = min(minValue, mid);
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	printf("%d", minValue);
	return 0;
}