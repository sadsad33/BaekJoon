#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(void) {
	char names[151][30];
	int characters[26] = { 0 };
	int num; scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%s", &names[i]);
		characters[names[i][0] - 97]++;
	}

	int succeed = 0;
	for (int i = 0; i < 26; i++) {
		if (characters[i] >= 5) {
			printf("%c", i + 97);
			succeed = 1;
		}
	}

	if (!succeed) printf("PREDAJA");
	return 0;
}