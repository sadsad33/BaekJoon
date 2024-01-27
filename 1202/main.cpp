// 1202 보석 도둑
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct {
	int weight;
	int price;
}Jewel;

Jewel jewels[300010];
long long bags[300010];

bool Compare(Jewel a, Jewel b) {
	if (a.weight == b.weight) return a.price > b.price;
	return a.weight < b.weight;
}

int main(void) {
	int n, k; scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d%d", &jewels[i].weight, &jewels[i].price);
	}
	for (int i = 0; i < k; i++) {
		scanf("%lld", &bags[i]);
	}

	sort(jewels, jewels + n, Compare);
	sort(bags, bags + k);
	priority_queue<long long>pq;
	long long totalPrice = 0;
	int index = 0;

	for (int i = 0; i < k; i++) {
		while (index < n && bags[i] >= jewels[index].weight) { // 앞선 가방에서 넣은 보석들은 다시 검사하면 안되므로 for문대신 while문 사용
			pq.push(jewels[index++].price); // 우선순위 큐에 가격들을 삽입
		}
		if (pq.size()) {
			totalPrice += pq.top(); // 우선순위 큐 내에 가격들이 높은 순으로 정렬 되어 있으므로 top 값이 최고가격
			pq.pop();
		}
	}
	printf("%lld", totalPrice);
	return 0;
}