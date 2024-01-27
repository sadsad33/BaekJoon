// 1202 ���� ����
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
		while (index < n && bags[i] >= jewels[index].weight) { // �ռ� ���濡�� ���� �������� �ٽ� �˻��ϸ� �ȵǹǷ� for����� while�� ���
			pq.push(jewels[index++].price); // �켱���� ť�� ���ݵ��� ����
		}
		if (pq.size()) {
			totalPrice += pq.top(); // �켱���� ť ���� ���ݵ��� ���� ������ ���� �Ǿ� �����Ƿ� top ���� �ְ���
			pq.pop();
		}
	}
	printf("%lld", totalPrice);
	return 0;
}