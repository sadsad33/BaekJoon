#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
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
		for (int i = 0; i < len; i++) {
			if (!buf.size()) {
				buf.push(input[i]);
			}
			else {
				if(bu)
			}
		}
	}
	printf("%d", cnt);
	return 0;
}