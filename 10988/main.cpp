#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
int main(void) {
	char input[100];
	scanf("%s", input);
	int len = strlen(input);
	int left = 0, right = len - 1;
	int cnt = 0;
	while (left < right) {
		if (input[left] == input[right])
			cnt++;
		left++; right--;
	}

	if (cnt == len / 2)
		printf("1");
	else
		printf("0");
	return 0;
}