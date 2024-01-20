#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int main(void) {
	scanf("%d", &n);
	priority_queue<double, vector<double>, greater<double>>pq;
	while (n--) {
		double grade; scanf("%lf", &grade);
		pq.push(grade);
	}

	for (int i = 0; i < 7; i++) {
		printf("%.3lf\n", pq.top());
		pq.pop();
	}

	return 0;
}