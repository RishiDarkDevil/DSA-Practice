#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return (a.second != b.second)? a.second > b.second : a.first < b.first;
}

int main() {
	int n;
	cin >> n;

	vector<pair<string, int>> mark_names;
	for (int i = 0; i < n; ++i) {
		string name; int marks;
		cin >> name >> marks;
		mark_names.push_back({name, marks});
	}

	sort(mark_names.begin(), mark_names.end(), cmp);

	for (auto &person: mark_names)
		cout << person.first << " " << person.second << endl;
}