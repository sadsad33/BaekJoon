#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
int main(void) {
	char input[100];
	scanf("%[^\n]s", input);
	int len = strlen(input);
	int res[100];
	for (int i = 0; i < len; i++) {
		if ((int)input[i] >= 97 && (int)input[i] <= 122) {
			res[i] = (int)input[i] + 13;
			if (res[i] > 122) res[i] -= 26;
		}
		else if ((int)input[i] >= 65 && (int)input[i] <= 90) {
			res[i] = (int)input[i] + 13;
			if (res[i] > 90) res[i] -= 26;
		}
		else res[i] = input[i];
	}
	
	for (int i = 0; i < len; i++) {
		printf("%c", res[i]);
	}
	return 0;
}