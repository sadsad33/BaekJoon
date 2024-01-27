// 2776 - ¾Ï±â¿Õ
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int note1[1000010], note2[1000010];

int BinarySearch(int target, int size) {
	int left = 0, right = size - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (note1[mid] < target) left = mid + 1;
		else if (note1[mid] > target) right = mid - 1;
		else return 1;
	}
	return 0;
}

int main(void) {
	int t; scanf("%d", &t);

	while (t--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &note1[i]);
		}

		sort(note1, note1 + n);
		int m; scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d", &note2[i]);

			printf("%d\n", BinarySearch(note2[i], n));
		}
	}
	return 0;
}