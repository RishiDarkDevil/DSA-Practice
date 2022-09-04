// https://www.hackerearth.com/problem/algorithm/the-three-musketeers-6efd5f2d/

#include <bits/stdc++.h>
using namespace std;

string distVows(string s) {
	set<char> vows;
	for (int i = 0; i < s.size(); ++i) {
		char ch = s[i];
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			vows.insert(ch);
	}
	string vowels = "";
	for (auto &i: vows)
		vowels.push_back(i);
	return vowels;
}

void update_hash(string s, unordered_map<string, int> &hash) {
	for (int mask = 0; mask < (1<<s.size()); ++mask) {
		string sub = "";
		for (int j = 0; j < s.size(); ++j) {
			if (mask & (1 << j))
				sub.push_back(s[j]);
		}
		if (sub.size()) hash[sub]++;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		unordered_map<string, int> hash;
		for (int i = 0; i < n; ++i) {
			string str;
			cin >> str;
			update_hash(distVows(str), hash);
		}

		long long ans = 0;
		for (auto &subvow: hash) {
			long long ct = subvow.second;
			long long ways = (ct * (ct - 1) * (ct - 2)) / 6;
			if (subvow.first.size() & 1)
				ans += ways;
			else
				ans -= ways;
		}
		cout << ans << endl;
	}
}