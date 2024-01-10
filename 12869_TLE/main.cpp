// 12869 시간초과
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
int n, minCnt;
int arr[3], visit[60][3], damage1[6] = { 9,9,3,3,1,1 }, damage2[6] = { 3,1,1,9,3,9 }, damage3[6] = { 1,3,9,1,9,3 };
void DFS(int damageIndex, int* attackCount) {
	visit[*attackCount][0] = visit[*attackCount - 1][0] - damage1[damageIndex];
	visit[*attackCount][1] = visit[*attackCount - 1][1] - damage2[damageIndex];
	visit[*attackCount][2] = visit[*attackCount - 1][2] - damage3[damageIndex];
	(*attackCount)++;

	if (visit[*attackCount - 1][0] <= 0 && visit[*attackCount - 1][1] <= 0 && visit[*attackCount - 1][2] <= 0) {
		minCnt = minCnt > *attackCount ? *attackCount : minCnt;
		return;
	}

	for (int i = 0; i < 6; i++) {
		if (*attackCount >= minCnt - 1) continue;
		DFS(i, attackCount);
		(*attackCount)--;
	}
}

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		visit[0][i] = arr[i];
	}

	minCnt = 1 << 30;
	for (int i = 0; i < 6; i++) {
		int attackCount = 1;
		DFS(i, &attackCount);
	}

	printf("%d", minCnt-1);
	return 0;
}