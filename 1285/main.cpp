// 1285 동전 뒤집기
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<limits.h>
#include<cstring>
using namespace std;
int n;
char arr[21][21];
int row[20], minCnt;

void DFS(int selectedRow, int reverse) {
	if (selectedRow >= n) return;

	if (reverse) row[selectedRow] = ~row[selectedRow];
	int colTailCnt[20], totalTailCnt = 0;
	memset(colTailCnt, 0, sizeof(int) * 20);

	for (int c = 0; c < n; c++) { // 열
		for (int r = 0; r < n; r++) { // 행
			if (row[r] & 1 << c) colTailCnt[c]++; // c번째 열을 순회하며 뒷면의 개수 세기
		}
		if (colTailCnt[c] > n - colTailCnt[c]) { // c번째 열을 뒤집었을때 뒷면의 개수가 더 적다면 뒤집는다
			for (int r = 0; r < n; r++) {
				if (row[r] & 1 << c) row[r] &= ~(1 << c);
				else row[r] |= 1 << c;
			}
			colTailCnt[c] = n - colTailCnt[c];
		}
		totalTailCnt += colTailCnt[c];
	}
	minCnt = min(minCnt, totalTailCnt);

	DFS(selectedRow + 1, 1);
	DFS(selectedRow + 1, 0);
}
int main(void) {
	minCnt = INT_MAX;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char temp[21]; scanf("%s", temp);
		for (int j = 0; j < n; j++) {
			arr[i][j] = temp[j];
			if (arr[i][j] == 'T') {
				row[i] |= 1 << j;
			}
		}
	}

	DFS(0, 0);
	DFS(0, 1);

	printf("%d", minCnt);
	return 0;
}