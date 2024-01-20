// 1931 회의실 배정
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	int start;
	int end;
}Time;

int n;
Time timeTable[100001];

int Compare(Time a, Time b) {
	if (a.end == b.end)
		return a.start < b.start;
	else
		return a.end < b.end;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &timeTable[i].start, &timeTable[i].end);
	}

	sort(timeTable, timeTable + n, Compare);

	int totalCnt = 1, index = 1;
	int endTime = timeTable[0].end;
	while (index < n) {
		if (timeTable[index].start >= endTime) {
			totalCnt++;
			endTime = timeTable[index].end;
		}
		index++;
	}

	printf("%d", totalCnt);
	return 0;
}