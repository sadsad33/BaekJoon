#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
int main(void) {
	int n; scanf("%d", &n);
	char input[100]; scanf("%s", input);
	int len_Input = strlen(input);
	char prefix[50], suffix[50];
	int change = 0, i, len_prefix = 0, len_suffix = 0;
	for (i = 0; i < len_Input; i++) {
		if (input[i] == '*') {
			change = 1;
			len_prefix = i;
		}
		else if (!change) prefix[i] = input[i];
		else suffix[i] = input[i];
	}
	len_suffix = len_Input - len_prefix - 1;

	char pattern[100][100];
	for (i = 0; i < n; i++) {
		scanf("%s", pattern[i]);
		int cnt = 0, len_pattern = strlen(pattern[i]);
		for (int j = 0; j < len_prefix; j++) {
			if (pattern[i][j] == prefix[j]) cnt++;
		}
		if (cnt != len_prefix) {
			printf("NE\n");
			continue;
		}
		int index = len_pattern - 1;
		for (int j = len_Input - 1; j >= len_Input - len_suffix; j--) {
			if (j-index > 1) break;
			else if (pattern[i][index--] == suffix[j]) cnt++;
		}

		if (cnt == len_suffix + len_prefix) printf("DA\n");
		else printf("NE\n");
	}
	return 0;
}