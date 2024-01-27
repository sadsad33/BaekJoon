// 2910 ºóµµ Á¤·Ä
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef struct {
	int num;
	int freq;
}Node;

typedef struct {
	Node* nodes;
	int size;
}List;

int main(void) {
	int n, c; scanf("%d%d", &n, &c);
	List* list = (List*)malloc(sizeof(List));
	list->nodes = (Node*)malloc(sizeof(Node) * n);
	for (int i = 0; i < n; i++) {
		list->nodes[i].num = 0;
		list->nodes[i].freq = 0;
	}

	list->size = 0;
	int maxCnt = 0, iter = n;
	while (iter--) {
		int exist = 0;
		int input; scanf("%d", &input);

		for (int i = 0; i < list->size; i++) {
			if (list->nodes[i].num == input) {
				list->nodes[i].freq++;
				maxCnt = max(maxCnt, list->nodes[i].freq);
				exist = 1;
				break;
			}
		}

		if (exist) continue;
		else {
			list->nodes[list->size].num = input;
			list->nodes[list->size++].freq = 1;
		}
	}

	while (maxCnt >= 1) {
		for (int i = 0; i < list->size; i++) {
			if (list->nodes[i].freq == maxCnt) {
				for (int j = 0; j < list->nodes[i].freq; j++) {
					printf("%d ", list->nodes[i].num);
				}
			}
		}
		maxCnt--;
	}
	return 0;
}