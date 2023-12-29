#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
using namespace std;
int main(void) {
	cin.tie(NULL); cout.tie(NULL);
	int n; scanf("%d", &n);

	while (n--) {
		map<string, int> closet;
		int n; scanf("%d", &n);
		string cloth, type;
		for (int i = 0; i < n; i++) {
			cin >> cloth >> type;
			closet[type]++;
		}

		int total = 1;
		for (auto iter : closet) {
			total *= (closet[iter.first] + 1);
		}
		printf("%d\n", --total);
	}

	return 0;
}