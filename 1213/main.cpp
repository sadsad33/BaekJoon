#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
int main(void) {
	char input[51]; scanf("%s", input);
	int len = strlen(input);
	map<char, int>m;
	vector<char> c;
	for (int i = 0; i < len; i++) {
		if (!m[input[i]]) c.push_back(input[i]);
		m[input[i]]++;
	}
	sort(c.begin(), c.end());
	int iter = len & 1 ? len / 2 : len / 2 - 1, cnt = 0;
	char res[51];
 	for (int i = 0; i <= iter; i++) {
		for (int j = 0; j < c.size(); j++) {
			if (m[c[j]] >= 2) {
				m[c[j]] -= 2;
				res[i] = c[j];
				res[len - 1 - i] = c[j];
				cnt += 2;
				break;
			}
			else if (m[c[j]] < 1) continue;
			else {
				if (i == iter) {
					res[i] = c[j];
					m[c[j]]--;
					cnt += 1;
					break;
				}
				continue;
			}
		}
	}
	if (cnt == len) {
		res[len] = '\0';
		printf("%s", res);
	}
	else {
		printf("I'm Sorry Hansoo");
	}
	return 0;
}