// 2343 기타 레슨
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int arr[100010];
int Check(int mid, int maxLength) {
	if (maxLength > mid) return 0; // 임의의 값이 포함 시켜야할 가장 큰 수보다 작으면 실패
	int temp = mid;
	int cnt = 0;
	// 임의로 정한 값에서 배열의 수중 하나씩 빼면서 만약 0보다 작아지면 카운트
	for (int i = 0; i < n; i++) {
		if (mid - arr[i] < 0) {
			mid = temp;
			cnt++;
		}
		mid -= arr[i];
	}
	// 모든 수를 뺐는데도 0이 되지않는다면 하나로 묶을수는 있는 것이므로 카운트
	if (mid != temp) cnt++;
	return cnt <= m;
}
int main(void) {
	scanf("%d%d", &n, &m);
	int maxLength = 0, totalLength = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		totalLength += arr[i];
		maxLength = max(maxLength, arr[i]);
	}

	int left = 0, right = totalLength, ans;
	while (left <= right) {
		int mid = (left + right) / 2; // 0과 총합 값 사이의 임의의 값을 선택
		if (Check(mid, maxLength)) {
			right = mid - 1;
			ans = mid;
		}
		else left = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}