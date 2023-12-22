#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
int main(void) {
	int num[26] = { 0 };
	char input[101];
	scanf("%s", input);
	int len = strlen(input);

	for (int i = 0; i < len; i++) {
		for (int j = 97; j < 123; j++) {
			if ((int)input[i] == j) {
				num[j - 97]++;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		printf("%d ", num[i]);
	}
	return 0;
}