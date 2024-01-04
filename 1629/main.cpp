#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
// ((A % C) * (A % C)) % C == A * A % C
unsigned long Divide(unsigned long a, unsigned long b, unsigned long c) {
	if (b == 0) return 1;
	else if (b == 1) return a % c;
	else {
		if (b & 1) {
			b--;
			return a * Divide(a * a % c, b / 2, c) % c;
		}
		else return Divide(a * a % c, b / 2, c) % c;
	}
}
int main(void) {
	unsigned long  a, b, c; scanf("%ld%ld%ld", &a, &b, &c);
	printf("%ld", Divide(a, b, c));
	return 0;
}