// 12738 LIS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int arr[1000010], ans[1000010];

// 위치 탐색과 재구성
void Search(int v[], int lastIndex, int i) {
	int left = 0, right = lastIndex;
	int index = 0;
	while (left <= right) {
		int mid = (left + right) / 2;

		if (v[mid] >= arr[i]) {
			index = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}
	v[index] = arr[i];
}
int main(void) {
	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	int index = 0;
	ans[index] = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > ans[index]) ans[++index] = arr[i];
		else Search(ans, index, i);
	}

	return 0;
}