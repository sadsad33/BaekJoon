// 2170 ¼±±ß±â
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
using namespace std;
int n;
typedef struct {
	int start;
	int end;
}Line;
Line lines[1000010];

bool Compare(Line a, Line b) {
	if (a.start == b.start) return a.end < b.end;
	return a.start < b.start;
}
int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &lines[i].start, &lines[i].end);
	}

	sort(lines, lines + n, Compare);
	int minStart = lines[0].start, maxEnd = lines[0].end;
	int totalLength = 0;
	for (int i = 1; i < n; i++) {
		int newStart = lines[i].start, newEnd = lines[i].end;
		if (newStart <= maxEnd && newEnd >= maxEnd) {
			maxEnd = newEnd;
		}
		else if (newStart > maxEnd) {
			totalLength += maxEnd - minStart;
			minStart = newStart;
			maxEnd = newEnd;
		}
	}
	totalLength += maxEnd - minStart;
	printf("%d", totalLength);
	return 0;
}