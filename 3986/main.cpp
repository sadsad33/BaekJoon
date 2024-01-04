#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int main(void) {
	int n; scanf("%d", &n);
	int cnt = 0;
	while (n--) {
		char input[100001]; scanf("%s", input);
		int len = strlen(input);
		stack<char> buf;
		buf.push(input[0]);
		for (int i = 1; i < len; i++) {
			if (buf.size() > 0 && buf.top() == input[i]) {
				buf.pop();
			}
			else {
				buf.push(input[i]);
			}
		}
		if (!buf.size()) cnt++;
	}
	printf("%d", cnt);
	return 0;
}