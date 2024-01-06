#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
using namespace std;
int arr[8], visit[8];
vector<int> v;
int n, m;

void Print() {
	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
}
void Select() {
	if (v.size() == m) {
		Print();
		puts("");
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visit[i]) continue;
		visit[i] = 1;
		v.push_back(arr[i]);
		Select();
		v.pop_back();
		visit[i] = 0;
	}
}
int main(void) {
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) {
		arr[i - 1] = i;
	}

	Select();
}