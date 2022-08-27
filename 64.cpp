#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<char, int> a, pair<char, int> b) {
	return (a.second != b.second)? (a.second > b.second) : (a.first < b.first); 
}

int main() {
	string str;
	getline(cin, str);

	map<char, int> freq_table;
	for (int i = 0; i < str.size(); ++i)
		freq_table[str[i]]++;
	
	vector<pair<char, int>> freq_vec;
	for (auto &i: freq_table)
		freq_vec.push_back({i.first, i.second});

	sort(freq_vec.begin(), freq_vec.end(), cmp);

	cout << freq_vec.begin()->first;
}