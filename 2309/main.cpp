#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

// 9개의 수 중에서 2개의 숫자를 골라 총 합에서 차감했을때 값이 100이면 된다.
int main(void) {
	int arr[9], total = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		total += arr[i];
	}

	std::sort(arr, arr + 9);
	int succeed = 0, i, j;
	for (i = 0; i < 9; i++) {
		for (j = i + 1; j < 9; j++) {
			if (total - (arr[i] + arr[j]) == 100) {
				succeed = 1;
				break;
			}
		}
		if (succeed) break;
	}

	for (int k = 0; k < 9; k++) {
		if (k == i || k == j) continue;
		printf("%d ", arr[k]);
	}

	return 0;
}