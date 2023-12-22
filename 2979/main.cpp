#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
int main(void) {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int begins[3], ends[3];
	for (int i = 0; i < 3; i++) {
		scanf("%d%d", &begins[i], &ends[i]);
	}

	int cnt = 0, total = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 0; j < 3; j++) {
			if (begins[j] == i) {
				cnt++;
			}if (ends[j] == i) {
				cnt--;
			}
		}
		if (cnt == 0)continue;
		if (cnt == 1) total += a;
		else if (cnt == 2) total += b * cnt;
		else if (cnt == 3) total += c * cnt;
	}

	printf("%d", total);
	return 0;
}