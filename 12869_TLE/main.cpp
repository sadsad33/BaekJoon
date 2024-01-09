// 12869 시간초과
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
int n, min;
int arr[3], original[3], damage[3] = { 9, 3, 1 };
void DFS(int index, int* attackCount) {
	int succeed = 0, fail = 0;

	for (int i = index; i < index + n; i++) {
		arr[i % n] -= damage[i - index];
		if (arr[i % n] < 1) succeed = 1;
		if (arr[i % n] >= 1) fail = 1;
	}
	(*attackCount)++;

	if (min != 1 << 30 && *attackCount >= min) return;

	if (succeed && !fail) {
		min = min > *attackCount ? *attackCount : min;
		return;
	}

	for (int i = index; i < index + n; i++) {
		DFS(i % n, attackCount);
		(*attackCount)--;
		for (int j = index; j < index + n; j++) {
			arr[j % n] += damage[j - index];
		}
	}
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &original[i]);
		arr[i] = original[i];
	}
	min = 1 << 30;
	for (int i = 0; i < n; i++) {
		int attackCount = 0;
		DFS(i, &attackCount);
	}
	printf("%d", min);
	return 0;
}