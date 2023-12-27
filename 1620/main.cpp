#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(void) {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	map<int, string> pokedexInt;
	map<string, int> pokedexStr;
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string input; cin >> input;
		pokedexInt.insert(pair<int, string>(i, input));
		pokedexStr.insert(pair<string, int>(input, i));
	}

	for (int i = 0; i < m; i++) {
		string input; cin >> input;
		if (!pokedexStr[input]) {
			int temp = stoi(input);
			cout << pokedexInt[temp] << '\n';
		}
		else {
			cout << pokedexStr[input] << '\n';
		}
	}
	return 0;
}