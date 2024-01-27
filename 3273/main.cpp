// 3273 두 수의 합
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[100001];
int main(void) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int x; scanf("%d", &x);
	sort(arr, arr + n);
	int leftIndex = 0, rightIndex = n - 1, cnt = 0;
	while (leftIndex < rightIndex) {
		if (arr[leftIndex] + arr[rightIndex] > x) rightIndex--;
		else if (arr[leftIndex] + arr[rightIndex] < x) leftIndex++;
		else {
			leftIndex++; rightIndex--;
			cnt++;
		}
	}

	printf("%d", cnt);
	return 0;
}