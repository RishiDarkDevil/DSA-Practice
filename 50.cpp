#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	unordered_map<string, int> word_count;
	for (int i = 0; i < n; ++i) {
		string word;
		cin >> word;
		word_count[word]++;
	}
	int count = 0;
	for (auto &wd_ct: word_count) {
		if (wd_ct.second == 2) count++;
	}
	cout << count;
}