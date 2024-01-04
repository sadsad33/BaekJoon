#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
// x mod n = (x mod n) mod n
int main(void) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int digit = 1;
		long long num = 1;
		while (1) {
			if (!(num % n)) break;
			else {
				num *= 10;
				num++;
				num %= n;
				digit++;
			}
		}
		printf("%d\n", digit);
	}

	return 0;
}