#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	map<int, multiset<string>> mark_names;
	for (int i = 0; i < n; ++i) {
		string name; int marks;
		cin >> name >> marks;
		mark_names[marks].insert(name);
	}

	for (auto marks = mark_names.rbegin(); marks != mark_names.rend(); marks++) {
		for (auto &name: marks->second)
			cout << name << " " << marks->first << endl;
	}
}