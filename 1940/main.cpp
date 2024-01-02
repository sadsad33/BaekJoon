#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	int n, m; scanf("%d%d", &n, &m);
	int nums[15001], remains[15001], size = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		int num; scanf("%d", &num);
		nums[i] = num;
		remains[i] = m - num;
		size++;
		if (size < 2) continue;
		else {
			for (int j = 0; j < size; j++) {
				if (remains[j] == num && num != m / 2) cnt++;
			}
		}
	}

	printf("%d", cnt);
	return 0;
}