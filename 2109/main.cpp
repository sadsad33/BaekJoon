// 2109 순회 강연
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>> arr;
int n;
int dates[100010] = { 0 }, visit[100010] = { 0 };
bool Compare(pair<int, int> a, pair<int, int>b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

int main(void) {
	scanf("%d", &n);

	int maxDeadline = 0;
	for (int i = 0; i < n; i++) {
		int d, p; scanf("%d%d", &p, &d);
		arr.push_back(make_pair(p, d));
		maxDeadline = max(maxDeadline, d);
	}
	sort(arr.begin(), arr.end(), Compare);
	int totalPay = 0;
	for (int i = 0; i < n; i++) {
		if (dates[arr[i].second]) { // 해당 날짜에 일정이 이미 있다면
			for (int date = arr[i].second; date >= 1; date--) {
				if (!dates[date] || dates[date] < arr[i].first) {
					if (!visit[i]) {
						dates[date] = arr[i].first;
						visit[i] = 1;
					}
				}
			}
		}
		else {
			dates[arr[i].second] = arr[i].first;
			visit[i] = 1;
		}
	}

	for (int i = 0; i <= maxDeadline; i++) {

		totalPay += dates[i];
	}

	printf("%d", totalPay);
	return 0;
}