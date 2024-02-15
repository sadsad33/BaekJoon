// 2343 ��Ÿ ����
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int arr[100010];
int Check(int mid, int maxLength) {
	if (maxLength > mid) return 0; // ������ ���� ���� ���Ѿ��� ���� ū ������ ������ ����
	int temp = mid;
	int cnt = 0;
	// ���Ƿ� ���� ������ �迭�� ���� �ϳ��� ���鼭 ���� 0���� �۾����� ī��Ʈ
	for (int i = 0; i < n; i++) {
		if (mid - arr[i] < 0) {
			mid = temp;
			cnt++;
		}
		mid -= arr[i];
	}
	// ��� ���� ���µ��� 0�� �����ʴ´ٸ� �ϳ��� �������� �ִ� ���̹Ƿ� ī��Ʈ
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
		int mid = (left + right) / 2; // 0�� ���� �� ������ ������ ���� ����
		if (Check(mid, maxLength)) {
			right = mid - 1;
			ans = mid;
		}
		else left = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}